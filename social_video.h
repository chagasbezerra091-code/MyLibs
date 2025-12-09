#ifndef SOCIAL_VIDEO_H
#define SOCIAL_VIDEO_H

/* ============================================================
    CONFIGURAÇÕES GERAIS
   ============================================================ */

// Tamanhos máximos
#define MAX_USERNAME_LEN 64
#define MAX_VIDEO_TITLE_LEN 128
#define MAX_VIDEO_PATH_LEN 256

// Códigos de erro
#define ERR_OK 0
#define ERR_FAIL -1
#define ERR_NOT_FOUND -2
#define ERR_INVALID -3
#define ERR_VIDEO_NOT_EXISTS -4
#define ERR_404 -5
// Qualidades de vídeo
#define VIDEO_480P 480
#define VIDEO_720P 720
#define VIDEO_1080P 1080


/* ============================================================
    ESTRUTURAS BÁSICAS
   ============================================================ */

/** Estrutura: Usuário */
typedef struct {
    int id;
    char username[MAX_USERNAME_LEN];
    int followers;
    int following;
} User;

/** Estrutura: Vídeo */
typedef struct {
    int id;
    char title[MAX_VIDEO_TITLE_LEN];
    char file_path[MAX_VIDEO_PATH_LEN];
    int likes;
    int saves;
    int reposts;
} Video;


/* ============================================================
    SISTEMA DE CONTAS
   ============================================================ */

/**
 * Cria uma nova conta de usuário.
 *
 * @param username - Nome do usuário.
 * @return ID do usuário criado ou código de erro.
 */
int create_account(const char *username);

/**
 * Carrega dados de um usuário.
 *
 * @param user_id - ID do usuário.
 * @param out - Ponteiro para struct User onde os dados serão carregados.
 * @return ERR_OK ou código de erro.
 */
int load_user(int user_id, User *out);

/**
 * Salva mudanças no usuário.
 *
 * @param user - Struct do usuário modificada.
 * @return ERR_OK ou código de erro.
 */
int save_user(const User *user);


/* ============================================================
    SISTEMA DE VÍDEOS
   ============================================================ */

/**
 * Registra um novo vídeo no sistema.
 *
 * @param title - Título.
 * @param path - Caminho do arquivo.
 * @return ID do vídeo criado ou código de erro.
 */
int register_video(const char *title, const char *path);

/**
 * Carrega vídeo.
 *
 * @param video_id - ID do vídeo.
 * @param out - Struct onde serão armazenados os dados.
 * @return ERR_OK ou código de erro.
 */
int load_video(int video_id, Video *out);

/**
 * Gera diversas qualidades (ex.: 480p, 720p, 1080p).
 *
 * @param video_id - ID do vídeo.
 * @param quality - Uma das constantes (VIDEO_480P, ...).
 * @return ERR_OK ou código de erro.
 */
int generate_quality(int video_id, int quality);


/* ============================================================
    CURTIDAS / SALVAMENTOS / REPOSTS
   ============================================================ */

/** Curte um vídeo */
int like_video(int user_id, int video_id);

/** Remove curtida */
int unlike_video(int user_id, int video_id);

/** Salva vídeo */
int save_video_user(int user_id, int video_id);

/** Remove vídeo salvo */
int unsave_video_user(int user_id, int video_id);

/** Reposta vídeo */
int repost_video(int user_id, int video_id);

/** Remove repost */
int remove_repost(int user_id, int video_id);


/* ============================================================
    FEED (ALGORITMO)
   ============================================================ */

/**
 * Gera feed recomendado.
 *
 * @param user_id - ID do usuário.
 * @param out_buffer - Array de IDs de vídeos.
 * @param max_videos - Quantidade máxima para preencher.
 * @return número de vídeos retornados.
 */
int generate_feed(int user_id, int *out_buffer, int max_videos);


/* ============================================================
    PLAYER DE VÍDEO
   ============================================================ */

/** Inicializa player de vídeo */
int video_player_init();

/** Reproduz vídeo */
int video_player_play(int video_id);

/** Pausa vídeo */
int video_player_pause();

/** Ajusta qualidade */
int video_player_set_quality(int quality);


/* ============================================================
    UPLOAD DE VÍDEO
   ============================================================ */

/** Envia arquivo bruto */
int upload_video(int user_id, const char *path);

/** Valida formato */
int validate_video(const char *path);

/** Gera thumbnail */
int generate_thumbnail(int video_id);

/** Publica vídeo depois do upload */
int publish_video(int video_id);


/* ============================================================
    DEMAIS UTILIDADES
   ============================================================ */

/** Gera ID único */
int generate_unique_id();

/** Converte erros em texto */
const char* get_error_str(int err);

#endif
