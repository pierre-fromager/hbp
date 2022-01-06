#!/bin/bash

g++ \
    src/main.cpp src/ellipsoid.cpp src/node.cpp \
    -g -Werror -Wall -Wextra -Wpedantic -std=c++17 \
    -I./include \
    -o ./test