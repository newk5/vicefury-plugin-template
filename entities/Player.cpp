#include "pch.h"
#include "Player.h"
#include "Server.h"
#include "Registry.h"

int32_t Player::GetPing()
{
    EXTRACT_INT(GetPlayerPing, PLAYER)
    return result;
}

std::string Player::GetIP()
{
    EXTRACT_STRING(GetPlayerIP, PLAYER)
    return result;
}

std::string Player::GetName()
{
    EXTRACT_STRING(GetPlayerName, PLAYER)
    return result;
}

Vec Player::GetPosition()
{
    EXTRACT_VEC(GetPlayerPosition, PLAYER)
    return result;
}

Vec Player::GetForwardVector()
{
    EXTRACT_VEC(GetPlayerForwardVector, PLAYER)
    return result;
}

Vec Player::GetRightVector()
{
    EXTRACT_VEC(GetPlayerRightVector, PLAYER)
    return result;
}

void Player::SetPosition(Vec Pos)
{
    THREAD_CHECK();
    API->SetPlayerPosition(this->Id, Pos.X, Pos.Y, Pos.Z);
}

double Player::GetYawAngle()
{
    EXTRACT_DOUBLE(GetPlayerYawAngle, PLAYER)
    return result;
}

void Player::SetYawAngle(double YawAngle)
{
    THREAD_CHECK();
    API->SetPlayerYawAngle(this->Id, YawAngle);
}

float Player::GetHealth()
{
    EXTRACT_FLOAT(GetPlayerHealth, PLAYER)
    return result;
}

float Player::GetArmour()
{
    EXTRACT_FLOAT(GetPlayerArmour, PLAYER)
    return result;
}

void Player::SetHealth(float Health)
{
    THREAD_CHECK();
    API->SetPlayerHealth(this->Id, Health);
}

float Player::GetMovementSpeed()
{
    EXTRACT_FLOAT(GetPlayerMovementSpeed, PLAYER)
    return result;
}

void Player::SetArmour(float Armour)
{
    THREAD_CHECK();
    API->SetPlayerArmour(this->Id, Armour);
}

bool Player::IsShooting()
{
    EXTRACT_BOOL(PlayerIsShooting, PLAYER)
    return result;
}

bool Player::IsRunning()
{
    EXTRACT_BOOL(PlayerIsRunning, PLAYER)
    return result;
}

bool Player::IsWalking()
{
    EXTRACT_BOOL(PlayerIsWalking, PLAYER)
    return result;
}

bool Player::IsCrouched()
{
    EXTRACT_BOOL(PlayerIsCrouched, PLAYER)
    return result;
}

bool Player::IsDriving()
{
    EXTRACT_BOOL(PlayerIsDriving, PLAYER)
    return result;
}

bool Player::IsPassenger()
{
    EXTRACT_BOOL(PlayerIsPassenger, PLAYER)
    return result;
}

bool Player::IsStandingOnVehicle(int32_t VehicleId)
{
    EXTRACT_BOOL_ONE_PARAM(PlayerIsStandingOnVehicle, VehicleId, PLAYER)
    return result;
}

std::shared_ptr<Vehicle> Player::GetVehicle()
{
    EXTRACT_INT_RETURN_VEHICLE(GetPlayerVehicle,PLAYER)
}

bool Player::IsFalling()
{
    EXTRACT_BOOL(PlayerIsFalling, PLAYER)
    return result;
}

bool Player::IsReloading()
{
    EXTRACT_BOOL(PlayerIsReloading, PLAYER)
    return result;
}

bool Player::IsKnocked()
{
    EXTRACT_BOOL(PlayerIsKnocked, PLAYER)
    return result;
}

void Player::SetTeam(int32_t Team)
{
    THREAD_CHECK();
    API->SetPlayerTeam(this->Id, Team);
}

int32_t Player::GetTeam()
{
    EXTRACT_INT(GetPlayerTeam, PLAYER)
    return result;
}

void Player::SetColor(int32_t TeamColor)
{
    THREAD_CHECK();
    API->SetPlayerColor(this->Id, TeamColor);
}

