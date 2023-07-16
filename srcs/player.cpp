#include "player.hpp"

Player::Player(void) : _pEntity(NULL), _base_entity(NULL), _index(NULL),
_info(NULL)
{
}

Player::Player(edict_t *pEntity) : _pEntity(pEntity)
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
}

Player::~Player()
{
	this->_pEntity = NULL;
	this->_base_entity = NULL;
	this->_index = -1;
	this->_info = NULL;
}

edict_t		*Player::GetPEntity(void) const
{
	return (this->_pEntity);
}

int		Player::GetIndex(void) const
{
	return (this->_index);
}


IPlayerInfo	*Player::GetPlayerInfo(void) const
{
	return (this->_info);
}