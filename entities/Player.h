#pragma once
#include "plugin.h"


class Registry;

class Player : public VFEntity
{
public:
    Player(int32_t id, std::shared_ptr<Registry> registry) : Id(id), Registry(registry)
    {
    }


    int32_t GetPing();
    std::string GetIP();
    std::string GetName();
    Vec GetPosition();
    Vec GetForwardVector();
    Vec GetRightVector();
    void SetPosition(Vec Pos);
    double GetYawAngle();
    void SetYawAngle(double YawAngle);
    float GetHealth();
    float GetArmour();
    void SetHealth(float Health);
    float GetMovementSpeed();
    void SetArmour(float Armour);
    bool IsShooting();
    bool IsRunning();
    bool IsWalking();
    bool IsCrouched();
    bool IsDriving();
    bool IsPassenger();
    bool IsStandingOnVehicle(int32_t VehicleId);
    std::shared_ptr<class Vehicle> GetVehicle();
    bool IsFalling();
    bool IsReloading();
    bool IsKnocked();
    void SetTeam(int32_t Team);
    int32_t GetTeam();
    void SetColor(int32_t TeamColor);
    int32_t GetColor();
    void SetSpawnpoint(Vec Pos, double YawAngle);
    VecWithAngle GetSpawnpoint();
    bool IsSpawned();
    int32_t GetSkin();
    void PlayerDetachAllObjects();
    std::string GetBoneNames();
    double GetMoveDirection();
    bool HasObjectAttached(int32_t ObjectId);
    void Kick(std::string Reason);
    void DetachObject(int32_t ObjectId);
    bool HasWeapon(int32_t WeaponId);
    void Launch(Vec Direction, double Force, bool Additive);
    Vec GetUpVector();
    float GetWeaponDamage(int32_t WeaponId);
    void SetWeaponDamage(int32_t WeaponId, float WeaponDmg);
    float GetWeaponRange(int32_t WeaponId);
    void SetWeaponRange(int32_t WeaponId, float WeaponRange);
    void KeepWeaponsOnRespawn(bool Status);
    void SetStoredWeaponAmmo(int32_t WeaponId, int32_t Ammo);
    int32_t GetStoredWeaponAmmo(int32_t WeaponId);
    void RemoveWeapon(int32_t WeaponId);
    void EnableFreeCam();
    void DisableFreeCam();
    void SpectatePlayer(int32_t TargetId);
    void StopSpectating();
    bool IsSpectating();
    bool IsSpectatingPlayer(int32_t TargetId);
    std::shared_ptr<Player> GetSpectateTarget();
    bool IsSwimming();
    bool IsUnderwater();
    bool PlayerCanBeRevived();
    void SetCanBeRevived(bool Status);
    bool IsAwaitingRevive();
    float GetReviveWaitTime();
    void SetReviveWaitTime(float Seconds);
    float GetReviveDuration();
    void SetReviveDuration(float Seconds);
    float GetAwaitingReviveHP();
    void SetAwaitingReviveHP(float HP);
    float GetHPWhenRevived();
    void SetHPWhenRevived(float HP);
    void Revive();
    void Down();
    bool IsBeingRevived();
    bool IsBeingRevivedBy(GameEntity CharType, int32_t CharId);
    bool IsRevivingSomeone();
    bool IsRevivingCharacter(GameEntity CharType, int32_t CharId);
    void EnableFreeCamWithDisabledControls();
    void EnableFreeCamWithTransformAndDisableControls(Vec Pos, Rotation Rot);
    void EnableFreeCamWithDisabledControlsAndInterpTo(Vec Pos, Rotation Rot, double Speed);
    void SetFreeCamTransform(Vec Pos, Rotation Rot);
    void AllowAccessToRemotePlayerData();
    void AllowAccessToRemoteVehicleData();
    void AllowAccessToRemoteNPCData();
    void AllowAccessToRemoteObjectData();
    void DisallowAccessToRemotePlayerData();
    void DisallowAccessToRemoteVehicleData();
    void DisallowAccessToRemoteNPCData();
    void DisallowAccessToRemoteObjectData();
    bool HasAccessToRemotePlayerData();
    bool HasAccessToRemoteVehicleData();
    bool HasAccessToRemoteObjectData();
    bool HasAccessToRemoteNPCData();
    Rotation GetFreeCamRotation();
    Vec GetFreeCamPosition();
    Vec GetFreeCamDirection();
    void InterpFreeCamTo(Vec Pos, Rotation Rot, double Speed);
    void SendChatMessage(std::string Msg);
    void SendChatMessage(std::string Msg, uint32_t Color);
    void SendData(std::string Channel, std::string Msg);

    ~Player() override
    {
    }

    GameEntity GetType() override
    {
        return GameEntity_Player;
    }

    int32_t GetId() override
    {
        return Id;
    }

private:
    int32_t Id;
    std::weak_ptr<Registry> Registry;
};
