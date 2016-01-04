#!/bin/sh

for l in map/*
	do clear
	echo "$l"	
	./lem-in < "$l"
	sleep 2
done
clear