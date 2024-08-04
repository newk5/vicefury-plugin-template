#pragma once
#include <functional>
#include <memory>

#include "common/GameTimer.h"

class Server
{
public:
    Server(const std::shared_ptr<class Registry> registry)
        : Registry(registry)
    {
    }

    Server()
    {
    }

    void SendChatMessageToAll(std::string Msg, uint32_t Color);
    void SendChatMessageToAll(std::string Msg);
    void SendChatMessageToPlayer(int32_t PlayerId, std::string Msg, uint32_t Color);
    bool PlayerExists(int32_t PlayerId);
    bool NPCExists(int32_t NpcId);
    bool VehicleExists(int32_t VehicleId);
    void SpawnNPC(NPCSpawnProperties& Props);
    void SendData(int32_t PlayerId, std::string Channel, std::string Data);
    Vec GetRandomPoint(Vec Origin, double Radius);
    Rotation FindRotationLookingAt(Vec FromPos, Vec ToPos);
    Vec FindDirectionLookingAt(Vec FromPos, Vec ToPos);
    void SetSpawnScreenLocation(Vec Pos, double YawLookAt);
    void SpawnObject(ObjectSpawnProperties& Props);
    void CreateEntitySocket(GameEntity EntityType, EntitySocket Socket);
    void SetTime(float Time);
    float GetTime();
    void SpawnZone(ZoneSpawnProperties& Props);
    void SetLowTPSWarningLimit(int32_t Limit);
    int32_t GetServerTPS();
    void SpawnWeapon(int32_t WeaponId, Vec Pos, int32_t Ammo);
    void GiveWeaponToPlayer(int32_t WeaponId, int32_t PlayerId, int32_t Ammo);
    void GiveWeaponToShooterNPC(int32_t NpcId, int32_t WeaponId, int32_t Ammo);
    void PutNpcInVehicle(int32_t NpcId, int32_t VehicleId);
    double GetWaterLevel();
    void SetWaterLevel(double Level);
    std::string GetConfigProperty(std::string Section, std::string Property);
    void SpawnVehicle(VehicleSpawnProperties& Props);
    void SetServerName(std::string Name);
    std::string GetServerName();
    std::string GetServerPassword();
    void SetServerPassword(std::string Password);
    std::string GetServerVersion();
    Rotation CreateRotationFromAxes(Vec FwdDirection, Vec RightDirection, Vec UpDirection);
    std::shared_ptr<GameTimer> CreateTimer(int64_t IntervalMs,
                                           bool IsRecurring, std::function<void(GameTimer& Timer)> codeToRun);

    std::shared_ptr<GameTimer> Every(int64_t IntervalMs, std::function<void(GameTimer& Timer)> codeToRun);
    std::shared_ptr<GameTimer> Delay(int64_t IntervalMs, std::function<void(GameTimer& Timer)> codeToRun);
    /*
     * Runs the code on the next server tick, should be used while in the context of a different thread
     * or if you just want to run something on the next server tick
     */
    void MainThread(std::function<void()> codeToRun);

private:
    std::weak_ptr<Registry> Registry;
};
