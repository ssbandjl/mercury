#------------------------------------------------------------------------------
# Include source and build directories
#------------------------------------------------------------------------------
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
)

# include_directories(/home/xb/project/libfabric/libfabric/build/include)
# link_directories(/home/xb/project/libfabric/libfabric/build/lib)

#------------------------------------------------------------------------------
# External dependencies
#------------------------------------------------------------------------------
# mercury
find_package(MERCURY REQUIRED)

find_package(Threads REQUIRED)

# Snappy
find_package(SNAPPY)
if(SNAPPY_FOUND)
  message(STATUS "Snappy include directory: ${SNAPPY_INCLUDE_DIR}")
  include_directories(${SNAPPY_INCLUDE_DIR})
else()
  message(STATUS "Could not find Snappy.")
endif()

#------------------------------------------------------------------------------
# Examples
#------------------------------------------------------------------------------
function(build_rpc_example example_name)
  add_executable(hg_example_${example_name} example_rpc.c example_rpc_engine.c example_${example_name}.c)
  target_link_libraries(hg_example_${example_name} PRIVATE Threads::Threads rt mercury)
endfunction()

function(build_bulk bulk_name)
  add_executable(hg_${bulk_name} ${bulk_name}.c)
  target_link_libraries(hg_${bulk_name} PRIVATE Threads::Threads rt mercury)
endfunction()

function(build_snappy_example example_name)
  add_executable(hg_example_${example_name} example_snappy.c example_${example_name}.c)
  target_link_libraries(hg_example_${example_name} PRIVATE Threads::Threads rt mercury ${SNAPPY_LIBRARIES})
endfunction()

build_rpc_example(rpc_client)
build_rpc_example(rpc_server)

build_bulk(bulk_client)
build_bulk(bulk_server)

if(SNAPPY_FOUND)
  build_snappy_example(snappy_client)
  build_snappy_example(snappy_server)
endif()


#bulk
#add_executable(05_hg_server_bulk server.c)
#target_link_libraries(05_hg_server_bulk mercury)

#add_executable(05_hg_client_bulk client.c)
#target_link_libraries(05_hg_client_bulk mercury)