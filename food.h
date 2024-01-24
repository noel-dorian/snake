#ifndef DEF_FOOD
#define DEF_FOOD

#include "define.h"
#include "snake.h"

Coord popFood(Snake* snake);
int isEaten(Snake* snake, Coord food);
void levelUp(Snake* snake, int direction);

#endif // DEF_FOOD

