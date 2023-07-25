cmake_minimum_required(VERSION 3.16)

project(AccelerometerVisualizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)
find_package(Qt6 6.2 REQUIRED COMPONENTS Quick3D)
find_package(Qt6 6.2 REQUIRED COMPONENTS SerialPort)


qt_add_executable(appAccelerometerVisualizer
    main.cpp
    serialmanager.h serialmanager.cpp
    resources.qrc
)

qt_add_qml_module(appAccelerometerVisualizer
    URI FXOS8700_Visualizer
    VERSION 1.0
    QML_FILES Main.qml
    RESOURCES resources.qrc
)

set_target_properties(appAccelerometerVisualizer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appAccelerometerVisualizer
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Quick3D
    PRIVATE Qt6::SerialPort
)

install(TARGETS appAccelerometerVisualizer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
