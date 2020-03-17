#!/bin/bash

clear

echo "Loged in user is : $USER"
echo "Current Shell is : $SHELL"
echo "Home location is : $HOME"
echo "OS type          : $OSTYPE"
echo "Current Path     : $PATH"
echo "Current Working Directory : $PWD"
echo "The Number of users logged in is : $(who | wc -l)"

