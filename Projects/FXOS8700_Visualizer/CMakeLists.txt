cmake_minimum_required(VERSION 3.16)

project(FXOS8700_Visualizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)
find_package(Qt6 6.2 REQUIRED COMPONENTS Quick3D)


qt_add_executable(appFXOS8700_Visualizer
    main.cpp
)

qt_add_qml_module(appFXOS8700_Visualizer
    URI FXOS8700_Visualizer
    VERSION 1.0
    QML_FILES Main.qml
)

set_target_properties(appFXOS8700_Visualizer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appFXOS8700_Visualizer
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Quick3D
)

install(TARGETS appFXOS8700_Visualizer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
