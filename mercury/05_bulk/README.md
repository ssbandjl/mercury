# scan and build bulk
```bash
Scanning dependencies of target mercury
[ 65%] Building C object src/CMakeFiles/mercury.dir/mercury_proc_bulk.c.o
[ 68%] Building C object src/CMakeFiles/mercury.dir/proc_extra/mercury_string_object.c.o
[ 71%] Building C object src/CMakeFiles/mercury.dir/mercury_core_header.c.o
[ 73%] Building C object src/CMakeFiles/mercury.dir/mercury_proc.c.o
[ 76%] Building C object src/CMakeFiles/mercury.dir/proc_extra/mercury_proc_string.c.o
[ 78%] Building C object src/CMakeFiles/mercury.dir/mercury.c.o
[ 81%] Building C object src/CMakeFiles/mercury.dir/mercury_bulk.c.o
[ 84%] Building C object src/CMakeFiles/mercury.dir/mercury_core.c.o
[ 86%] Building C object src/CMakeFiles/mercury.dir/mercury_header.c.o
[ 89%] Linking C shared library ../bin/libmercury.so


#bulk
add_executable(05_hg_server_bulk server.c)
target_link_libraries(05_hg_server_bulk mercury)

add_executable(05_hg_client_bulk client.c)
target_link_libraries(05_hg_client_bulk mercury)
...
```