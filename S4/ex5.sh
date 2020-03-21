#!/bin/bash

clear

echo -e "\n\nOS DETAILS\n"
cat /etc/os-release
echo -e "\n\nAvailable SHELL\n"
cat /etc/shells
echo -e "\n\nCPU details\n"
cat /proc/cpuinfo
echo -e "\n\nMemory info \n"
cat /proc/meminfo
echo -e "\n\nFile system\n"
cat /proc/mounts
echo -e "\n\nHardDisk INfo"
sudo hdparm -I /dev/sda
echo -e "\n"


