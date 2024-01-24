#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#include "food.h"
#include "print.h"

/**
 * \fn popFood
 * \brief Déterminer les coordonnées de la nouvelle nourriture et l'afficher
 * \return coord : les coordonnées de la nouvelle nourriture
 */
Coord popFood(Snake* snake)
{
    srand(time(0));
    Coord coord;

    coord.x = rand()%WIDTH;
    coord.y = rand()%HEIGHT;

    Body* body = snake->first;

    while(body != NULL)
    {
        if(body->coord.x == coord.x && body->coord.y == coord.y)
        {
            coord.x = rand()%WIDTH;
            coord.y = rand()%HEIGHT;
            body = snake->first;
        }
        body = body->next;
    }



   GotoXY(X0+coord.x,Y0+coord.y);
   printf(FOOD);
   return coord;
}

/**
 * \fn isEaten
 * \brief Test si le serpent se situe sur la nourriture
 * \param snake : le serpent
 * \param food : les coordonnées de la nourriture
 * \return 1 si le serpent a mangé la nourriture
 * \return 0 si le serpent n'a pas mangé la nourriture
 */
int isEaten(Snake* snake, Coord food)
{
    Body* head = snake->first;

    int x=0;
    int y=0;

    while(head != NULL)
    {
        x = head->coord.x;
        y = head->coord.y;
        head = head->next;
    }

    if(x == food.x && y == food.y) return 1;
    else return 0;
}

/**
 * \fn levelUp
 * \brief Agrandir de 1 le serpent
 * \param snake : le serpent
 * \param direction : la direction actuelle du serpent
 */
void levelUp(Snake* snake, int direction)
{
    switch (direction)
    {
    case KEY_Z:
      addAtBeginning(snake, snake->first->coord.x, snake->first->coord.y-1);
      break;
    case KEY_Q:
      addAtBeginning(snake, snake->first->coord.x+1, snake->first->coord.y);
      break;
    case KEY_S:
      addAtBeginning(snake, snake->first->coord.x, snake->first->coord.y+1);
      break;
    case KEY_D:
      addAtBeginning(snake, snake->first->coord.x-1, snake->first->coord.y);
      break;
    default:
      break;
    }
}

