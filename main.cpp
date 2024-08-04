#include "pch.h"
#include "main.h"
#include "events/GeneralEvents.h"
#include "events/ObjectEvents.h"
#include "events/PlayerEvents.h"
#include "events/VehicleEvents.h"
#include "events/ZoneEvents.h"
#include "events/NPCEvents.h"
#include "Registry.h"
#include "entities/Server.h"

ServerFunctions* functions;
ServerCallbacks* events;
ServerInfo* info;


INITIALIZE_EASYLOGGINGPP

static std::thread bt;

extern "C" EXPORT void PluginInit(ServerFunctions* serverFunctions, ServerCallbacks* serverEvents,
                                  ServerInfo* serverInfo)
{
    functions = serverFunctions;
    events = serverEvents;
    info = serverInfo;

    //configure logger
    std::string LoggerConfigPath(info->LaunchPath);
    LoggerConfigPath.append(std::string("logger.conf"));
    el::Configurations conf(LoggerConfigPath);

    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);


    //initialize the registry
    std::shared_ptr<Registry> Reg = std::make_shared<Registry>(serverFunctions);
    std::shared_ptr<Server> server = std::make_shared<Server>(Reg);
    Reg->Server = server;
    GeneralEvents::Setup(Reg, server);
    ObjectEvents::Setup(Reg, server);
    PlayerEvents::Setup(Reg, server);
    VehicleEvents::Setup(Reg, server);
    ZoneEvents::Setup(Reg, server);
    NPCEvents::Setup(Reg, server);

    BindEvents(serverEvents);
    LOG(INFO) << "\033[32m Loaded vicefury-plugin-template \033[0m";

}

