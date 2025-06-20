server:
export PATH=/root/project/net/libfabric/build/bin:$PATH
export LD_LIBRARY_PATH=/root/project/rdma/dpu_user_rdma/build/lib
export HUGE_PAGE_NUM=20
export XT_CQ_INLINE_CQE=0
export FI_UNIVERSE_SIZE=16
export FI_LOG_LEVEL=debug
export HG_LOG_LEVEL=debug

fi_info


cd build/bin/
./hg_example_rpc_server -f "ofi+verbs;ofi_rxm://192.168.2.117:12345"


./hg_example_rpc_client "ofi+tcp;ofi_rxm://192.168.1.6:42252" tcp

client:
