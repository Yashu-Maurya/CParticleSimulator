#! /bin/bash

cmake -B build --log-level=VERBOSE && cmake --build build
./build/ParticleSimulator