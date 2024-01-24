#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "snake.h"
#include "move.h"
#include "define.h"
#include "food.h"
#include "print.h"
#include "config.h"

int main()
{
    // Initialisation du serpent
    Snake* snake = init();

    // Affichage de l'aire de jeu et de la nourriture
    printBorder();
    Coord food = popFood(snake);

    // Suppression du curseur
    removeCursor();

    int direction = KEY_D; // Direction de d�part : vers la droite
    int pressedKey = 0; // Touche press�e
    int gameBreak = 0; // Pause du jeu
    int loose = 0; // Fin de la partie
    int score = 0; // Score de la partie


    // BOUCLE PRINCIPALE
    while(!loose)
    {
        Sleep(TIME_INTERVAL); // Rafraichissement de la page toutes les TIME_INTERVAL ms

        // R�cup�ration de la touche press�e
        pressedKey = getPressedKey();

        if(pressedKey == KEY_P) gameBreak = 1; // Mettre le jeu en pause
        if(pressedKey == KEY_R) gameBreak = 0; // Relancer le jeu apr�s une pause

        // BOUCLE SECONDAIRE : Quand le jeu n'est pas en pause
        if(!gameBreak)
        {
            // Faire bouger le serpent en fonction de la touche press�e
            direction = moveSnake(pressedKey, direction, snake);

            if(isOutside(snake)) loose = 1; // Partie termin�e si le serpent touche la bordure
            if(isCut(snake)) loose=1; // Partie termin�e si le serpent se touche lui-m�me

            // Lorsque le serpent mange la nourriture
            if(isEaten(snake, food))
            {
                score++; // +1 au score
                food = popFood(snake); // g�n�ration d'une nouvelle nourriture
                levelUp(snake, direction); // le serpent s'agrandit
            }
        } // FIN BOUCLE SECONDAIRE
    } // FIN BOUCLE PRINCIPALE

    printEndMenu(score); // Affiche du menu de fin
    stop(snake); // Lib�ration de la m�moire
}
