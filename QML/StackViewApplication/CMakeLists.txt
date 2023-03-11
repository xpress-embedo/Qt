cmake_minimum_required(VERSION 3.16)

project(StackViewApplication VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appStackViewApplication
    main.cpp
)

qt_add_qml_module(appStackViewApplication
    URI StackViewApplication
    VERSION 1.0
    QML_FILES main.qml Home.qml Page1.qml Page2.qml
)

set_target_properties(appStackViewApplication PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appStackViewApplication
    PRIVATE Qt6::Quick)

install(TARGETS appStackViewApplication
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
