#pragma once
#define KGLGE_A 0
#define KGLGE_B 1
#define KGLGE_C 2
#define KGLGE_D 3
#define KGLGE_E 4
#define KGLGE_F 5
#define KGLGE_G 6
#define KGLGE_H 7
#define KGLGE_I 8
#define KGLGE_J 9
#define KGLGE_K 10
#define KGLGE_L 11
#define KGLGE_M 12
#define KGLGE_N 13
#define KGLGE_O 14
#define KGLGE_P 15
#define KGLGE_Q 16
#define KGLGE_R 17
#define KGLGE_S 18
#define KGLGE_T 19
#define KGLGE_U 20
#define KGLGE_V 21
#define KGLGE_W 22
#define KGLGE_X 23
#define KGLGE_Y 24
#define KGLGE_Z 25
static unsigned int convertCharToInt(char letter){
    switch (letter)
    {
    case ('A'):
        return KGLGE_A;
        break;
    case('B'):
        return KGLGE_B;
        break;
    case('C'):
        return KGLGE_C;
    case('D'):
        return KGLGE_D;
    case('E'):
        return KGLGE_E;
    case('F'):
        return KGLGE_F;
    case('G'):
        return KGLGE_G;
    case('H'):
        return KGLGE_H;
    case('I'):
        return KGLGE_I;
    case('J'):
        return KGLGE_J;
    case('K'):
        return KGLGE_K;
    case('L'):
        return KGLGE_L;
    case('M'):
        return KGLGE_M;
    case('N'):
        return KGLGE_N;
    case('O'):
        return KGLGE_O;
    case('P'):
        return KGLGE_P;
    case('Q'):
        return KGLGE_Q;
    case('R'):
        return KGLGE_R;
    case('S'):
        return KGLGE_S;
    case('T'):
        return KGLGE_T;
    case('U'):
        return KGLGE_U;
    case('V'):
        return KGLGE_V;
    case('W'):
        return KGLGE_W;
    case('X'):
        return KGLGE_X;
    case('Y'):
        return KGLGE_Y;
    case('Z'):
        return KGLGE_Z;
    default:
        return 0;
        break;
    }
}
static unsigned int convertKeyToLetter(unsigned int Key){
    return 0;
}
//Format being used https://fontmeme.com/fonts/bbbixxxel-font/