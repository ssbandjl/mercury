cd build/bin/
###
 # @Author: xb ssbandjl@163.com
 # @Date: 2023-09-20 11:56:06
 # @LastEditors: xb ssbandjl@163.com
 # @LastEditTime: 2023-09-21 19:22:44
 @FilePath: /mercury/bulk_c.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 
export LD_LIBRARY_PATH=/opt/daos/prereq/debug/mercury/lib:$LD_LIBRARY_PATH

# dd if=/dev/zero of=bulk1m bs=1M count=1 oflag=direct
# cd /home/xb/project/mercury/build/bin; ./05_hg_client_bulk "verbs" "ofi+verbs;ofi_rxm://175.16.53.61:55555" ../bulk1m
# export FI_LOG_LEVEL=debug
./05_hg_client_bulk "verbs" "ofi+verbs;ofi_rxm://172.17.29.63:55555" ../bulk1m



s118:
dd if=/dev/zero of=bulk_file bs=1M count=500 oflag=direct
export LD_LIBRARY_PATH=/root/project/rdma/rdma-core/build/lib
export FI_UNIVERSE_SIZE=16
export FI_LOG_LEVEL=debug
export HG_LOG_LEVEL=debug
./05_hg_client_bulk "verbs" "ofi+verbs;ofi_rxm://192.168.2.117:55555" ./bulk_file
