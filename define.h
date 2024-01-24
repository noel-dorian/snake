#ifndef DEF_DEFINE
#define DEF_DEFINE

#define HEIGHT      20 // Hauteur de l'aire de jeu
#define WIDTH       60 // Largeur de l'aire de jeu
#define X0          30 // Position en X du début de l'aire de jeu (point en haut à gauche)
#define Y0          4   // Position en Y du début de l'aire de jeu (point en haut à gauche)

#define TIME_INTERVAL   50 // Période d'actualisation du jeu (en ms)

#define BORDER     "!" // Caractère de délimitation de bordure
#define FOOD        "O" // Caractère de nourriture
#define BODY        'X' // Caractère du serpent

#define KEY_Z    122 // Code ASCII de la lettre z
#define KEY_Q    113 // Code ASCII de la lettre Q
#define KEY_S    115 // Code ASCII de la lettre S
#define KEY_D    100 // Code ASCII de la lettre D
#define KEY_P    112 // Code ASCII de la lettre P
#define KEY_R    114 // Code ASCII de la lettre R

typedef struct Coord Coord;
struct Coord
{
    int x;
    int y;
};

typedef struct Body Body;
struct Body
{
    Coord coord;
    Body *next;
};

typedef struct Snake Snake;
struct Snake
{
    Body *first;
};

#endif // DEF_DEFINE
