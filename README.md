# Emotive-Robot-Companion
Emotive Robot Companion. The robot Ada is capable of responding by movement to simple keywords from the users, using two separate aspects. The first is a speech recognition algorithm, using **Machine Learning** on an Arduino Nano 33 BLE Sense as the cognitive side, built on [Edge Impulse](https://www.edgeimpulse.com/). The second is to use this Arduino chip to control a **physical robot**, known under the name of Otto, able to move around accordingly to what was understood.

For more, check our [demo](https://www.youtube.com/watch?v=UjGXaB7CqaM)!

Report [here](https://github.com/blobquiet/Emotive-Robot-Companion-CIR/blob/main/Ada_Emotive_Robot_Companion.pdf).

## What's on this repo?

```
   Arduino folder -> two .ino files with the code of the physical cognitive part of the robot
   Dataset folder -> two folders with training and test vocal samples of 1s each for every class.
   Evaluation folder -> t_test.py and pdf folder with questionnaires.
   nn folder -> The neural network architecture int nn_architecture.py
```

## Dataset download

The dataset compressed with about 150Mb can be downloaded [here](https://drive.google.com/file/d/1sX5JTAqtWuOeFYqJr-ih8VvcjP6tFRPC/view?usp=sharing).

## Basic circuit

Ada's on-board circuit

​	<img src="https://github.com/blobquiet/Emotive-Robot-Companion-CIR/blob/main/images/circuit.png" width="500">	
​                                                                                   *Source (circuito.io)*

###### Ada says bye!

![fall](https://github.com/blobquiet/Emotive-Robot-Companion-CIR/blob/main/images/fall.gif)

