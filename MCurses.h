#ifndef MCURSES_H
#define MCURSES_H

#include <stdio.h>
#include "Colors.h"

// ---- Cores (enum estilo ncurses) ----
enum MCursesColors {
    COR_VERMELHO = 1,
    COR_VERDE,
    COR_AZUL,
    COR_CIANO,
    COR_PRETO,
    COR_RESET,
    COR_BRANCO,
    COR_AMARELO,
    COR_TRANSPARENTE,
    COR_LARANJA
};

// ---- Estilo de texto ----
enum MCursesStyle {
    ESTILO_NORMAL = 0,
    ESTILO_BOLD   = 1 << 0,
    ESTILO_ITALIC = 1 << 1,
    ESTILO_UNDER  = 1 << 2,
    ESTILO_REVERSE= 1 << 3
};

// ---- Tamanho das janelas ----
enum MCursesWindowSize {
    JANELA_GRANDE  = 1,
    JANELA_MEDIA   = 2,
    JANELA_PEQUENA = 3
};

// ---- Estrutura de janela (tipo WINDOW do ncurses) ----
typedef struct {
    int x;
    int y;
    int w;
    int h;
    int cor;
    int estilo;
} MCURSES_WINDOW;

#endif
#define MCURSES_MASK1 (1 << 0) // 00000001
#define MCURSES_MASK2 (1 << 1) // 00000010
#define MCURSES_MASK3 (1 << 2) // 00000100
#define MCURSES_MASK4 (1 << 3) // 00001000
#define MCURSES_MASK5 (1 << 4) // 00010000
#define MCURSES_MASK6 (1 << 5) // 00100000
#define MCURSES_MASK7 (1 << 6) // 01000000
#define MCURSES_MASK8 (1 << 7) // 10000000
#define MCURSES_MASK9 (1 << 8) // 1 00000000
int flags = MCURSES_MASK1 | MCURSES_MASK9;
typedef struct {
int btn_ui;
int btn_style;
int btn_onclick;
int btn_color;
}
/** MACROS IGUAL DA ncurses.h */
/* — Máscara auxiliar interna — */
#define NCURSES_BITS(mask,shift)  ((mask) << ((shift) + 8))

/* — Máscaras para caracteres e atributos — */
#define A_CHARTEXT   (NCURSES_BITS(1UL,0) - 1UL)
#define A_NORMAL     0L
#define A_COLOR      NCURSES_BITS(((1UL) << 8) - 1UL, 0)

/* — Atributos de texto / vídeo — */
#define A_STANDOUT   NCURSES_BITS(1UL,8)
#define A_UNDERLINE  NCURSES_BITS(1UL,9)
#define A_REVERSE    NCURSES_BITS(1UL,10)
#define A_BLINK      NCURSES_BITS(1UL,11)
#define A_DIM        NCURSES_BITS(1UL,12)
#define A_BOLD       NCURSES_BITS(1UL,13)
#define A_ALTCHARSET NCURSES_BITS(1UL,14)
#define A_INVIS      NCURSES_BITS(1UL,15)
#define A_PROTECT    NCURSES_BITS(1UL,16)

/* — Atributos extras / comprimentos — */
#define A_HORIZONTAL NCURSES_BITS(1UL,17)
#define A_LEFT       NCURSES_BITS(1UL,18)
#define A_LOW        NCURSES_BITS(1UL,19)
#define A_RIGHT      NCURSES_BITS(1UL,20)
#define A_TOP        NCURSES_BITS(1UL,21)
#define A_VERTICAL   NCURSES_BITS(1UL,22)

/* — Máscara de todos os atributos — */
#define A_ATTRIBUTES NCURSES_BITS(~(1UL - 1UL),0)

