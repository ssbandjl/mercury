# centos7 open HG_HAS_BOOST, yum install -y boost-python36-devel
###
 # @Author: xb ssbandjl@163.com
 # @Date: 2023-09-19 08:37:17
 # @LastEditors: xb ssbandjl@163.com
 # @LastEditTime: 2023-09-20 16:08:15
 # @FilePath: /mercury/build.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 
cd build
# ccmake ..

export OFI_INCLUDE_DIR=/home/xb/project/libfabric/libfabric/build/include
export OFI_LIBRARY=/home/xb/project/libfabric/libfabric/build/lib
make && make install

#build example; cd example;make rebuild_cache;make


