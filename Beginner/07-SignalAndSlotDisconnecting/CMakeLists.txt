cmake_minimum_required(VERSION 3.14)

project(07-SignalAndSlotDisconnecting LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(07-SignalAndSlotDisconnecting
  main.cpp
  radio.h radio.cpp
  station.h station.cpp
)
target_link_libraries(07-SignalAndSlotDisconnecting Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS 07-SignalAndSlotDisconnecting
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
