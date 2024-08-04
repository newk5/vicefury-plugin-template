#include "pch.h"
#include "NPCEvents.h"
#include "entities/Server.h"
#include "Registry.h"

std::shared_ptr<Registry> NPCEvents::Registry;
std::shared_ptr<Server> NPCEvents::Server;

void NPCEvents::OnNPCStartedSwimming(int32_t NpcId)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCStoppedSwimming(int32_t NpcId)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCDivedUnderwater(int32_t NpcId)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCReachedWaterSurface(int32_t NpcId)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

float NPCEvents::OnNPCReceiveDamage(int32_t NpcId, DamageEvent ev)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    return ev.DamageToApply;
}

void NPCEvents::OnNPCDied(int32_t NpcId, DamageEvent ev)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCLostSightOf(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCGainedSightOf(int32_t NpcId, GameEntity entityType, int32_t entityID)
{

    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCHeardNoise(int32_t NpcId, double x, double y, double z)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCActionChanged(int32_t NpcId, NPCAction oldAction, NPCAction newAction)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCSpawned(int32_t NpcId)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCCreated(int32_t NpcId, NPCType Type)
{
    Registry->RegisterNewNpc(NpcId);
    
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    
}

void NPCEvents::OnNPCDestroyed(int32_t NpcId)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    
    Registry->UnregisterNpc(NpcId);
}

void NPCEvents::OnNPCWeaponReceived(int32_t NpcId, int32_t WeaponId, uint8_t Equipped)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCWeaponRemoved(int32_t NpcId, int32_t WeaponId, uint8_t Equipped)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCEnterVehicle(int32_t NpcId, int32_t VehicleId)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
}

void NPCEvents::OnNPCLeaveVehicle(int32_t NpcId, int32_t VehicleId)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
}

void NPCEvents::OnNPCReachedLocation(int32_t NpcId, const char* location)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::string Loc(location);
}

void NPCEvents::OnNPCEnemyDied(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCEnemyLeftServer(int32_t NpcId, int32_t PlayerId)
{
    std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    
}

void NPCEvents::OnNPCEnemyEnterVehicle(int32_t NpcId, GameEntity entityType, int32_t entityID, int32_t VehicleID, uint8_t AsDriver)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleID);
}

void NPCEvents::OnNPCEnemyLeaveVehicle(int32_t NpcId, GameEntity entityType, int32_t entityID, int32_t VehicleId, uint8_t AsDriver)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
}

void NPCEvents::OnNPCFollowTargetDied(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCFollowTargetLeftServer(int32_t NpcId, int32_t PlayerId)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerId);
}

void NPCEvents::OnNPCFollowTargetEnterVehicle(int32_t NpcId, GameEntity entityType, int32_t entityID, int32_t VehicleId, uint8_t AsDriver)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
}

void NPCEvents::OnNPCFollowTargetLeaveVehicle(int32_t NpcId, GameEntity entityType, int32_t entityID, int32_t VehicleId, uint8_t AsDriver)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
}

void NPCEvents::OnNPCReachedFollowTarget(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCRanOutOfAmmo(int32_t NpcId, int32_t Weapon)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
}

void NPCEvents::OnNPCIsAboutToAttack(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCDowned(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCRevived(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCStartedRevive(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCFailedRevive(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCEnemyDowned(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}

void NPCEvents::OnNPCFollowTargetDowned(int32_t NpcId, GameEntity entityType, int32_t entityID)
{
    std::shared_ptr<NPC> npc = Registry->GetNpc(NpcId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(entityType,entityID);
}