/* — Equivalentes com prefixo WA_ (para attr_t, wide curses API) — */
#define WA_NORMAL    A_NORMAL
#define WA_STANDOUT  A_STANDOUT
#define WA_UNDERLINE A_UNDERLINE
#define WA_REVERSE   A_REVERSE
#define WA_BLINK     A_BLINK
#define WA_DIM       A_DIM
#define WA_BOLD      A_BOLD
#define WA_ALTCHARSET A_ALTCHARSET
#define WA_INVIS     A_INVIS
#define WA_PROTECT   A_PROTECT
#define WA_HORIZONTAL A_HORIZONTAL
#define WA_LEFT       A_LEFT
#define WA_LOW        A_LOW
#define WA_RIGHT      A_RIGHT
#define WA_TOP        A_TOP
#define WA_VERTICAL   A_VERTICAL
#define WA_ATTRIBUTES A_ATTRIBUTES

/* — Cores básicas definidas — */
#define COLOR_BLACK   0
#define COLOR_RED     1
#define COLOR_GREEN   2
#define COLOR_YELLOW  3
#define COLOR_BLUE    4
#define COLOR_MAGENTA 5
#define COLOR_CYAN    6
#define COLOR_WHITE   7

/* — Macro para usar par de cores como atributo — */
#define COLOR_PAIR(n)  ( (n) << CPAIR_SHIFT )  /* depende da definição CPAIR_SHIFT */

/* — (Outras macros/utilidades internas — flags de janela, atributos internos etc.) — */
#define _SUBWIN     0x01
#define _ENDLINE    0x02
#define _FULLWIN    0x04
#define _ISPAD      0x10
#define _HASMOVED   0x20
#define TRACE_MAXIMUM 0xffff

/* Tipo de caractere + atributos + cor */
typedef unsigned long chtype;
/* Tipo booleano (em algumas builds) */
typedef char bool;
/* ────────── Conjunto alternativo de caracteres (ACS) ────────── */
/* Usados com addch() / mvaddch() para desenhar linhas e cantos */

/* Cantos */
#define ACS_ULCORNER  0x6b  /* ┌ */
#define ACS_LLCORNER  0x6c  /* └ */
#define ACS_URCORNER  0x6a  /* ┐ */
#define ACS_LRCORNER  0x69  /* ┘ */

/* Linhas horizontais e verticais */
#define ACS_HLINE     0x71  /* ─ */
#define ACS_VLINE     0x78  /* │ */

/* Junções e T’s */
#define ACS_LTEE      0x74  /* ├ */
#define ACS_RTEE      0x75  /* ┤ */
#define ACS_BTEE      0x76  /* ┴ */
#define ACS_TTEE      0x77  /* ┬ */
#define ACS_PLUS      0x73  /* ┼ */

/* Bloquinhos e caracteres especiais */
#define ACS_BLOCK     0xdb  /* █ */
#define ACS_BOARD     0xdc  /* ▓ */
#define ACS_CKBOARD   0xb2  /* ▒ */

/* Outros símbolos gráficos */
#define ACS_LARROW    0x1b  /* ← */
#define ACS_RARROW    0x1a  /* → */
#define ACS_UARROW    0x19  /* ↑ */
#define ACS_DARROW    0x18  /* ↓ */
#define ACS_DIAMOND   0x04  /* ♦ */
#define ACS_CKBOARD   0xb2  /* ▒ */
#define ACS_PLMINUS   0x0f  /* ± */
#define ACS_BULLET    0x07  /* • */
#define ACS_LANTERN   0x08  /* ⌂ */
#define ACS_BOARD     0xdc  /* ▓ */
#define ACS_S1        0xb0  /* ░ */
#define ACS_S9        0xb1  /* ▒ */
/* ─────────── MCurses Keyboard Keys ─────────── */

/* Teclas de função */
#define MCURSES_H_KEYBOARD_KEY_F1      0x101
#define MCURSES_H_KEYBOARD_KEY_F2      0x102
#define MCURSES_H_KEYBOARD_KEY_F3      0x103
#define MCURSES_H_KEYBOARD_KEY_F4      0x104
#define MCURSES_H_KEYBOARD_KEY_F5      0x105
#define MCURSES_H_KEYBOARD_KEY_F6      0x106
#define MCURSES_H_KEYBOARD_KEY_F7      0x107
#define MCURSES_H_KEYBOARD_KEY_F8      0x108
#define MCURSES_H_KEYBOARD_KEY_F9      0x109
#define MCURSES_H_KEYBOARD_KEY_F10     0x10A
#define MCURSES_H_KEYBOARD_KEY_F11     0x10B
#define MCURSES_H_KEYBOARD_KEY_F12     0x10C

