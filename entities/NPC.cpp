#include "pch.h"
#include "NPC.h"
#include "Server.h"
#include "Registry.h"


int32_t NPC::GetNpcType()
{
    EXTRACT_INT(GetNpcType, NPC)
    return result;
}

float NPC::GetRespawnDelay()
{
    EXTRACT_FLOAT(GetNpcRespawnDelay, NPC)
    return result;
}

void NPC::SetRespawnDelay(float Delay)
{
    THREAD_CHECK();
    API->SetNpcRespawnDelay(this->Id, Delay);
}

float NPC::GetMaxHealth()
{
    EXTRACT_FLOAT(GetNpcMaxHealth, NPC)
    return result;
}

void NPC::SetMaxHealth(float HP)
{
    THREAD_CHECK();
    API->SetNpcMaxHealth(this->Id, HP);
}

float NPC::GetHealth()
{
    EXTRACT_FLOAT(GetNpcHealth, NPC)
    return result;
}

void NPC::SetHealth(float HP)
{
    THREAD_CHECK();
    API->SetNpcHealth(this->Id, HP);
}

void NPC::Attack(VFEntity Entity)
{
    THREAD_CHECK();
    API->NpcAttack(this->Id, Entity.GetType(), Entity.GetId());
}


void NPC::NpcAttack(GameEntity GameEntityType, int32_t TargetId)
{
    THREAD_CHECK();
    API->NpcAttack(this->Id, GameEntityType, TargetId);
}

float NPC::GetMovementSpeed()
{
    EXTRACT_FLOAT(GetNpcMovementSpeed, NPC)
    return result;
}

void NPC::SetMovementSpeed(float Speed)
{
    THREAD_CHECK();
    API->SetNpcMovementSpeed(this->Id, Speed);
}

Vec NPC::GetPosition()
{
    EXTRACT_VEC(GetNpcPosition, NPC)
    return result;
}

void NPC::SetPosition(Vec Pos)
{
    THREAD_CHECK();
    API->SetNpcPosition(this->Id, Pos.X, Pos.Y, Pos.Z);
}

bool NPC::HasAutoRespawnEnabled()
{
    EXTRACT_BOOL(NpcHasAutoRespawnEnabled, NPC)
    return result;
}

void NPC::EnableAutoRespawn()
{
    THREAD_CHECK();
    API->NpcEnableAutoRespawn(this->Id);
}

void NPC::DisableAutoRespawn()
{
    THREAD_CHECK();
    API->NpcDisableAutoRespawn(this->Id);
}

float NPC::GetSightAngle()
{
    EXTRACT_FLOAT(GetNpcSightAngle, NPC)
    return result;
}

void NPC::SetSightAngle(float Angle)
{
    THREAD_CHECK();
    API->SetNpcSightAngle(this->Id, Angle);
}

float NPC::GetSightDistance()
{
    EXTRACT_FLOAT(GetNpcSightDistance, NPC)
    return result;
}

void NPC::SetSightDistance(float Distance)
{
    THREAD_CHECK();
    API->SetNpcSightDistance(this->Id, Distance);
}

float NPC::GetHearingDistance()
{
    EXTRACT_FLOAT(GetNpcHearingDistance, NPC)
    return result;
}

void NPC::SetHearingDistance(float Distance)
{
    THREAD_CHECK();
    API->SetNpcHearingDistance(this->Id, Distance);
}

void NPC::Respawn()
{
    THREAD_CHECK();
    API->NpcRespawn(this->Id);
}

void NPC::SetSpawnpoint(Vec Pos, double YawAngle)
{
    THREAD_CHECK();
    API->SetNpcSpawnpoint(this->Id, Pos.X, Pos.Y, Pos.Z, YawAngle);
}

VecWithAngle NPC::GetSpawnpoint()
{
    EXTRACT_VEC_WITH_ANGLE(GetNpcSpawnpoint, NPC)
    return result;
}

void NPC::SetYawAngle(double Yaw)
{
    THREAD_CHECK();
    API->SetNpcYawAngle(this->Id, Yaw);
}

double NPC::GetYawAngle()
{
    EXTRACT_DOUBLE(GetNpcYawAngle, NPC)
    return result;
}

bool NPC::IsWithinLineOfSightOfNpc(GameEntity Ent, int32_t EntId)
{
    EXTRACT_BOOL_TWO_PARAM(IsWithinLineOfSightOfNpc, Ent, EntId, NPC)
    return result;
}

