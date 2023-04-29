# Getting Started

Hello! Welcome to the documentation site for RPL-TASK. The purpose of this project to allow for ease of generation of code files involving tasks and the creation of the tasks themselves.


## __Setup__

Setup is done in a couple of parts. 

1. Set up CMake
	- The first thing that one needs to do is install CMake which can be done from the [Cmake site](https://cmake.org/). You need to be able to use the `cmake` command in order to make the tests as well as build the code.
2. Set up Make
	- Make is a tool to make shortcuts for terminal commands. If you have Windows you will need to find way to run Makefiles. Most other operating systems should be fine.
3. Clone the repository
	- Go to [the repository](https://github.com/rocketproplab/rpl-task) to clone the RPL-Task repository.
3. Test that it works
	- run `make test` in the home directory of the clone repository and if all the tests pass success you're done.
	- If not try and see what the issue is and fix it
4. Learn some GoogleTest
	- This is mainly going to be if you are writing tests, but go to the [GoogleTest Primer](http://google.github.io/googletest/quickstart-cmake.html#prerequisites) to learn about it


## __Preliminaries__

### What is a Task?

A task is what we have defined to be a small simple unit of work. Some quick examples of tasks are:

- Reading data from a magnetic encoder
- Turning a servo motor
- Accuating a solenoid
- Reading data from a serial port

These task are used to build more complex routines. Some examples of tasks could be:

- GpsTask
- ServoValueTask
- AltimeterTask
- IgnitionTask
- Radio Task

### Why do we need Tasks?

Complex codebases are hard to work on. Even if we split the code into multiple files it would still be hard to work on and hard for people to learn. 

A better idea is to split the program into small self contained units of logic that are easy to understand and work with. These small units are the tasks.




## __Project Layout__

This project is broken into three main parts:

1. Task Library
    - The Task Library serves to allow for the easy creation of tasks through the use of interfaces.
    - A benefit is that Tasks are forced to be able to work with other componenets by the interfaces.
2. Organization of Tasks
    - The organization of tasks prevents human error in creating strange dependecies (more on this later).
3. Code Generation
    - Quickly generates code that is easy to understand and human error free

