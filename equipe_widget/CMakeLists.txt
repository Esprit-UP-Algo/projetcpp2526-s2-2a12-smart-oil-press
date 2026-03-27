cmake_minimum_required(VERSION 3.21)
project(test_equipe_widget LANGUAGES CXX)

# Enable automatic MOC, RCC, and UIC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 components
find_package(Qt6 COMPONENTS Core Gui Widgets Sql Charts REQUIRED)

# Create executable
add_executable(test_equipe_widget
    main.cpp
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
    equipe_widget.h
    equipe_widget.cpp
    equipe_widget.ui
    team_repository.h
    team_repository.cpp
    resources.qrc
)

# Link Qt libraries
target_link_libraries(test_equipe_widget
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
    Qt6::Charts
)

# Optional: Add compiler warnings
if(MSVC)
    target_compile_options(test_equipe_widget PRIVATE /W4)
else()
    target_compile_options(test_equipe_widget PRIVATE -Wall -Wextra -Wpedantic)
endif()
