cmake_minimum_required(VERSION 3.16)

project(integration_complete VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Network PrintSupport Sql Charts)
find_package(Qt${QT_VERSION_MAJOR} 6.7.3 REQUIRED COMPONENTS Core Widgets Network PrintSupport Sql Charts)

# Vérification de l'existence du dossier SMTPClient
set(SMTPCLIENT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/SmtpClient-for-Qt-2.0")
if(NOT EXISTS "${SMTPCLIENT_ROOT}")
    message(WARNING "Le dossier SmtpClient-for-Qt-2.0 n'existe pas. Téléchargez-le depuis https://github.com/blablacar/smtpclient-for-qt")
    set(SMTPCLIENT_SOURCES "")
else()
    set(SMTPCLIENT_SRC_DIR "${SMTPCLIENT_ROOT}/src")
    file(GLOB SMTPCLIENT_SOURCES CONFIGURE_DEPENDS
        "${SMTPCLIENT_SRC_DIR}/*.cpp"
    )
endif()

set(PROJECT_SOURCES
        main.cpp
        connection.cpp
        connection.h
        employe.cpp
        employe.h
        labo.cpp
        labo.h
        email_sender.cpp
        email_sender.h
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        commande_widget.cpp          # ← AJOUT DE CETTE LIGNE MANQUANTE
        commande_widget.h            # ← AJOUT DE CETTE LIGNE MANQUANTE
        
        ${SMTPCLIENT_SOURCES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(integration_complete
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resources.qrc
    )
else()
    if(ANDROID)
        add_library(integration_complete SHARED
            ${PROJECT_SOURCES}
        )
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
)

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
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(integration_complete)
endif()
