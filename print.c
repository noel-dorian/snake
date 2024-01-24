#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "print.h"
#include "define.h"

void printBodySnake(Body* body, char c)
{
    int x = body->coord.x;
    int y = body->coord.y;
    GotoXY(X0 + x, Y0 + y);
    printf("%c", c);
}

void printAllSnake(Snake* snake)
{

}

/**
 * \fn printSnake
 * \brief Affiche le serpent dans la console
 * \param *snake : le pointeur sur le serpent du jeu
 * \param c : le caractère représentant le serpent
 */
void printSnake(Snake* snake, char c)
{
    Body* body = snake->first;
    while(body != NULL)
    {
        int x = body->coord.x;
        int y = body->coord.y;
        GotoXY(X0 + x, Y0 + y);
        printf("%c", c);
        body = body->next;
    }
}

/**
 * \fn printSnakeD
 * \brief Affiche le serpent dans la console en fonction de la direction du serpent
 * \param *snake : le pointeur sur le serpent du jeu
 * \param c : le caractère représentant le serpent
 * \param c_head : le caractère représentant la tête du serpent
 */
void printSnakeD(Snake* snake, char c, char c_head)
{
    Body* body = snake->first;
    while(body != NULL)
    {
        int x = body->coord.x;
        int y = body->coord.y;
        GotoXY(X0 + x, Y0 + y);
        if(body->next != NULL) printf("%c", c);
        else printf("%c", c_head);
        body = body->next;
    }
}

/**
 * \fn printBorder
 * \brief Affiche dans la console la bordure du jeu
 * \return void
 */
void printBorder()
{
    for (int i=Y0-1; i<=Y0+HEIGHT; i+=(HEIGHT+1))
    {
        for (int j=X0; j<X0+WIDTH; j++)
        {
            GotoXY(j, i);
            printf(BORDER);
        }
    }

    for (int i=X0-1; i<=X0+WIDTH; i+=(WIDTH+1))
    {
        for (int j=Y0-1; j<Y0+HEIGHT+1; j++)
        {
            GotoXY(i, j);
            printf(BORDER);
        }
    }
}

/**
 * \fn GotoXY
 * \brief Parametrer le curseur de la console
 * \param x : coordonnée X
 * \param y : coordonnée Y
 * \return void
 */
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}

/**
 * \fn removeCursor
 * \brief Cacher le curseur de la console
 * \return void
 */
void removeCursor()
{
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

/**
 * \fn printEndMenu
 * \brief Afficher le menu de fin de partie
 * \param score : le score de la partie
 * \return void
 */
void printEndMenu(int score)
{
    system("cls");
    printf("Vous avez perdu !\nVotre score est de %d points ! Bravo ! \n", score);
}

