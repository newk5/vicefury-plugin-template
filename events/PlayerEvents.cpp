#include "pch.h"
#include "PlayerEvents.h"
#include "entities/Server.h"
#include "Registry.h"
#include "entities/Player.h"

std::shared_ptr<Registry> PlayerEvents::Registry;
std::shared_ptr<Server> PlayerEvents::Server;

void PlayerEvents::OnPlayerJoin(int32_t id)
{
	Registry->RegisterNewPlayer(id);
	std::shared_ptr<Player> Player = Registry->GetPlayer(id);
	
}

uint8_t PlayerEvents::OnPlayerMessage(int32_t PlayerID, const char* Message)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerID);
	std::string Msg(Message);

	
	return 1;
}

float PlayerEvents::OnPlayerReceiveDamage(int32_t PlayerId, DamageEvent ev)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
	return ev.DamageToApply;
}

void PlayerEvents::OnPlayerLeave(int32_t id)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(id);
	
	Registry->UnregisterPlayer(id);
}

void PlayerEvents::OnPlayerCommand(int32_t PlayerID, const char* Message)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerID);
	std::string Msg(Message);
}

void PlayerEvents::OnPlayerEnterVehicle(int32_t PlayerID, int32_t VehicleId, uint8_t AsDriver)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerID);
	std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
}

void PlayerEvents::OnPlayerLeaveVehicle(int32_t PlayerID, int32_t VehicleId, uint8_t AsDriver)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerID);
	std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
}

uint8_t PlayerEvents::OnPlayerRequestSpawn(int32_t PlayerId)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
	
	return 1;
}

void PlayerEvents::OnPlayerSpawnScreenSkinChange(int32_t PlayerId, int32_t SkinId)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
}

void PlayerEvents::OnPlayerSpawn(int32_t PlayerId)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
}

void PlayerEvents::OnPlayerDied(int32_t PlayerID, DamageEvent DmgEvent)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerID);
}

void PlayerEvents::OnPlayerWeaponReceived(int32_t PlayerId, int32_t WeaponId, uint8_t Equipped)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
}

void PlayerEvents::OnPlayerWeaponRemoved(int32_t PlayerId, int32_t WeaponId, uint8_t Equipped)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
}

void PlayerEvents::OnPlayerStartedSwimming(int32_t PlayerId)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
}

void PlayerEvents::OnPlayerStoppedSwimming(int32_t PlayerId)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
}

void PlayerEvents::OnPlayerDivedUnderwater(int32_t PlayerId)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
}

void PlayerEvents::OnPlayerReachedWaterSurface(int32_t PlayerId)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
}

void PlayerEvents::OnPlayerDowned(int32_t PlayerId, GameEntity entityType, int32_t entityID)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
	std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void PlayerEvents::OnPlayerRevived(int32_t PlayerId, GameEntity entityType, int32_t entityID)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
	std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void PlayerEvents::OnPlayerStartedRevive(int32_t PlayerId, GameEntity entityType, int32_t entityID)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
	std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void PlayerEvents::OnPlayerFailedRevive(int32_t PlayerId, GameEntity entityType, int32_t entityID)
{
	std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
	std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}