NPCAction NPC::GetAction()
{
    NPCAction npcAct;
    THREAD_CHECK_RETURN(NPCAction_None);
    ViceFuryExitCode ExitCode = API->GetNpcAction(this->Id, &npcAct);
    if (ExitCode != ViceFuryExitCode_Success)
    {
        LOG(WARNING) << "Error Calling GetNpcAction non Existent NPC entity for ID: " << this->Id;
    }
    return npcAct;
}

void NPC::AddFriend(GameEntity Ent, int32_t EntId)
{
    THREAD_CHECK();
    API->AddNpcFriend(this->Id, Ent, EntId);
}

void NPC::RemoveFriend(GameEntity Ent, int32_t EntId)
{
    THREAD_CHECK();
    API->RemoveNpcFriend(this->Id, Ent, EntId);
}

void NPC::MoveToLocation(Vec Pos)
{
    THREAD_CHECK();
    API->NpcMoveToLocation(this->Id, Pos.X, Pos.Y, Pos.Z);
}

void NPC::MoveToLocation(Vec Pos, std::string Loc)
{
    THREAD_CHECK();
    API->MoveNpcToLocation(this->Id, Pos.X, Pos.Y, Pos.Z, Loc.c_str());
}

void NPC::Investigate(float Radius)
{
    THREAD_CHECK();
    API->NpcInvestigate(this->Id, Radius);
}

void NPC::InvestigateLocation(Vec Pos, float Radius)
{
    THREAD_CHECK();
    API->NpcInvestigateLocation(this->Id, Pos.X, Pos.Y, Pos.Z, Radius);
}

Vec NPC::GetForwardVector()
{
    EXTRACT_VEC(GetNpcForwardVector, NPC)
    return result;
}

Vec NPC::GetRightVector()
{
    EXTRACT_VEC(GetNpcRightVector, NPC)
    return result;
}

void NPC::Destroy()
{
    THREAD_CHECK();
    API->DestroyNpc(this->Id);
}

void NPC::DetachAllObjects()
{
    THREAD_CHECK();
    API->DetachAllNpcObjects(this->Id);
}

std::string NPC::GetBoneNames()
{
    EXTRACT_STRING(GetNpcBoneNames, NPC)
    return result;
}


bool NPC::CanMoveTo(Vec Pos)
{
    EXTRACT_BOOL_THREE_PARAM(NpcCanMoveTo, Pos.X, Pos.Y, Pos.Z, NPC)
    return result;
}

double NPC::GetMoveDirection()
{
    EXTRACT_DOUBLE(GetNpcMoveDirection, NPC)
    return result;
}

bool NPC::HasObjectAttached(int32_t ObjectId)
{
    EXTRACT_BOOL_ONE_PARAM(NpcHasObjectAttached, ObjectId, NPC)
    return result;
}

void NPC::DetachObject(int32_t ObjectId)
{
    THREAD_CHECK();
    API->NpcDetachObject(this->Id, ObjectId);
}

bool NPC::IsFriendly(GameEntity Ent, int32_t EntID)
{
    EXTRACT_BOOL_TWO_PARAM(NpcIsFriendly, Ent, EntID, NPC)
    return result;
}

int32_t NPC::GetTeam()
{
    EXTRACT_INT(GetNpcTeam, NPC)
    return result;
}

void NPC::SetTeam(int32_t Team)
{
    THREAD_CHECK();
    API->SetNpcTeam(this->Id, Team);
}

double NPC::GetShooterAccuracy()
{
    EXTRACT_DOUBLE(GetNpcShooterAccuracy, NPC)
    return result;
}

void NPC::SetShooterAccuracy(double Accuracy)
{
    THREAD_CHECK();
    API->SetNpcShooterAccuracy(this->Id, Accuracy);
}

float NPC::GetShooterWalkSpeed()
{
    EXTRACT_FLOAT(GetNpcShooterWalkSpeed, NPC)
    return result;
}

void NPC::SetShooterWalkSpeed(float OutSpeed)
{
    THREAD_CHECK();
    API->SetNpcShooterWalkSpeed(this->Id, OutSpeed);
}

float NPC::GetShooterRunSpeed()
{
    EXTRACT_FLOAT(GetNpcShooterRunSpeed, NPC)
    return result;
}

