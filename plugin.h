#pragma once
#include <stdint.h>
#include <stdlib.h>

/* ENUMS */

typedef enum
{
	ZoneType_Blocking = 1,
	ZoneType_Mesh = 2,
	ZoneType_Sphere = 3
} ZoneType;

typedef enum
{
	NPCType_Zombie = 1,
	NPCType_Shooter = 2
} NPCType;

typedef enum
{
	NPCMovementMode_Walking = 1,
	NPCMovementMode_Running = 2
} NPCMovementMode;

typedef enum
{
	DamageSource_Undefined = -1,
	DamageSource_Weapon = 0,
	DamageSource_Vehicle = 1,
	DamageSource_Explosion = 2,
	DamageSource_Script = 3
} DamageSource;

typedef enum
{
	GameEntity_Undefined = 0,
	GameEntity_Player = 1,
	GameEntity_Vehicle = 2,
	GameEntity_NPC = 3,
	GameEntity_Object = 4,
	GameEntity_Zone = 5
} GameEntity;

typedef enum
{
	NPCShooterAttackStrategy_Static = 0,
	NPCShooterAttackStrategy_Moveable = 1,
	NPCShooterAttackStrategy_Evasive = 2
} NPCShooterAttackStrategy;

typedef enum
{
	AttachResult_Success = 0,
	AttachResult_Error_FailedToFindSocket = 1,
	AttachResult_Error_FailedToFindSourceEntity = 2,
	AttachResult_Error_FailedToFindTargetEntity = 3,
	AttachResult_Error_InvalidEntityType = 4,
	AttachResult_Error_CannotAttach = 5,
	AttachResult_Error_AlreadyAttached = 6
} AttachResult;

typedef enum
{
	ViceFuryExitCode_Success = 0,
	ViceFuryExitCode_Error_NoExistingEntity = 1
} ViceFuryExitCode;

typedef enum
{
	NPCAction_None = 0,
	NPCAction_Attacking = 1,
	NPCAction_Investigating = 2,
	NPCAction_MovingToTarget = 3,
	NPCAction_MovingToLocation = 4,
	NPCAction_Following = 5,
	NPCAction_MovingToReviveTarget = 6,
	NPCAction_RevivingOther = 7
} NPCAction;

/* STRUCTS */

typedef struct
{
	uint8_t NPCType;
	uint8_t NPCSubType;
	double SpawnX;
	double SpawnY;
	double SpawnZ;
	double SpawnYawAngle;
} NPCSpawnProperties;

typedef struct
{
	uint8_t ModelID;
	double SpawnX;
	double SpawnY;
	double SpawnZ;
	double SpawnPitch;
	double SpawnYaw;
	double SpawnRoll;
} VehicleSpawnProperties;

typedef struct
{
	int32_t ModelID;
	double SpawnX;
	double SpawnY;
	double SpawnZ;
	double SpawnPitch;
	double SpawnYaw;
	double SpawnRoll;
	uint8_t WithCollision;
	uint8_t Damageable;
} ObjectSpawnProperties;


typedef struct
{
	ZoneType Type;
	double SpawnX;
	double SpawnY;
	double SpawnZ;
	double SpawnYaw;
	double SpawnPitch;
	double SpawnRoll;
	double SizeX;
	double SizeY;
	double Height;
	int32_t Color;
} ZoneSpawnProperties;

typedef struct
{
	DamageSource DamageSource;
	GameEntity DamagedBy;
	float DamageToApply;
	int32_t DamagedById;
	int32_t DamageSourceId;
} DamageEvent;

typedef struct
{
	char* Name;
	char* Bone;
	double RelativeX;
	double RelativeY;
	double RelativeZ;
	double RelativeYaw;
	double RelativeRoll;
	double RelativePitch;
} EntitySocket;

typedef struct
{
	int32_t MAJOR;
	int32_t MINOR;
	int32_t PATCH;
	const char* LaunchPath;
} ServerInfo;

/* FUNCTIONS */

