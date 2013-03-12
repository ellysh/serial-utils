include_directories(${COMMON_INCLUDE_DIRS})
link_directories(${COMMON_LIBDIR})

set(write_data_SRCS
    data_parser.cpp
    program_options.cpp
    write_data.cpp)

add_executable(write-data ${write_data_SRCS})

if(UNIX)
    target_link_libraries(write-data serial ${Boost_LIBRARIES})
endif(UNIX)

install(TARGETS write-data DESTINATION /usr/bin)


set(read_data_SRCS
    data_parser.cpp
    program_options.cpp
    read_data.cpp)

add_executable(read-data ${read_data_SRCS})

if(UNIX)
    target_link_libraries(read-data serial ${Boost_LIBRARIES})
endif(UNIX)

install(TARGETS read-data DESTINATION /usr/bin)


set(read_async_SRCS
    data_parser.cpp
    program_options.cpp
    read_async.cpp)

add_executable(read-async ${read_async_SRCS})

if(UNIX)
    target_link_libraries(read-async serial ${Boost_LIBRARIES})
endif(UNIX)

install(TARGETS read-async DESTINATION /usr/bin)


set(write_read_SRCS
    data_parser.cpp
    program_options.cpp
    write_read.cpp)

add_executable(write-read ${write_read_SRCS})

if(UNIX)
    target_link_libraries(write-read serial ${Boost_LIBRARIES})
endif(UNIX)

install(TARGETS write-read DESTINATION /usr/bin)
