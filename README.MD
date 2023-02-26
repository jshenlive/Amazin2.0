# Welcome to Your Event Simulator

Created by Jesse Shen, 7909192 for COMP 2150 (OOP) with Olivier Tremblay-Savard
(Assignment 2)

## Introduction
An Event Queue Simulator Created With Object Oriented C++

Currently, supported activities:
* Stores order info from given data file
* Tracks arrival,preparing, and shipping events
* Calculate Profits, Costs and Penalties

## Project Setup
* Make sure all files are in one folder
* Make sure a data file is created with same format as provided in test.txt
  - Each Line consist of data in format as follows
  - `[time] [customerType] [orderValue]`

## Startup
* Type `clang++ *.cpp -std=c++11` to manually compile main program in CLI.
* Type `./a.out [arg1] [arg2]` to manually run main program in CLI. (arg1 for filename.txt, arg2 for number of employees (excluding boss))
* e.g., `./a.out test.txt 1`