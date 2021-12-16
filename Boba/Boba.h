#pragma once
#include "BobaApp.h"
#include "BobaUtils.h"
#include "BobaWindow.h"
#include "BobaSprite.h"
#include "BobaShader.h"
#include "BobaRenderer.h"
#include "BobaEvents.h"
#include "BobaKeyCodes.h"

#define START_BOBA_GAME(classname)\
int main()\
{\
classname _boba_game; \
_boba_game.Run();\
}