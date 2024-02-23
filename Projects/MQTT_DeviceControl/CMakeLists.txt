cmake_minimum_required(VERSION 3.16)

project(MQTT_DeviceControl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick Mqtt)


qt_add_executable(appMQTT_DeviceControl
    main.cpp
    mqtthandler.cpp
    mqtthandler.h
)

qt_add_qml_module(appMQTT_DeviceControl
    URI MQTT_DeviceControl
    VERSION 1.0
    QML_FILES Main.qml
    QML_FILES ColorSlider.qml
    QML_FILES CustomButton.qml
    QML_FILES CustomSwitch.qml
    SOURCES mqtthandler.h mqtthandler.cpp
    QML_FILES CustomSlider.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMQTT_DeviceControl PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMQTT_DeviceControl
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMQTT_DeviceControl
    PRIVATE Qt6::Quick
            Qt6::Mqtt
)

include(GNUInstallDirs)
install(TARGETS appMQTT_DeviceControl
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
