#pragma once

#include <cstdint>

namespace pfv
{

    namespace screen
    {
        constexpr uint32_t WIDTH  = 1200; 
        constexpr uint32_t HEIGHT = 780; 

        constexpr uint32_t POSITION_X  = 300; 
        constexpr uint32_t POSITION_Y  = 200; 
    }// screen

    namespace grid
    {
        constexpr uint32_t ROWS    = 24; 
        constexpr uint32_t COLUMNS = 32; 
    } // grid

    namespace node
    {
        constexpr float WIDTH  = 30.0f;
        constexpr float HEIGHT = 30.0f; 

        constexpr float ORIGIN_X = WIDTH / 2;
        constexpr float ORIGIN_Y = HEIGHT / 2;

        constexpr float START_POSITION_X = 40.0f; 
        constexpr float START_POSITION_Y = 40.0f; 

        constexpr float OUTLINE_THICKNESS = 1.0f; 

        constexpr uint32_t START_INDEX_X = 0;
        constexpr uint32_t START_INDEX_Y = 0;

        constexpr uint32_t DEFAULT_DISTANCE_VALUE = 10000;

        enum Type : uint8_t
        {
            START  =  1,
            TARGET =  2,
            PATH   =  3,
            EMPTY  =  4,
            WALL   =  5,
        };
    }// grid

    namespace wall
    {
        constexpr float HEIGHT = 1.0f;
        constexpr float WIDTH  = node::WIDTH;

        constexpr float ORIGIN_X = node::WIDTH / 2;
        constexpr float ORIGIN_Y = node::HEIGHT / 2;

        constexpr float START_POSITION_X = node::START_POSITION_X;
        constexpr float START_POSITION_Y = node::START_POSITION_Y;  

        constexpr uint32_t WALL_COUNT = 4;

        enum Position : uint8_t
        {
            LEFT    =  0,
            RIGHT   =  1,
            TOP     =  2,
            BOTTOM  =  3,
        }; 

        enum Rotation : int8_t
        {
            LEFT_ROTATION_ANGLE    =  -45,
            RIGHT_ROTATION_ANGLE   =   45,
            TOP_ROTATION_ANGLE     =    0,
            BOTTOM_ROTATION_ANGLE  =  -90,
        };
    } // wall

    namespace maze
    {
        enum Direction : uint8_t
        {
            LEFT    =  0,
            RIGHT   =  1,
            TOP     =  2,
            BOTTOM  =  3,
        };
    }  // maze

    namespace app
    {
        constexpr uint32_t FRAMES_PER_SECOND = 60;

        enum Scene : uint8_t
        {
            MENU           =  0,
            MAZE_SOLVING   =  1,
            WALL_BUILDING  =  2,
        };

        enum Algorithm : uint8_t
        {
            NOT_SELECTED  =  0,
            DFS           =  1,
            BFS           =  2,
            DIJKSTRA      =  3,
        };
    } // app

    namespace menu
    {
        constexpr uint32_t NUMBER_OF_OPTIONS = 3;

        constexpr int32_t SPACING_BETWEEN_ITEMS = 100;

        constexpr float BACKGROND_SCALE_X = 0.4f;
        constexpr float BACKGROND_SCALE_Y = 0.4f;

        constexpr float FONT_SIZE = 30.0f;

        enum Mode : uint8_t
        {
            MAZE_SOLVING   =  0,
            WALL_BUILDING  =  1,
            EXIT           =  2,
        };
    } // menu

    namespace legend
    {
        constexpr float POSITION_X = screen::WIDTH - 200.0f;
        constexpr float POSITION_Y = 25;

        constexpr float FONT_SIZE = 15.0f;

        constexpr uint32_t NUMBER_OF_ITEMS = 13;

        constexpr uint32_t ITEM_SPACING = 40;

        enum Option : uint8_t
        {
            EMPTY_START  =  0,
            RESET        =  1,
            DFS          =  2,
            BFS          =  3,
            DIJKSTRA     =  4,
            ESC          =  5,
            EMPTY_MIDDLE =  6,
            START        =  7,
            TARGET       =  8,
            WALL         =  9,
            PATH         =  10,
            VISITED      =  11,
            EMPTY_END    =  12
        };
    } // legend

} // pfv
