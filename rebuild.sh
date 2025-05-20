# centos7 open HG_HAS_BOOST, yum install -y boost-python36-devel
###
 # @Author: xb ssbandjl@163.com
 # @Date: 2023-09-19 08:37:17
 # @LastEditors: xb ssbandjl@163.com
 # @LastEditTime: 2023-09-19 17:44:11
 # @FilePath: /mercury/build.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 
rm -rf build
mkdir build
cd build
# ccmake ..

# export OFI_INCLUDE_DIR=/home/xb/project/libfabric/libfabric/build/include
# export OFI_LIBRARY=/home/xb/project/libfabric/libfabric/build/lib


cmake -DMERCURY_USE_CHECKSUMS=OFF -DCMAKE_INSTALL_PREFIX=/root/project/net/mercury/build -DBUILD_EXAMPLES=OFF -DMERCURY_USE_BOOST_PP=ON -DMERCURY_ENABLE_DEBUG=ON -DBUILD_TESTING=OFF -DNA_USE_OFI=ON -DBUILD_DOCUMENTATION=OFF -DBUILD_SHARED_LIBS=ON ../mercury -DOFI_INCLUDE_DIR=/opt/daos/prereq/debug/ofi/include -DOFI_LIBRARY=/opt/daos/prereq/debug/ofi/lib/libfabric.so
cmake ..
make && make install

cd ..
cp mercury/05_bulk/*.sh build/bin/

