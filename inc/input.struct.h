#ifndef INPUT_STRUCT_H
#define INPUT_STRUCT_H

/* ---------------------------------------------------------------------------------------------------- */

#define MAX_MOUSE_BUTTONS 4

/* ---------------------------------------------------------------------------------------------------- */

struct Mouse
{
	int x;
	int y;

	int buttons[MAX_MOUSE_BUTTONS];
};

struct Events
{
	struct Mouse mouse;
};

/* ---------------------------------------------------------------------------------------------------- */

#endif // INPUT_STRUCT_H
