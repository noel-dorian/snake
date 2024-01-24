#include <stdlib.h>
#include <stdio.h>

#include "config.h"

/**
 * \fn init
 * \brief Initialise le serpent de la partie
 * \return Renvoie un pointeur sur le serpent du jeu
 */
Snake* init()
{
    Snake *snake = malloc(sizeof(Snake*));
    Body *first = malloc(sizeof(Body*));
    snake->first = first;
    snake->first->coord.x = 4;
    snake->first->coord.y = 8;
    snake->first->next = NULL;

    addAtEnd(snake, 5, 8);
    addAtEnd(snake, 6, 8);
    addAtEnd(snake, 7, 8);
    addAtEnd(snake, 8, 8);

    return snake;
}

/**
 * \fn stop
 * \brief Libère la mémoire
 * \param snake : le serpent
 */
void stop(Snake* snake)
{
    while(snake->first != NULL)
    {
        removeAtEnd(snake);
    }
    free(snake);
}
