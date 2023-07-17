#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <eiface.h>
# include <edict.h>
# include <iplayerinfo.h>
# include "zombie.hpp"

class Player
{
	private:
		edict_t		*_pEntity;
		CBaseEntity	*_base_entity;
		int		_index;
		IPlayerInfo	*_info;
		const Zombie	*_zombie;
	public:
		Player(void);
		Player(edict_t *pEntity);
		Player(edict_t *pEntity, const Zombie *zombie);
		Player(Player const &ref);
		~Player();

		Player		&operator=(Player const &ref);
		edict_t		*GetPEntity(void) const;
		int		GetIndex(void) const;
		IPlayerInfo	*GetPlayerInfo(void) const;
		void		SetZombie(const Zombie *zombie);
		const Zombie	*GetZombie(void) const;
};

extern IVEngineServer		*engine;
extern IServerGameEnts		*gameents;
extern IPlayerInfoManager	*playerinfomanager;

#endif