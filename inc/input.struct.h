#ifndef INPUT_STRUCT_H
#define INPUT_STRUCT_H

/* ---------------------------------------------------------------------------------------------------- */

#define MAX_MOUSE_BUTTONS 4
// #define MAX_KEYBOARD_KEYS 232

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
