cmake_minimum_required(VERSION 3.10)
project(Low_latency_HPC)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "/opt/homebrew/opt/boost")
find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS} include)


add_executable(feed_handler
    src/main.cpp
    src/FeedReceiver.cpp
    # src/Dispatcher.cpp
    # src/Utils.cpp
)


target_link_libraries(feed_handler PRIVATE ${Boost_LIBRARIES} pthread)


add_executable(dispatcher src/Dispatcher.cpp)

target_link_libraries(dispatcher PRIVATE ${Boost_LIBRARIES} pthread)