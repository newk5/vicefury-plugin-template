#pragma once


#include "plugin.h"

class NPCEvents
{
public:
	static void Setup(std::shared_ptr<class Registry> registry, std::shared_ptr<class Server> server)
	{
		Registry = registry;
		Server = server;
	}
	
	static void OnNPCStartedSwimming(int32_t NpcId);
	static void OnNPCStoppedSwimming(int32_t NpcId);
	static void OnNPCDivedUnderwater(int32_t NpcId);
	static void OnNPCReachedWaterSurface(int32_t NpcId);
	static float OnNPCReceiveDamage(int32_t NpcId, DamageEvent ev);
	static void OnNPCDied(int32_t NpcId, DamageEvent ev);
	static void OnNPCLostSightOf(int32_t npcId, GameEntity entityType, int32_t entityID);
	static void OnNPCGainedSightOf(int32_t npcId, GameEntity entityType, int32_t entityID);
	static void OnNPCHeardNoise(int32_t npcId, double x, double y, double z);
	static void OnNPCActionChanged(int32_t npcId, NPCAction oldAction, NPCAction newAction);
	static void OnNPCSpawned(int32_t NpcId);
	static void OnNPCCreated(int32_t NpcId, NPCType Type);
	static void OnNPCDestroyed(int32_t NpcId);
	static void OnNPCWeaponReceived(int32_t NpcId, int32_t WeaponId, uint8_t Equipped);
	static void OnNPCWeaponRemoved(int32_t NpcId, int32_t WeaponId, uint8_t Equipped);
	static void OnNPCEnterVehicle(int32_t NpcId, int32_t VehicleId);
	static void OnNPCLeaveVehicle(int32_t NpcId, int32_t VehicleId);
	static void OnNPCReachedLocation(int32_t NpcId, const char* location);
	static void OnNPCEnemyDied(int32_t NpcId, GameEntity entityType, int32_t entityID);
	static void OnNPCEnemyLeftServer(int32_t NpcId, int32_t PlayerId);
	static void OnNPCEnemyEnterVehicle(int32_t NpcId, GameEntity entityType, int32_t entityID, int32_t VehicleID, uint8_t AsDriver);
	static void OnNPCEnemyLeaveVehicle(int32_t NpcId, GameEntity entityType, int32_t entityID, int32_t VehicleID, uint8_t AsDriver);
	static void OnNPCFollowTargetDied(int32_t NpcId, GameEntity entityType, int32_t entityID);
	static void OnNPCFollowTargetLeftServer(int32_t NpcId, int32_t PlayerId);
	static void OnNPCFollowTargetEnterVehicle(int32_t NpcId, GameEntity entityType, int32_t entityID, int32_t VehicleID, uint8_t AsDriver);
	static void OnNPCFollowTargetLeaveVehicle(int32_t NpcId, GameEntity entityType, int32_t entityID, int32_t VehicleID, uint8_t AsDriver);
	static void OnNPCReachedFollowTarget(int32_t NpcId, GameEntity entityType, int32_t entityID);
	static void OnNPCRanOutOfAmmo(int32_t NpcId, int32_t Weapon);
	static void OnNPCIsAboutToAttack(int32_t NpcId, GameEntity entityType, int32_t entityID);
	static void OnNPCDowned(int32_t NpcId, GameEntity entityType, int32_t entityID);
	static void OnNPCRevived(int32_t NpcId, GameEntity entityType, int32_t entityID);
	static void OnNPCStartedRevive(int32_t NpcId, GameEntity entityType, int32_t entityID);
	static void OnNPCFailedRevive(int32_t NpcId, GameEntity entityType, int32_t entityID);
	static void OnNPCEnemyDowned(int32_t NpcId, GameEntity entityType, int32_t entityID);
	static void OnNPCFollowTargetDowned(int32_t NpcId, GameEntity entityType, int32_t entityID);

private:
	static std::shared_ptr<Registry> Registry;
	static std::shared_ptr<Server> Server;
};

