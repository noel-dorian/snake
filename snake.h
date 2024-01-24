#ifndef DEF_SNAKE
#define DEF_SNAKE

#include "define.h"

void addAtEnd(Snake *snake, int nvx, int nvy);
Coord removeAtEnd(Snake *snake);
void addAtBeginning(Snake *snake, int nvx, int nvy);

#endif // DEF_SNAKE
