#ifndef __DEMON_AGENT__H
#define __DEMON_AGENT__H 

#include "enviro.h"

using namespace enviro;
//! This is a class inheriting from enviro::agent for the robot Demon.
//! Demon is a guard robot in the dungeon, which can move counterclockwise in the fourth floor with very fast speed.
//! Demon can interact with the Player, which when Demon notices collisions with the Player, Demon will remove the Player agent.
class DemonController : public Process, public AgentInterface {

    public:
    DemonController() : Process(), AgentInterface() {}

    void init() {
        notice_collisions_with("Player", [&](Event &e) {
            remove_agent(e.value()["id"]);
        });
    }
    void start() {}
    void update() {
        track_velocity(70,0);
        if (sensor_value(0) < 20) {
            track_velocity(0,-40);
        } else {
            track_velocity(70,0);
        }
    }
    void stop() {}

};

class Demon : public Agent {
    public:
    Demon(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    DemonController c;
};

DECLARE_INTERFACE(Demon)

#endif