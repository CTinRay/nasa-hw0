#!/usr/bin/bash

mkdir toolbox
cp magic toolbox
cp crisis toolbox
cp flag5 toolbox
touch toolbox/obstacle
tar zxf toolbox toolbox.tar.gz
zip toolbox.zip -P $(cat toolbox-key) toolbox.tar.gz
mv toolbox.zip toolbox-key /usr/share/challenges
cp engine /usr/share/challenges

mkdir /mnt/nasa
chmod 555 /mnt/nasa
chown NASA /mnt/nasa
cp etago /mnt/nasa

mkdir /plane
cp throttle /plane/
