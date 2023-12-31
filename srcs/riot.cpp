#include "riot.hpp"
#include "day.hpp"
#include "zombie.hpp"
#include "player.hpp"
#include "bot.hpp"

Riot			g_Riot;
Player			*g_Players[PLAYER_MAX_PLAYERS];
IVEngineServer		*engine = NULL;
IServerGameEnts		*gameents = NULL;
IServerGameDLL		*server = NULL;
IPlayerInfoManager	*playerinfomanager = NULL;
IServerGameClients	*gameclients = NULL;
IBotManager		*botmanager = NULL;
IBaseFileSystem		*basefilesystem = NULL;
ICvar			*icvar = NULL;

PLUGIN_EXPOSE(Riot, g_Riot);

SH_DECL_HOOK6(IServerGameDLL, LevelInit, SH_NOATTRIB, 0, bool, char const *, char const *, char const *, char const *, bool, bool);
SH_DECL_HOOK2_void(IServerGameClients, ClientPutInServer, SH_NOATTRIB, 0, edict_t *, char const *);
SH_DECL_HOOK1_void(IServerGameClients, ClientDisconnect, SH_NOATTRIB, 0, edict_t *);

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
		g_Zombies[idx] = curr;
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
	GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer, INTERFACEVERSION_VENGINESERVER);
	GET_V_IFACE_CURRENT(GetServerFactory, gameents, IServerGameEnts, INTERFACEVERSION_SERVERGAMEENTS);
	GET_V_IFACE_CURRENT(GetServerFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
	GET_V_IFACE_CURRENT(GetServerFactory, playerinfomanager, IPlayerInfoManager, INTERFACEVERSION_PLAYERINFOMANAGER);
	GET_V_IFACE_CURRENT(GetServerFactory, gameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
	GET_V_IFACE_CURRENT(GetServerFactory, botmanager, IBotManager, INTERFACEVERSION_PLAYERBOTMANAGER);
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
	SH_ADD_HOOK(IServerGameDLL, LevelInit, server, SH_MEMBER(this, &Riot::Hook_LevelInit), true);
	SH_ADD_HOOK(IServerGameClients, ClientPutInServer, gameclients, SH_MEMBER(this, &Riot::Hook_ClientPutInServer), true);
	SH_ADD_HOOK(IServerGameClients, ClientDisconnect, gameclients, SH_MEMBER(this, &Riot::Hook_ClientDisconnect), true);
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

void			Riot::Hook_ClientPutInServer(edict_t *pEntity,
			char const *playername)
{
	CreatePlayer(pEntity);
}

void			Riot::Hook_ClientDisconnect(edict_t *pEntity)
{
	DeletePlayer(FindPlayer(pEntity));
}

bool			Riot::Hook_LevelInit(const char *pMapName,
			char const *pMapEntities, char const *pOldLevel,
			char const *pLandmarkName, bool loadGame,
			bool background)
{
	unsigned int	idx;

	idx = ~0;
	while (BOT_MAX > ++idx)
	{
		CreateBot(g_Zombies[0]);
	}
	return true;
}