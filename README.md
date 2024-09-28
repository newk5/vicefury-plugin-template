
# vicefury-plugin-template

This is a C++ project that wraps the ViceFury C API. It's meant to be used as a base to add support for 
new languages or to script gamemodes in C++ instead of using the C API directly. Feel free to clone it and modify it according to your needs or just take whatever parts you need.

It has wrapper classes for all game entities that wrap every function from the C API,
and converts the data types to a more C++ friendly format
(const char* to std::string, uint8 to bool, etc...).
It also contains a logging library and a timer implementation that's compatible with the game server loop
and some nice utilities that allow you to call the ViceFury server API from other threads.

## Building
This project uses C++20, and has been tested on Visual Studio 2022 (v143) on windows. Make is used on Linux with clang, building is just `make build` for release build and `make debug` for debug.

## Project Structure

After compiling this project you should have a .dll/.so file, put this file in the plugins folder on the server root directory and the server will load it and call the the entry point, which is the [main.cpp PluginInit function](./main.cpp). The server calls this function when it starts. In there
 we create the [Registry](./Registry.h) which is responsible for storing all game entities (Players, Npcs, etc...) and managing their lifetime. You should avoid storing instances of game entities globally and should instead use the registry to fetch them when needed, it already has functions to do this which already do multiple checks to ensure thread safety.

The registry is available everywhere in the code, it's available inside the classes for each game entity and in all event classes. If you're adding support for a new language this is where you'd put your language VM/Interface/Bridge.

- [entities folder](./entities)
: Contains classes for all game entities. Players, Npcs, GameObjects, Zones, Vehicles. All these classes inherit from 
[VFEntity](./common/VFEntity.h) which only has two functions that return the type (Player, Vehicle,Npc, etc..) of the entity and its id. All places in the code return instances of these classes in the form of a std::shared_ptr.
If you want to call a certain API function always do it through one of these classes and avoid calling
the C API directly, because all the functions inside these classes have checks to ensure proper thread
safety and with logging already added to every function call to detect errors or incorrect usage.

- [events folder](./events) : Contains "static" classes for each game entity event (Player events, Npc events, etc...).
All these classes already have a `Registry` and a `Server` variable. Use `Registry` to fetch existing game entities and `Server` to call general API functions.
- [ext folder](./ext): Contains external dependencies, currently there's only 1 which is easylogging++

- [common folder](./common/) : Contains common classes, like Vector, Rotation, Transform, etc...


## Threading
Internally the API is not thread safe, which means that you can't use the API from a different thread than the main server thread. Doing so will result in undefined behaviour, the server may crash completely or just lead to memory corruption.
If you absolutely need to access the API from a different thread the [Server instance](./entities/Server.h) provides you with a way to do it, which is as follows:

```cpp
function SomeOtherThread()
{
    //assuming this code is running in a different thread but we have access to the Server instance
    std::string NewServerName = "My new Server";
    Server->SetServerName(NewServerName); //WRONG! this will not work and will show you an error message

    //instead do this:
    Server->MainThread( [Server, NewServerName] {
        //this will run on the next server tick and will run on the main server thread here
         Server->SetServerName(NewServerName);
         LOG(INFO) << "Server name changed to: " << NewServerName;
    });
}
```
## Timers
You can create timers in the following manner:

For recurring timers:
```cpp
    auto t = Server->Every(1000, [](auto Timer)
    {
        LOG(INFO) << "This timer will run every 1 second, indefinitely";
        //the timer instance itself is passed so you can cancel the timer from inside itself
        if (someConditionHere) Timer.Cancel();
    });
    //you can also cancel it from the outside with t->Cancel();
```
For non-recurring timers:

```cpp
    auto t = Server->Delay(2000, [](auto Timer)
    {
        LOG(INFO) << "This timer will run once after 2 seconds and destroy itself";
    });
```
## Examples
Fetching game entities:
```cpp
    //fetching by id
    auto Player1 = Registry->GetPlayer(1);
    if (Player1)
    {
        LOG(INFO) << "Found player " << Player1->GetName();
    }
    //fetching by predicate
    auto player2 = Reg->FindPlayer([](auto& p) { return p.GetName() == "John"; });
    if (Player)
    {
        LOG(INFO) << "Found player named John";
        Player2->SendChatMessage("Hello");
    }
    /*
    those 2 functions exist for all Game entities
    
     Npcs, Vehicles, Zones, GameObjects: 
     Registry->GetVehicle(id) / Registry->FindVehicle 
     Registry->GetNpc(id) / Registry->FindNpc
     
     etc...

     */
```
Sending data to clients:
```cpp
    //find the first player from team 4 that is under water
    auto player = Reg->FindPlayer([](auto& p) { 
        return p.GetTeam() == 4 && p.IsUnderwater();
    });
    if (Player)
    {
        //first param is the channel name
        Player->SendData("statsChannel", "some data here")
    }
```
