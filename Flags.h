#define EXEMPLO_1 (1 << 0)   // 0001    
#define EXEMPLO_2 (1 << 1)   // 0010    
#define EXEMPLO_3 (1 << 2)   // 0100    
#define EXEMPLO_4 (1 << 3)   // 1000    
int exemp1 = EXEMPLO_1 | EXEMPLO_1;  
int exemp2 = EXEMPLO_1 | EXEMPLO_2;  
int exemp3 = EXEMPLO_1 | EXEMPLO_3;  
int exemp4 = EXEMPLO_1 | EXEMPLO_4;  
int todos = EXEMPLO_1 | EXEMPLO_2 | EXEMPLO_3 | EXEMPLO_4;
#define F1 (1 << 0)
#define F2 (1 << 1)
#define F3 (1 << 2)
#define F4 (1 << 3)
value |= F2;
value &= ~F3;
value ^= F1;
