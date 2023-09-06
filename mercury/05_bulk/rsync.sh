ip="182.200.53.62"
ssh root@$ip -C "mkdir -p /home/xb/project/stor/daos/origin/docker/daos/build/external/debug/mercury/mercury/05_bulk"
rsync -ravup /home/xb/project/stor/daos/origin/docker/daos/build/external/debug/mercury/mercury/05_bulk root@$ip:/home/xb/project/stor/daos/origin/docker/daos/build/external/debug/mercury/mercury/