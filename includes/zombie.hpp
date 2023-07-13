#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define ZOMBIE_MAX 32

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef enum			e_zombie_type
{
	NORMAL,
	OVERRIDE_REQUIRED
}				t_zombie_type;

class Zombie
{
	private:
		char		*_name;
		t_zombie_type	_type;
		char		*_model;
		unsigned int	_health;
		unsigned int	_speed;
		float		_gravity;
		float		_jump;
		unsigned short	_fov;
		char		*_zvision;

	public:
		Zombie(void);
		Zombie(char * const name);
		Zombie(const Zombie &ref);
		~Zombie(void);

		Zombie		&operator=(const Zombie &ref);
		char		*GetName(void) const;
		void		SetName(char * const name);
		t_zombie_type	GetType(void) const;
		void		SetType(const t_zombie_type type);
		char		*GetModel(void) const;
		void		SetModel(char * const model);
		unsigned int	GetHealth(void) const;
		void		SetHealth(const unsigned int health);
		unsigned int	GetSpeed(void) const;
		void		SetSpeed(const unsigned int speed);
		float		GetGravity(void) const;
		void		SetGravity(float const gravity);
		float		GetJump(void) const;
		void		SetJump(const float jump);
		unsigned short	GetFov(void) const;
		void		SetFov(const unsigned short fov);
		char		*GetZvision(void) const;
		void		SetZvision(char * const zvision);
};

static Zombie			*g_Zombies[ZOMBIE_MAX];

#endif