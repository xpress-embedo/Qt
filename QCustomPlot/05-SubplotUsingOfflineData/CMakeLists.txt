cmake_minimum_required(VERSION 3.5)

project(05-SubplotUsingOfflineData VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)
add_subdirectory(../../ThirdParty/QCustomPlot build)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(05-SubplotUsingOfflineData
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 05-SubplotUsingOfflineData APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(05-SubplotUsingOfflineData SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(05-SubplotUsingOfflineData
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(05-SubplotUsingOfflineData PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# Link Needed Libraries, QCustomPlot Library
target_link_libraries(05-SubplotUsingOfflineData PRIVATE qcustomplot)

# Compile needed definitions
target_compile_definitions(05-SubplotUsingOfflineData PRIVATE QCUSTOMPLOT_USE_LIBRARY)


set_target_properties(05-SubplotUsingOfflineData PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS 05-SubplotUsingOfflineData
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(05-SubplotUsingOfflineData)
endif()
