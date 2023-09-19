# centos7 open HG_HAS_BOOST, yum install -y boost-python36-devel
rm -rf build
mkdir build
cd build
# ccmake ..
cmake ..
make && make install

