#ifndef RIOT_HPP
# define RIOT_HPP

# define RIOT_AUTHOR "exha"
# define RIOT_NAME "Riot"
# define RIOT_DESCRIPTION "Riot gamemode."
# define RIOT_URL ""
# define RIOT_LICENSE "UNLICENSED"
# define RIOT_VERSION "0.0.0"
# define RIOT_TAG "RIOT"

# include <ISmmPlugin.h>
# include <stdio.h>

# if defined WIN32 && !defined snprintf
#  define snprintf _snprintf
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