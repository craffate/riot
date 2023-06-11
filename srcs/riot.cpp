#include "riot.hpp"

SH_DECL_HOOK3_void(IServerGameDLL, ServerActivate, SH_NOATTRIB, 0, edict_t *, int, int);

Riot			g_Riot;
IServerGameDLL	*server = NULL;

PLUGIN_EXPOSE(Riot, g_Riot);

bool			Riot::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	PLUGIN_SAVEVARS();

	return (true);
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