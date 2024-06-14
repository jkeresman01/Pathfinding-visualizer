#pragma once

#include <cstdint>

namespace gc
{
    namespace screen
    {
        constexpr int WIDTH = 1200; 
        constexpr int HEIGHT = 780; 

        constexpr int POSITION_X  = 300; 
        constexpr int POSITION_Y  = 200; 
    }

    namespace grid
    {
        constexpr int ROWS = 24; 
        constexpr int COLUMNS = 32; 
    }

    namespace node
    {
        constexpr float WIDTH = 30.0f;
        constexpr float HEIGHT = 30.0f; 

        constexpr float ORIGIN_X = WIDTH / 2;
        constexpr float ORIGIN_Y = HEIGHT / 2;

        constexpr float START_POSITION_X = 40.0f; 
        constexpr float START_POSITION_Y = 40.0f; 

        constexpr int START_INDEX_X = 0;
        constexpr int START_INDEX_Y = 0;

        constexpr float OUTLINE_THICKNESS = 1.0f; 

        constexpr uint32_t DEFAULT_DISTANCE_VALUE = 10000;

        enum Type
        {
            CURRENT = 1,
            START = 2,
            TARGET = 3,
            RECREATED_PATH = 4,
            PATH = 5,
            EMPTY = 6,
            WALL = 7,
        };
    }

    namespace wall
    {
        constexpr float HEIGHT = 1.0f;
        constexpr float WIDTH = node::WIDTH;

        constexpr float ORIGIN_X = node::WIDTH / 2;
        constexpr float ORIGIN_Y = node::HEIGHT / 2;

        constexpr float START_POSITION_X = node::START_POSITION_X;
        constexpr float START_POSITION_Y = node::START_POSITION_Y;  

        constexpr int WALL_COUNT = 4;

        enum Position
        {
            LEFT =  0,
            RIGHT = 1,
            TOP = 2,
            BOTTOM = 3,
        };

        enum Rotation
        {
            LEFT_ROTATION_ANGLE = -45,
            RIGHT_ROTATION_ANGLE = 45,
            TOP_ROTATION_ANGLE = 0,
            BOTTOM_ROTATION_ANGLE = -90,
        };
    }

    namespace maze
    {
        enum Direction
        {
            LEFT = 0,
            RIGHT = 1,
            TOP = 2,
            BOTTOM = 3,
        };
    }

    namespace tool
    {
        constexpr int FRAMES_PER_SECOND = 60;

        enum Scene
        {
            MENU = 0,
            MAZE_SOLVING = 1,
            WALL_BUILDING = 2,
        };

        enum Algorithm
        {
            NOT_SELECTED = 0,
            DFS = 1,
            BFS = 2,
            DIJKSTRA = 3,
        };
    }

    namespace button
    {
        constexpr int POSITION_X = screen::WIDTH - 20;
        constexpr int POSITION_Y = 40;

        constexpr float SCALE = 1.2f;
    }

    namespace menu
    {
        constexpr int NUMBER_OF_OPTIONS = 3;
        constexpr int SPACING_BETWEEN_ITEMS = 100;

        constexpr float BACKGROND_SCALE_X = 0.4f;
        constexpr float BACKGROND_SCALE_Y = 0.4f;

        constexpr float FONT_SIZE = 30.0f;

        enum Mode
        {
            MAZE_SOLVING = 0,
            WALL_BUILDING = 1,
            EXIT = 2
        };
    }

    namespace legend
    {
        constexpr int NUMBER_OF_ITEMS = 13;

        constexpr float POSITION_X = screen::WIDTH - 200.0f;
        constexpr float POSITION_Y = 25;

        constexpr float FONT_SIZE = 15.0f;

        constexpr int ITEM_SPACING = 40;

        enum Option
        {
            EMPTY_START = 0,
            RESET = 1,
            DFS = 2,
            BFS = 3,
            DIJKSTRA = 4,
            ESC = 5,
            EMPTY_MIDDLE = 6,
            START = 7,
            TARGET = 8,
            WALL = 9,
            PATH = 10,
            VISITED = 11,
            EMPTY_END = 12
        };
    }

}
