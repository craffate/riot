#ifndef CVAR_HPP
# define CVAR_HPP

# include "ISmmPlugin.h"
# include "icvar.h"

# define CVAR_BOT_QUOTA_VALUE 16
# define CVAR_MP_LIMITTEAMS_VALUE 0
# define CVAR_MP_AUTOTEAMBALANCE_VALUE 0
# define CVAR_BOT_JOIN_TEAM_VALUE "T"
# define CVAR_BOT_KNIVES_ONLY_VALUE 1
# define CVAR_BOT_JOIN_AFTER_PLAYER_VALUE 0

bool		SetCvar(const char *var_name, const char *value);
bool		SetCvar(const char *var_name, const float value);
bool		SetCvar(const char *var_name, const int value);

extern ICvar	*icvar;

#endif