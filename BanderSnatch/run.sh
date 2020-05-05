#!/bin/bash
clear
echo "Compiling"
gcc levelchallenges.c levelsgeneral.c gamefunctional.c main.c -o Bandersnatch.exe
./Bandersnatch.exe
