#!/bin/bash

set -e

echo === CMAKE ===

cmake -S ./src -B ./out  

mv out/compile_commands.json .

echo === BUILD ===

make -j 16 -C ./out;

echo === RUN ===

./out/lab2