typedef struct
{
	/* Server */
	void (*SendChatMessageToAll) (uint32_t Color, const char* Text);
	void (*SendChatMessageToPlayer) (int32_t PlayerId, const char* Text, uint32_t Color);
	uint8_t(*PlayerExists) (int32_t PlayerId);
	uint8_t(*NPCExists) (int32_t PlayerId);
	uint8_t(*VehicleExists) (int32_t VehicleId);
	int32_t(*SpawnNPC) (NPCSpawnProperties Props);
	void (*SendData) (int32_t PlayerId, const char* Channel, const char* Text);
	uint8_t(*GetRandomPoint) (double OriginX, double OriginY, double OriginZ, double Radius, double* OutX, double* OutY,
		double* OutZ);
	void (*FindRotationLookingAt) (double FromX, double FromY, double FromZ, double ToX, double ToY, double ToZ, double* OutYaw, double* OutPitch, double* OutRoll);
	void (*FindDirectionLookingAt) (double FromX, double FromY, double FromZ, double ToX, double ToY, double ToZ, double* OutX, double* OutY, double* OutZ);
	void (*SetSpawnScreenLocation) (double X, double Y, double Z, double YawLookAt);
	int32_t(*SpawnObject) (ObjectSpawnProperties Props);
	void (*CreateEntitySocket) (GameEntity EntityType, EntitySocket Socket);
	void (*SetTime) (float Time);
	float (*GetTime) ();
	int32_t(*SpawnZone) (ZoneSpawnProperties Props);
	void (*SetLowTPSWarningLimit) (int32_t Limit);
	int32_t(*GetServerTPS) ();
	void (*SpawnWeapon) (int32_t WeaponId, double X, double Y, double Z, int32_t Ammo);
	void (*GiveWeaponToPlayer) (int32_t WeaponId, int32_t PlayerId, int32_t Ammo);
	void (*GiveWeaponToShooterNPC) (int32_t NpcId, int32_t WeaponId, int32_t Ammo);
	void (*PutNpcInVehicle) (int32_t NpcId, int32_t VehicleId);
	void (*GetWaterLevel) (double* OutLevel);
	void (*SetWaterLevel) (double Level);
	void (*GetConfigProperty) (const char* Section, const char* PropertyName, char** OutResult);
	int32_t(*SpawnVehicle) (VehicleSpawnProperties SpawnProps);
	void (*SetServerName) (const char* Name);
	char* (*GetServerName) ();
	char* (*GetServerPassword) ();
	void (*SetServerPassword) (const char* Password);
	char* (*GetServerVersion) ();
	void (*CreateRotationFromAxes) (double ForwardX, double ForwardY, double ForwardZ, double RightX, double RightY, double RightZ, double UpX, double UpY, double UpZ, double* OutYaw, double* OutPitch, double* OutRoll);

	/* Player  */
	ViceFuryExitCode(*GetPlayerPing) (int32_t PlayerId, int32_t* OutResult);
	ViceFuryExitCode(*GetPlayerIP) (int32_t PlayerId, char** IPOut);
	ViceFuryExitCode(*GetPlayerName) (int32_t PlayerId, char** NameOut);
	ViceFuryExitCode(*GetPlayerPosition) (int32_t PlayerId, double* OutX, double* OutY, double* OutZ);
	ViceFuryExitCode(*GetPlayerForwardVector) (int32_t PlayerId, double* OutX, double* OutY, double* OutZ);
	ViceFuryExitCode(*GetPlayerRightVector) (int32_t PlayerId, double* OutX, double* OutY, double* OutZ);
	void (*SetPlayerPosition) (int32_t PlayerId, double XPos, double YPos, double ZPos);
	ViceFuryExitCode(*GetPlayerYawAngle) (int32_t PlayerId, double* OutAngle);
	void (*SetPlayerYawAngle) (int32_t PlayerId, double YawAngle);
	ViceFuryExitCode(*GetPlayerHealth) (int32_t PlayerId, float* OutHealth);
	ViceFuryExitCode(*GetPlayerArmour) (int32_t PlayerId, float* OutArmour);
	void (*SetPlayerHealth) (int32_t PlayerId, float Health);
	ViceFuryExitCode(*GetPlayerMovementSpeed) (int32_t PlayerId, float* OutMovementSpeed);
	void (*SetPlayerArmour) (int32_t PlayerId, float Armour);
	ViceFuryExitCode(*PlayerIsShooting) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsRunning) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsWalking) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsCrouched) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsDriving) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsPassenger) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsStandingOnVehicle) (int32_t PlayerId, int32_t VehicleId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsFalling) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsReloading) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsKnocked) (int32_t PlayerId, uint8_t* OutResult);
	void (*SetPlayerTeam) (int32_t PlayerId, int32_t Team);
	ViceFuryExitCode(*GetPlayerTeam) (int32_t PlayerId, int32_t* OutTeam);
	void (*SetPlayerColor) (int32_t PlayerId, int32_t TeamColor);
	ViceFuryExitCode(*GetPlayerColor) (int32_t PlayerId, int32_t* OutTeamColor);
	void (*SetPlayerSpawnpoint) (int32_t PlayerId, double XPos, double YPos, double ZPos, double YawAngle);
	ViceFuryExitCode(*GetPlayerSpawnpoint) (int32_t PlayerId, double* OutX, double* OutY, double* OutZ, double* OutYaw);
	ViceFuryExitCode(*PlayerIsSpawned) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*GetPlayerSkin) (int32_t PlayerId, int32_t* OutResult);
	void (*PlayerDetachAllObjects) (int32_t PlayerId);
	ViceFuryExitCode(*GetPlayerBoneNames) (int32_t PlayerId, char** OutBoneNames);
	ViceFuryExitCode(*GetPlayerMoveDirection) (int32_t PlayerId, double* OutYaw);
	ViceFuryExitCode(*PlayerHasObjectAttached) (int32_t PlayerId, int32_t ObjectId, uint8_t* OutResult);
	void (*KickPlayer) (int32_t PlayerId, const char* Reason);
	void (*PlayerDetachObject) (int32_t PlayerId, int32_t ObjectId);
	ViceFuryExitCode(*PlayerHasWeapon) (int32_t PlayerId, int32_t WeaponId, uint8_t* OutResult);
	void (*LaunchPlayer) (int32_t PlayerId, double DirectionX, double DirectionY, double DirectionZ, double Force, uint8_t Additive);
	ViceFuryExitCode(*GetPlayerUpVector) (int32_t PlayerId, double* OutX, double* OutY, double* OutZ);
	ViceFuryExitCode(*GetPlayerWeaponDamage) (int32_t PlayerId, int32_t WeaponId, float* OutWeaponDmg);
	void (*SetPlayerWeaponDamage) (int32_t PlayerId, int32_t WeaponId, float WeaponDmg);
	ViceFuryExitCode(*GetPlayerWeaponRange) (int32_t PlayerId, int32_t WeaponId, float* OutWeaponRange);
	void (*SetPlayerWeaponRange) (int32_t PlayerId, int32_t WeaponId, float WeaponRange);
	void (*KeepPlayerWeaponsOnRespawn) (int32_t PlayerId, uint8_t Status);
	void (*SetPlayerStoredWeaponAmmo) (int32_t PlayerId, int32_t WeaponId, int32_t Ammo);
	ViceFuryExitCode(*GetPlayerStoredWeaponAmmo) (int32_t PlayerId, int32_t WeaponId, int32_t* OutAmmo);
	void (*RemovePlayerWeapon) (int32_t PlayerId, int32_t WeaponId);
	void (*EnablePlayerFreeCam) (int32_t PlayerId);
	void (*DisablePlayerFreeCam) (int32_t PlayerId);
	void (*SpectatePlayer) (int32_t PlayerId, int32_t TargetId);
	void (*StopSpectating) (int32_t PlayerId);
	ViceFuryExitCode(*PlayerIsSpectating) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*IsSpectatingPlayer) (int32_t PlayerId, int32_t TargetId, uint8_t* OutResult);
	ViceFuryExitCode(*GetSpectateTarget) (int32_t PlayerId, int32_t* OutResult);
	ViceFuryExitCode(*PlayerIsSwimming) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsUnderwater) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerCanBeRevived) (int32_t PlayerId, uint8_t* OutResult);
	void (*SetPlayerCanBeRevived) (int32_t PlayerId, uint8_t Status);
	ViceFuryExitCode(*PlayerIsAwaitingRevive) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*GetPlayerReviveWaitTime) (int32_t PlayerId, float* OutSeconds);
	void (*SetPlayerReviveWaitTime) (int32_t PlayerId, float Seconds);
	ViceFuryExitCode(*GetPlayerReviveDuration) (int32_t PlayerId, float* OutSeconds);
	void (*SetPlayerReviveDuration) (int32_t PlayerId, float Seconds);
	ViceFuryExitCode(*GetPlayerAwaitingReviveHP) (int32_t PlayerId, float* OutHP);
	void (*SetPlayerAwaitingReviveHP) (int32_t PlayerId, float HP);
	ViceFuryExitCode(*GetPlayerHPWhenRevived) (int32_t PlayerId, float* OutHP);
	void (*SetPlayerHPWhenRevived) (int32_t PlayerId, float HP);
	void (*RevivePlayer) (int32_t PlayerId);
	void (*DownPlayer) (int32_t PlayerId);
	ViceFuryExitCode(*PlayerIsBeingRevived) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsBeingRevivedBy) (int32_t PlayerId, GameEntity CharType, int32_t CharId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsRevivingSomeone) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*PlayerIsRevivingCharacter) (int32_t PlayerId, GameEntity CharType, int32_t CharId, uint8_t* OutResult);
	void (*EnablePlayerFreeCamWithDisabledControls) (int32_t PlayerId);
	void (*EnablePlayerFreeCamWithTransformAndDisableControls) (int32_t PlayerId, double XPos, double YPos, double ZPos, double Yaw, double Pitch, double Roll);
	void (*EnablePlayerFreeCamWithDisabledControlsAndInterpTo) (int32_t PlayerId, double XPos, double YPos, double ZPos, double Yaw, double Pitch, double Roll, double Speed);
	void (*SetPlayerFreeCamTransform) (int32_t PlayerId, double XPos, double YPos, double ZPos, double Yaw, double Pitch, double Roll);
	void (*AllowAccessToRemotePlayerData) (int32_t PlayerId);
	void (*AllowAccessToRemoteVehicleData) (int32_t PlayerId);
	void (*AllowAccessToRemoteNPCData) (int32_t PlayerId);
	void (*AllowAccessToRemoteObjectData) (int32_t PlayerId);
	void (*DisallowAccessToRemotePlayerData) (int32_t PlayerId);
	void (*DisallowAccessToRemoteVehicleData) (int32_t PlayerId);
	void (*DisallowAccessToRemoteNPCData) (int32_t PlayerId);
	void (*DisallowAccessToRemoteObjectData) (int32_t PlayerId);
	ViceFuryExitCode(*HasAccessToRemotePlayerData) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*HasAccessToRemoteVehicleData) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*HasAccessToRemoteObjectData) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*HasAccessToRemoteNPCData) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*GetFreeCamRotation) (int32_t PlayerId, double* OutYaw, double* OutPitch, double* OutRoll);
	ViceFuryExitCode(*GetFreeCamPosition) (int32_t PlayerId, double* OutX, double* OutY, double* OutZ);
	ViceFuryExitCode(*GetFreeCamDirection) (int32_t PlayerId, double* OutX, double* OutY, double* OutZ);
	void (*InterpFreeCamTo) (int32_t PlayerId, double XPos, double YPos, double ZPos, double Yaw, double Pitch, double Roll, double Speed);
	ViceFuryExitCode(*GetPlayerVehicle) (int32_t PlayerId, int32_t* OutVehicleId);

	/* NPC */
	ViceFuryExitCode(*GetNpcType) (int32_t NpcId, int32_t* TypeOut);
	ViceFuryExitCode(*GetNpcRespawnDelay) (int32_t NpcId, float* DelayOut);
	void (*SetNpcRespawnDelay) (int32_t NpcId, float Delay);
	ViceFuryExitCode(*GetNpcMaxHealth) (int32_t NpcId, float* HealthOut);
	void (*SetNpcMaxHealth) (int32_t NpcId, float HP);
	ViceFuryExitCode(*GetNpcHealth) (int32_t NpcId, float* HealthOut);
	void (*SetNpcHealth) (int32_t NpcId, float HP);
	void (*NpcAttack) (int32_t NpcId, GameEntity GameEntityType, int32_t TargetId);
	ViceFuryExitCode(*GetNpcMovementSpeed) (int32_t NpcId, float* SpeedOut);
	void (*SetNpcMovementSpeed) (int32_t NpcId, float Speed);
	ViceFuryExitCode(*GetNpcPosition) (int32_t NpcId, double* OutX, double* OutY, double* OutZ);
	void (*SetNpcPosition) (int32_t NpcId, double XPos, double YPos, double ZPos);
	ViceFuryExitCode(*NpcHasAutoRespawnEnabled) (int32_t NpcId, uint8_t* EnabledOut);
	void (*NpcEnableAutoRespawn) (int32_t NpcId);
	void (*NpcDisableAutoRespawn) (int32_t NpcId);
	ViceFuryExitCode(*GetNpcSightAngle) (int32_t NpcId, float* AngleOut);
	void (*SetNpcSightAngle) (int32_t NpcId, float Angle);
	ViceFuryExitCode(*GetNpcSightDistance) (int32_t NpcId, float* DistanceOut);
	void (*SetNpcSightDistance) (int32_t NpcId, float Distance);
	ViceFuryExitCode(*GetNpcHearingDistance) (int32_t NpcId, float* DistanceOut);
	void (*SetNpcHearingDistance) (int32_t NpcId, float Distance);
	void (*NpcRespawn) (int32_t NpcId);
	void (*SetNpcSpawnpoint) (int32_t NpcId, double XPos, double YPos, double ZPos, double YawAngle);
	ViceFuryExitCode(*GetNpcSpawnpoint) (int32_t NpcId, double* OutX, double* OutY, double* OutZ, double* OutYaw);
	void (*SetNpcYawAngle) (int32_t NpcId, double Yaw);
	ViceFuryExitCode(*GetNpcYawAngle) (int32_t NpcId, double* YawOut);
	ViceFuryExitCode(*IsWithinLineOfSightOfNpc) (int32_t EntID, GameEntity Ent, int32_t EntId, uint8_t* ResultOut);
	ViceFuryExitCode(*GetNpcAction) (int32_t NpcId, NPCAction* ActionOut);
	void (*AddNpcFriend) (int32_t NpcId, GameEntity Ent, int32_t EntId);
	void (*RemoveNpcFriend) (int32_t NpcId, GameEntity Ent, int32_t EntId);
	void (*NpcMoveToLocation) (int32_t NpcId, double XPos, double YPos, double ZPos);
	void (*MoveNpcToLocation) (int32_t NpcId, double XPos, double YPos, double ZPos, const char* Loc);
	void (*NpcInvestigate) (int32_t NpcId, float Radius);
	void (*NpcInvestigateLocation) (int32_t NpcId, double XPos, double YPos, double ZPos, float Radius);
	ViceFuryExitCode(*GetNpcForwardVector) (int32_t NpcId, double* OutX, double* OutY, double* OutZ);
	ViceFuryExitCode(*GetNpcRightVector) (int32_t NpcId, double* OutX, double* OutY, double* OutZ);
	void (*DestroyNpc) (int32_t NpcId);
	void (*DetachAllNpcObjects) (int32_t NpcId);
	ViceFuryExitCode(*GetNpcBoneNames) (int32_t NpcId, char** OutBoneNames);
	ViceFuryExitCode(*NpcCanMoveTo) (int32_t NpcId, double XPos, double YPos, double ZPos, uint8_t* OutResult);
	ViceFuryExitCode(*GetNpcMoveDirection) (int32_t NpcId, double* OutYaw);
	ViceFuryExitCode(*NpcHasObjectAttached) (int32_t NpcId, int32_t ObjectId, uint8_t* OutResult);
	void (*NpcDetachObject) (int32_t NpcId, int32_t ObjectId);
	ViceFuryExitCode(*NpcIsFriendly) (int32_t NpcId, GameEntity Ent, int32_t EntID, uint8_t* OutResult);
	ViceFuryExitCode(*GetNpcTeam) (int32_t NpcId, int32_t* OutTeam);
	void (*SetNpcTeam) (int32_t NpcId, int32_t Team);
	ViceFuryExitCode(*GetNpcShooterAccuracy) (int32_t NpcId, double* OutAccuracy);
	void (*SetNpcShooterAccuracy) (int32_t NpcId, double Accuracy);
	ViceFuryExitCode(*GetNpcShooterWalkSpeed) (int32_t NpcId, float* OutSpeed);
	void (*SetNpcShooterWalkSpeed) (int32_t NpcId, float OutSpeed);
	ViceFuryExitCode(*GetNpcShooterRunSpeed) (int32_t NpcId, float* OutSpeed);
	void (*SetNpcShooterRunSpeed) (int32_t NpcId, float OutSpeed);
	ViceFuryExitCode(*NpcHasWeapon) (int32_t NpcId, int32_t WeaponId, uint8_t* OutResult);
	void (*RemoveNpcWeapon) (int32_t NpcId, int32_t WeaponId);
	void (*SwitchNpcWeapon) (int32_t NpcId, int32_t WeaponId);
	void (*RemoveNpcFromVehicle) (int32_t NpcId);
	void (*NpcStartShooting) (int32_t NpcId, double DirectionX, double DirectionY, double DirectionZ);
	void (*NpcStopShooting) (int32_t NpcId);
	ViceFuryExitCode(*NpcIsShooting) (int32_t NpcId, uint8_t* Out);
	ViceFuryExitCode(*GetNpcTargetLocation) (int32_t NpcId, char** OutLocation);
	void (*SetNpcAcceptanceRadius) (int32_t NpcId, float Radius);
	ViceFuryExitCode(*GetNpcAcceptanceRadius) (int32_t NpcId, float* OutRadius);
	void (*SetNpcMovementMode) (int32_t NpcId, NPCMovementMode Mode);
	ViceFuryExitCode(*GetNpcMovementMode) (int32_t NpcId, NPCMovementMode* OutMode);
	void (*NpcFollow) (int32_t NpcId, GameEntity GameEntityType, int32_t TargetId);
	ViceFuryExitCode(*GetNpcFollowTarget) (int32_t NpcId, GameEntity* OutEntityType, int32_t* OutEntityId);
	ViceFuryExitCode(*GetNpcEnemy) (int32_t NpcId, GameEntity* OutEntityType, int32_t* OutEntityId);
	void (*LaunchNpc) (int32_t NpcId, double DirectionX, double DirectionY, double DirectionZ, double Force, uint8_t Additive);
	ViceFuryExitCode(*GetNpcArmour) (int32_t NpcId, float* ArmourOut);
	void (*SetNpcArmour) (int32_t NpcId, float Armour);
	ViceFuryExitCode(*GetNpcNameTag) (int32_t NpcId, char** OutNameTag);
	void (*SetNpcNameTag) (int32_t NpcId, const char* Text);
	void (*SetNpcColor) (int32_t NpcId, int32_t TeamColor);
	ViceFuryExitCode(*GetNpcColor) (int32_t NpcId, int32_t* OutTeamColor);
	ViceFuryExitCode(*GetNpcAttackStrategy) (int32_t NpcId, NPCShooterAttackStrategy* OutStrategy);
	void (*SetNpcAttackStrategy) (int32_t NpcId, NPCShooterAttackStrategy Strategy);
	void (*NpcStopMoving) (int32_t NpcId);
	ViceFuryExitCode(*NpcIsMoving) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsMovingToLocation) (int32_t NpcId, const char* Text, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsInvestigating) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsBeingFollowedByNpc) (int32_t NpcId, int32_t TargetNpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsBeingAttackedByNpc) (int32_t NpcId, int32_t TargetNpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsBeingFollowedByNpcs) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsBeingAttackedByNpcs) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsRunning) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsFalling) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*IsNpcNameTagVisible) (int32_t NpcId, uint8_t* OutResult);
	void (*ShowNpcNameTag) (int32_t NpcId);
	void (*HideNpcNameTag) (int32_t NpcId);
	ViceFuryExitCode(*NpcIsOnTheGround) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsInVehicle) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*GetNpcUpVector) (int32_t NpcId, double* OutX, double* OutY, double* OutZ);
	ViceFuryExitCode(*GetNpcVehicle) (int32_t NpcId, int32_t* OutVehicleId);
	ViceFuryExitCode(*GetNpcWeaponDamage) (int32_t NpcId, int32_t WeaponId, float* OutWeaponDmg);
	void (*SetNpcWeaponDamage) (int32_t NpcId, int32_t WeaponId, float WeaponDmg);
	ViceFuryExitCode(*GetNpcWeaponRange) (int32_t NpcId, int32_t WeaponId, float* OutWeaponRange);
	void (*SetNpcWeaponRange) (int32_t NpcId, int32_t WeaponId, float WeaponRange);
	void (*KeepNpcWeaponsOnRespawn) (int32_t NpcId, uint8_t status);
	void (*SetNpcStoredWeaponAmmo) (int32_t PlayerId, int32_t WeaponId, int32_t Ammo);
	ViceFuryExitCode(*GetNpcStoredWeaponAmmo) (int32_t PlayerId, int32_t WeaponId, int32_t* OutAmmo);
	void (*EnableNpcAvoidance) (int32_t NpcId);
	void (*DisableNpcAvoidance) (int32_t NpcId);
	ViceFuryExitCode(*NpcHasAvoidanceEnabled) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsSwimming) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsUnderwater) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcCanBeRevived) (int32_t NpcId, uint8_t* OutResult);
	void (*SetNpcCanBeRevived) (int32_t NpcId, uint8_t Status);
	ViceFuryExitCode(*NpcIsAwaitingRevive) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*GetNpcReviveWaitTime) (int32_t NpcId, float* OutSeconds);
	void (*SetNpcReviveWaitTime) (int32_t NpcId, float Seconds);
	ViceFuryExitCode(*GetNpcReviveDuration) (int32_t NpcId, float* OutSeconds);
	void (*SetNpcReviveDuration) (int32_t NpcId, float Seconds);
	ViceFuryExitCode(*GetNpcAwaitingReviveHP) (int32_t NpcId, float* OutHP);
	void (*SetNpcAwaitingReviveHP) (int32_t NpcId, float HP);
	ViceFuryExitCode(*GetNpcHPWhenRevived) (int32_t NpcId, float* OutHP);
	void (*SetNpcHPWhenRevived) (int32_t NpcId, float HP);
	void (*ReviveNpc) (int32_t NpcId);
	void (*DownNpc) (int32_t NpcId);
	void (*NpcReviveCharacter) (int32_t NpcId, GameEntity CharType, int32_t CharId);
	ViceFuryExitCode(*NpcIsBeingRevived) (int32_t NpcId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsBeingRevivedBy) (int32_t NpcId, GameEntity CharType, int32_t CharId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsRevivingSomeone) (int32_t PlayerId, uint8_t* OutResult);
	ViceFuryExitCode(*NpcIsRevivingCharacter) (int32_t PlayerId, GameEntity CharType, int32_t CharId, uint8_t* OutResult);
	ViceFuryExitCode(*GetNpcSubtype) (int32_t NpcId, int32_t* OutSubtype);


	/* Vehicle */
	ViceFuryExitCode(*GetVehicleDriver) (int32_t VehicleId, int32_t* OutPlayerId);
	void (*DestroyVehicle) (int32_t VehicleId);
	ViceFuryExitCode(*GetVehicleHealth) (int32_t VehicleId, float* OutHealth);
	void (*SetVehicleHealth) (int32_t VehicleId, float Health);
	ViceFuryExitCode(*GetVehiclePosition) (int32_t VehicleId, double* OutX, double* OutY, double* OutZ);
	void (*SetVehiclePosition) (int32_t VehicleId, double XPos, double YPos, double ZPos);
	ViceFuryExitCode(*VehicleIsPassenger) (int32_t VehicleId, GameEntity EntType, int32_t EntId, uint8_t* OutResult);
	ViceFuryExitCode(*VehicleIsExploded) (int32_t VehicleId, uint8_t* OutResult);
	ViceFuryExitCode(*GetVehicleSpawnpoint) (int32_t VehicleId, double* OutX, double* OutY, double* OutZ, double* OutYaw,
		double* OutPitch, double* OutRoll);
	void (*SetVehicleSpawnPoint) (int32_t VehicleId, double XPos, double YPos, double ZPos, double Yaw, double Pitch, double Roll);
	ViceFuryExitCode(*GetVehicleRotation) (int32_t VehicleId, double* OutYaw, double* OutPitch, double* OutRoll);
	void (*SetVehicleRotation) (int32_t VehicleId, double Yaw, double Pitch, double Roll);
	void (*SetVehicleTransform) (int32_t VehicleId, double XPos, double YPos, double ZPos, double Yaw, double Pitch, double Roll);
	void (*VehicleDetachAllObjects) (int32_t VehicleId);
	ViceFuryExitCode(*GetVehicleBoneNames) (int32_t VehicleId, char** OutBoneNames);
	ViceFuryExitCode(*GetVehicleMoveDirection) (int32_t VehicleId, double* OutYaw);
	ViceFuryExitCode(*VehicleHasObjectAttached) (int32_t VehicleId, int32_t ObjectId, uint8_t* OutResult);
	void (*VehicleDetachObject) (int32_t VehicleId, int32_t ObjectId);

	/* Object */
	ViceFuryExitCode(*GameObjectIsDamageable) (int32_t ObjectId, uint8_t* OutResult);
	ViceFuryExitCode(*GameObjectHasCollision) (int32_t ObjectId, uint8_t* OutResult);
	ViceFuryExitCode(*GameObjectHasTouchEventsEnabled) (int32_t ObjectId, uint8_t* OutResult);
	ViceFuryExitCode(*GetGameObjectHealth) (int32_t ObjectId, double* OutResult);
	ViceFuryExitCode(*GetGameObjectName) (int32_t ObjectId, char** NameOut);
	void (*SetGameObjectTouchEventsEnabled) (int32_t ObjectId, uint8_t Value);
	void (*SetGameObjectHealth) (int32_t ObjectId, double Value);
	ViceFuryExitCode(*GetGameObjectModelId) (int32_t ObjectId, int32_t* OutResult);
	ViceFuryExitCode(*GetGameObjectPosition) (int32_t ObjectId, double* OutX, double* OutY, double* OutZ);
	void (*SetGameObjectPosition) (int32_t ObjectId, double XPos, double YPos, double ZPos);
	ViceFuryExitCode(*GetGameObjectRotation) (int32_t ObjectId, double* OutYaw, double* OutPitch, double* OutRoll);
	void (*SetGameObjectRotation) (int32_t ObjectId, double Yaw, double Pitch, double Roll);
	void (*SetGameObjectTransform) (int32_t ObjectId, double XPos, double YPos, double ZPos, double Yaw, double Pitch,
		double Roll);
	AttachResult(*AttachGameObjectToEntity) (int32_t ObjectId, GameEntity EntityType, int32_t EntityId, const char* SocketName);
	ViceFuryExitCode(*GameObjectIsAttached) (int32_t ObjectId, uint8_t* OutResult);
	ViceFuryExitCode(*GameObjectGetAttachedEntity) (int32_t ObjectId, GameEntity* GameEntityType, int32_t* EntityId);
	void (*GameObjectDetach) (int32_t ObjectId);
	void (*DestroyGameObject) (int32_t ObjectId);
	void (*SetGameObjectCollisionEnabled) (int32_t ObjectId, uint8_t Value);
	ViceFuryExitCode(*GameObjectIsBroken) (int32_t ObjectId, uint8_t* OutResult);
	void (*GameObjectRestore) (int32_t ObjectId);
	void (*SetGameObjectRestoreAfterBreaking) (int32_t ObjectId, uint8_t Value);
	void (*SetGameObjectRestoreAfterBreakingDelay) (int32_t ObjectId, float Value);
	ViceFuryExitCode(*GameObjectIsBreakable) (int32_t ObjectId, uint8_t* OutResult);
	void (*SetGameObjectShowHealthBarWhenDamaged) (int32_t ObjectId, uint8_t Value);
	void (*SetGameObjectDamageable) (int32_t ObjectId, uint8_t Value);
	void (*SetGameObjectVisible) (int32_t ObjectId, uint8_t Value);
	ViceFuryExitCode(*GameObjectIsVisible) (int32_t ObjectId, uint8_t* OutResult);
	void (*SetGameObjectOverlapEventsEnabled) (int32_t ObjectId, uint8_t Value);
	ViceFuryExitCode(*GameObjectHasOverlapEventsEnabled) (int32_t ObjectId, uint8_t* OutResult);
	ViceFuryExitCode(*GameObjectIsOverlapping) (int32_t ObjectId, GameEntity GameEntityTypeType, int32_t EntityId, uint8_t* OutResult);

	/* Zone */
	void (*SetZoneTransform) (int32_t ZoneId, double XPos, double YPos, double ZPos, double Yaw, double Pitch, double Roll);
	ViceFuryExitCode(*GetZoneTransform) (int32_t ZoneId, double* OutX, double* OutY, double* OutZ, double* OutYaw, double* OutPitch, double* OutRoll);
	ViceFuryExitCode(*ZoneIsVisible) (int32_t ZoneId, uint8_t* OutResult);
	void (*SetZoneVisible) (int32_t ZoneId, uint8_t Status);
	void (*DestroyZone) (int32_t ZoneId);
	void (*SetZoneColor) (int32_t ZoneId, int32_t Color);
	void (*SetZoneHeight) (int32_t ZoneId, double Height);
	void (*SetZoneSize) (int32_t ZoneId, double SizeX, double SizeY);
	ViceFuryExitCode(*GetZoneSize) (int32_t ZoneId, double* OutSizeX, double* OutSizeY);
	ViceFuryExitCode(*IsPointInsideZone) (int32_t ZoneId, double X, double Y, uint8_t* Result);
	void (*SetZoneStyle) (int32_t ZoneId, int32_t Style);
	ViceFuryExitCode(*GetZoneStyle) (int32_t ZoneId, int32_t* OutResult);
	ViceFuryExitCode(*ZoneOverlapEventsEnabled) (int32_t ZoneId, uint8_t* OutResult);
	void (*SetZoneOverlapEventsEnabled) (int32_t ZoneId, uint8_t Status);
	ViceFuryExitCode(*IsPointInsideZoneSphere) (int32_t ZoneId, double XPos, double YPos, double ZPos, uint8_t* Result);
	AttachResult(*AttachZoneToEntity) (int32_t ZoneId, GameEntity EntityType, int32_t EntityId, const char* SocketName);
	ViceFuryExitCode(*ZoneGetAttachedEntity) (int32_t ZoneId, GameEntity* GameEntityType, int32_t* EntityId);
	ViceFuryExitCode(*ZoneIsAttached) (int32_t ZoneId, uint8_t* OutResult);
	void (*DetachZone) (int32_t ZoneId);
	void (*SetZoneCircleShape) (int32_t ZoneId, uint8_t Status);
	ViceFuryExitCode(*ZoneIsCircleShaped) (int32_t ZoneId, uint8_t* OutResult);

} ServerFunctions;

