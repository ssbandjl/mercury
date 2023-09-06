include_directories(/opt/daos/prereq/debug/mercury/lib/include)
link_directories(/opt/daos/prereq/debug/mercury/lib)

set(CMAKE_C_FLAGS "-g3")

# add_executable(foo ${FOO_SRCS})
# target_link_libraries(foo bar) # libbar.so is found in ${CMAKE_SOURCE_DIR}/lib

add_executable(05_hg_server server.c)
target_link_libraries(05_hg_server mercury)

add_executable(05_hg_client client.c)
target_link_libraries(05_hg_client mercury)
