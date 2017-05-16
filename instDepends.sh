#!/bin/bash
# instDepends.sh
 
echo "install Build Dependencies..."
sudo apt-get update
sudo apt-get -y install build-essential
sudo apt-get -y install nasm
sudo apt-get -y install genisoimage
sudo apt-get -y install bochs
sudo apt-get -y install bochs-sdl

echo "install package for GNU global..."
sudo apt-get -y install curl
sudo apt-get -y install wget
sudo apt-get -y install ncurses-dev
sudo apt-get -y install exuberant-ctags
 
sudo apt-get -y install python
 
CUR=`pwd`
echo "install GNU global..."
wget http://tamacom.com/global/global-6.4.tar.gz
tar zxvf global-6.4.tar.gz
cd global-6.4
./configure
make
sudo make install
cd $CUR
 
echo "install pip..."
sudo apt-get -y install python-pip
 
echo "install pygments..."
sudo pip install pygments==1.6

echo "Cleanup..."
sudo rm -rf global-6.4
sudo rm -rf global-6.4.tar.gz
 
echo "$0 done."
exit 0
