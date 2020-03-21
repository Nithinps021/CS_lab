#!/bin/bash

clear

i="y"
echo -e "\nCalculatoR\n"
while [ $i == "y" ]
	do

		echo -e "1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.DIVISION\n5.MODULO DIVISION\n"

		echo -e "Enter the first number"
		read n1
		echo -e "Enter the secound number" 
		read n2

		echo -e "\nSelect an Option "
		read c
		case $c in
			1) echo -e "sum = ` expr $n1 + $n2 ` "
				;;
			2) echo -e "Difference = ` expr $n1 - $n2 `"
				;;
			3) echo -e "Product = ` expr $n1 \* $n2 ` "
				;;
			4) echo -e "Divison = ` expr $n1 / $n2 ` "
				;;
			5) echo -e "Modulo = ` expr $n1 % $n2 `"
				;;	
		esac
		echo -e "\nDo you want to continue (y/n)\n\n"
		read i
	done
