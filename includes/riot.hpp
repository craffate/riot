#ifndef RIOT_HPP
# define RIOT_HPP

# define RIOT_AUTHOR "exha"
# define RIOT_NAME "Riot"
# define RIOT_DESCRIPTION "Riot gamemode."
# define RIOT_URL ""
# define RIOT_LICENSE "UNLICENSED"
# define RIOT_VERSION "0.0.0"
# define RIOT_TAG "RIOT"
# define RIOT_PATH "addons/riot"
# define RIOT_CONFIG_PATH RIOT_PATH ## "/configs"

# include <ISmmPlugin.h>
# include <stdio.h>
# include <filesystem.h>
# include "KeyValues.h"

# ifdef WIN32
#   include <windows.h>
#   ifndef snprintf
#     define snprintf _snprintf
#   endif
#   define strdup _strdup
# endif

# ifdef SOURCE_ENGINE
#   include "KeyValues.h"
# endif

class Riot : public ISmmPlugin
{
	public:
		bool		Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late);
		void		AllPluginsLoaded();
		bool		Unload(char *error, size_t maxlen);
		bool		Pause(char *error, size_t maxlen);
		bool		Unpause(char *error, size_t maxlen);
		const char	*GetAuthor();
		const char	*GetName();
		const char	*GetDescription();
		const char	*GetURL();
		const char	*GetLicense();
		const char	*GetVersion();
		const char	*GetDate();
		const char	*GetLogTag();
};

extern Riot			g_Riot;

PLUGIN_GLOBALVARS();

#endif