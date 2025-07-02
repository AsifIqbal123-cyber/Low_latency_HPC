cmake_minimum_required(VERSION 3.10)
project(MarketDataFeedHandler)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS} include)


add_executable(feed_handler
    src/main.cpp
    src/FeedReceiver.cpp
)


target_link_libraries(feed_handler PRIVATE ${Boost_LIBRARIES} pthread)


add_executable(dispatcher src/Dispatcher.cpp)

target_link_libraries(dispatcher PRIVATE ${Boost_LIBRARIES} pthread)