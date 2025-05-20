# Mercury Note

## fi_getinfo
```c
(gdb) bt
#0  fi_getinfo_ (version=0, node=0x0, service=0x0, flags=0, hints=0x0, info=0x0) at src/fabric.c:1322
#1  0x00007ffff7d2953f in na_ofi_getinfo (prov_type=prov_type@entry=NA_OFI_PROV_TCP, info=info@entry=0x0, fi_info_p=fi_info_p@entry=0x7fffffffd9c8) at /root/project/net/mercury/src/na/na_ofi.c:3591
#2  0x00007ffff7d316f2 in na_ofi_check_protocol (protocol_name=<optimized out>) at /root/project/net/mercury/src/na/na_ofi.c:7597
#3  0x00007ffff7d20cb5 in na_plugin_check_protocol (class_ops=0x7ffff7d52930 <na_plugin_static_g>, ops_p=<synthetic pointer>, protocol_name=<optimized out>, class_name=<optimized out>) at /root/project/net/mercury/src/na/na.c:472
#4  NA_Initialize_opt2 (info_string=info_string@entry=0x555555556066 "tcp://:12345", listen=<optimized out>, version=version@entry=393216, na_init_info=na_init_info@entry=0x0) at /root/project/net/mercury/src/na/na.c:885
#5  0x00007ffff7f7f896 in hg_core_init (na_info_string=<optimized out>, na_listen=<optimized out>, version=<optimized out>, hg_init_info_p=<optimized out>, class_p=<optimized out>) at /root/project/net/mercury/src/mercury_core.c:1342
#6  0x00007ffff7f8828e in HG_Core_init_opt2 (na_info_string=na_info_string@entry=0x555555556066 "tcp://:12345", na_listen=na_listen@entry=1 '\001', version=version@entry=0, hg_init_info=hg_init_info@entry=0x0)
    at /root/project/net/mercury/src/mercury_core.c:6083
#7  0x00007ffff7f74e6c in HG_Init_opt2 (na_info_string=na_info_string@entry=0x555555556066 "tcp://:12345", na_listen=na_listen@entry=1 '\001', version=version@entry=0, hg_init_info_p=hg_init_info_p@entry=0x0)
    at /root/project/net/mercury/src/mercury.c:1088
#8  0x00007ffff7f74fd1 in HG_Init (na_info_string=na_info_string@entry=0x555555556066 "tcp://:12345", na_listen=na_listen@entry=1 '\001') at /root/project/net/mercury/src/mercury.c:1027
#9  0x00005555555559f6 in hg_engine_init (listen=<optimized out>, local_addr=0x555555556066 "tcp://:12345") at /root/project/net/mercury/Examples/src/example_rpc_engine.c:36
#10 0x000055555555545b in main () at /root/project/net/mercury/Examples/src/example_rpc_server.c:22
```


## ofi cleanup monitor
```c
libfabric.so.1!ofi_monitor_cleanup(struct ofi_mem_monitor * monitor) (\root\project\net\libfabric\prov\util\src\util_mem_monitor.c:154)
libfabric.so.1!ofi_monitors_cleanup() (\root\project\net\libfabric\prov\util\src\util_mem_monitor.c:341)
libfabric.so.1!fi_fini() (\root\project\net\libfabric\src\fabric.c:1034)
ld-linux-x86-64.so.2!_dl_fini() (\build\glibc-FcRMwW\glibc-2.31\elf\dl-fini.c:138)
libc.so.6!__run_exit_handlers(int status, struct exit_function_list ** listp, _Bool run_list_atexit, _Bool run_dtors) (\build\glibc-FcRMwW\glibc-2.31\stdlib\exit.c:108)
libc.so.6!__GI_exit(int status) (\build\glibc-FcRMwW\glibc-2.31\stdlib\exit.c:139)
libc.so.6!__libc_start_main(int (*)(int, char **, char **) main, int argc, char ** argv, int (*)(int, char **, char **) init, void (*)(void) fini, void (*)(void) rtld_fini, void * stack_end) (\build\glibc-FcRMwW\glibc-2.31\csu\libc-start.c:342)
_start() (\root\project\net\mercury\Examples\src\example_rpc_client.c:57)

dddddddddd```