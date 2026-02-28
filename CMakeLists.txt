cmake_minimum_required(VERSION 3.16)

project(gestion_de_commande VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    commande_widget.cpp
    commande_widget.h
    commande_widget.ui
    connection.cpp
    Ccommande.h
    Ccommande.cpp
    connection.h
    resources.qrc
)

add_executable(gestion_de_commande ${PROJECT_SOURCES})

target_link_libraries(gestion_de_commande PRIVATE Qt6::Core Qt6::Widgets Qt6::Sql Qt6::PrintSupport)

if(WIN32)
    set_target_properties(gestion_de_commande PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()

include(GNUInstallDirs)
install(TARGETS gestion_de_commande
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql PrintSupport)
