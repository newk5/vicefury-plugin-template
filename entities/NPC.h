#pragma once
#include "plugin.h"

class Registry;

class NPC : public VFEntity
{
public:
    NPC(int32_t id, std::shared_ptr<Registry> registry) : Id(id), Registry(registry)
    {
    }

    ~NPC() override
    {
    }

    GameEntity GetType() override
    {
        return GameEntity_NPC;
    }

    int32_t GetId() override
    {
        return Id;
    }

    int32_t GetNpcType();
    float GetRespawnDelay();
    void SetRespawnDelay(float Delay);
    float GetMaxHealth();
    void SetMaxHealth(float HP);
    float GetHealth();
    void SetHealth(float HP);
    void Attack(VFEntity Entity);
    void NpcAttack(GameEntity GameEntityType, int32_t TargetId);
    float GetMovementSpeed();
    void SetMovementSpeed(float Speed);
    Vec GetPosition();
    void SetPosition(Vec Pos);
    bool HasAutoRespawnEnabled();
    void EnableAutoRespawn();
    void DisableAutoRespawn();
    float GetSightAngle();
    void SetSightAngle(float Angle);
    float GetSightDistance();
    void SetSightDistance(float Distance);
    float GetHearingDistance();
    void SetHearingDistance(float Distance);
    void Respawn();
    void SetSpawnpoint(Vec Pos, double YawAngle);
    VecWithAngle GetSpawnpoint();
    void SetYawAngle(double Yaw);
    double GetYawAngle();
    bool IsWithinLineOfSightOfNpc(GameEntity Ent, int32_t EntId);
    NPCAction GetAction();
    void AddFriend(GameEntity Ent, int32_t EntId);
    void RemoveFriend(GameEntity Ent, int32_t EntId);
    void MoveToLocation(Vec Pos);
    void MoveToLocation(Vec Pos, std::string Loc);
    void Investigate(float Radius);
    void InvestigateLocation(Vec Pos, float Radius);
    Vec GetForwardVector();
    Vec GetRightVector();
    void Destroy();
    void DetachAllObjects();
    std::string GetBoneNames();
    bool CanMoveTo(Vec Pos);
    double GetMoveDirection();
    bool HasObjectAttached(int32_t ObjectId);
    void DetachObject(int32_t ObjectId);
    bool IsFriendly(GameEntity Ent, int32_t EntID);
    int32_t GetTeam();
    void SetTeam(int32_t Team);
    double GetShooterAccuracy();
    void SetShooterAccuracy(double Accuracy);
    float GetShooterWalkSpeed();
    void SetShooterWalkSpeed(float OutSpeed);
    float GetShooterRunSpeed();
    void SetShooterRunSpeed(float OutSpeed);
    bool HasWeapon(int32_t WeaponId);
    void RemoveWeapon(int32_t WeaponId);
    void SwitchToWeapon(int32_t WeaponId);
    void RemoveFromVehicle();
    void StartShooting(Vec Direction);
    void StopShooting();
    bool IsShooting();
    std::string GetTargetLocation();
    void SetAcceptanceRadius(float Radius);
    float GetAcceptanceRadius();
    void SetMovementMode(NPCMovementMode Mode);
    NPCMovementMode GetMovementMode();
    void Follow(VFEntity* Entity);
    void NpcFollow(GameEntity GameEntityType, int32_t TargetId);
    std::shared_ptr<VFEntity> GetFollowTarget();
    std::shared_ptr<VFEntity> GetEnemy();
    void Launch(Vec Direction, double Force, bool Additive);
    float GetArmour();
    void SetArmour(float Armour);
    std::string GetNameTag();
    void SetNameTag(std::string Text);
    void SetColor(int32_t TeamColor);
    int32_t GetColor();
    NPCShooterAttackStrategy GetAttackStrategy();
    void SetAttackStrategy(NPCShooterAttackStrategy Strategy);
    void StopMoving();
    bool IsMoving();
    bool IsMovingToLocation(std::string Location);
    bool IsInvestigating();
    bool IsBeingFollowedByNpc(int32_t TargetNpcId);
    bool IsBeingAttackedByNpc(int32_t TargetNpcId);
    bool IsBeingFollowedByNpcs();
    bool IsBeingAttackedByNpcs();
    bool IsRunning();
    bool IsFalling();
    bool IsNameTagVisible();
    void ShowNameTag();
    void HideNameTag();
    bool IsOnTheGround();
    bool IsInVehicle();
    Vec GetUpVector();
    int32_t GetVehicle();
    float GetWeaponDamage(int32_t WeaponId);
    void SetWeaponDamage(int32_t WeaponId, float WeaponDmg);
    float GetWeaponRange(int32_t WeaponId);
    void SetWeaponRange(int32_t WeaponId, float WeaponRange);
    void KeepWeaponsOnRespawn(bool status);
    void SetStoredWeaponAmmo(int32_t WeaponId, int32_t Ammo);
    int32_t GetStoredWeaponAmmo(int32_t WeaponId);
    void EnableAvoidance();
    void DisableAvoidance();
    bool HasAvoidanceEnabled();
    bool IsSwimming();
    bool IsUnderwater();
    bool CanBeRevived();
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
    void ReviveCharacter(GameEntity CharType, int32_t CharId);
    bool IsBeingRevived();
    bool IsBeingRevivedBy(GameEntity CharType, int32_t CharId);
    bool IsRevivingSomeone();
    bool IsRevivingCharacter(GameEntity CharType, int32_t CharId);
    int32_t GetSubtype();

private:
    int32_t Id;
    std::weak_ptr<Registry> Registry;
};
