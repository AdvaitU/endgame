# Endgame
A video game demo created by Advait Ukidve and Mae Horak for Creative Making: Advanced Visualisation and Computational Environments for the MSc. Creative Computing at UAL CCI.    
<sub>(May 2023)</sub>         
      
### Two Sentence Summary
Endgame is a video game based in a post-apocalyptic fictional London 50 years after the bombs fell in 2019. The game lets you take the control of AI-Football Harold as you navigate a post-nuclear fictional London gathering intelligence from your network of football-AI spy colleagues and report to release the overseer Erik Ten Haag from his long imprisonment in a telephone box.

### Technical Summary
The core idea of Endgmae was to explore alternative control systems that tie in to the world of the game and examine how a player's perception adjusts to the affordances of their controls. The game runs using a custom built accelerometer based controller that lets the player assume the role of a ball both in game and in how they control it. The controller is built using an [Adafruit BNO055 9-Axis Absolute Orientation Sensor](https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/overview) connected to an Arduino Leonardo that communicates with [Unreal Engine 5.1](https://www.unrealengine.com/en-US/) real-time over Serial (thanks to [Ramiro Montes De Oca](https://github.com/videofeedback)'s [SerialCOM Plugin](https://github.com/videofeedback/Unreal_Engine_SerialCOM_Plugin) for Unreal Engine).

### Video Documentation
- [Presentation Video]()
- [Controller Testing and Prototyping]()
- [Game Demo and Process]()

### This Repository
- [Arduino_Code]() contains the Arduino code used to carry out the functionality. This includes [Accelerometer.h](), the custom built library for the project, a [Readme.md]() containing attributions, and [accelerometer_test.ino]() containing the final code.
- The Gallery folder contains final demonstration images of Endgame
- The Images Folder contains images used in this readme documenting the process of creating Endgame

# Project Documentation

## The World
### The Idea
### The story
### Building the world visually

## Building the World
### Blocking out the level
### Building the Landscape
### Sourcing Assets
### Tweaking and Twisting
###

## Getting code to do the thing
### Arduino
### Creating the Controller
### Unreal Engine
