cmake_minimum_required(VERSION 3.16)

project(ImageViewerLocal VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appImageViewerLocal
    main.cpp dirhelper.h dirhelper.cpp
)

qt_add_qml_module(appImageViewerLocal
    URI ImageViewerLocal
    VERSION 1.0
    QML_FILES main.qml ImagePage.qml
)

set_target_properties(appImageViewerLocal PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appImageViewerLocal
    PRIVATE Qt6::Quick)

install(TARGETS appImageViewerLocal
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