void NPC::SetShooterRunSpeed(float OutSpeed)
{
    THREAD_CHECK();
    API->SetNpcShooterRunSpeed(this->Id, OutSpeed);
}

bool NPC::HasWeapon(int32_t WeaponId)
{
    EXTRACT_BOOL_ONE_PARAM(NpcHasWeapon, WeaponId, NPC)
    return result;
}

void NPC::RemoveWeapon(int32_t WeaponId)
{
    THREAD_CHECK();
    API->RemoveNpcWeapon(this->Id, WeaponId);
}

void NPC::SwitchToWeapon(int32_t WeaponId)
{
    THREAD_CHECK();
    API->SwitchNpcWeapon(this->Id, WeaponId);
}

void NPC::RemoveFromVehicle()
{
    THREAD_CHECK();
    API->RemoveNpcFromVehicle(this->Id);
}

void NPC::StartShooting(Vec Direction)
{
    THREAD_CHECK();
    API->NpcStartShooting(this->Id, Direction.X, Direction.Y, Direction.Z);
}

void NPC::StopShooting()
{
    THREAD_CHECK();
    API->NpcStopShooting(this->Id);
}

bool NPC::IsShooting()
{
    EXTRACT_BOOL(NpcIsShooting, NPC)
    return result;
}

std::string NPC::GetTargetLocation()
{
    EXTRACT_STRING(GetNpcTargetLocation, NPC)
    return result;
}

void NPC::SetAcceptanceRadius(float Radius)
{
    THREAD_CHECK();
    API->SetNpcAcceptanceRadius(this->Id, Radius);
}

float NPC::GetAcceptanceRadius()
{
    EXTRACT_FLOAT(GetNpcAcceptanceRadius, NPC)
    return result;
}

void NPC::SetMovementMode(NPCMovementMode Mode)
{
    THREAD_CHECK();
    API->SetNpcMovementMode(this->Id, Mode);
}

NPCMovementMode NPC::GetMovementMode()
{
    NPCMovementMode Mode = NPCMovementMode_Walking;
    THREAD_CHECK_RETURN(Mode);
    API->GetNpcMovementMode(this->Id,&Mode);
    return Mode;
}

void NPC::Follow(VFEntity* Entity)
{
    THREAD_CHECK();
    API->NpcFollow(Id, Entity->GetType(), Entity->GetId());
}

void NPC::NpcFollow(GameEntity GameEntityType, int32_t TargetId)
{
    THREAD_CHECK();
    API->NpcFollow(this->Id, GameEntityType, TargetId);
}

std::shared_ptr<VFEntity> NPC::GetFollowTarget()
{
    THREAD_CHECK_RETURN(nullptr);
    int32_t OutId = 0;
    GameEntity OutType = GameEntity_Undefined;
    ViceFuryExitCode ExitCode = API->GetNpcFollowTarget(this->Id, &OutType, &OutId);
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success)
    {
        LOG(WARNING) << "Error Calling GetNpcFollowTarget - non Existent NPC entity for ID: " << this->Id;
    }
    return REGISTRY->GetEntity(OutType, OutId);
}

std::shared_ptr<VFEntity> NPC::GetEnemy()
{
    THREAD_CHECK_RETURN(nullptr);
    int32_t OutId = 0;
    GameEntity OutType = GameEntity_Undefined;
    ViceFuryExitCode ExitCode = API->GetNpcEnemy(this->Id, &OutType, &OutId);

    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success)
    {
        LOG(WARNING) << "Error Calling GetNpcEnemy - non Existent NPC entity for ID: " << this->Id;
    }
    return REGISTRY->GetEntity(OutType, OutId);
}

void NPC::Launch(Vec Direction, double Force, bool Additive)
{
    THREAD_CHECK();
    API->LaunchNpc(this->Id, Direction.X, Direction.Y, Direction.Z, Force, Additive);
}

float NPC::GetArmour()
{
    EXTRACT_FLOAT(GetNpcArmour, NPC)
    return result;
}

void NPC::SetArmour(float Armour)
{
    THREAD_CHECK();
    API->SetNpcArmour(this->Id, Armour);
}

std::string NPC::GetNameTag()
{
    EXTRACT_STRING(GetNpcNameTag, NPC)
    return result;
}

void NPC::SetNameTag(std::string Text)
{
    THREAD_CHECK();
    API->SetNpcNameTag(this->Id, Text.c_str());
}

