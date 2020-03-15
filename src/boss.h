#ifndef __BOSS_AGENT__H
#define __BOSS_AGENT__H 

#include "enviro.h"

using namespace enviro;
//! This is a class inheriting from enviro::agent for the robot Boss.
//! Boss is a guard robot in the dungeon, which can move clockwise in the final floor with very fast speed.
//! Boss can interact with the Player, which when Boss notices collisions with the Player, Boss will remove the Player agent.
class BossController : public Process, public AgentInterface {

    public:
    BossController() : Process(), AgentInterface() {}

    void init() {
        notice_collisions_with("Player", [&](Event &e) {
            remove_agent(e.value()["id"]);
        });
    }
    void start() {}
    void update() {
        track_velocity(100,0);
        if (sensor_value(0) < 20) {
            track_velocity(0,70);
        } else {
            track_velocity(100,0);
        }
    }
    void stop() {}

};

class Boss : public Agent {
    public:
    Boss(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    BossController c;
};

DECLARE_INTERFACE(Boss)

#endif