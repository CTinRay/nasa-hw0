#!/usr/bin/bash

mkdir toolbox
cp magic toolbox
cp crisis toolbox
cp flag5.txt toolbox
touch toolbox/obstacle
tar zcf toolbox.tar.gz toolbox
zip toolbox.zip -P $(cat toolbox-key) toolbox.tar.gz
cp engine /usr/share/challenges
cp toolbox-key /usr/share/challenges
cp toolbox.zip /usr/share/challenges
chmod 444 /usr/share/challenges/*

mkdir /mnt/nasa
chmod 555 /mnt/nasa
chown NASA /mnt/nasa
cp etago /mnt/nasa

mkdir /plane
cp throttle /plane/
