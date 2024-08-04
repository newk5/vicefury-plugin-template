#pragma once

#include "plugin.h"

class VehicleEvents
{
public:
	static void Setup(std::shared_ptr<class Registry> registry, std::shared_ptr<class Server> server)
	{
		Registry = registry;
		Server = server;
	}
	static float OnVehicleReceiveDamage(int32_t VehicleId, DamageEvent ev);
	static void OnVehicleExploded(int32_t VehicleId);
	static void OnVehicleCreated(int32_t VehicleId);
	static void OnVehicleDestroyed(int32_t VehicleId);

private:
	static std::shared_ptr<Registry> Registry;
	static std::shared_ptr<Server> Server;
};

