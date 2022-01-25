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
#define KGLGE_a 26
#define KGLGE_b 27
#define KGLGE_c 28
#define KGLGE_d 29
#define KGLGE_e 30
#define KGLGE_f 31
#define KGLGE_g 32
#define KGLGE_h 33
#define KGLGE_i 34
#define KGLGE_j 35
#define KGLGE_k 36
#define KGLGE_l 37
#define KGLGE_m 38
#define KGLGE_n 39
#define KGLGE_o 40
#define KGLGE_p 41
#define KGLGE_q 42
#define KGLGE_r 43
#define KGLGE_s 44
#define KGLGE_t 45
#define KGLGE_u 46
#define KGLGE_v 47
#define KGLGE_w 48
#define KGLGE_x 49
#define KGLGE_y 50
#define KGLGE_z 51
#define KGLGE_0 52
#define KGLGE_1 53
#define KGLGE_2 54
#define KGLGE_3 55
#define KGLGE_4 56
#define KGLGE_5 57
#define KGLGE_6 58
#define KGLGE_7 59
#define KGLGE_8 60
#define KGLGE_9 61
#define KGLGE_Dot 62
#define KGLGE_Comma 63
#define KGLGE_SemiColon 64
#define KGLGE_Colon 65
#define KGLGE_Dollar 66
#define KGLGE_Pound 67
#define KGLGE_Apostrophie 68
#define KGLGE_Exclamation 69
#define KGLGE_Quote 70
#define KGLGE_Slash 71
#define KGLGE_Question 72
#define KGLGE_Percent 73
#define KGLGE_Ampersand 74
#define KGLGE_OpeningParenthesis 75
#define KGLGE_ClosingParenthesis 76
#define KGLGE_at 77
#define KGLGE_Space 255
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
    case ('a'):
        return KGLGE_a;
    case('b'):
        return KGLGE_b;
    case('c'):
        return KGLGE_c;
    case('d'):
        return KGLGE_d;
    case('e'):
        return KGLGE_e;
    case('f'):
        return KGLGE_f;
    case('g'):
        return KGLGE_g;
    case('h'):
        return KGLGE_h;
    case('i'):
        return KGLGE_i;
    case('j'):
        return KGLGE_j;
    case('k'):
        return KGLGE_k;
    case('l'):
        return KGLGE_l;
    case('m'):
        return KGLGE_m;
    case('n'):
        return KGLGE_n;
    case('o'):
        return KGLGE_o;
    case('p'):
        return KGLGE_p;
    case('q'):
        return KGLGE_q;
    case('r'):
        return KGLGE_r;
    case('s'):
        return KGLGE_s;
    case('t'):
        return KGLGE_t;
    case('u'):
        return KGLGE_u;
    case('v'):
        return KGLGE_v;
    case('w'):
        return KGLGE_w;
    case('x'):
        return KGLGE_x;
    case('y'):
        return KGLGE_y;
    case('z'):
        return KGLGE_z;
    case('0'):
        return KGLGE_0;
    case('1'):
        return KGLGE_1;
    case('2'):
        return KGLGE_2;
    case('3'):
        return KGLGE_3;
    case('4'):
        return KGLGE_4;
    case('5'):
        return KGLGE_5;
    case('6'):
        return KGLGE_6;
    case('7'):
        return KGLGE_7;
    case('8'):
        return KGLGE_8;
    case('9'):
        return KGLGE_9;
    case(' '):
        return KGLGE_Space;
    case('.'):
        return KGLGE_Dot;
    case(','):
        return KGLGE_Comma;
    case(';'):
        return KGLGE_SemiColon;
    case(':'):
        return KGLGE_Colon;
    case('$'):
        return KGLGE_Dollar;
    case('#'):
        return KGLGE_Pound;
    case('\''):
        return KGLGE_Apostrophie;
    case('!'):
        return KGLGE_Exclamation;
    case('\"'):
        return KGLGE_Quote;
    case('/'):
        return KGLGE_Slash;
    case('?'):
        return KGLGE_Question;
    case('%'):
        return KGLGE_Percent;
    case('&'):
        return KGLGE_Ampersand;
    case('('):
        return KGLGE_OpeningParenthesis;
    case(')'):
        return KGLGE_ClosingParenthesis;
    case('@'):
        return KGLGE_at;
    default:
        return KGLGE_Space;
        break;
    }
}
static unsigned int convertKeyToLetter(unsigned int Key,bool shift){
    if(Key >= 65 && Key <= 90){
        if(shift){
            return (Key - 39);
        }
        return Key - 65;
    }
    if(Key >= 48 && Key <= 57){
        return Key + 4;
    }
    if(Key == 32){
        return KGLGE_Space;
    }
    return 32;
}
//Format being used https://fontmeme.com/fonts/bbbixxxel-font/