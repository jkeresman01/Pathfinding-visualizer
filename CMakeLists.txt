cmake_minimum_required(VERSION 3.10)
project(PathFindingVisualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

include_directories(src/headers)

set(SOURCES
    src/Background.cpp
    src/BreadthFirstSearch.cpp
    src/DepthFirstSearch.cpp
    src/Dijkstra.cpp
    src/Grid.cpp
    src/Legend.cpp
    src/Main.cpp
    src/Menu.cpp
    src/MenuItem.cpp
    src/Node.cpp
    src/PathFindingVisulizer.cpp
    src/RecreatePath.cpp
    src/RecursiveBacktracking.cpp
    src/ResourceManager.cpp
    src/Wall.cpp
)

add_executable(PathFindingVisualizer ${SOURCES})

target_link_libraries(PathFindingVisualizer sfml-system sfml-window sfml-graphics sfml-audio)

add_custom_command(TARGET PathFindingVisualizer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:PathFindingVisualizer>/resources
)