void NPC::SetColor(int32_t TeamColor)
{
    THREAD_CHECK();
    API->SetNpcColor(this->Id, TeamColor);
}

int32_t NPC::GetColor()
{
    EXTRACT_INT(GetNpcColor, NPC)
    return result;
}

NPCShooterAttackStrategy NPC::GetAttackStrategy()
{
    NPCShooterAttackStrategy As;
    THREAD_CHECK_RETURN(NPCShooterAttackStrategy_Static);
    ViceFuryExitCode ExitCode =API->GetNpcAttackStrategy(this->Id,&As);
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success)
    {
        LOG(WARNING) << "Error Calling GetNpcAttackStrategy - non Existent NPC entity for ID: " << this->Id;
    }
    return As;
}

void NPC::SetAttackStrategy(NPCShooterAttackStrategy Strategy)
{
    THREAD_CHECK();
    API->SetNpcAttackStrategy(this->Id, Strategy);
}

void NPC::StopMoving()
{
    THREAD_CHECK();
    API->NpcStopMoving(this->Id);
}

bool NPC::IsMoving()
{
    EXTRACT_BOOL(NpcIsMoving, NPC)
    return result;
}

bool NPC::IsMovingToLocation(std::string Location)
{
    EXTRACT_BOOL_ONE_PARAM(NpcIsMovingToLocation, Location.c_str(), NPC)
    return result;
}

bool NPC::IsInvestigating()
{
    EXTRACT_BOOL(NpcIsInvestigating, NPC)
    return result;
}

bool NPC::IsBeingFollowedByNpc(int32_t TargetNpcId)
{
    EXTRACT_BOOL_ONE_PARAM(NpcIsBeingFollowedByNpc, TargetNpcId, NPC)
    return result;
}

bool NPC::IsBeingAttackedByNpc(int32_t TargetNpcId)
{
    EXTRACT_BOOL_ONE_PARAM(NpcIsBeingAttackedByNpc, TargetNpcId, NPC)
    return result;
}

bool NPC::IsBeingFollowedByNpcs()
{
    EXTRACT_BOOL(NpcIsBeingFollowedByNpcs, NPC)
    return result;
}

bool NPC::IsBeingAttackedByNpcs()
{
    EXTRACT_BOOL(NpcIsBeingAttackedByNpcs, NPC)
    return result;
}

bool NPC::IsRunning()
{
    EXTRACT_BOOL(NpcIsRunning, NPC)
    return result;
}

bool NPC::IsFalling()
{
    EXTRACT_BOOL(NpcIsFalling, NPC)
    return result;
}

bool NPC::IsNameTagVisible()
{
    EXTRACT_BOOL(IsNpcNameTagVisible, NPC)
    return result;
}

void NPC::ShowNameTag()
{
    THREAD_CHECK();
    API->ShowNpcNameTag(this->Id);
}

void NPC::HideNameTag()
{
    THREAD_CHECK();
    API->HideNpcNameTag(this->Id);
}

bool NPC::IsOnTheGround()
{
    EXTRACT_BOOL(NpcIsOnTheGround, NPC)
    return result;
}

bool NPC::IsInVehicle()
{
    EXTRACT_BOOL(NpcIsInVehicle, NPC)
    return result;
}

Vec NPC::GetUpVector()
{
    EXTRACT_VEC(GetNpcUpVector, NPC)
    return result;
}

int32_t NPC::GetVehicle()
{
    EXTRACT_INT(GetNpcVehicle, NPC)
    return result;
}

float NPC::GetWeaponDamage(int32_t WeaponId)
{
    EXTRACT_FLOAT_ONE_PARAM(GetNpcWeaponDamage, WeaponId,NPC)
    return result;
}

void NPC::SetWeaponDamage(int32_t WeaponId, float WeaponDmg)
{
    THREAD_CHECK();
    API->SetNpcWeaponDamage(this->Id, WeaponId, WeaponDmg);
}

float NPC::GetWeaponRange(int32_t WeaponId)
{
    EXTRACT_FLOAT_ONE_PARAM(GetNpcWeaponRange, WeaponId, NPC)
    return result;
}

void NPC::SetWeaponRange(int32_t WeaponId, float WeaponRange)
{
    THREAD_CHECK();
    API->SetNpcWeaponRange(this->Id, WeaponId, WeaponRange);
}

