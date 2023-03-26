cmake_minimum_required(VERSION 3.14)

project(10-TemplateSimple LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(10-TemplateSimple
  main.cpp
)
target_link_libraries(10-TemplateSimple Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS 10-TemplateSimple
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
