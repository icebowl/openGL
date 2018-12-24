# openGL
debian

apt install gcc g++
apt install libglfw3 libglfw3-dev
apt install freeglut3 freeglut3-dev


ls /usr/include/ | grep GL
ls /usr/include/GL/

notes:
root@kube:/usr/include# apt install libglfw3 libglfw3-dev
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following additional packages will be installed:
  libdrm-dev libegl1-mesa-dev libgl1-mesa-dev libpthread-stubs0-dev libvulkan-dev libvulkan1 libwayland-bin libwayland-dev libx11-dev libx11-doc libx11-xcb-dev libxau-dev libxcb-dri2-0-dev
  libxcb-dri3-dev libxcb-glx0-dev libxcb-present-dev libxcb-randr0 libxcb-randr0-dev libxcb-render0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-xfixes0-dev libxcb1-dev libxdamage-dev
  libxdmcp-dev libxext-dev libxfixes-dev libxrandr-dev libxrender-dev libxshmfence-dev libxxf86vm-dev mesa-common-dev x11proto-core-dev x11proto-damage-dev x11proto-dri2-dev
  x11proto-fixes-dev x11proto-gl-dev x11proto-input-dev x11proto-kb-dev x11proto-randr-dev x11proto-render-dev x11proto-xext-dev x11proto-xf86vidmode-dev xorg-sgml-doctools xtrans-dev
Suggested packages:
  libxcb-doc libxext-doc
The following NEW packages will be installed:
  libdrm-dev libegl1-mesa-dev libgl1-mesa-dev libglfw3 libglfw3-dev libpthread-stubs0-dev libvulkan-dev libvulkan1 libwayland-bin libwayland-dev libx11-dev libx11-doc libx11-xcb-dev
  libxau-dev libxcb-dri2-0-dev libxcb-dri3-dev libxcb-glx0-dev libxcb-present-dev libxcb-randr0 libxcb-randr0-dev libxcb-render0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-xfixes0-dev
  libxcb1-dev libxdamage-dev libxdmcp-dev libxext-dev libxfixes-dev libxrandr-dev libxrender-dev libxshmfence-dev libxxf86vm-dev mesa-common-dev x11proto-core-dev x11proto-damage-dev
  x11proto-dri2-dev x11proto-fixes-dev x11proto-gl-dev x11proto-input-dev x11proto-kb-dev x11proto-randr-dev x11proto-render-dev x11proto-xext-dev x11proto-xf86vidmode-dev
  xorg-sgml-doctools xtrans-dev
0 upgraded, 47 newly installed, 0 to remove and 0 not upgraded.
Need to get 7,552 kB of archives.
After this operation, 30.1 MB of additional disk space will be used.


apt install freeglut3 freeglut3-dev
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following additional packages will be installed:
  libglu1-mesa-dev libice-dev libsm-dev libxt-dev
Suggested packages:
  libice-doc libsm-doc libxt-doc
The following NEW packages will be installed:
  freeglut3 freeglut3-dev libglu1-mesa-dev libice-dev libsm-dev libxt-dev
0 upgraded, 6 newly installed, 0 to remove and 0 not upgraded.
Need to get 1,028 kB of archives.
After this operation, 3,897 kB of additional disk space will be used.
