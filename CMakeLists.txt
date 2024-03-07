cmake_minimum_required(VERSION 3.16.3)

project(binary)

set(CMAKE_CXX_STANDARD 11)

add_executable(binary main.cpp ShipReader.cpp ShipReader.h)

configure_file(friendlyships.shp ${CMAKE_CURRENT_BINARY_DIR}/friendlyships.shp COPYONLY)
configure_file(enemyships.shp ${CMAKE_CURRENT_BINARY_DIR}/enemyships.shp COPYONLY)
