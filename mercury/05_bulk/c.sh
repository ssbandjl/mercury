export LD_LIBRARY_PATH=/opt/daos/prereq/debug/mercury/lib:$LD_LIBRARY_PATH
./05_hg_client "verbs" "ofi+verbs;ofi_rxm://175.16.53.61:55555" bulkdata

