cd build/bin

export HG_LOG_LEVEL=warn

./05_hg_client_bulk "verbs" "ofi+verbs;ofi_rxm://172.17.29.63:55555" ../bulk1m

