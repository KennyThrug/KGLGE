#include <stdio.h>
#include <stdlib.h>

#include "Window.h"
#include <GLEW/GL/glew.h>
#include <gl/gl.h>
#include <gl/glu.h>

#define kTextureDim 64

GLuint t1;
GLuint t2;

/* adapted from the red book */
GLuint makeCheckTex() {
    GLubyte image[kTextureDim][kTextureDim][4]; // RGBA storage

    for (int i = 0; i < kTextureDim; i++) {
        for (int j = 0; j < kTextureDim; j++) {
            int c = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;
            image[i][j][0] = (GLubyte)c;
            image[i][j][1] = (GLubyte)c;
            image[i][j][2] = (GLubyte)c;
            image[i][j][3] = (GLubyte)255;
        }
    }

    GLuint texName;
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, kTextureDim, kTextureDim, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    return texName;
}

void loadShader() {
#define STRINGIFY(A) #A

    const GLchar* source = STRINGIFY(

        uniform sampler2D tex1;
    uniform sampler2D tex2;

    void main() {
        vec4 s1 = texture2D(tex1, gl_TexCoord[0].st);
        vec4 s2 = texture2D(tex2, gl_TexCoord[0].st + vec2(0.0625, 0.0625));
        gl_FragColor = mix(vec4(1, s1.g, s1.b, 0.5), vec4(s2.r, s2.g, 1, 0.5), 0.5);
    }

    );

    GLuint program = glCreateProgram();
    GLuint shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    GLint logLength;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar* log = (GLchar*)malloc(logLength);
        glGetShaderInfoLog(shader, logLength, &logLength, log);
        printf("Shader compile log:\n%s\n", log);
        free(log);
    }

    glAttachShader(program, shader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar* log = (GLchar*)malloc(logLength);
        glGetProgramInfoLog(program, logLength, &logLength, log);
        printf("Program link log:\n%s\n", log);
        free(log);
    }

    GLuint t1Location = glGetUniformLocation(program, "tex1");
    GLuint t2Location = glGetUniformLocation(program, "tex2");

    glUniform1i(t1Location, 0);
    glUniform1i(t2Location, 1);

    glUseProgram(program);
}


void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);

    t1 = makeCheckTex();
    t2 = makeCheckTex();

    loadShader();
}


void display(KGLGE::Window* win)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glActiveTexture(GL_TEXTURE0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, t1);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, t2);

    glBegin(GL_QUADS);
    //lower left
    glTexCoord2f(0, 0);
    glVertex2f(-1.0, -1.0);
    //upper left
    glTexCoord2f(0, 1.0);
    glVertex2f(-1.0, 1.0);
    //upper right
    glTexCoord2f(1.0, 1.0);
    glVertex2f(1.0, 1.0);
    //lower right
    glTexCoord2f(1.0, 0);
    glVertex2f(1.0, -1.0);
    glEnd();

    win->swapBuffers();
}


void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*
int main(int argc, char** argv)
{
    KGLGE::Window win(100,100,"tesi");
    win.display();
    init();

    while (!win.shouldClose()) {
        win.clearWindow(1,1,1,1);
        display(&win);
    }
    return 0;
}*/