#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "move.h"
#include "define.h"
#include "print.h"

/**
 * \fn getPressedKey
 * \brief Renvoie la touche pressé du clavier. Si aucune touche n'est pressée, la fonction renvoie -1
 */
int getPressedKey()
{
    if(kbhit()) return getch();
    else return -1;
}

/**
 * \fn moveRight
 * \brief Déplace le serpent de 1 vers la droite
 * \param snake : pointeur sur le serpent
 * \return void
 */
void moveRight(Snake* snake)
{
    Body* body = snake->first;

    int x=0;
    int y=0;
    GotoXY(0,0);
    while(body != NULL)
    {
        x = body->coord.x;
        y = body->coord.y;

        body = body->next;
    }
    addAtEnd(snake, x+1, y);
    removeAtEnd(snake);
}

/**
 * \fn moveLeft
 * \brief Déplace le serpent de 1 vers la gauche
 * \param snake : pointeur sur le serpent
 * \return void
 */
void moveLeft(Snake* snake)
{
    Body* body = snake->first;

    int x=0;
    int y=0;

    while(body != NULL)
    {
        x = body->coord.x;
        y = body->coord.y;
        body = body->next;
    }
    addAtEnd(snake, x-1, y);
    removeAtEnd(snake);
}

/**
 * \fn moveUp
 * \brief Déplace le serpent de 1 vers le haut
 * \param snake : pointeur sur le serpent
 * \return void
 */
void moveUp(Snake* snake)
{
    Body* body = snake->first;

    int x=0;
    int y=0;

    while(body != NULL)
    {
        x = body->coord.x;
        y = body->coord.y;
        body = body->next;
    }
    addAtEnd(snake, x, y-1);
    removeAtEnd(snake);
}

/**
 * \fn moveDown
 * \brief Déplace le serpent de 1 vers le bas
 * \param snake : pointeur sur le serpent
 * \return void
 */
void moveDown(Snake* snake)
{
    Body* body = snake->first;

    int x=0;
    int y=0;

    while(body != NULL)
    {
        x = body->coord.x;
        y = body->coord.y;
        body = body->next;
    }
    addAtEnd(snake, x, y+1);
    removeAtEnd(snake);
}

/**
 * \fn moveSnake
 * \brief Déplacer le serpent en fonction de la direction
 * \param pressedKey : la touche pressée
 * \param direction : la direction actuelle du serpent
 * \param snake : le serpent
 * \return direction : la nouvelle direction du serpent
 */
int moveSnake(int pressedKey, int direction, Snake* snake)
{
    if((pressedKey == KEY_Z && direction != KEY_S) ||
       (pressedKey == KEY_Q && direction != KEY_D) ||
       (pressedKey == KEY_S && direction != KEY_Z) ||
       (pressedKey == KEY_D && direction != KEY_Q)) direction = pressedKey;

    printSnake(snake, ' ');

    switch (direction)
    {
    case KEY_Z:
      moveUp(snake);
      printSnakeD(snake, BODY, '^');
      return direction;
    case KEY_Q:
      moveLeft(snake);
      printSnakeD(snake, BODY, '<');
      return direction;
    case KEY_S:
      moveDown(snake);
      printSnakeD(snake, BODY, 'v');
      return direction;
    case KEY_D:
      moveRight(snake);
      printSnakeD(snake, BODY, '>');
      return direction;
    default:
      return direction;
    }
}

/**
 * \fn isOutside
 * \brief Test si le serpent touche une bordure
 * \param snake : le serpent
 * \return 1 si le serpent touche une bordure
 * \return 0 si le serpent ne touche pas une bordure
 */
int isOutside(Snake* snake)
{
    Body* body = snake->first;

    int x=0;
    int y=0;

    while(body != NULL)
    {
        x = body->coord.x;
        y = body->coord.y;
        body = body->next;
    }

    if( (x < 0) || (x >= WIDTH) || (y < 0) || (y >= HEIGHT) ) return 1;
    else return 0;
}

/**
 * \fn isCut
 * \brief Test si le serpent se touche lui-même
 * \param snake : le serpent
 * \return 1 si le serpent se touche lui-même
 * \return 0 si le serpent ne se touche pas lui-même
 */
int isCut(Snake* snake)
{
    Body* body = snake->first;

    Body* head;
    int x_head;
    int y_head;

    while(body != NULL)
    {
        x_head = body->coord.x;
        y_head = body->coord.y;
        head = body;
        body = body->next;
    }

    body = snake->first;

    while(body != NULL && body != head)
    {
        if(body->coord.x == x_head && body->coord.y == y_head) return 1;
        body = body->next;
    }
    return 0;
}
