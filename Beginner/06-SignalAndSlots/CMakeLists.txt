cmake_minimum_required(VERSION 3.14)

project(06-SignalAndSlots LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(06-SignalAndSlots
  main.cpp
  source.h source.cpp
  destination.h destination.cpp
)
target_link_libraries(06-SignalAndSlots Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS 06-SignalAndSlots
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
