#s63
###
 # @Author: xb ssbandjl@163.com
 # @Date: 2023-09-19 16:50:18
 # @LastEditors: xb ssbandjl@163.com
 # @LastEditTime: 2023-09-21 17:23:30
 # @FilePath: /mercury/bulk_s.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 
cd build/bin/

# dd if=/dev/zero of=bulk1m bs=1M count=1 oflag=direct
# 选取第一个激活的网卡, export FI_LOG_LEVEL=debug, export HG_LOG_LEVEL=debug
echo -e "client:./05_hg_client_bulk \"verbs\" \"ofi+verbs;ofi_rxm://172.17.29.63:55555\" bulk1m"
./05_hg_server_bulk "ofi+verbs;ofi_rxm://172.17.29.63:55555" 
# gdb --args 05_hg_server_bulk "ofi+verbs;ofi_rxm://192.169.29.63:55555"



s:
cd buld/bin/
export LD_LIBRARY_PATH=/root/project/rdma/dpu_user_rdma/build/lib
export HUGE_PAGE_NUM=20
export XT_CQ_INLINE_CQE=0
export FI_UNIVERSE_SIZE=16
# export FI_LOG_LEVEL=debug
# unset FI_LOG_LEVEL
# export HG_LOG_LEVEL=debug
# unset HG_LOG_LEVEL
./hg_bulk_server "ofi+verbs;ofi_rxm://192.168.1.11:55555"