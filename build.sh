# centos7 open HG_HAS_BOOST, yum install -y boost-python36-devel
rm -rf build
mkdir build
cd build
# ccmake ..

export OFI_INCLUDE_DIR=/home/xb/project/libfabric/libfabric/build/include
export OFI_LIBRARY=/home/xb/project/libfabric/libfabric/build/lib
cmake ..
make && make install

cd ..
cp mercury/05_bulk/*.sh build/bin/

