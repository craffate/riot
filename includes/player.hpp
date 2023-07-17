#ifndef PLAYER_HPP
# define PLAYER_HPP

# define PLAYER_MAX_PLAYERS 65

# include "zombie.hpp"
# include <eiface.h>
# include <edict.h>
# include <iplayerinfo.h>

class Player
{
	private:
		edict_t		*_pEntity;
		CBaseEntity	*_base_entity;
		int		_index;
		IPlayerInfo	*_info;
		const Zombie	*_zombie;
		IBotController	*_bot_controller;
	public:
		Player(void);
		Player(edict_t *pEntity);
		Player(edict_t *pEntity, IBotController *bot_controller);
		Player(edict_t *pEntity, const Zombie *zombie);
		Player(edict_t *pEntity, const Zombie *zombie,
		IBotController *bot_controller);
		Player(Player const &ref);
		~Player();

		Player		&operator=(const Player &ref);
		edict_t		*GetPEntity(void) const;
		int		GetIndex(void) const;
		IPlayerInfo	*GetPlayerInfo(void) const;
		void		SetZombie(const Zombie *zombie);
		const Zombie	*GetZombie(void) const;
};

extern Player			*g_Players[PLAYER_MAX_PLAYERS];
extern IVEngineServer		*engine;
extern IServerGameEnts		*gameents;
extern IPlayerInfoManager	*playerinfomanager;

Player				*CreatePlayer(edict_t *pEntity);
Player				*CreatePlayer(edict_t *pEntity,
				IBotController *bot_controller);
Player				*CreatePlayer(edict_t *pEntity,
				const Zombie *zombie);
Player				*CreatePlayer(edict_t *pEntity,
				const Zombie *zombie,
				IBotController *bot_controller);
void				DeletePlayer(Player *player);
Player				*FindPlayer(edict_t *pEntity);

#endif