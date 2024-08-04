#pragma once

#include "plugin.h"

class ZoneEvents
{
public:
	static void Setup(std::shared_ptr<class Registry> registry, std::shared_ptr<class Server> server)
	{
		Registry = registry;
		Server = server;
	}
	static void OnZoneCreated(int32_t ZoneId, ZoneType type);
	static void OnZoneDestroyed(int32_t ZoneId);
	static void OnZoneEnter(int32_t ZoneId, GameEntity GameEntityType, int32_t GameEntityID);
	static void OnZoneLeave(int32_t ZoneId, GameEntity GameEntityType, int32_t GameEntityID);

private:
	static std::shared_ptr<Registry> Registry;
	static std::shared_ptr<Server> Server;
};

