#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "edict.h"
# include "iplayerinfo.h"

class Player
{
	private:
		edict_t		*_edict;
		IPlayerInfo	*_info;
	public:
		Player(void);
		Player(edict_t *edict);
		Player(Player const &ref);
		~Player();

		Player		&operator=(Player const &ref);
		edict_t		*GetEdict(void) const;
		void		SetEdict(edict_t *edict);
		IPlayerInfo	*GetPlayerInfo(void) const;
};

extern IPlayerInfoManager	*playerinfomanager;

#endif