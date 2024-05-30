#pragma once

namespace gc{

    namespace screen{
        constexpr int WIDTH = 1280; 
        constexpr int HEIGHT = 720; 

        constexpr int POSITION_X  = 300; 
        constexpr int POSITION_Y  = 200; 
    }

    namespace grid{
        constexpr int ROWS = 15; 
        constexpr int COLUMNS = 30; 
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

        constexpr float OUTLINE_THICKNESS = 4.5f; 

        enum State{
            NOT_VISITED = 0,
            VISITED = 1,
            CURRENT = 2,
            START = 3,
            TARGET = 4,
        };
    }

    namespace tool{
        constexpr int FRAMES_PER_SECOND = 60;
        constexpr float REFRESH_TIME_SECONDS = 0.5f; 
    }
}
