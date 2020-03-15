#ifndef __ROVER_AGENT__H
#define __ROVER_AGENT__H 

#include "enviro.h"

using namespace enviro;
//! This is a class inheriting from enviro::agent for the robot Rover.
//! Rover is a guard robot in the dungeon, which can move clockwise in the first floor with slow speed.
//! Rover can interact with the Player, which when Rover notices collisions with the Player, Rover will remove the Player agent.
class RoverController : public Process, public AgentInterface {

    public:
    RoverController() : Process(), AgentInterface() {}

    void init() {
        notice_collisions_with("Player", [&](Event &e) {
            remove_agent(e.value()["id"]);
        });
    }
    void start() {}
    void update() {
        track_velocity(15,0);
        if (sensor_value(0) < 20) {
            track_velocity(0,10);
        } else {
            track_velocity(15,0);
        }
        
    }
    void stop() {}

};

class Rover : public Agent {
    public:
    Rover(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    RoverController c;
};

DECLARE_INTERFACE(Rover)

#endif