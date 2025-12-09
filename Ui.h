typedef struct {
    int x, y, w, h;      // posição e tamanho
    int estado;          // normal, hover, pressionado
    void (*on_click)();  // callback quando clicar
} Botao;
void atualiza_botao(Botao *b, SDL_Event *e) {
    int dentro =
        e->motion.x >= b->x &&
        e->motion.x <= b->x + b->w &&
        e->motion.y >= b->y &&
        e->motion.y <= b->y + b->h;

    if (dentro && e->type == SDL_MOUSEBUTTONDOWN) {
        b->estado = 1; // pressionado
    }

    if (dentro && e->type == SDL_MOUSEBUTTONUP) {
        if (b->on_click) b->on_click();
        b->estado = 0;
    }
}
