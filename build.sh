#!/bin/bash

cd build
cmake configure ..
cmake generate ..
make
cd ..