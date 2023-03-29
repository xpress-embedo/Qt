cmake_minimum_required(VERSION 3.14)

project(13-FileInformationUsingQFileInfo LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(13-FileInformationUsingQFileInfo
  main.cpp
)
target_link_libraries(13-FileInformationUsingQFileInfo Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS 13-FileInformationUsingQFileInfo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
