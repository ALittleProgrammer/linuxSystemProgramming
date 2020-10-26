#!/bin/bash

if [ $# != 1 ]
then
	echo "use: cmd <name>"
else
	echo "hello $1"
fi
exit 0
