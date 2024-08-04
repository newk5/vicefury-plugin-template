#include "pch.h"
#include "entities/Player.h"
#include "Registry.h"

#include "common/GameTimer.h"
#include "entities/GameObject.h"
#include "entities/NPC.h"
#include "entities/Vehicle.h"
#include "entities/Zone.h"


Registry::Registry(ServerFunctions* Api)
{
    Players.reserve(MAX_PLAYER_COUNT);
    Vehicles.reserve(MAX_VEHICLE_COUNT);
    Npcs.reserve(MAX_NPC_COUNT);
    Zones.reserve(MAX_ZONE_COUNT);
    Objects.reserve(MAX_OBJECT_COUNT);
    api = Api;
    ServerThreadId = std::this_thread::get_id();
    Queue = std::make_unique<MPSCLambdaQueue>();
}

bool Registry::IsOnMainThread()
{
    return std::this_thread::get_id() == ServerThreadId;
}


void Registry::RegisterNewPlayer(int32_t Id)
{
    Players.emplace(Id, std::make_shared<Player>(Id, shared_from_this()));
}

void Registry::RegisterNewVehicle(int32_t Id)
{
    Vehicles.emplace(Id, std::make_shared<Vehicle>(Id, shared_from_this()));
}

void Registry::RegisterNewNpc(int32_t Id)
{
    Npcs.emplace(Id, std::make_shared<NPC>(Id, shared_from_this()));
}

void Registry::RegisterNewObject(int32_t Id)
{
    Objects.emplace(Id, std::make_shared<GameObject>(Id, shared_from_this()));
}

void Registry::RegisterNewZone(int32_t Id)
{
    Zones.emplace(Id, std::make_shared<Zone>(Id, shared_from_this()));
}

void Registry::UnregisterPlayer(int32_t Id)
{
    Players.erase(Id);
}

void Registry::UnregisterVehicle(int32_t Id)
{
    Vehicles.erase(Id);
}

void Registry::UnregisterNpc(int32_t Id)
{
    Npcs.erase(Id);
}

void Registry::UnregisterObject(int32_t Id)
{
    Objects.erase(Id);
}

void Registry::UnregisterZone(int32_t Id)
{
    Zones.erase(Id);
}

std::shared_ptr<Player> Registry::GetPlayer(int32_t Id)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    auto it = Players.find(Id);
    if (it != Players.end())
    {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<Vehicle> Registry::GetVehicle(int32_t Id)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    auto it = Vehicles.find(Id);
    if (it != Vehicles.end())
    {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<NPC> Registry::GetNpc(int32_t Id)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    auto it = Npcs.find(Id);
    if (it != Npcs.end())
    {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<GameObject> Registry::GetGameObject(int32_t Id)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    auto it = Objects.find(Id);
    if (it != Objects.end())
    {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<Zone> Registry::GetZone(int32_t Id)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    auto it = Zones.find(Id);
    if (it != Zones.end())
    {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<VFEntity> Registry::GetEntity(GameEntity Type, int32_t Id)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    if (Type == GameEntity_Player)
    {
        return GetPlayer(Id);
    }
    else if (Type == GameEntity_Object)
    {
        return GetGameObject(Id);
    }
    else if (Type == GameEntity_Vehicle)
    {
        return GetVehicle(Id);
    }
    else if (Type == GameEntity_Zone)
    {
        return GetZone(Id);
    }
    else if (Type == GameEntity_NPC)
    {
        return GetNpc(Id);
    }
    return nullptr;
}

std::shared_ptr<Player> Registry::FindPlayer(const std::function<bool(Player&)>& predicate)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    for (const auto& pair : Players)
    {
        const auto& playerPtr = pair.second;
        if (playerPtr && predicate(*playerPtr))
        {
            return playerPtr;
        }
    }
    return nullptr;
}

std::shared_ptr<Vehicle> Registry::FindVehicle(const std::function<bool(const Vehicle&)>& predicate)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    for (const auto& pair : Vehicles)
    {
        const auto& instance = pair.second;
        if (instance && predicate(*instance))
        {
            return instance;
        }
    }
    return nullptr;
}

std::shared_ptr<NPC> Registry::FindNpc(const std::function<bool(const NPC&)>& predicate)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    for (const auto& pair : Npcs)
    {
        const auto& instance = pair.second;
        if (instance && predicate(*instance))
        {
            return instance;
        }
    }
    return nullptr;
}

std::shared_ptr<GameObject> Registry::FindGameObject(const std::function<bool(const GameObject&)>& predicate)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    for (const auto& pair : Objects)
    {
        const auto& instance = pair.second;
        if (instance && predicate(*instance))
        {
            return instance;
        }
    }
    return nullptr;
}

