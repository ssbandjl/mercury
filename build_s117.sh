git submodule update --init

rm -rf CMakeCache.txt CMakeFiles/

mkdir -p build
cd build

# apt install cmake-curses-gui libjson-c-dev -y

cmake .. -DMERCURY_USE_CHECKSUMS=OFF -DCMAKE_INSTALL_PREFIX=/root/project/net/mercury/build -DBUILD_EXAMPLES=ON -DMERCURY_USE_BOOST_PP=ON -DMERCURY_ENABLE_DEBUG=ON -DBUILD_TESTING=OFF -DNA_USE_OFI=ON -DBUILD_DOCUMENTATION=OFF -DBUILD_SHARED_LIBS=ON -DOFI_INCLUDE_DIR=/root/project/net/libfabric/build/include -DOFI_LIBRARY=/root/project/net/libfabric/build/lib/libfabric.so

# cmake .. -DMERCURY_USE_CHECKSUMS=OFF -DBUILD_EXAMPLES=OFF -DMERCURY_USE_BOOST_PP=ON -DMERCURY_ENABLE_DEBUG=ON -DBUILD_TESTING=OFF -DNA_USE_OFI=ON -DBUILD_DOCUMENTATION=OFF -DBUILD_SHARED_LIBS=ON -DOFI_INCLUDE_DIR=/root/project/net/libfabric/build/include -DOFI_LIBRARY=/root/project/net/libfabric/build/lib/libfabric.so

make -j32
# make install

#build example
cd example
make -j32
make install
