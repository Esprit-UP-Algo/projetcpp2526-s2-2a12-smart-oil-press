cmake_minimum_required(VERSION 3.16)

project(integration_complete VERSION 0.1 LANGUAGES C CXX)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# Set available build types (Debug and Release)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Network PrintSupport Sql Charts SerialPort)
find_package(Qt${QT_VERSION_MAJOR} 6.7.3 REQUIRED COMPONENTS Core Widgets Network PrintSupport Sql Charts SerialPort)

set(SMTPCLIENT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/SmtpClient-for-Qt-2.0")
set(SMTPCLIENT_SRC_DIR "${SMTPCLIENT_ROOT}/src")
file(GLOB SMTPCLIENT_SOURCES CONFIGURE_DEPENDS
    "${SMTPCLIENT_SRC_DIR}/*.cpp"
)

set(PROJECT_SOURCES
        main.cpp
        connection.cpp
        connection.h
        equipe.cpp
        equipe.h
        employe.cpp
        employe.h
        labo.cpp
        labo.h
        commande.cpp
        commande.h
        client.cpp
        client.h
        Arduino.cpp
        Arduino.h
        email_sender.cpp
        email_sender.h
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        machine.cpp
        machine.h
        tunisia_map_widget.cpp
        tunisia_map_widget.h
        tunisia_map_data.h
        tunisian_regions.h
        arduino_environment.h
        arduino_environment.cpp
        parking_widget.cpp
        parking_widget.h
    
        ${SMTPCLIENT_SOURCES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(integration_complete
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resources.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET integration_complete APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(integration_complete SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(integration_complete
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(integration_complete PRIVATE
    ${SMTPCLIENT_ROOT}
    ${SMTPCLIENT_SRC_DIR}
)

target_link_libraries(integration_complete PRIVATE
    Qt6::Network
    Qt6::Core
    Qt6::Widgets
    Qt6::PrintSupport
    Qt6::Sql
    Qt6::Charts
    Qt6::SerialPort
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.integration_complete)
endif()
set_target_properties(integration_complete PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS integration_complete
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(integration_complete)
endif()
