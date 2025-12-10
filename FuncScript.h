for (int i=0; i < sizeof(__FUNCSCRIPTALLCOMMANDS__)/sizeof(char*); i++) {
    printf("Comando: %s\n", __FUNCSCRIPTALLCOMMANDS__[i]);
}
static const char* __FUNCSCRIPTALLCOMMANDS__[] = {
    "define",
    "var",
    "let",
    "read.io",
    "write.io",
    "print"
};
/* Resto no repositorio oficial */
