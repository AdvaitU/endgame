# Endgame
A video game demo created by [Advait Ukidve](https://github.com/AdvaitU) and [Mae Horak](https://github.com/mkh7878) for Creative Making: Advanced Visualisation and Computational Environments for the MSc. Creative Computing at UAL CCI.    
<sub>(May 2023)</sub>    
      
### Two Sentence Summary
Endgame is a video game based in a post-apocalyptic fictional London 50 years after the bombs fell in 2019. The game lets you take the control of AI-Football Harold as you navigate a post-nuclear fictional London gathering intelligence from your network of football-AI spy colleagues and report to release the overseer Erik Ten Haag from his long imprisonment in a telephone box.

### Technical Summary
The core idea of Endgame was to explore alternative control systems that tie in to the world of the game and examine how a player's perception adjusts to the affordances of their controls. The game runs using a custom built accelerometer based controller that lets the player assume the role of a ball both in game and in how they control it. The controller is built using an [Adafruit BNO055 9-Axis Absolute Orientation Sensor](https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/overview) connected to an Arduino Leonardo that communicates with [Unreal Engine 5.1](https://www.unrealengine.com/en-US/) real-time over Serial (thanks to [Ramiro Montes De Oca's](https://github.com/videofeedback) [SerialCOM Plugin](https://github.com/videofeedback/Unreal_Engine_SerialCOM_Plugin) for Unreal Engine).

**Link to GitHub:** https://github.com/AdvaitU/endgame

### Video Documentation
- [Game Demonstration and Worldbuilding]()
- [Technical Demonstration - Endgame in Action](https://youtu.be/DlGWNB3HCrw)
- [Technical Documentation and Explanation](https://youtu.be/J3sBT4w4Pwg) (~11 Minutes long)

### For Submission
This project was completed by Advait Ukidve and Mae Horak as a joint effort for the Creative Making: Advanced Visualisation and Computational Environments for the MSc. Creative Computing at UAL CCI. We both worked in various capacities across game design, development, prototyping, asset creation, etc. collaboratively:
**Both:** Unreal Blueprint Design, Worldbuilding, Gameplay Design and Testing
**Advait:** Arduino programming, Level Design, 3D Printing and Prototyping
**Mae:** Sound Design, 3D Asset Creation, 2D Visual Design.


### This Repository
- [Arduino_Code](./Arduino_Code) contains the Arduino code used to carry out the functionality and a README explaining components. 
- The [Gallery](./Gallery/) Folder contains final demonstration images of Endgame
- The [Images](./Images/) Folder contains images used in this readme documenting the process of creating Endgame.
- [UE5.1_Blueprints](./UE5.1_Blueprints/) contains all the important Blueprints in the project as uasset files. These can be opened and reused in Unreal Engine 5.1.
- [AssetAttribution.md](AssetAttribution.md) contains credits to all authors whose wark was used in/learned from for the project.

