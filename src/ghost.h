#ifndef __GHOST_AGENT__H
#define __GHOST_AGENT__H 

#include "enviro.h"

using namespace enviro;
//! This is a class inheriting from enviro::agent for the robot Ghost.
//! Ghost is a guard robot in the dungeon, which can move counterclockwise in the second floor with decent speed.
//! Ghost can interact with the Player, which when Ghost notices collisions with the Player, Ghost will remove the Player agent.
class GhostController : public Process, public AgentInterface {

    public:
    GhostController() : Process(), AgentInterface() {}

    void init() {
        notice_collisions_with("Player", [&](Event &e) {
            remove_agent(e.value()["id"]);
        });
    }
    void start() {}
    void update() {
        track_velocity(20,0);
        if (sensor_value(0) < 20) {
            track_velocity(0,-15);
        } else {
            track_velocity(20,0);
        }
        
    }
    void stop() {}

};

class Ghost : public Agent {
    public:
    Ghost(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    GhostController c;
};

DECLARE_INTERFACE(Ghost)

#endif