/* Teclas de seta */
#define MCURSES_H_KEYBOARD_KEY_UP      0x111
#define MCURSES_H_KEYBOARD_KEY_DOWN    0x112
#define MCURSES_H_KEYBOARD_KEY_LEFT    0x113
#define MCURSES_H_KEYBOARD_KEY_RIGHT   0x114

/* Teclas especiais */
#define MCURSES_H_KEYBOARD_KEY_HOME    0x115
#define MCURSES_H_KEYBOARD_KEY_END     0x116
#define MCURSES_H_KEYBOARD_KEY_PAGE_UP 0x117
#define MCURSES_H_KEYBOARD_KEY_PAGE_DOWN 0x118
#define MCURSES_H_KEYBOARD_KEY_INSERT  0x119
#define MCURSES_H_KEYBOARD_KEY_DELETE  0x11A

/* Teclas de controle */
#define MCURSES_H_KEYBOARD_KEY_BACKSPACE 0x11B
#define MCURSES_H_KEYBOARD_KEY_ENTER     0x11C
#define MCURSES_H_KEYBOARD_KEY_ESC       0x11D
#define MCURSES_H_KEYBOARD_KEY_TAB       0x11E
#define MCURSES_H_KEYBOARD_KEY_SPACE     0x20

/* Teclas alfanuméricas básicas */
/* A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z */
#define MCURSES_H_KEYBOARD_KEY_A 'A'
#define MCURSES_H_KEYBOARD_KEY_B 'B'
#define MCURSES_H_KEYBOARD_KEY_C 'C'
#define MCURSES_H_KEYBOARD_KEY_D 'D'
#define MCURSES_H_KEYBOARD_KEY_E 'E'
#define MCURSES_H_KEYBOARD_KEY_F 'F'
#define MCURSES_H_KEYBOARD_KEY_G 'G'
#define MCURSES_H_KEYBOARD_KEY_H 'H'
#define MCURSES_H_KEYBOARD_KEY_I 'I'
#define MCURSES_H_KEYBOARD_KEY_J 'J'
#define MCURSES_H_KEYBOARD_KEY_K 'K'
#define MCURSES_H_KEYBOARD_KEY_L 'L'
#define MCURSES_H_KEYBOARD_KEY_M 'M'
#define MCURSES_H_KEYBOARD_KEY_N 'N'
#define MCURSES_H_KEYBOARD_KEY_O 'O'
#define MCURSES_H_KEYBOARD_KEY_P 'P'
#define MCURSES_H_KEYBOARD_KEY_Q 'Q'
#define MCURSES_H_KEYBOARD_KEY_R 'R'
#define MCURSES_H_KEYBOARD_KEY_S 'S'
#define MCURSES_H_KEYBOARD_KEY_T 'T'
#define MCURSES_H_KEYBOARD_KEY_U 'U'
#define MCURSES_H_KEYBOARD_KEY_V 'V'
#define MCURSES_H_KEYBOARD_KEY_W 'W'
#define MCURSES_H_KEYBOARD_KEY_X 'X'
#define MCURSES_H_KEYBOARD_KEY_Y 'Y'
#define MCURSES_H_KEYBOARD_KEY_Z 'Z'
#define MCURSES_H_KEYBOARD_KEY_0 '0'
#define MCURSES_H_KEYBOARD_KEY_1 '1'
#define MCURSES_H_KEYBOARD_KEY_2 '2'
#define MCURSES_H_KEYBOARD_KEY_3 '3'
#define MCURSES_H_KEYBOARD_KEY_4 '4'
#define MCURSES_H_KEYBOARD_KEY_5 '5'
#define MCURSES_H_KEYBOARD_KEY_6 '6'
#define MCURSES_H_KEYBOARD_KEY_7 '7'
#define MCURSES_H_KEYBOARD_KEY_8 '8'
#define MCURSES_H_KEYBOARD_KEY_9 '9'
