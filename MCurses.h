/////////ARQUIVO: MCurses.h \\\\\\\\\\
#include <Colors.h> /** https://github.com/chagasbezerra091-code/MyLibs/blob/main/Colors.h */
#include <stdio.h>
#define COR_VERMELHO 1
#define COR_VERDE    2
#define COR_AZUL     3
#define COR_CIANO         4
#define COR_PRETO         5
#define COR_RESET         6
#define COR_BRANCO         7
#define COR_AMARELO         8
#define COR_TRANSPARENTE         9
#define COR_LARANJA         10
typedef struct {
ITALIC,
BOLD,
SANS_SERIF,
MONOSPACE
}
enum window {
GRANDE = 1,
MEDIA = 2,
PEQUENA = 3
}
printf("Janelas: %d \
        Logs: %d    \
\n");
