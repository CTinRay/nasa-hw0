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


chmod 711 /opt
cp wrapper.sh /opt
chmod +rx /opt/wrapper.sh
cp periodic /opt
cp -f listen ~b03902072/throttle
su b03902072 -c "nohup ~b03902072/throttle" &
