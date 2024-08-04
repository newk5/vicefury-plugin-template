#pragma once

#include <unordered_map>
#include <memory>
#include "plugin.h"
#include "UglyMacros.h"



#define MAX_PLAYER_COUNT 100
#define MAX_VEHICLE_COUNT 100
#define MAX_NPC_COUNT 100
#define MAX_OBJECT_COUNT 5000
#define MAX_ZONE_COUNT 5000

class Registry : public std::enable_shared_from_this<Registry>
{
private:
    std::unordered_map<int32_t, std::shared_ptr<class Player>> Players;
    std::unordered_map<int32_t, std::shared_ptr<class Vehicle>> Vehicles;
    std::unordered_map<int32_t, std::shared_ptr<class NPC>> Npcs;
    std::unordered_map<int32_t, std::shared_ptr<class GameObject>> Objects;
    std::unordered_map<int32_t, std::shared_ptr<class Zone>> Zones;
    std::vector<std::shared_ptr<class GameTimer>> Timers ;
   // std::vector<std::function<void()>> Queue;
    std::unique_ptr<MPSCLambdaQueue> Queue;
    std::thread::id ServerThreadId ;
  
public:
    Registry(ServerFunctions* Api);
    bool IsOnMainThread();
  

    ServerFunctions* api=nullptr;
    std::shared_ptr<class Server> Server;

    //add to the queue of functions to run on the main thread
    void AddToQueue(std::function<void()> func);
    void ProcessQueue();
   
    
    //timers
    void AddTimer(std::shared_ptr<GameTimer> Timer);
    void ProcessTimers();

    //when new instances are created
    void RegisterNewPlayer(int32_t Id);
    void RegisterNewVehicle(int32_t Id);
    void RegisterNewNpc(int32_t Id);
    void RegisterNewObject(int32_t Id);
    void RegisterNewZone(int32_t Id);

    //when existing instances are removed/destroyed
    void UnregisterPlayer(int32_t Id);
    void UnregisterVehicle(int32_t Id);
    void UnregisterNpc(int32_t Id);
    void UnregisterObject(int32_t Id);
    void UnregisterZone(int32_t Id);

    //getters
    std::shared_ptr<Player> GetPlayer(int32_t Id);
    std::shared_ptr<Vehicle> GetVehicle(int32_t Id);
    std::shared_ptr<NPC> GetNpc(int32_t Id);
    std::shared_ptr<GameObject> GetGameObject(int32_t Id);
    std::shared_ptr<Zone> GetZone(int32_t Id);
    std::shared_ptr<VFEntity> GetEntity(GameEntity Type, int32_t Id);

    std::shared_ptr<Player> FindPlayer(const std::function<bool(Player&)>& predicate);
    std::shared_ptr<Vehicle> FindVehicle(const std::function<bool(const Vehicle&)>& predicate);
    std::shared_ptr<NPC> FindNpc(const std::function<bool(const NPC&)>& predicate);
    std::shared_ptr<GameObject> FindGameObject(const std::function<bool(const GameObject&)>& predicate);
    std::shared_ptr<Zone> FindZone(const std::function<bool(const Zone&)>& predicate);

    std::vector<std::shared_ptr<Player>> GetAllPlayers();
    std::vector<std::shared_ptr<Vehicle>> GetAllVehicles();
    std::vector<std::shared_ptr<NPC>> GetAllNpcs();
    std::vector<std::shared_ptr<GameObject>> GetAllGameObjects();
    std::vector<std::shared_ptr<Zone>> GetAllZones();
};