void NPC::KeepWeaponsOnRespawn(bool status)
{
    THREAD_CHECK();
    API->KeepNpcWeaponsOnRespawn(this->Id, status);
}

void NPC::SetStoredWeaponAmmo(int32_t WeaponId, int32_t Ammo)
{
    THREAD_CHECK();
    API->SetNpcStoredWeaponAmmo(this->Id, WeaponId, Ammo);
}

int32_t NPC::GetStoredWeaponAmmo(int32_t WeaponId)
{
    EXTRACT_INT_ONE_PARAM(GetNpcStoredWeaponAmmo, WeaponId, NPC)
    return result;
}

void NPC::EnableAvoidance()
{
    THREAD_CHECK();
    API->EnableNpcAvoidance(this->Id);
}

void NPC::DisableAvoidance()
{
    THREAD_CHECK();
    API->DisableNpcAvoidance(this->Id);
}

bool NPC::HasAvoidanceEnabled()
{
    EXTRACT_BOOL(NpcHasAvoidanceEnabled, NPC)
    return result;
}

bool NPC::IsSwimming()
{
    EXTRACT_BOOL(NpcIsSwimming, NPC)
    return result;
}

bool NPC::IsUnderwater()
{
    EXTRACT_BOOL(NpcIsUnderwater, NPC)
    return result;
}

bool NPC::CanBeRevived()
{
    EXTRACT_BOOL(NpcCanBeRevived, NPC)
    return result;
}

void NPC::SetCanBeRevived(bool Status)
{
    THREAD_CHECK();
    API->SetNpcCanBeRevived(this->Id, Status);
}

bool NPC::IsAwaitingRevive()
{
    EXTRACT_BOOL(NpcIsAwaitingRevive, NPC)
    return result;
}

float NPC::GetReviveWaitTime()
{
    EXTRACT_FLOAT(GetNpcReviveWaitTime, NPC)
    return result;
}

void NPC::SetReviveWaitTime(float Seconds)
{
    THREAD_CHECK();
    API->SetNpcReviveWaitTime(this->Id, Seconds);
}

float NPC::GetReviveDuration()
{
    EXTRACT_FLOAT(GetNpcReviveDuration, NPC)
    return result;
}

void NPC::SetReviveDuration(float Seconds)
{
    THREAD_CHECK();
    API->SetNpcReviveDuration(this->Id, Seconds);
}

float NPC::GetAwaitingReviveHP()
{
    EXTRACT_FLOAT(GetNpcAwaitingReviveHP, NPC)
    return result;
}

void NPC::SetAwaitingReviveHP(float HP)
{
    THREAD_CHECK();
    API->SetNpcAwaitingReviveHP(this->Id, HP);
}

float NPC::GetHPWhenRevived()
{
    EXTRACT_FLOAT(GetNpcHPWhenRevived, NPC)
    return result;
}

void NPC::SetHPWhenRevived(float HP)
{
    THREAD_CHECK();
    API->SetNpcHPWhenRevived(this->Id, HP);
}

void NPC::Revive()
{
    THREAD_CHECK();
    API->ReviveNpc(this->Id);
}

void NPC::Down()
{
    THREAD_CHECK();
    API->DownNpc(this->Id);
}

void NPC::ReviveCharacter(GameEntity CharType, int32_t CharId)
{
    THREAD_CHECK();
    API->NpcReviveCharacter(this->Id, CharType, CharId);
}

bool NPC::IsBeingRevived()
{
    EXTRACT_BOOL(NpcIsBeingRevived, NPC)
    return result;
}

bool NPC::IsBeingRevivedBy(GameEntity CharType, int32_t CharId)
{
    EXTRACT_BOOL_TWO_PARAM(NpcIsBeingRevivedBy, CharType, CharId, NPC)
    return result;
}

bool NPC::IsRevivingSomeone()
{
    EXTRACT_BOOL(NpcIsRevivingSomeone, NPC)
    return result;
}

bool NPC::IsRevivingCharacter(GameEntity CharType, int32_t CharId)
{
    EXTRACT_BOOL_TWO_PARAM(NpcIsRevivingCharacter, CharType, CharId, NPC)
    return result;
}

int32_t NPC::GetSubtype()
{
    EXTRACT_INT(GetNpcSubtype, NPC)
    return result;
}
