#pragma once

#ifdef _MSC_VER
#define FUNC_NAME() __FUNCTION__
#else
    #define FUNC_NAME() __func__
#endif

#define THREAD_CHECK_RETURN_INTERNAL(DefaultReturnValue) \
    if (!IsOnMainThread()) \
    { \
        LOG(ERROR) << "\033[31m Attempting to call " << FUNC_NAME() << " On Different thread, You cannot call the Server API from a different thread, server->MainThread([]{ /* your code here */ }); to switch to the main thread \033[0m"; \
        return DefaultReturnValue; \
    }

#define THREAD_CHECK_INTERNAL() \
    if (!IsOnMainThread()) \
    { \
        LOG(ERROR) << "\033[31m Attempting to call " << FUNC_NAME() << " On Different thread, You cannot call the Server API from a different thread, server->MainThread([]{ /* your code here */ }); to switch to the main thread \033[0m"; \
        return; \
    }

#define THREAD_CHECK_RETURN(DefaultReturnValue) \
    if (!REGISTRY->IsOnMainThread()) \
    { \
        LOG(ERROR) << "\033[31m Attempting to call " << FUNC_NAME() << " On Different thread, You cannot call the Server API from a different thread, server->MainThread([]{ /* your code here */ }); to switch to the main thread \033[0m"; \
        return DefaultReturnValue; \
    }

#define THREAD_CHECK() \
    if (!REGISTRY->IsOnMainThread()) \
    { \
        LOG(ERROR) << "\033[31m Attempting to call " << FUNC_NAME() << " On Different thread, You cannot call the Server API from a different thread, server->MainThread([]{ /* your code here */ }); to switch to the main thread \033[0m"; \
        return; \
    }

//some useful macros to auto extract data from the C api when inside Game Entities

#define REGISTRY Registry.lock()
#define API REGISTRY->api
#define SERVER REGISTRY->Server
#define EXTRACT_VEC(FunctionName,EntityName)                                   \
    THREAD_CHECK_RETURN(Vec())                                      \
    double x = -1;                                                 \
    double y = -1;                                                 \
    double z = -1;                                                 \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &x, &y, &z); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    Vec result(x, y, z);

#define EXTRACT_VEC2(FunctionName,EntityName)                                   \
    THREAD_CHECK_RETURN(Vec())                                      \
    double x = -1;                                                 \
    double y = -1;                                                 \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &x, &y); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    Vec result(x, y, 0);

#define EXTRACT_VEC_WITH_ANGLE(FunctionName,EntityName)                                   \
    THREAD_CHECK_RETURN(VecWithAngle())     \
    double x = -1;                                                 \
    double y = -1;                                                 \
    double z = -1;                                                 \
    double yaw = -1;                                                 \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &x, &y, &z, &yaw); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    VecWithAngle result(x, y, z,yaw);

#define EXTRACT_ROT(FunctionName,EntityName)                                   \
    THREAD_CHECK_RETURN(Rotation())     \
    double Yaw = -1;                                                 \
    double Pitch = -1;                                                 \
    double Roll = -1;                                                 \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &Yaw, &Pitch, &Roll); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    Rotation result(Yaw, Pitch, Roll);

#define EXTRACT_BOOL(FunctionName,EntityName)                                   \
    uint8_t out = 0;                                                 \
    THREAD_CHECK_RETURN(false)     \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &out); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    bool result = out ==1;

#define EXTRACT_BOOL_ONE_PARAM(FunctionName,Param1,EntityName)                                   \
    uint8_t out = 0;                                                 \
    THREAD_CHECK_RETURN(false)     \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, Param1, &out); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    bool result = out ==1;

#define EXTRACT_BOOL_TWO_PARAM(FunctionName,Param1,Param2,EntityName)                                   \
    THREAD_CHECK_RETURN(false)     \
    uint8_t out = 0;                                                 \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, Param1,Param2, &out); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    bool result = out ==1;

#define EXTRACT_BOOL_THREE_PARAM(FunctionName,Param1,Param2,Param3,EntityName)                                   \
    THREAD_CHECK_RETURN(false)     \
    uint8_t out = 0;                                                 \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, Param1,Param2,Param3, &out); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    bool result = out ==1;

#define EXTRACT_FLOAT(FunctionName,EntityName)                                   \
    float result = 0;      THREAD_CHECK_RETURN(result)                            \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &result); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    }

#define EXTRACT_FLOAT_ONE_PARAM(FunctionName,Param1,EntityName)                                   \
    float result = 0;        THREAD_CHECK_RETURN(result)                                          \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, Param1,&result); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    }

#define EXTRACT_DOUBLE(FunctionName,EntityName)                                   \
    double result = 0;      THREAD_CHECK_RETURN(result)                                             \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &result); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    }

#define EXTRACT_INT(FunctionName,EntityName)                                   \
    int32_t result = 0;     THREAD_CHECK_RETURN(result)                                              \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &result); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    }

#define EXTRACT_INT_RETURN_PLAYER(FunctionName,EntityName)                                   \
    int32_t result = 0;     THREAD_CHECK_RETURN(nullptr)                                              \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &result); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    return REGISTRY->GetPlayer(result);

#define EXTRACT_INT_RETURN_VEHICLE(FunctionName,EntityName)                                   \
    int32_t result = 0;     THREAD_CHECK_RETURN(nullptr)                                              \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &result); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    return REGISTRY->GetVehicle(result);


#define EXTRACT_INT_ONE_PARAM(FunctionName,Param1,EntityName)                                   \
    int32_t result = 0;    THREAD_CHECK_RETURN(result)                                               \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, Param1, &result); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    }

#define EXTRACT_STRING(FunctionName,EntityName)                                   \
    char* nativeStr = nullptr;    THREAD_CHECK_RETURN("")                                              \
    ViceFuryExitCode ExitCode = Registry.lock()->api->FunctionName(this->Id, &nativeStr); \
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success) { \
        LOG(WARNING) << "\033[33m Error Calling " #FunctionName " - non Existent " #EntityName " entity for ID: " << this->Id << "\033[0m"; \
    } \
    std::string result(nativeStr);
