#!/bin/bash -eu

if [ ! -d build ]; then
  mkdir build
  touch build/.gitkeep
else
  rm -rf build/*
fi

cd build
cmake -DCMAKE_BUILD_TYPE=Debug .. && make
