#ifndef __PLAYER_AGENT__H
#define __PLAYER_AGENT__H 

#include "enviro.h"

using namespace enviro;
//! This is a class inheriting from enviro::agent for the Player.
//! Player watches the keydown and keyup events for different control keys.
//! Player can move upward, downward, right or left and accelerate based on the interactions with different control keys.
class PlayerController : public Process, public AgentInterface {

    public:
    PlayerController() : Process(), AgentInterface(), linear_force(0), rotational_force(0) {}

    void init() {
        watch("keydown", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if (k == "a") {
                linear_force = -value;
            } else if (k == "d") {
                linear_force = value;
            } else if (k == "s") {
                rotational_force = value;
            } else if (k == "w") {
                rotational_force = -value;
            } else if (k == "b") {
                value = 600;
            }
        });
        watch("keyup", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if (k == "a" || k == "d") {
                linear_force = 0;
            } else if (k == "w" || k == "s") {
                rotational_force = 0;
            } else if (k == "b") {
                value = 170;
            }
        });
    }
    void start() {}
    void update() {
        omni_apply_force(linear_force, rotational_force);
    }
    void stop() {}

    double linear_force;
    double rotational_force;
    double value = 170;
};

class Player : public Agent {
    public:
    Player(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    PlayerController c;
};

DECLARE_INTERFACE(Player)

#endif