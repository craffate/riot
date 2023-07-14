#include "cvar.hpp"

bool			SetCvar(const char *var_name, const char *value)
{
	bool		ret;
	ConVar		*cvar;

	ret = false;
	if (NULL != icvar)
	{
		cvar = icvar->FindVar(var_name);
	}
	if (NULL != cvar)
	{
		cvar->SetValue(value);
		ret = true;
	}
	return (ret);
}

bool			SetCvar(const char *var_name, const float value)
{
	bool		ret;
	ConVar		*cvar;

	ret = false;
	if (NULL != icvar)
	{
		cvar = icvar->FindVar(var_name);
	}
	if (NULL != cvar)
	{
		cvar->SetValue(value);
		ret = true;
	}
	return (ret);
}

bool			SetCvar(const char *var_name, const int value)
{
	bool		ret;
	ConVar		*cvar;

	ret = false;
	if (NULL != icvar)
	{
		cvar = icvar->FindVar(var_name);
	}
	if (NULL != cvar)
	{
		cvar->SetValue(value);
		ret = true;
	}
	return (ret);
}