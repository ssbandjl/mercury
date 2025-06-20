# include_directories(/opt/daos/prereq/debug/mercury/lib/include)
# link_directories(/opt/daos/prereq/debug/mercury/lib)

include_directories(/usr/local/include)
# include_directories(/home/xb/project/mercury/mercury/05_bulk)
link_directories(/usr/local/lib)

set(CMAKE_C_FLAGS "-g3")

# add_executable(foo ${FOO_SRCS})
# target_link_libraries(foo bar) # libbar.so is found in ${CMAKE_SOURCE_DIR}/lib

add_executable(05_hg_server_bulk server.c)
target_link_libraries(05_hg_server_bulk mercury)

add_executable(05_hg_client_bulk client.c)
target_link_libraries(05_hg_server_bulk mercury)
