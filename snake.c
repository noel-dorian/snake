#include <stdlib.h>
#include <stdio.h>

#include "snake.h"

/**
 * \fn addAtEnd
 * \brief Ajouter un �l�ment � la fin du serpent
 * \param *snake : le pointeur sur le serpent du jeu
 * \param nvx : la coordonn�e en x du nouvel �l�ment
 * \param nvy : la coordonn�e en y du nouvel �l�ment
 */
void addAtEnd(Snake *snake, int nvx, int nvy)
{
    Body *newBody = malloc(sizeof(*newBody));
    if (snake == NULL || newBody == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newBody->coord.x = nvx;
    newBody->coord.y = nvy;
    newBody->next = NULL;

    if (snake->first != NULL) /* La file n'est pas vide */
    {
        /* On se positionne � la fin de la file */
        Body *thisBody = snake->first;
        while (thisBody->next != NULL)
        {
            thisBody = thisBody->next;
        }
        thisBody->next = newBody;
    }
    else /* La file est vide, notre �l�ment est le premier */
    {
        snake->first = newBody;
    }
}

/**
 * \fn removeAtEnd
 * \brief Supprimer un �l�ment � la fin du serpent
 * \param *snake : le pointeur sur le serpent du jeu
 * \return Renvoie les coordonn�es de l'�l�ment supprim�
 */
Coord removeAtEnd(Snake *snake)
{
    if (snake == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Coord coord;
    /* On v�rifie s'il y a quelque chose � d�filer */
    if (snake->first != NULL)
    {

        Body *bodyRemoved = snake->first;

        coord.x = bodyRemoved->coord.x;
        coord.y = bodyRemoved->coord.y;

        snake->first = bodyRemoved->next;

        free(bodyRemoved);
    }

    return coord;
}

/**
 * \fn addAtBeginning
 * \brief Ajoute un �l�ment au d�but du serpent
 * \param *snake : le pointeur sur le serpent du jeu
 * \param nvx : la coordonn�e en x du nouvel �l�ment
 * \param nvy : la coordonn�e en y du nouvel �l�ment
 */
void addAtBeginning(Snake *snake, int nvx, int nvy)
{
    /* Cr�ation du nouvel �l�ment */
    Body *newBody = malloc(sizeof(*newBody));
    if (snake == NULL || newBody == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newBody->coord.x = nvx;
    newBody->coord.y = nvy;

    /* Insertion de l'�l�ment au d�but de la liste */
    newBody->next = snake->first;
    snake->first = newBody;
}


