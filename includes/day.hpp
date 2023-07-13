#ifndef DAY_HPP
# define DAY_HPP

# define DAY_MAX 128

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

class Day
{
	private:
		char		*_display;
		unsigned short	_count;
		int		_healthboost;
		unsigned short	_respawn;
		unsigned short	_deaths_before_zombie;
		float		_fade_min;
		float		_fade_max;
		char		*_zombie_override;
		char		*_storyline;

	public:
		Day(void);
		Day(char * const display);
		Day(Day const &ref);
		~Day(void);

		Day		&operator=(Day const &ref);
		char		*GetDisplay(void) const;
		void		SetDisplay(char * const display);
		unsigned short	GetCount(void) const;
		void		SetCount(const unsigned short count);
		int		GetHealthboost(void) const;
		void		SetHealthboost(const int healthboost);
		unsigned short	GetRespawn(void) const;
		void		SetRespawn(const unsigned short respawn);
		unsigned short	GetDeathsBeforeZombie(void) const;
		void		SetDeathsBeforeZombie(const unsigned short death_before_zombie);
		float		GetFadeMin(void) const;
		void		SetFadeMin(const float fade_min);
		float		GetFadeMax(void) const;
		void		SetFadeMax(const float fade_max);
		char		*GetZombieOverride(void) const;
		void		SetZombieOverride(char * const zombie_override);
		char		*GetStoryline(void) const;
		void		SetStoryline(char * const storyline);
};

static Day			*g_Days[DAY_MAX];

#endif