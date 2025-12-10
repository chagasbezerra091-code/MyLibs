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
