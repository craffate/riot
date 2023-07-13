#include "day.hpp"

Day::Day(void) : _display(NULL), _count(25), _healthboost(0),
_respawn(0), _deaths_before_zombie(2), _fade_min(0.0F), _fade_max(0.0F),
_zombie_override(NULL), _storyline(NULL)
{
}

Day::Day(char * const display) : _display(display), _count(25), _healthboost(0),
_respawn(0), _deaths_before_zombie(2), _fade_min(0.0F), _fade_max(0.0F),
_zombie_override(NULL), _storyline(NULL)
{
}

Day::Day(Day const &ref)
{
	this->_display = strdup(ref._display);
	this->_count = ref._count;
	this->_healthboost = ref._healthboost;
	this->_respawn = ref._respawn;
	this->_deaths_before_zombie = ref._deaths_before_zombie;
	this->_fade_min = ref._fade_min;
	this->_fade_max = ref._fade_max;
	this->_zombie_override = strdup(ref._zombie_override);
	this->_storyline = strdup(ref._storyline);
}

Day::~Day(void)
{
	free(this->_display);
	this->_display = NULL;
	free(this->_zombie_override);
	this->_zombie_override = NULL;
	free(this->_storyline);
	this->_storyline = NULL;
}

char		*Day::GetDisplay(void) const
{
	return (this->_display);
}

void		Day::SetDisplay(char * const display)
{
	this->_display = display;
}

unsigned short	Day::GetCount(void) const
{
	return (this->_count);
}

void		Day::SetCount(const unsigned short count)
{
	this->_count = count;
}

int		Day::GetHealthboost(void) const
{
	return (this->_healthboost);
}

void		Day::SetHealthboost(const int healthboost)
{
	this->_healthboost = healthboost;
}

unsigned short	Day::GetRespawn(void) const
{
	return (this->_respawn);
}

void		Day::SetRespawn(const unsigned short respawn)
{
	this->_respawn = respawn;
}

unsigned short	Day::GetDeathsBeforeZombie(void) const
{
	return (this->_deaths_before_zombie);
}

void		Day::SetDeathsBeforeZombie(const unsigned short death_before_zombie)
{
	this->_deaths_before_zombie = death_before_zombie;
}

float		Day::GetFadeMin(void) const
{
	return (this->_fade_min);
}

void		Day::SetFadeMin(const float fade_min)
{
	this->_fade_min = fade_min;
}

float		Day::GetFadeMax(void) const
{
	return (this->_fade_max);
}

void		Day::SetFadeMax(const float fade_max)
{
	this->_fade_max = fade_max;
}


char		*Day::GetZombieOverride(void) const
{
	return (this->_zombie_override);
}

void		Day::SetZombieOverride(char * const zombie_override)
{
	this->_zombie_override = zombie_override;
}


char		*Day::GetStoryline(void) const
{
	return (this->_storyline);
}

void		Day::SetStoryline(char * const storyline)
{
	this->_storyline = storyline;
}