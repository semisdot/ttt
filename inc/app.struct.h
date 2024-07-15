#ifndef APP_STRUCT_H
#define APP_STRUCT_H

/* ---------------------------------------------------------------------------------------------------- */

#include "sdl.struct.h"
#include "input.struct.h"
#include "game.struct.h"

/* ---------------------------------------------------------------------------------------------------- */

struct application;

struct delegation
{
	void (*logic)(struct application *app);
	// void (*draw)(struct application *app);
};

struct application
{
	struct delegation	stage;
	struct SDL			sdl;
	struct Events		events;
	struct Game			game;
};

/* ---------------------------------------------------------------------------------------------------- */

#endif // APP_STRUCT_H
