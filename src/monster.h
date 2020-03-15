#ifndef __MONSTER_AGENT__H
#define __MONSTER_AGENT__H 

#include "enviro.h"

using namespace enviro;
//! This is a class inheriting from enviro::agent for the robot Monster.
//! Monster is a guard robot in the dungeon, which can move clockwise in the third floor with slow speed.
//! Monster can interact with the Player, which when Monster notices collisions with the Player, Monster will remove the Player agent.
class MonsterController : public Process, public AgentInterface {

    public:
    MonsterController() : Process(), AgentInterface() {}

    void init() {
        notice_collisions_with("Player", [&](Event &e) {
            remove_agent(e.value()["id"]);
        });
    }
    void start() {}
    void update() {
        track_velocity(10,0);
        if (sensor_value(0) < 15) {
            track_velocity(0,10);
        } else {
            track_velocity(10,0);
        }
        
    }
    void stop() {}

};

class Monster : public Agent {
    public:
    Monster(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    MonsterController c;
};

DECLARE_INTERFACE(Monster)

#endif