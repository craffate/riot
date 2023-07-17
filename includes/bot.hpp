#ifndef BOT_HPP
# define BOT_HPP

# define BOT_MAX 16
# define BOT_DEFAULT_NAME "Zombie"

# include "player.hpp"
# include <iplayerinfo.h>

extern Player			*g_Players[PLAYER_MAX_PLAYERS];
extern IBotManager		*botmanager;

Player				*CreateBot(void);
Player				*CreateBot(const Zombie *zombie);

#endif