void BindEvents(ServerCallbacks* Events)
{
    //GeneralEvents
    Events->OnServerStart = &GeneralEvents::OnServerStart;
    Events->OnServerShutdown = &GeneralEvents::OnServerShutdown;
    Events->OnDataReceived = &GeneralEvents::OnDataReceived;
    Events->OnTick = &GeneralEvents::OnTick;
    Events->OnLowTPS = &GeneralEvents::OnLowTPS;
    //PlayerEvents
    Events->OnPlayerJoin = &PlayerEvents::OnPlayerJoin;
    Events->OnPlayerLeave = &PlayerEvents::OnPlayerLeave;
    Events->OnPlayerCommand = &PlayerEvents::OnPlayerCommand;
    Events->OnPlayerMessage = &PlayerEvents::OnPlayerMessage;
    Events->OnPlayerReceiveDamage = &PlayerEvents::OnPlayerReceiveDamage;
    Events->OnPlayerDied = &PlayerEvents::OnPlayerDied;
    Events->OnPlayerEnterVehicle = &PlayerEvents::OnPlayerEnterVehicle;
    Events->OnPlayerLeaveVehicle = &PlayerEvents::OnPlayerLeaveVehicle;
    Events->OnPlayerRequestSpawn = &PlayerEvents::OnPlayerRequestSpawn;
    Events->OnPlayerSpawn = &PlayerEvents::OnPlayerSpawn;
    Events->OnPlayerSpawnScreenSkinChange = &PlayerEvents::OnPlayerSpawnScreenSkinChange;
    Events->OnPlayerWeaponReceived = &PlayerEvents::OnPlayerWeaponReceived;
    Events->OnPlayerWeaponRemoved = &PlayerEvents::OnPlayerWeaponRemoved;
    Events->OnPlayerStartedSwimming = &PlayerEvents::OnPlayerStartedSwimming;
    Events->OnPlayerStoppedSwimming = &PlayerEvents::OnPlayerStoppedSwimming;
    Events->OnPlayerDivedUnderwater = &PlayerEvents::OnPlayerDivedUnderwater;
    Events->OnPlayerReachedWaterSurface = &PlayerEvents::OnPlayerReachedWaterSurface;
    Events->OnPlayerDowned = &PlayerEvents::OnPlayerDowned;
    Events->OnPlayerRevived = &PlayerEvents::OnPlayerRevived;
    Events->OnPlayerStartedRevive = &PlayerEvents::OnPlayerStartedRevive;
    Events->OnPlayerFailedRevive = &PlayerEvents::OnPlayerFailedRevive;
    //VehicleEvents
    Events->OnVehicleReceiveDamage = &VehicleEvents::OnVehicleReceiveDamage;
    Events->OnVehicleCreated = &VehicleEvents::OnVehicleCreated;
    Events->OnVehicleDestroyed = &VehicleEvents::OnVehicleDestroyed;
    Events->OnVehicleExploded = &VehicleEvents::OnVehicleExploded;
    //NPCEvents
    Events->OnNPCReceiveDamage = &NPCEvents::OnNPCReceiveDamage;
    Events->OnNPCDied = &NPCEvents::OnNPCDied;
    Events->OnNPCLostSightOf = &NPCEvents::OnNPCLostSightOf;
    Events->OnNPCGainedSightOf = &NPCEvents::OnNPCGainedSightOf;
    Events->OnNPCHeardNoise = &NPCEvents::OnNPCHeardNoise;
    Events->OnNPCActionChanged = &NPCEvents::OnNPCActionChanged;
    Events->OnNPCCreated = &NPCEvents::OnNPCCreated;
    Events->OnNPCSpawned = &NPCEvents::OnNPCSpawned;
    Events->OnNPCDestroyed = &NPCEvents::OnNPCDestroyed;
    Events->OnNPCWeaponReceived = &NPCEvents::OnNPCWeaponReceived;
    Events->OnNPCWeaponRemoved = &NPCEvents::OnNPCWeaponRemoved;
    Events->OnNPCEnterVehicle = &NPCEvents::OnNPCEnterVehicle;
    Events->OnNPCLeaveVehicle = &NPCEvents::OnNPCLeaveVehicle;
    Events->OnNPCReachedLocation = &NPCEvents::OnNPCReachedLocation;
    Events->OnNPCEnemyDied = &NPCEvents::OnNPCEnemyDied;
    Events->OnNPCEnemyLeftServer = &NPCEvents::OnNPCEnemyLeftServer;
    Events->OnNPCEnemyEnterVehicle = &NPCEvents::OnNPCEnemyEnterVehicle;
    Events->OnNPCEnemyLeaveVehicle = &NPCEvents::OnNPCEnemyLeaveVehicle;
    Events->OnNPCFollowTargetDied = &NPCEvents::OnNPCFollowTargetDied;
    Events->OnNPCFollowTargetLeftServer = &NPCEvents::OnNPCFollowTargetLeftServer;
    Events->OnNPCFollowTargetEnterVehicle = &NPCEvents::OnNPCFollowTargetEnterVehicle;
    Events->OnNPCFollowTargetLeaveVehicle = &NPCEvents::OnNPCFollowTargetLeaveVehicle;
    Events->OnNPCReachedFollowTarget = &NPCEvents::OnNPCReachedFollowTarget;
    Events->OnNPCRanOutOfAmmo = &NPCEvents::OnNPCRanOutOfAmmo;
    Events->OnNPCIsAboutToAttack = &NPCEvents::OnNPCIsAboutToAttack;
    Events->OnNPCStartedSwimming = &NPCEvents::OnNPCStartedSwimming;
    Events->OnNPCStoppedSwimming = &NPCEvents::OnNPCStoppedSwimming;
    Events->OnNPCDivedUnderwater = &NPCEvents::OnNPCDivedUnderwater;
    Events->OnNPCReachedWaterSurface = &NPCEvents::OnNPCReachedWaterSurface;
    Events->OnNPCDowned = &NPCEvents::OnNPCDowned;
    Events->OnNPCRevived = &NPCEvents::OnNPCRevived;
    Events->OnNPCStartedRevive = &NPCEvents::OnNPCStartedRevive;
    Events->OnNPCFailedRevive = &NPCEvents::OnNPCFailedRevive;
    Events->OnNPCEnemyDowned = &NPCEvents::OnNPCEnemyDowned;
    Events->OnNPCFollowTargetDowned = &NPCEvents::OnNPCFollowTargetDowned;
    //ObjectEvents
    Events->OnObjectCreated = &ObjectEvents::OnObjectCreated;
    Events->OnObjectDestroyed = &ObjectEvents::OnObjectDestroyed;
    Events->OnObjectReceiveDamage = &ObjectEvents::OnObjectReceiveDamage;
    Events->OnObjectTouched = &ObjectEvents::OnObjectTouched;
    Events->OnObjectBroken = &ObjectEvents::OnObjectBroken;
    Events->OnObjectOverlapped = &ObjectEvents::OnObjectOverlapped;
    Events->OnObjectStoppedOverlapping = &ObjectEvents::OnObjectStoppedOverlapping;
    //ZoneEvents
    Events->OnZoneCreated = &ZoneEvents::OnZoneCreated;
    Events->OnZoneDestroyed = &ZoneEvents::OnZoneDestroyed;
    Events->OnZoneEnter = &ZoneEvents::OnZoneEnter;
    Events->OnZoneLeave = &ZoneEvents::OnZoneLeave;
}
