sudo apt-get install build-essential debhelper fakeroot autotools-dev zlib1g-dev python-dev


sh synclibs.sh
sh autogen.sh
sh ./configure --enable-python --enable-static-executables
make
sudo make install
