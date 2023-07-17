#include "player.hpp"

Player::Player(void) : _pEntity(NULL), _base_entity(NULL), _index(NULL),
_info(NULL), _zombie(NULL)
{
}

Player::Player(edict_t *pEntity) : _pEntity(pEntity), _zombie(NULL)
{
	this->_base_entity = gameents->EdictToBaseEntity(pEntity);
	this->_index = engine->IndexOfEdict(pEntity);
	this->_info = playerinfomanager->GetPlayerInfo(pEntity);
}

Player::Player(edict_t *pEntity, IBotController *bot_controller) :
_pEntity(pEntity), _bot_controller(bot_controller), _zombie(NULL)
{
	this->_base_entity = gameents->EdictToBaseEntity(pEntity);
	this->_index = engine->IndexOfEdict(pEntity);
	this->_info = playerinfomanager->GetPlayerInfo(pEntity);
}

Player::Player(edict_t *pEntity, const Zombie *zombie) : _pEntity(pEntity),
_zombie(zombie)
{
	this->_base_entity = gameents->EdictToBaseEntity(pEntity);
	this->_index = engine->IndexOfEdict(pEntity);
	this->_info = playerinfomanager->GetPlayerInfo(pEntity);
}

Player::Player(edict_t *pEntity, const Zombie *zombie,
IBotController *bot_controller) : _pEntity(pEntity),
_bot_controller(bot_controller), _zombie(zombie)
{
	this->_base_entity = gameents->EdictToBaseEntity(pEntity);
	this->_index = engine->IndexOfEdict(pEntity);
	this->_info = playerinfomanager->GetPlayerInfo(pEntity);
}

Player::Player(Player const &ref)
{
	this->_pEntity = ref._pEntity;
	this->_base_entity = ref._base_entity;
	this->_index = ref._index;
	this->_info = ref._info;
	this->_zombie = ref._zombie;
}

Player::~Player()
{
	this->_pEntity = NULL;
	this->_base_entity = NULL;
	this->_index = -1;
	this->_info = NULL;
}

edict_t			*Player::GetPEntity(void) const
{
	return (this->_pEntity);
}

int			Player::GetIndex(void) const
{
	return (this->_index);
}


IPlayerInfo		*Player::GetPlayerInfo(void) const
{
	return (this->_info);
}

void			Player::SetZombie(const Zombie *zombie)
{
	this->_zombie = zombie;
}

const Zombie		*Player::GetZombie(void) const
{
	return (this->_zombie);
}

Player			*CreatePlayer(edict_t *pEntity)
{
	unsigned int	idx;

	idx = 0;
	while (PLAYER_MAX_PLAYERS > idx && NULL != g_Players[idx])
	{
		idx += 1;
	}
	if (PLAYER_MAX_PLAYERS > idx)
	{
		g_Players[idx] = new Player(pEntity);
	}
	return (g_Players[idx]);
}

Player			*CreatePlayer(edict_t *pEntity, IBotController *bot_controller)
{
	unsigned int	idx;

	idx = 0;
	while (PLAYER_MAX_PLAYERS > idx && NULL != g_Players[idx])
	{
		idx += 1;
	}
	if (PLAYER_MAX_PLAYERS > idx)
	{
		g_Players[idx] = new Player(pEntity, bot_controller);
	}
	return (g_Players[idx]);
}

Player			*CreatePlayer(edict_t *pEntity, const Zombie *zombie)
{
	unsigned int	idx;

	idx = 0;
	while (PLAYER_MAX_PLAYERS > idx && NULL != g_Players[idx])
	{
		idx += 1;
	}
	if (PLAYER_MAX_PLAYERS > idx)
	{
		g_Players[idx] = new Player(pEntity, zombie);
	}
	return (g_Players[idx]);
}

Player			*CreatePlayer(edict_t *pEntity, const Zombie *zombie,
			IBotController *bot_controller)
{
	unsigned int	idx;

	idx = 0;
	while (PLAYER_MAX_PLAYERS > idx && NULL != g_Players[idx])
	{
		idx += 1;
	}
	if (PLAYER_MAX_PLAYERS > idx)
	{
		g_Players[idx] = new Player(pEntity, zombie, bot_controller);
	}
	return (g_Players[idx]);
}

void			DeletePlayer(Player *player)
{
	unsigned int	idx;

	idx = ~0;
	while (PLAYER_MAX_PLAYERS > ++idx && NULL != player)
	{
		if (player == g_Players[idx])
		{
			delete g_Players[idx];
			g_Players[idx] = NULL;
			player = NULL;
		}
	}
}

Player			*FindPlayer(edict_t *pEntity)
{
	unsigned int	idx;
	Player		*ret;

	idx = ~0;
	ret = NULL;
	while (PLAYER_MAX_PLAYERS > ++idx && NULL != ret)
	{
		if (pEntity == g_Players[idx]->GetPEntity())
		{
			ret = g_Players[idx];
		}
	}
	return (ret);
}