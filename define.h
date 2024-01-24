#ifndef DEF_DEFINE
#define DEF_DEFINE

#define HEIGHT      20 // Hauteur de l'aire de jeu
#define WIDTH       60 // Largeur de l'aire de jeu
#define X0          30 // Position en X du d�but de l'aire de jeu (point en haut � gauche)
#define Y0          4   // Position en Y du d�but de l'aire de jeu (point en haut � gauche)

#define TIME_INTERVAL   50 // P�riode d'actualisation du jeu (en ms)

#define BORDER     "!" // Caract�re de d�limitation de bordure
#define FOOD        "O" // Caract�re de nourriture
#define BODY        'X' // Caract�re du serpent

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