int32_t Player::GetColor()
{
    EXTRACT_INT(GetPlayerColor, PLAYER)
    return result;
}

void Player::SetSpawnpoint(Vec Pos, double YawAngle)
{
    THREAD_CHECK();
    API->SetPlayerSpawnpoint(this->Id, Pos.X, Pos.Y, Pos.Z, YawAngle);
}

VecWithAngle Player::GetSpawnpoint()
{
    EXTRACT_VEC_WITH_ANGLE(GetPlayerSpawnpoint, PLAYER)
    return result;
}

bool Player::IsSpawned()
{
    EXTRACT_BOOL(PlayerIsSpawned, PLAYER)
    return result;
}

int32_t Player::GetSkin()
{
    EXTRACT_INT(GetPlayerSkin, PLAYER)
    return result;
}

void Player::PlayerDetachAllObjects()
{
    THREAD_CHECK();
    API->PlayerDetachAllObjects(this->Id);
}

std::string Player::GetBoneNames()
{
    EXTRACT_STRING(GetPlayerBoneNames, PLAYER)
    return result;
}

double Player::GetMoveDirection()
{
    EXTRACT_DOUBLE(GetPlayerMoveDirection, PLAYER)
    return result;
}

bool Player::HasObjectAttached(int32_t ObjectId)
{
    EXTRACT_BOOL_ONE_PARAM(PlayerHasObjectAttached, ObjectId, PLAYER)
    return result;
}

void Player::Kick(std::string Reason)
{
    THREAD_CHECK();
    API->KickPlayer(this->Id, Reason.c_str());
}

void Player::DetachObject(int32_t ObjectId)
{
    THREAD_CHECK();
    API->PlayerDetachObject(this->Id, ObjectId);
}

bool Player::HasWeapon(int32_t WeaponId)
{
    EXTRACT_BOOL_ONE_PARAM(PlayerHasWeapon, WeaponId, PLAYER)
    return result;
}

void Player::Launch(Vec Direction, double Force, bool Additive)
{
    THREAD_CHECK();
    API->LaunchPlayer(this->Id, Direction.X, Direction.Y, Direction.Z, Force, Additive);
}

Vec Player::GetUpVector()
{
    EXTRACT_VEC(GetPlayerUpVector, PLAYER)
    return result;
}

float Player::GetWeaponDamage(int32_t WeaponId)
{
    EXTRACT_FLOAT_ONE_PARAM(GetPlayerWeaponDamage, WeaponId, NPC)
    return result;
}

void Player::SetWeaponDamage(int32_t WeaponId, float WeaponDmg)
{
    THREAD_CHECK();
    API->SetPlayerWeaponDamage(this->Id, WeaponId, WeaponDmg);
}

float Player::GetWeaponRange(int32_t WeaponId)
{
    EXTRACT_FLOAT_ONE_PARAM(GetPlayerWeaponRange, WeaponId, NPC)
    return result;
}

void Player::SetWeaponRange(int32_t WeaponId, float WeaponRange)
{
    THREAD_CHECK();
    API->SetPlayerWeaponRange(this->Id, WeaponId, WeaponRange);
}

void Player::KeepWeaponsOnRespawn(bool Status)
{
    THREAD_CHECK();
    API->KeepPlayerWeaponsOnRespawn(this->Id, Status);
}

void Player::SetStoredWeaponAmmo(int32_t WeaponId, int32_t Ammo)
{
    THREAD_CHECK();
    API->SetPlayerStoredWeaponAmmo(this->Id, WeaponId, Ammo);
}

int32_t Player::GetStoredWeaponAmmo(int32_t WeaponId)
{
    EXTRACT_INT_ONE_PARAM(GetPlayerStoredWeaponAmmo, WeaponId, NPC)
    return result;
}

void Player::RemoveWeapon(int32_t WeaponId)
{
    THREAD_CHECK();
    API->RemovePlayerWeapon(this->Id, WeaponId);
}

void Player::EnableFreeCam()
{
    THREAD_CHECK();
    API->EnablePlayerFreeCam(this->Id);
}

void Player::DisableFreeCam()
{
    THREAD_CHECK();
    API->DisablePlayerFreeCam(this->Id);
}

