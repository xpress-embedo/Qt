cmake_minimum_required(VERSION 3.14)

project(03-Inheritence LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(03-Inheritence
  main.cpp animal.h animal.cpp mammal.h mammal.cpp canine.h canine.cpp feline.h
  feline.cpp
)
target_link_libraries(03-Inheritence Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS 03-Inheritence
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
