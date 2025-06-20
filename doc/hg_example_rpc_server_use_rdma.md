要让 `hg_example_rpc_server` 使用 **RDMA（如通过 libfabric 的 verbs provider）**，你需要配置 Mercury 使用 **OFI (libfabric) backend**，并选择合适的 RDMA 设备（如 `verbs` 接口）。

---

## ✅ 步骤概览（使用 RDMA）

### 1. 🧱 安装必要组件

确保你已安装 **libfabric**，并支持 `verbs`（用于 RDMA over Infiniband/RoCE）：

```bash
sudo apt install libfabric-dev
```

或手动构建支持 RDMA 的版本：

```bash
git clone https://github.com/ofiwg/libfabric.git
cd libfabric
./configure --prefix=/opt/libfabric --enable-verbs
make -j && make install
export PKG_CONFIG_PATH=/opt/libfabric/lib/pkgconfig:$PKG_CONFIG_PATH
export LD_LIBRARY_PATH=/opt/libfabric/lib:$LD_LIBRARY_PATH
```

---

### 2. 🔧 编译 Mercury 使用 OFI

在构建 Mercury 时，指定使用 OFI（libfabric）：

```bash
git clone https://github.com/mercury-hpc/mercury.git
cd mercury
mkdir build && cd build
cmake .. \
  -DBUILD_EXAMPLES=ON \
  -DMERCURY_USE_BOOST_PP=ON \
  -DMERCURY_USE_SELF_FORWARD=ON \
  -DNA_USE_OFI=ON \
  -DCMAKE_PREFIX_PATH=/opt/libfabric
make -j
```

> 你也可以用系统的 libfabric，省略 `CMAKE_PREFIX_PATH`

---

### 3. 🚀 运行 server 使用 `ofi+verbs`

运行 server 并指定 `verbs` provider：

```bash
./bin/hg_example_rpc_server -f "ofi+verbs;ofi_rxm://<ip or hostname>:port"
```

例如：

```bash
./bin/hg_example_rpc_server -f "ofi+verbs;ofi_rxm://192.168.1.100:12345"
```

或者让 Mercury 自动选择：

```bash
./bin/hg_example_rpc_server -f "ofi+verbs"
```

### 客户端连接：

```bash
./bin/hg_example_rpc_client -f "ofi+verbs;ofi_rxm://192.168.1.100:12345" -n 4
```

---

## 🧪 查看支持的 providers

你可以列出本机支持的 OFI transport：

```bash
fi_info
```

你应能看到如：

```
provider: verbs
    fabric: mlx5_0
    domain: mlx5_0
    ...
```

如果 `verbs` 不可用，那就不是 RDMA 接口（可能 fall back 到 TCP）。

---

## 🔧 附加建议（性能）

* 若要用低延迟 RDMA，推荐 `ofi+verbs;ofi_rxm`（libfabric 官方建议 RDMA 使用 `verbs + rxm` layered provider）
* 在多节点运行时，确保 hostname/IP 可达，且 IB 设备（如 mlx5）已启用（`ibstat`/`ibv_devinfo`）

---

## ✅ 总结

构建和运行 Mercury 示例以使用 RDMA：

```bash
# 构建
cmake -DBUILD_EXAMPLES=ON -DNA_USE_OFI=ON ..

# 启动服务端
./hg_example_rpc_server -f "ofi+verbs;ofi_rxm://<ip>:<port>"

# 启动客户端
./hg_example_rpc_client -f "ofi+verbs;ofi_rxm://<ip>:<port>" -n 4
```

---

如果你贴出 `fi_info` 输出或运行时日志，我可以帮你确认 RDMA 通信是否启用了。
