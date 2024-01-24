#ifndef DEF_PRINT
#define DEF_PRINT

#include "snake.h"

void printBorder();
void GotoXY(int x, int y);
void printSnake(Snake* snake, char c);
void printBodySnake(Body* body, char c);
void printSnakeD(Snake* snake, char c, char c_head);
void removeCursor();
void printEndMenu(int score);

#endif // DEF_PRINT

