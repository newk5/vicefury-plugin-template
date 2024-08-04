#pragma once

#include "plugin.h"

class ObjectEvents
{
public:
	static void Setup(std::shared_ptr<class Registry> registry, std::shared_ptr<class Server> server)
	{
		Registry = registry;
		Server = server;
	}
	static void OnObjectCreated(int32_t id);
	static void OnObjectDestroyed(int32_t id);
	static float OnObjectReceiveDamage(int32_t ObjectId, DamageEvent Event);
	static void OnObjectTouched(int32_t ObjectId, GameEntity GameEntityType, int32_t GameEntityID);
	static void OnObjectBroken(int32_t ObjectId);
	static void OnObjectOverlapped(int32_t ObjectId, GameEntity GameEntityType, int32_t GameEntityID);
	static void OnObjectStoppedOverlapping(int32_t ObjectId, GameEntity GameEntityType, int32_t GameEntityID);
private:
	static std::shared_ptr<Registry> Registry;
	static std::shared_ptr<Server> Server;
};

