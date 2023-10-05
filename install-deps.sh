#!/bin/bash

RED='\033[0;31m'
GRN='\033[0;32m'
NC='\033[0m'


function install {
   if [[ ! -z "$(sudo -v)" ]]; then
      echo -ne "${RED}You do not have sudo privilege on this system${NC}"
      echo -ne "${RED}Please contact system administrator for installation of \"gcc\" and \"gcc-multilib\" ${NC}"
   fi
   sudo apt install $1

}


if [[ -f "/usr/bin/gcc" ]]; then
   echo -ne "DEPENDENCY: gcc            [${GRN}   FOUND   ${NC}]\n"
else
   echo -ne "DEPENDENCY: gcc            [${RED} NOT FOUND ${NC}]\n"
   echo -ne "Installing..."
   install gcc
fi


if [[ -z "$(dpkg -l | grep gcc-multilib)" ]] ; then
   echo -ne "DEPENDENCY: gcc-multilib   [${RED} NOT FOUND ${NC}]\n"
   install gcc-multilib
else
   echo -ne "DEPENDENCY: gcc-multilib   [${GRN}   FOUND   ${NC}]\n"
fi
