#s63
###
 # @Author: xb ssbandjl@163.com
 # @Date: 2023-09-19 16:50:18
 # @LastEditors: xb ssbandjl@163.com
 # @LastEditTime: 2023-09-19 17:49:12
 # @FilePath: /mercury/bulk_s.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 
cd build/bin/
./05_hg_server_bulk "ofi+verbs;ofi_rxm://192.169.29.63:55555"

# gdb --args 05_hg_server_bulk "ofi+verbs;ofi_rxm://192.169.29.63:55555"