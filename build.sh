# open HG_HAS_BOOST, yum install boost-devel -y, 
rm -rf build
mkdir build
cd build
# ccmake ..
cmake ..
make && make install

