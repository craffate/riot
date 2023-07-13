#include "zombie.hpp"

Zombie::Zombie(void) : _name(NULL), _type(NORMAL),
_model(NULL), _health(100), _speed(300), _gravity(1.0F), _jump(0.0F),
_fov(90), _zvision(NULL)
{
}

Zombie::Zombie(char * const name) : _name(name), _type(NORMAL),
_model(NULL), _health(100), _speed(300), _gravity(1.0F), _jump(0.0F),
_fov(90), _zvision(NULL)
{
}

Zombie::Zombie(const Zombie &ref)
{
	this->_name = strdup(ref._name);
	this->_type = ref._type;
	this->_model = strdup(ref._model);
	this->_health = ref._health;
	this->_speed = ref._speed;
	this->_gravity = ref._gravity;
	this->_jump = ref._jump;
	this->_fov = ref._fov;
	this->_zvision = strdup(ref._zvision);
}

Zombie::~Zombie(void)
{
	free(this->_name);
	this->_name = NULL;
	free(this->_model);
	this->_model = NULL;
	free(this->_zvision);
	this->_zvision = NULL;
}

char		*Zombie::GetName(void) const
{
	return (this->_name);
}

void		Zombie::SetName(char * const name)
{
	this->_name = name;
}

t_zombie_type	Zombie::GetType(void) const
{
	return (this->_type);
}

void		Zombie::SetType(const t_zombie_type type)
{
	this->_type = type;
}

char		*Zombie::GetModel(void) const
{
	return (this->_model);
}

void		Zombie::SetModel(char * const model)
{
	this->_model = model;
}

unsigned int	Zombie::GetHealth(void) const
{
	return (this->_health);
}

void		Zombie::SetHealth(const unsigned int health)
{
	this->_health = health;
}

unsigned int	Zombie::GetSpeed(void) const
{
	return (this->_speed);
}

void		Zombie::SetSpeed(const unsigned int speed)
{
	this->_speed = speed;
}

float		Zombie::GetGravity(void) const
{
	return (this->_gravity);
}

void		Zombie::SetGravity(const float gravity)
{
	this->_gravity = gravity;
}

float		Zombie::GetJump(void) const
{
	return (this->_jump);
}

void		Zombie::SetJump(const float jump)
{
	this->_jump = jump;
}

unsigned short	Zombie::GetFov(void) const
{
	return (this->_fov);
}

void		Zombie::SetFov(const unsigned short fov)
{
	this->_fov = fov;
}

char		*Zombie::GetZvision(void) const
{
	return (this->_zvision);
}

void		Zombie::SetZvision(char * const zvision)
{
	this->_zvision = zvision;
}