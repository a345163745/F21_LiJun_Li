#pragma once
#include "BobaApp.h"
#include "BobaUtils.h"

#define START_BOBA_GAME(classname)\
int main()\
{\
classname _boba_game; \
_boba_game.Run();\
}