void Player::SpectatePlayer(int32_t TargetId)
{
    THREAD_CHECK();
    API->SpectatePlayer(this->Id, TargetId);
}

void Player::StopSpectating()
{
    THREAD_CHECK();
    API->StopSpectating(this->Id);
}

bool Player::IsSpectating()
{
    EXTRACT_BOOL(PlayerIsSpectating, PLAYER)
    return result;
}

bool Player::IsSpectatingPlayer(int32_t TargetId)
{
    EXTRACT_BOOL_ONE_PARAM(IsSpectatingPlayer, TargetId, PLAYER)
    return result;
}

 std::shared_ptr<Player> Player::GetSpectateTarget()
{
    EXTRACT_INT_RETURN_PLAYER(GetSpectateTarget, PLAYER)
}

bool Player::IsSwimming()
{
    EXTRACT_BOOL(PlayerIsSwimming, PLAYER)
    return result;
}

bool Player::IsUnderwater()
{
    EXTRACT_BOOL(PlayerIsUnderwater, PLAYER)
    return result;
}

bool Player::PlayerCanBeRevived()
{
    EXTRACT_BOOL(PlayerCanBeRevived, PLAYER)
    return result;
}

void Player::SetCanBeRevived(bool Status)
{
    THREAD_CHECK();
    API->SetPlayerCanBeRevived(this->Id, Status);
}

bool Player::IsAwaitingRevive()
{
    EXTRACT_BOOL(PlayerIsAwaitingRevive, PLAYER)
    return result;
}

float Player::GetReviveWaitTime()
{
    EXTRACT_FLOAT(GetPlayerReviveWaitTime, PLAYER)
    return result;
}

void Player::SetReviveWaitTime(float Seconds)
{
    THREAD_CHECK();
    API->SetPlayerReviveWaitTime(this->Id, Seconds);
}

float Player::GetReviveDuration()
{
    EXTRACT_FLOAT(GetPlayerReviveDuration, PLAYER)
    return result;
}

void Player::SetReviveDuration(float Seconds)
{
    THREAD_CHECK();
    API->SetPlayerReviveDuration(this->Id, Seconds);
}

float Player::GetAwaitingReviveHP()
{
    EXTRACT_FLOAT(GetPlayerAwaitingReviveHP, PLAYER)
    return result;
}

void Player::SetAwaitingReviveHP(float HP)
{
    THREAD_CHECK();
    API->SetPlayerAwaitingReviveHP(this->Id, HP);
}

float Player::GetHPWhenRevived()
{
    EXTRACT_FLOAT(GetPlayerHPWhenRevived, PLAYER)
    return result;
}

void Player::SetHPWhenRevived(float HP)
{
    THREAD_CHECK();
    API->SetPlayerHPWhenRevived(this->Id, HP);
}

void Player::Revive()
{
    THREAD_CHECK();
    API->RevivePlayer(this->Id);
}

void Player::Down()
{
    THREAD_CHECK();
    API->DownPlayer(this->Id);
}

bool Player::IsBeingRevived()
{
    EXTRACT_BOOL(PlayerIsBeingRevived, PLAYER)
    return result;
}

bool Player::IsBeingRevivedBy(GameEntity CharType, int32_t CharId)
{
    EXTRACT_BOOL_TWO_PARAM(PlayerIsBeingRevivedBy, CharType, CharId, PLAYER)
    return result;
}

bool Player::IsRevivingSomeone()
{
    EXTRACT_BOOL(PlayerIsRevivingSomeone, PLAYER)
    return result;
}

bool Player::IsRevivingCharacter(GameEntity CharType, int32_t CharId)
{
    EXTRACT_BOOL_TWO_PARAM(PlayerIsRevivingCharacter, CharType, CharId, PLAYER)
    return result;
}

void Player::EnableFreeCamWithDisabledControls()
{
    THREAD_CHECK();
    API->EnablePlayerFreeCamWithDisabledControls(this->Id);
}