/* EVENTS */

typedef struct
{
	/* Server */
	void (*OnServerStart) (void);
	void (*OnServerShutdown) (void);
	void (*OnDataReceived) (int32_t PlayerId, const char* Channel, const char* Data);
	void (*OnTick) (void);
	void (*OnLowTPS) (int32_t Limit, int32_t Current);
	/* Player */
	void (*OnPlayerJoin) (int32_t PlayerId);
	void (*OnPlayerLeave) (int32_t PlayerId);
	void (*OnPlayerCommand) (int32_t PlayerId, const char* Message);
	uint8_t(*OnPlayerMessage) (int32_t PlayerId, const char* Message);
	float (*OnPlayerReceiveDamage) (int32_t PlayerId, DamageEvent Event);
	void (*OnPlayerDied) (int32_t PlayerId, DamageEvent Event);
	void (*OnPlayerEnterVehicle) (int32_t PlayerId, int32_t VehicleID, uint8_t AsDriver);
	void (*OnPlayerLeaveVehicle) (int32_t PlayerId, int32_t VehicleID, uint8_t AsDriver);
	uint8_t(*OnPlayerRequestSpawn) (int32_t PlayerId);
	void (*OnPlayerSpawn) (int32_t PlayerId);
	void (*OnPlayerSpawnScreenSkinChange) (int32_t PlayerId, int32_t SkinId);
	void (*OnPlayerWeaponReceived) (int32_t PlayerId, int32_t WeaponId, uint8_t Equipped);
	void (*OnPlayerWeaponRemoved) (int32_t PlayerId, int32_t WeaponId, uint8_t Equipped);
	void (*OnPlayerStartedSwimming) (int32_t PlayerId);
	void (*OnPlayerStoppedSwimming) (int32_t PlayerId);
	void (*OnPlayerDivedUnderwater) (int32_t PlayerId);
	void (*OnPlayerReachedWaterSurface) (int32_t PlayerId);
	void (*OnPlayerDowned) (int32_t PlayerId, GameEntity EntityType, int32_t EntityId);
	void (*OnPlayerRevived) (int32_t PlayerId, GameEntity EntityType, int32_t EntityId);
	void (*OnPlayerStartedRevive) (int32_t PlayerId, GameEntity EntityType, int32_t EntityId);
	void (*OnPlayerFailedRevive) (int32_t PlayerId, GameEntity EntityType, int32_t EntityId);

	/* Vehicle */
	float (*OnVehicleReceiveDamage) (int32_t VehicleId, DamageEvent Event);
	void (*OnVehicleCreated) (int32_t VehicleId);
	void (*OnVehicleDestroyed) (int32_t VehicleId);
	void (*OnVehicleExploded) (int32_t VehicleId);

	/* NPC */
	float (*OnNPCReceiveDamage) (int32_t NpcId, DamageEvent Event);
	void (*OnNPCDied) (int32_t NpcId, DamageEvent Event);
	void (*OnNPCLostSightOf) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCGainedSightOf) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCHeardNoise) (int32_t NpcId, double XPos, double YPos, double ZPos);
	void (*OnNPCActionChanged) (int32_t NpcId, NPCAction oldAction, NPCAction newAction);
	void (*OnNPCCreated) (int32_t NpcId, NPCType Type);
	void (*OnNPCSpawned) (int32_t NpcId);
	void (*OnNPCDestroyed) (int32_t NpcId);
	void (*OnNPCWeaponReceived) (int32_t NpcId, int32_t WeaponId, uint8_t Equipped);
	void (*OnNPCWeaponRemoved) (int32_t NpcId, int32_t WeaponId, uint8_t Equipped);
	void (*OnNPCEnterVehicle) (int32_t NpcId, int32_t VehicleId);
	void (*OnNPCLeaveVehicle) (int32_t NpcId, int32_t VehicleId);
	void (*OnNPCReachedLocation) (int32_t NpcId, const char* location);
	void (*OnNPCEnemyDied) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCEnemyLeftServer) (int32_t NpcId, int32_t PlayerId);
	void (*OnNPCEnemyEnterVehicle) (int32_t NpcId, GameEntity EntityType, int32_t EntityId, int32_t VehicleID, uint8_t AsDriver);
	void (*OnNPCEnemyLeaveVehicle) (int32_t NpcId, GameEntity EntityType, int32_t EntityId, int32_t VehicleID, uint8_t AsDriver);
	void (*OnNPCFollowTargetDied) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCFollowTargetLeftServer) (int32_t NpcId, int32_t PlayerId);
	void (*OnNPCFollowTargetEnterVehicle) (int32_t NpcId, GameEntity EntityType, int32_t EntityId, int32_t VehicleID, uint8_t AsDriver);
	void (*OnNPCFollowTargetLeaveVehicle) (int32_t NpcId, GameEntity EntityType, int32_t EntityId, int32_t VehicleID, uint8_t AsDriver);
	void (*OnNPCReachedFollowTarget) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCRanOutOfAmmo) (int32_t NpcId, int32_t Weapon);
	void (*OnNPCIsAboutToAttack) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCStartedSwimming) (int32_t NpcId);
	void (*OnNPCStoppedSwimming) (int32_t NpcId);
	void (*OnNPCDivedUnderwater) (int32_t NpcId);
	void (*OnNPCReachedWaterSurface) (int32_t NpcId);
	void (*OnNPCDowned) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCRevived) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCStartedRevive) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCFailedRevive) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCEnemyDowned) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);
	void (*OnNPCFollowTargetDowned) (int32_t NpcId, GameEntity EntityType, int32_t EntityId);

	/* GameObject */
	void (*OnObjectCreated) (int32_t ObjectId);
	void (*OnObjectDestroyed) (int32_t ObjectId);
	float (*OnObjectReceiveDamage) (int32_t ObjectId, DamageEvent Event);
	void (*OnObjectTouched) (int32_t ObjectId, GameEntity GameEntityType, int32_t GameEntityID);
	void (*OnObjectBroken) (int32_t ObjectId);
	void (*OnObjectOverlapped) (int32_t ObjectId, GameEntity GameEntityType, int32_t GameEntityID);
	void (*OnObjectStoppedOverlapping) (int32_t ObjectId, GameEntity GameEntityType, int32_t GameEntityID);

	/* Zone */
	void (*OnZoneCreated) (int32_t ZoneId, ZoneType Type);
	void (*OnZoneDestroyed) (int32_t ZoneId);
	void (*OnZoneEnter) (int32_t ZoneId, GameEntity GameEntityType, int32_t GameEntityID);
	void (*OnZoneLeave) (int32_t ZoneId, GameEntity GameEntityType, int32_t GameEntityID);
} ServerCallbacks;
