#ifndef DEF_MOVE
#define DEF_MOVE

#include "snake.h"

int getPressedKey();
void moveRight(Snake* snake);
void moveLeft(Snake* snake);
void moveUp(Snake* snake);
void moveDown(Snake* snake);
int moveSnake(int pressedKey, int direction, Snake* snake);
int isOutside(Snake* snake);
int isCut(Snake* snake);

#endif // DEF_MOVE


