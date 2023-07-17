#include "bot.hpp"

Player			*CreateBot(void)
{
	Player		*ret;
	edict_t		*bot;
	IBotController	*bot_controller;

	ret = NULL;
	bot = botmanager->CreateBot(BOT_DEFAULT_NAME);
	if (NULL != bot)
	{
		bot_controller = botmanager->GetBotController(bot);
		ret = CreatePlayer(bot, bot_controller);
	}
	return (ret);
}

Player			*CreateBot(const Zombie *zombie)
{
	Player		*ret;
	edict_t		*bot;
	IBotController	*bot_controller;

	ret = NULL;
	bot = botmanager->CreateBot(zombie->GetName());
	if (NULL != bot)
	{
		bot_controller = botmanager->GetBotController(bot);
		ret = CreatePlayer(bot, zombie, bot_controller);
	}
	return (ret);
}