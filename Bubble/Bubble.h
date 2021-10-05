#pragma once
#include "BubbleApp.h"
#include "BubbleUtils.h"

#define START_BUBBLE_GAME(classname)\
int main()\
{\
classname _bubble_game; \
_bubble_game.Run();\
}