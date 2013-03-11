include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(write_data_SRCS
    program_options.cpp
    write_data.cpp)

add_executable(write-data ${write_data_SRCS})

if(UNIX)
    target_link_libraries(write-data)
endif(UNIX)

install(TARGETS write-data DESTINATION bin)
