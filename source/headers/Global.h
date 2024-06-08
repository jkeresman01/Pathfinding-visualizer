#pragma once

namespace gc
{

    namespace screen
    {
        constexpr int WIDTH = 840; 
        constexpr int HEIGHT = 900; 

        constexpr int POSITION_X  = 300; 
        constexpr int POSITION_Y  = 200; 
    }

    namespace grid
    {
        constexpr int ROWS = 40; 
        constexpr int COLUMNS = 30; 
    }

    namespace node
    {
        constexpr float WIDTH = 20.0f;
        constexpr float HEIGHT = 20.0f; 

        constexpr float ORIGIN_X = WIDTH / 2;
        constexpr float ORIGIN_Y = HEIGHT / 2;

        constexpr float START_POSITION_X = 40.0f; 
        constexpr float START_POSITION_Y = 90.0f; 

        constexpr int START_INDEX_X = 0;
        constexpr int START_INDEX_Y = 0;
        constexpr float OUTLINE_THICKNESS = 1.0f; 

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
        constexpr float HEIGHT = 2.0f;
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
        constexpr float REFRESH_TIME_SECONDS = 0.5f; 
    }
}
