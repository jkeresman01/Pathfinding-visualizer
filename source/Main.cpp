#include "headers/Global.h"
#include "headers/BreadthFirstSearch.h"
#include "headers/Legend.h"
#include "headers/Menu.h"
#include "headers/RecreatePath.h"
#include "headers/DepthFirstSearch.h"
#include "headers/Grid.h"
#include "headers/RecursiveBacktracking.h"

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Time.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iostream>
#include <queue>
#include <stack>
#include <thread>


/*
 *
 * NOT BAKED YET!!!!!!!!!!!!!!!
 * NOT BAKED YET!!!!!!!!!!!!!!!
 * NOT BAKED YET!!!!!!!!!!!!!!!
 * NOT BAKED YET!!!!!!!!!!!!!!!
 * NOT BAKED YET!!!!!!!!!!!!!!!
 * NOT BAKED YET!!!!!!!!!!!!!!!
 *
 */

/*
   sf::Font font;
   font.loadFromFile("./resources/fonts/Emulogic-zrEw.ttf");
   sf::Text tada;
   tada.setString("Pac seacrch");
   tada.setFont(font);
   tada.setCharacterSize(40);
   tada.setFillColor(sf::Color());
   tada.setPosition(10, 10);
   tada.setFillColor(sf::Color(51, 51, 255));
   */

/*
   std::stack<Node*> dfs_visited_nodes;
   dfs_visited_nodes.push(start);

   bool build_maze = false;
   */


/*
//BFS queuve
std::queue<Node*> q_nodes;
q_nodes.push(start);
*/


/*
// start and end search nodes
Node* start = grid.getNodeAtPosition(2, 13);
start->setType(gc::node::Type::START);

Node* end = grid.getNodeAtPosition(12, 13);
end->setType(gc::node::Type::TARGET);
*/
//grid.removeWalls();

/*
   if(!is_target_reached and !q_nodes.empty()){
   bfs(grid, q_nodes, is_target_reached);
   }

   if(is_target_reached and end != nullptr){
   recreatePath(end);
   }
   */


int main(){

    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(gc::screen::WIDTH, gc::screen::HEIGHT), "", sf::Style::Default);
    window.setPosition(sf::Vector2i(gc::screen::POSITION_X, gc::screen::POSITION_Y));
    window.setFramerateLimit(gc::tool::FRAMES_PER_SECOND);

    Grid grid(&window);

    // Maze generation stuff
    std::stack<Node*> maze_visited_nodes;;
    Node* grid_start_draw_node = grid.getNodeAtPosition(0, 0);
    maze_visited_nodes.push(grid_start_draw_node );
    int visited_count = 1;



    // start and end search nodes

    Node* start = grid.getNodeAtPosition(gc::grid::ROWS / 2 + 1, gc::grid::COLUMNS / 2 + 1);
    start->setType(gc::node::Type::START);

    Node* end = grid.getNodeAtPosition(gc::grid::ROWS - 1, gc::grid::COLUMNS - 1);
    end->setType(gc::node::Type::TARGET);

    bool is_target_reached = false;

    //BFS queuve
    std::queue<Node*> q_nodes;
    q_nodes.push(start);

    Menu menu;
    menu.setWindow(&window);

    sf::Clock clock;


    // bool to check if maze generation has finished 
    bool is_maze_finised = false;

    //Don't go to recreate path 100 times
    bool is_path_recreated = false;

    bool draw_menue = true;

    sf::SoundBuffer soundBuffer;
    soundBuffer.loadFromFile("./resources/images/maze_draw3.wav");
    sf::Sound sound;
    sound.setBuffer(soundBuffer);

    int current_scene = 0;

    Legend legend;
    legend.setWindow(&window);

    while (window.isOpen()){
        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Return){
                if(menu.getSelectedItem() == gc::menu::MAZE_SOLVING){
                    current_scene = 2;
                    draw_menue = false;
                }

                if(menu.getSelectedItem() == gc::menu::WALL_BUILDING){
                    current_scene = 1;
                    grid.restoreVisitedNodes();
                    grid.removeWalls();
                    draw_menue = false;
                }

                if(menu.getSelectedItem() == gc::menu::EXIT){
                    window.close();
                }
            }

            if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Down){
                menu.moveDown();
            }

            if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Up){
                menu.moveUp();
            }

            if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Escape){
                draw_menue = true;
            }

            if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::R){
                grid.removeWalls();
                grid.restoreVisitedNodes();
            }


        }


        //grid.removeWalls();
        //grid.draw();
        //dfs_button.draw();
        //bfs_button.draw();

            window.clear(sf::Color(3, 11, 28));

            if(draw_menue){
                menu.draw();
            }else {
                grid.draw();
                legend.draw();
            }

            window.display();


            if(current_scene == 2)
            {
                if(menu.getSelectedItem() == gc::menu::MAZE_SOLVING){
                    if(!is_maze_finised){
                        drawMaze(grid, maze_visited_nodes, visited_count);
                        if(visited_count > gc::grid::ROWS * gc::grid::COLUMNS){
                            is_maze_finised = true;
                            grid.restoreVisitedNodes();
                        }
                    }

                    if(is_maze_finised){

                        if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::D){
                            dfs(grid, start, &window, is_target_reached);
                            if(is_target_reached)
                            {
                                recreatePath(start, grid, &window, sound);
                            }
                        }

                        if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::B){
                            bfs(grid, q_nodes, is_target_reached);
                        }

                    }

                }

                if(current_scene == 1){
                    grid.restoreVisitedNodes();
                    //Random wall
                    grid.getNodeAtPosition(10, 8)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(10, 9)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(10, 10)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(10, 11)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(10, 12)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(10, 13)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(10, 14)->setType(gc::node::WALL);


                    //Random wall
                    grid.getNodeAtPosition(0, 11)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(1, 11)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(2, 11)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(3, 11)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(4, 11)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(5, 11)->setType(gc::node::WALL);
                    grid.getNodeAtPosition(6, 11)->setType(gc::node::WALL);


                    if(!is_target_reached and !q_nodes.empty()){
                        bfs(grid, q_nodes, is_target_reached);
                    }

                    if(is_target_reached and end != nullptr){
                        recreatePath(end, grid, &window, sound);
                    }
                }


        }

    }

    return EXIT_SUCCESS;
}
     

/*

   if(current_scene == 2)
   {
   if(menu.getSelectedItem() == gc::menu::MAZE_SOLVING){
   if(!is_maze_finised){
   drawMaze(grid, maze_visited_nodes, visited_count);
   if(visited_count > gc::grid::ROWS * gc::grid::COLUMNS){
   is_maze_finised = true;
   grid.restoreVisitedNodes();
   }
   }
   if(is_maze_finised){
   if(!is_target_reached){
   dfs(grid, start, &window, is_target_reached);
   }else if(!is_path_recreated) {
   recreatePath(end, grid, &window, sound);
   is_path_recreated = true;
   }
   }
   }

                */
