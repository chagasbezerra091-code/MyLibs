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
