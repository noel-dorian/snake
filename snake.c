#include <stdlib.h>
#include <stdio.h>

#include "snake.h"

/**
 * \fn addAtEnd
 * \brief Ajouter un élément à la fin du serpent
 * \param *snake : le pointeur sur le serpent du jeu
 * \param nvx : la coordonnée en x du nouvel élément
 * \param nvy : la coordonnée en y du nouvel élément
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
        /* On se positionne à la fin de la file */
        Body *thisBody = snake->first;
        while (thisBody->next != NULL)
        {
            thisBody = thisBody->next;
        }
        thisBody->next = newBody;
    }
    else /* La file est vide, notre élément est le premier */
    {
        snake->first = newBody;
    }
}

/**
 * \fn removeAtEnd
 * \brief Supprimer un élément à la fin du serpent
 * \param *snake : le pointeur sur le serpent du jeu
 * \return Renvoie les coordonnées de l'élément supprimé
 */
Coord removeAtEnd(Snake *snake)
{
    if (snake == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Coord coord;
    /* On vérifie s'il y a quelque chose à défiler */
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
 * \brief Ajoute un élément au début du serpent
 * \param *snake : le pointeur sur le serpent du jeu
 * \param nvx : la coordonnée en x du nouvel élément
 * \param nvy : la coordonnée en y du nouvel élément
 */
void addAtBeginning(Snake *snake, int nvx, int nvy)
{
    /* Création du nouvel élément */
    Body *newBody = malloc(sizeof(*newBody));
    if (snake == NULL || newBody == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newBody->coord.x = nvx;
    newBody->coord.y = nvy;

    /* Insertion de l'élément au début de la liste */
    newBody->next = snake->first;
    snake->first = newBody;
}


