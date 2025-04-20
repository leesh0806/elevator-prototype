# elevator-prototype
Simple elevator prototype control with Arduino and LED

## Introduction

### Title
| Name | elevator-prototype using arduino |
|:---|:---|
| Background | Challenges for Periodic Control and Understanding of Various Sequences Using Arduino

### Tech Stack
|Part|Technologies|
|---|---|
|Development<br/>Environment|<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=white"/> <img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=Ubuntu&logoColor=white"/>|
|Language|<img src="https://img.shields.io/badge/-C++-blue?logo=cplusplus"/> 
|Hardware|<img src="https://img.shields.io/badge/Arduino-00878F?logo=arduino&logoColor=fff&style=plastic"/> 
|Collaborative Tools| <img src="https://img.shields.io/badge/slack-4A154B?style=for-the-badge&logo=slack&logoColor=white"/> |

## 0. Research Background

### Understanding and Studying Periodic Control?

While studying Arduino, I thought at first that there would be no problem if I simply put Delay to control the robot's movement, but I was coding it in the wrong way. There is a big disadvantage in that it is impossible to perform other movements at the same time without periodic control. To study periodic control, I did this task by simply simulating an elevator prototype so that I could study why periodic control is necessary and get used to coding for periodic control.

## 1. Conceptual Design

### 1-1. Feature list

| No. | Function | Description |
|:---:|---|---|
|UR_01| Calling | When the button is pressed, Green led and Red led are turned on and start moving for a moment Red led means closing |
|UR_02| Moving | If you move, go to red, yellow, blue and move slowly |
|UR_03| Calling cancel | If you press the button again in the middle, the green will turn off, but the move lead will carry out the mission to the position you pressed before |
|UR_04| Door Open |The door opens when it stays red and then turns blue|


### 1-2. Circuit Diagram

![circuit](https://github.com/user-attachments/assets/acc9f0bd-8d77-4087-86dc-307ee35a80c4)


## 2. Detailed Design (Sequence diagram)

![elevator drawio](https://github.com/user-attachments/assets/81f5a91d-9c05-4b5b-9555-586d8a9e36da)

## 3. Tinkercad Simulation

https://www.tinkercad.com/things/cJN2z4nJCRO-oneday-project

## 4. Testcase

| No. | Case | Check |
|:---:|---|---|
|up_case|||
|UR_01| 1->2->3 | O |
|UR_02| 1 -> 3 | O |
|UR_03| 1 -> 2 | O |
|UR_04| 1 -> 2nd floor canceled -> 2 | O |
|UR_05| 1 -> 2nd floor canceled -> 2 -> 3 | O |
|UR_06| 1 -> 2 -> 3rd floor canceled -> 3 | O |
|UR_07| 1 -> 3rd floor canceled -> 2 ->  3 | O |





















