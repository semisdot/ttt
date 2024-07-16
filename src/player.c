#include <stddef.h> // NULL

#include "player.h"

/* ---------------------------------------------------------------------------------------------------- */

enum
{
	NEXT_PLAYER =  1,
	PREV_PLAYER = -1
};

/* ---------------------------------------------------------------------------------------------------- */

static struct Player *next_player(struct Player *players, struct Player *curr_player, int next_i);

/* ---------------------------------------------------------------------------------------------------- */

void init_starting_player(struct Game *game)
{
	game->starting_player	= &game->players[0];
	game->active_player		= game->starting_player;
}

void next_starting_player(struct Game *game)
{
	game->starting_player	= next_player(&game->players[0], game->starting_player, NEXT_PLAYER);
	game->active_player		= game->starting_player;
}

void next_active_player(struct Game *game)
{
	game->active_player = next_player(&game->players[0], game->active_player, NEXT_PLAYER);
}

/* ---------------------------------------------------------------------------------------------------- */

static struct Player *next_player(struct Player *players, struct Player *curr_player, int next_i)
{
	struct Player *next_player;
	int curr_player_i;
	int next_player_i;

	curr_player_i = curr_player - &players[0];

#if 0
	if (curr_player_i < 0 || curr_player_i >= MAX_PLAYERS)
	{
		next_player = NULL;

		goto end;
	}
#endif

	next_player_i = (MAX_PLAYERS + (curr_player_i + next_i)) % MAX_PLAYERS;

	next_player = &players[next_player_i];

// end:
	return next_player;
}
