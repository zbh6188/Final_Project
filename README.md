# EEP 520 Final_Project Rainbow Dungeon Game
### Baohua Zhu 

# Overview
This project is a maze game created based on Enviro, the multi-agent, multi-user, multi-everything simulator. The goal of this game is for the player to operate his/her robot, to dodge all the dungeon guards in the dungeon, and to find the golden treasure at the deepest center of the rainbow dungeon. 

The wining condition of the player (gold color) is to get to the gold area safely inside the dungeon. Player can use keyboard ("w", "a", "s", "d") to control the direction and movement, and player can also press and hold "b" before pressing direction keys to accelerate. The player has no weapon and needs to dodge all the dungeon guards in the dungeon. The player will die if the player gets caught by one of the dungeon guards.

There are five dungeon guards wandering around in each floor of the dungeon trying to catch the player. The first dungeon guard is called "Rover" (blue color), with small size, wandering around in the first floor with relatively slow speed. The second dungeon guard is called "Ghost" (red color) in the second floor. It has small size and fast speed. The third dungeon guard is called "Monster" (Green color) in the third floor. Monster has very large size but it only can move slowly. The fourth guard is called "Demon" (purple color) in the fourth floor of the dungeon. Demon has extremely fast speed, so be careful. The final guard is the "Boss" (black color), wandering in the fifth floor of the dungeon and protecting the golden treasure. The Boss has large size with very fast speed, and its movement pattern is unpredictable.

This is the overview of the Rainbow Dungeon Game. Be careful dealing with those guards and have fun!

# Key challenges in this project

The first challenge is designing the dungeon. The designing process includes drawing the map on paper, calculating the coordinates of each corner on each wall, and creating the walls using static objects. The second challenge is designing the dungeon guard agents, which includes their moving patterns, unique features, and interaction with the player. I solved this challenge by learning the Virus and Omni examples from Prof. Klavins' enviro repository, and I found out the ways to create clean moving and interaction features. The final challenge is creating the player and responding to the front end events. I solved this challenge by using the `keyup` and `keydown` events for different control keys for the player.

# How to install and run code
1. First, clone this project into your local directory
```
git clone https://github.com/zbh6188/Final_Project.git
```
2. Second, to start the docker image environment, do
```
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.4 bash
esm start
```
3. Third, the -p80:80 option maps port 80 from the Docker container to ports on your host computer, then you can go to
http://localhost with your web browser.

4. Fourth, make the project and start the enviro sever
```
cd Final_Project
make
enviro
```
5. Finally, play the game based on the instructions and have fun!

# How to run and use this project

After you make the project and start the enviro sever, you can start to play the game. Here are some instructions.

### Player controls

w: going upward

a: going right

s: going downward

d: going left

b: accelerate (press and hold "b" and then press direction key (w, a, s, d)

### Win condition

Control the player (gold color robot) to get to the golden treasure (deepest floor in the dungeon with gold wall).

### Loss condition

If you get caught or collide with one of the dungeon guards, you loss.

### Restart the game

If the player was eliminated by the dungeon guard, you can restart the game by doing
```
control (command) c
enviro
```
# Reference

1. enviro example "Virus": https://github.com/klavinslab/enviro.git

2. enviro example "Omni": https://github.com/klavinslab/enviro.git
