#export LD_LIBRARY_PATH=/opt/daos/prereq/debug/mercury/lib:$LD_LIBRARY_PATH
# gdb --args 05_hg_server_bulk "ofi+tcp://172.17.29.63:55555"
gdb --args 05_hg_server_bulk "ofi+verbs;ofi_rxm://172.17.29.63:55555"
