#delete cmakecache.txt, cmake .
###
 # @Author: xb ssbandjl@163.com
 # @Date: 2023-09-19 08:36:09
 # @LastEditors: xb ssbandjl@163.com
 # @LastEditTime: 2023-09-19 08:58:03
 # @FilePath: /mercury/mercury/05_bulk/build.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 


# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lib64/:/opt/daos/prereq/debug/mercury/lib/:/opt/daos/prereq/debug/mercury/include/
# export C_INCLUDE_PATH=$C_INCLUDE_PATH:/home/xb/project/stor/daos/origin/docker/daos/build/external/debug/mercury.build/src/na:/home/xb/project/stor/daos/origindocker/daos/build/external/debug/mercury.build/src:/home/xb/project/stor/daos/origin/docker/daos/build/external/debug/mercury/src:/home/xb/project/stor/daos/origindocker/daos/build/external/debug/mercury/src/na:/home/xb/project/stor/daos/origin/docker/daos/build/external/debug/mercury/src/util:/home/xb/project/stor/daosorigin/docker/daos/build/external/debug/mercury/src/proc_extra

rm -rf build
mkdir build
cd build
cmake ..
make