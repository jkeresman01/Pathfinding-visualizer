#pragma once

namespace gc{

    namespace screen{
        constexpr int WIDTH = 1200; 
        constexpr int HEIGHT = 720; 

        constexpr int POSITION_X  = 300; 
        constexpr int POSITION_Y  = 200; 
    }

    namespace grid{
        constexpr int ROWS = 15; 
        constexpr int COLUMNS = 15; 
    }

    namespace node{
        constexpr float WIDTH = 40.0f; 
        constexpr float HEIGHT = 40.0f; 

        constexpr float ORIGIN_X = WIDTH / 2;
        constexpr float ORIGIN_Y = HEIGHT / 2;

        constexpr float START_POSITION_X = 40.0f; 
        constexpr float START_POSITION_Y = 40.0f; 

        constexpr int START_INDEX_X = 0;
        constexpr int START_INDEX_Y = 0;
        constexpr float OUTLINE_THICKNESS = 12.5f; 

        enum State{
            CURRENT = 1,
            START = 2,
            TARGET = 3,
        };
    }

    namespace wall{
        constexpr float HEIGHT = 1.0f;
        constexpr float WIDTH = node::WIDTH;

        constexpr float ORIGIN_X = node::WIDTH / 2;
        constexpr float ORIGIN_Y = node::HEIGHT / 2;

        constexpr float START_POSITION_X = node::START_POSITION_X;
        constexpr float START_POSITION_Y = node::START_POSITION_Y;  

        constexpr int WALL_COUNT = 4;

        enum Position{
            LEFT = 0,
            RIGHT = 1,
            TOP = 2,
            BOTTOM = 3,
        };

        enum Rotation{
            LEFT_ROTATION = -45,
            RIGHT_ROTATION = 45,
            TOP_ROTATION = 0,
            BOTTOM_ROTATION = -90,
        };
    }

    namespace tool{
        constexpr int FRAMES_PER_SECOND = 60;
        constexpr float REFRESH_TIME_SECONDS = 0.5f; 
    }
}
