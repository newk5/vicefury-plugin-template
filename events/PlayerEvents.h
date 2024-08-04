#pragma once

#include "plugin.h"

class PlayerEvents
{
public:
	static void Setup(std::shared_ptr<class Registry> registry, std::shared_ptr<class Server> server)
	{
		Registry = registry;
		Server = server;
	}
	static void OnPlayerJoin(int32_t id);
	static uint8_t OnPlayerMessage(int32_t PlayerID, const char* Message);
	static float OnPlayerReceiveDamage(int32_t PlayerId, DamageEvent ev);
	static void OnPlayerLeave(int32_t id);
	static void OnPlayerCommand(int32_t PlayerID, const char* Message);
	static void OnPlayerEnterVehicle(int32_t PlayerID, int32_t VehicleId, uint8_t AsDriver);
	static void OnPlayerLeaveVehicle(int32_t PlayerID, int32_t VehicleId, uint8_t AsDriver);
	static uint8_t OnPlayerRequestSpawn(int32_t PlayerId);
	static void OnPlayerSpawnScreenSkinChange(int32_t PlayerId, int32_t SkinId);
	static void OnPlayerSpawn(int32_t PlayerId);
	static void OnPlayerDied(int32_t PlayerID, DamageEvent DmgEvent);
	static void OnPlayerWeaponReceived(int32_t PlayerId, int32_t WeaponId, uint8_t Equipped);
	static void OnPlayerWeaponRemoved(int32_t PlayerId, int32_t WeaponId, uint8_t Equipped);
	static void OnPlayerStartedSwimming(int32_t PlayerId);
	static void OnPlayerStoppedSwimming(int32_t PlayerId);
	static void OnPlayerDivedUnderwater(int32_t PlayerId);
	static void OnPlayerReachedWaterSurface(int32_t PlayerId);
	static void OnPlayerDowned(int32_t PlayerId, GameEntity entityType, int32_t entityID);
	static void OnPlayerRevived(int32_t PlayerId, GameEntity entityType, int32_t entityID);
	static void OnPlayerStartedRevive(int32_t PlayerId, GameEntity entityType, int32_t entityID);
	static void OnPlayerFailedRevive(int32_t PlayerId, GameEntity entityType, int32_t entityID);
private:
	static std::shared_ptr<Registry> Registry;
	static std::shared_ptr<Server> Server;
};

