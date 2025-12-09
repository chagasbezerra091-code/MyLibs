#define MASCARA_F12 (F1 | F2)
flags &= ~MASCARA_F12;
flags |= MASCARA_F12;
typedef enum {
    F_A = 1 << 0,
    F_B = 1 << 1,
    F_C = 1 << 2,
    F_D = 1 << 3,
} Flags;
Flags x = F_A | F_C;
struct Status {
    unsigned int ligado : 1;
    unsigned int erro   : 1;
    unsigned int modo   : 2;
};