void Player::EnableFreeCamWithTransformAndDisableControls(Vec Pos, Rotation Rot)
{
    THREAD_CHECK();
    API->EnablePlayerFreeCamWithTransformAndDisableControls(this->Id, Pos.X, Pos.Y, Pos.Z, Rot.Yaw, Rot.Pitch,
                                                            Rot.Roll);
}

void Player::EnableFreeCamWithDisabledControlsAndInterpTo(Vec Pos, Rotation Rot, double Speed)
{
    THREAD_CHECK();
    API->EnablePlayerFreeCamWithDisabledControlsAndInterpTo(this->Id, Pos.X, Pos.Y, Pos.Z, Rot.Yaw, Rot.Pitch, Rot.Roll,
                                                            Speed);
}

void Player::SetFreeCamTransform(Vec Pos, Rotation Rot)
{
    THREAD_CHECK();
    API->SetPlayerFreeCamTransform(this->Id, Pos.X, Pos.Y, Pos.Z, Rot.Yaw, Rot.Pitch, Rot.Roll);
}

void Player::AllowAccessToRemotePlayerData()
{
    THREAD_CHECK();
    API->AllowAccessToRemotePlayerData(this->Id);
}

void Player::AllowAccessToRemoteVehicleData()
{
    THREAD_CHECK();
    API->AllowAccessToRemoteVehicleData(this->Id);
}

void Player::AllowAccessToRemoteNPCData()
{
    THREAD_CHECK();
    API->AllowAccessToRemoteNPCData(this->Id);
}

void Player::AllowAccessToRemoteObjectData()
{
    THREAD_CHECK();
    API->AllowAccessToRemoteObjectData(this->Id);
}

void Player::DisallowAccessToRemotePlayerData()
{
    THREAD_CHECK();
    API->DisallowAccessToRemotePlayerData(this->Id);
}

void Player::DisallowAccessToRemoteVehicleData()
{
    THREAD_CHECK();
    API->DisallowAccessToRemoteVehicleData(this->Id);
}

void Player::DisallowAccessToRemoteNPCData()
{
    THREAD_CHECK();
    API->DisallowAccessToRemoteNPCData(this->Id);
}

void Player::DisallowAccessToRemoteObjectData()
{
    THREAD_CHECK();
    API->DisallowAccessToRemoteObjectData(this->Id);
}

bool Player::HasAccessToRemotePlayerData()
{
    EXTRACT_BOOL(HasAccessToRemotePlayerData, PLAYER)
    return result;
}

bool Player::HasAccessToRemoteVehicleData()
{
    EXTRACT_BOOL(HasAccessToRemoteVehicleData, PLAYER)
    return result;
}

bool Player::HasAccessToRemoteObjectData()
{
    EXTRACT_BOOL(HasAccessToRemoteObjectData, PLAYER)
    return result;
}

bool Player::HasAccessToRemoteNPCData()
{
    EXTRACT_BOOL(HasAccessToRemoteNPCData, PLAYER)
    return result;
}

Rotation Player::GetFreeCamRotation()
{
    EXTRACT_ROT(GetFreeCamRotation, PLAYER)
    return result;
}

Vec Player::GetFreeCamPosition()
{
    EXTRACT_VEC(GetFreeCamPosition, PLAYER)
    return result;
}

Vec Player::GetFreeCamDirection()
{
    EXTRACT_VEC(GetFreeCamDirection, PLAYER)
    return result;
}

void Player::InterpFreeCamTo(Vec Pos, Rotation Rot, double Speed)
{
    THREAD_CHECK();
    API->InterpFreeCamTo(this->Id, Pos.X, Pos.Y, Pos.Z, Rot.Yaw, Rot.Pitch, Rot.Roll, Speed);
}
void Player::SendChatMessage(std::string Msg)
{
    THREAD_CHECK();
    uint32_t White = 0xFFFFFFFF;
    SERVER->SendChatMessageToPlayer(this->Id,Msg,White);
}
void Player::SendChatMessage(std::string Msg,uint32_t Color)
{
    THREAD_CHECK();
    SERVER->SendChatMessageToPlayer(this->Id,Msg,Color);
}

void Player::SendData(std::string Channel, std::string Msg)
{
    THREAD_CHECK();
    SERVER->SendData(this->Id,Channel,Msg);
}