std::shared_ptr<Zone> Registry::FindZone(const std::function<bool(const Zone&)>& predicate)
{
    THREAD_CHECK_RETURN_INTERNAL(nullptr)
    for (const auto& pair : Zones)
    {
        const auto& instance = pair.second;
        if (instance && predicate(*instance))
        {
            return instance;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Player>> Registry::GetAllPlayers()
{
    std::vector<std::shared_ptr<Player>> lst(Players.size());
    THREAD_CHECK_RETURN_INTERNAL(lst);
    lst.reserve(Players.size());
    size_t index = 0;
    for (const auto& pair : Players)
    {
        lst[index++] = pair.second;
    }
    return lst;
}

std::vector<std::shared_ptr<Vehicle>> Registry::GetAllVehicles()
{
    std::vector<std::shared_ptr<Vehicle>> lst(Vehicles.size());
    THREAD_CHECK_RETURN_INTERNAL(lst);
    lst.reserve(Vehicles.size());
    size_t index = 0;
    for (const auto& pair : Vehicles)
    {
        lst[index++] = pair.second;
    }
    return lst;
}

std::vector<std::shared_ptr<NPC>> Registry::GetAllNpcs()
{
    std::vector<std::shared_ptr<NPC>> lst(Npcs.size());
    THREAD_CHECK_RETURN_INTERNAL(lst);
    lst.reserve(Npcs.size());
    size_t index = 0;
    for (const auto& pair : Npcs)
    {
        lst[index++] = pair.second;
    }
    return lst;
}

std::vector<std::shared_ptr<GameObject>> Registry::GetAllGameObjects()
{
    std::vector<std::shared_ptr<GameObject>> lst(Objects.size());
    THREAD_CHECK_RETURN_INTERNAL(lst);
    lst.reserve(Objects.size());
    size_t index = 0;
    for (const auto& pair : Objects)
    {
        lst[index++] = pair.second;
    }
    return lst;
}

std::vector<std::shared_ptr<Zone>> Registry::GetAllZones()
{
    std::vector<std::shared_ptr<Zone>> lst(Zones.size());
    THREAD_CHECK_RETURN_INTERNAL(lst);
    lst.reserve(Zones.size());
    size_t index = 0;
    for (const auto& pair : Zones)
    {
        lst[index++] = pair.second;
    }
    return lst;
}


//queues
void Registry::AddToQueue(std::function<void()> func)
{
    Queue->Enqueue(std::move(func));
}

void Registry::ProcessQueue()
{
    for (auto& Task : Queue->GetAll())
    {
        Task();
    }
}

//timers
void Registry::AddTimer(std::shared_ptr<GameTimer> Timer)
{
    THREAD_CHECK_INTERNAL();
    Timers.emplace_back(Timer);
}

void Registry::ProcessTimers()
{
    if (Timers.empty()) return;
    auto it = Timers.begin();
    while (it != Timers.end())
    {
        auto& timer = *it;

        if (timer->ShouldRun())
        {
            timer->Process();
        }
        if (timer->IsPendingCancellation() || timer->HasExpired())
        {
            it = Timers.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
