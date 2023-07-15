#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <eiface.h>
# include <edict.h>
# include <iplayerinfo.h>

class Player
{
	private:
		edict_t		*_pEntity;
		int		_index;
		IPlayerInfo	*_info;
	public:
		Player(void);
		Player(edict_t *pEntity);
		Player(Player const &ref);
		~Player();

		Player		&operator=(Player const &ref);
		edict_t		*GetPEntity(void) const;
		int		GetIndex(void) const;
		IPlayerInfo	*GetPlayerInfo(void) const;
};

extern IVEngineServer		*engine;
extern IServerGameEnts		*gameents;
extern IPlayerInfoManager	*playerinfomanager;

#endif