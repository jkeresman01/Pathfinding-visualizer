#pragma once

namespace gc{

    constexpr int FRAMES_PER_SECOND = 60;

    namespace SCREEN{
        constexpr int WIDTH = 1280; 
        constexpr int HEIGHT = 720; 

        constexpr int POSITION_X  = 300; 
        constexpr int POSITION_Y  = 200; 
    }

    namespace GRID{
        constexpr int ROWS = 60; 
        constexpr int COLUMNS = 120; 
    }

    namespace TILE{
        constexpr float WIDTH = 10.0f; 
        constexpr float HEIGHT = 10.0f; 

        constexpr float ORIGIN_X = WIDTH / 2;
        constexpr float ORIGIN_Y = HEIGHT / 2;

        constexpr float START_POSITION_X = 45.0f; 
        constexpr float START_POSITION_Y = 100.0f; 

        constexpr float OUTLINE_THICKNESS = 0.5f; 

        enum TYPE{
            EMPTY = 0,
            WALL = 1,
            START = 0,
            TARGET = 0,
        };
    }
}
