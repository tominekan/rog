#!/bin/sh

# Function to return the exit code of a specific command
return_code() {
    command $1
    echo "Exit Code:" $?
    return $?;
}

RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0;0m'
requirements_are="met"
GCC_EXISTS_CHECK=$(return_code "gcc --version")
echo "This script checks if you have tools required to run rog"
echo "These tools are needed:"
echo "    - gcc >= 8.3.0"
echo "    - make >= 4.3.1"
echo "    - GNU coreutils >= 8.30 (should already be installed)"

echo "You ..."
if [ $GCC_EXISTS_CHECK -ne 0 ]
then
    echo "${RED}    - Don't have gcc ${RESET}"
else
    echo "${GREEN}    - Have gcc ${RESET}"
fi