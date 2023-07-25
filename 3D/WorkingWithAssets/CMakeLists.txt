cmake_minimum_required(VERSION 3.16)

project(WorkingWithAssets VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)


qt_add_executable(appWorkingWithAssets
    main.cpp
)

qt_add_qml_module(appWorkingWithAssets
    URI WorkingWithAssets
    VERSION 1.0
    QML_FILES Main.qml Monkey.qml
    RESOURCES meshes/suzanne.mesh
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appWorkingWithAssets PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appWorkingWithAssets
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appWorkingWithAssets
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appWorkingWithAssets
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
