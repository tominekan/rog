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
echo "This script checks if you have tools required to run rog"
echo "These tools are needed:"
echo "    - gcc (v8.3.0 or greater preferred)"
echo "    - make (v4.2.1 or greater preferred)"
echo "    - GNU coreutils, specifically install (should already be installed)"

echo "You ..."
# Checks if gcc is installed (by seeing if gcc --version works)
$(which gcc)  --version > /dev/null 2> /dev/null
if [ $? -ne 0 ]
then
    echo "${RED}    - Don't have gcc ${RESET}"
else
    echo "${GREEN}    - Have gcc ${RESET}"
fi

# Checks if make is installed (by seeing if make --version works)
$(which make) --version > /dev/null 2> /dev/null
if [ $? -ne 0 ]
then
    echo "${RED}    - Don't have make ${RESET}"
else
    echo "${GREEN}    - Have make ${RESET}"
fi

# Checks if GNU coreutils is installed by checking install,
# the coreutils tool we will be using, since install is 
# a part of the GNU coreutils
$(which install) --version > /dev/null 2> /dev/null
if [ $? -ne 0 ]
then
    echo "${RED}    - Don't have install ${RESET}"
else
    echo "${GREEN}    - Have install ${RESET}"
fi