#include "riot.hpp"
#include "day.hpp"
#include "zombie.hpp"
#include "cvar.hpp"

Riot			g_Riot;
IServerGameDLL		*server = NULL;
IBaseFileSystem		*basefilesystem = NULL;
ICvar			*icvar = NULL;

PLUGIN_EXPOSE(Riot, g_Riot);

static void		LoadDays(KeyValues * const root)
{
	KeyValues	*days;
	Day		*curr;
	unsigned int	idx;

	days = NULL;
	curr = NULL;
	idx = ~0;
	days = root->GetFirstTrueSubKey();
	while (++idx < DAY_MAX && NULL != days)
	{
		curr = g_Days[idx];
		curr = new Day((char * const)days->GetName());
		curr->SetCount((unsigned short)days->GetInt("count"));
		curr->SetHealthboost(days->GetInt("healthboost"));
		curr->SetRespawn((unsigned short)days->GetInt("respawn"));
		curr->SetDeathsBeforeZombie((unsigned short)days->GetInt("deaths_before_zombie"));
		curr->SetFadeMin(days->GetFloat("fademin"));
		curr->SetFadeMax(days->GetFloat("fademax"));
		curr->SetZombieOverride((char * const)days->GetString("zombieoverride", NULL));
		days = days->GetNextTrueSubKey();
	}
	days = NULL;
}

static void		LoadZombies(KeyValues * const root)
{
	KeyValues	*zombies;
	Zombie		*curr;
	unsigned int	idx;

	zombies = NULL;
	curr = NULL;
	idx = ~0;
	zombies = root->GetFirstTrueSubKey();
	while (++idx < ZOMBIE_MAX && NULL != zombies)
	{
		curr = g_Zombies[idx];
		curr = new Zombie((char * const)zombies->GetName());
		curr->SetType((const t_zombie_type)zombies->GetInt("type"));
		curr->SetModel((char * const)zombies->GetString("model"));
		curr->SetHealth((unsigned int)zombies->GetInt("health"));
		curr->SetSpeed(zombies->GetInt("speed"));
		curr->SetGravity(zombies->GetFloat("gravity"));
		curr->SetJump(zombies->GetFloat("jump"));
		curr->SetFov((unsigned short)zombies->GetInt("fov"));
		curr->SetZvision((char * const)zombies->GetString("zvision"));
		zombies = zombies->GetNextTrueSubKey();
	}
	zombies = NULL;
}

bool			Riot::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	bool		ret;
	char		days_path[MAX_PATH + 1];
	char		zombies_path[MAX_PATH + 1];
	KeyValues	*days_root;
	KeyValues	*zombies_root;

	ret = true;
	days_root = new KeyValues("Days");
	zombies_root = new KeyValues("Zombies");
	PLUGIN_SAVEVARS();
	GET_V_IFACE_CURRENT(GetServerFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
	GET_V_IFACE_CURRENT(GetFileSystemFactory, basefilesystem, IBaseFileSystem, BASEFILESYSTEM_INTERFACE_VERSION);
	GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
	ismm->PathFormat(days_path, (MAX_PATH + 1), "%s/%s/%s", ismm->GetBaseDir(), RIOT_CONFIG_PATH, "days.cfg");
	ismm->PathFormat(zombies_path, (MAX_PATH + 1), "%s/%s/%s", ismm->GetBaseDir(), RIOT_CONFIG_PATH, "zombies.cfg");

	if (!days_root->LoadFromFile(basefilesystem, days_path))
	{
		days_root->deleteThis();
		META_LOG(g_PLAPI, "Could not load days configuration file \"%s\".", days_path);
		ret = false;
	}
	if (!zombies_root->LoadFromFile(basefilesystem, zombies_path))
	{
		zombies_root->deleteThis();
		META_LOG(g_PLAPI, "Could not load zombies configuration file \"%s\".", zombies_path);
		ret = false;
	}
	if (true == ret)
	{
		LoadDays((KeyValues * const)days_root);
		days_root->deleteThis();
		LoadZombies((KeyValues * const)zombies_root);
		zombies_root->deleteThis();
	}
	return (ret);
}

void			Riot::AllPluginsLoaded()
{
}

bool			Riot::Unload(char *error, size_t maxlen)
{
	return (true);
}

bool			Riot::Pause(char *error, size_t maxlen)
{
	return (true);
}

bool			Riot::Unpause(char *error, size_t maxlen)
{
	return (true);
}

const char		*Riot::GetAuthor()
{
	return (RIOT_AUTHOR);
}

const char		*Riot::GetName()
{
	return (RIOT_NAME);
}

const char		*Riot::GetDescription()
{
	return (RIOT_DESCRIPTION);
}

const char		*Riot::GetURL()
{
	return (RIOT_URL);
}

const char		*Riot::GetLicense()
{
	return (RIOT_LICENSE);
}

const char		*Riot::GetVersion()
{
	return (RIOT_VERSION);
}

const char		*Riot::GetDate()
{
	return (__DATE__);
}

const char		*Riot::GetLogTag()
{
	return (RIOT_TAG);
}