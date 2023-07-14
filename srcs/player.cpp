#include "player.hpp"

Player::Player(void) : _edict(NULL), _info(NULL)
{
}

Player::Player(edict_t *edict) : _edict(edict)
{
	this->_info = playerinfomanager->GetPlayerInfo(edict);
}

Player::Player(Player const &ref)
{
	this->_edict = ref._edict;
	this->_info = ref._info;
}

Player::~Player()
{
	this->_edict = NULL;
	this->_info = NULL;
}

edict_t		*Player::GetEdict(void) const
{
	return (this->_edict);
}

void		Player::SetEdict(edict_t *edict)
{
	this->_edict = edict;
	this->_info = playerinfomanager->GetPlayerInfo(edict);
}

IPlayerInfo	*Player::GetPlayerInfo(void) const
{
	return (this->_info);
}