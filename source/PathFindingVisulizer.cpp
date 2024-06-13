#include "headers/BreadthFirstSearch.h"
#include "headers/DepthFirstSearch.h"
#include "headers/Global.h"
#include "headers/PathFindingVisulizer.h"
#include "headers/RecreatePath.h"
#include "headers/RecursiveBacktracking.h"

#include <ctime>
#include <thread>

/*
 *
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 *
 */

PathFindingVisulizer::PathFindingVisulizer() 
    : m_window(sf::VideoMode(gc::screen::WIDTH, gc::screen::HEIGHT), ""),
    m_start(nullptr), m_end(nullptr), m_currentScene(gc::tool::MENU),
    m_isTargetReached(false), m_numberOfVisitedNodes(0), m_algorithm(gc::tool::Algorithm::NOT_SELECTED)
{
    m_window.setPosition(sf::Vector2i(gc::screen::POSITION_X, gc::screen::POSITION_Y));
    m_window.setFramerateLimit(gc::tool::FRAMES_PER_SECOND);
    m_grid.setWindow(&m_window);
    m_menu.setWindow(&m_window);
    m_legend.setWindow(&m_window);
    srand(time(nullptr));
}

void PathFindingVisulizer::run()
{

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }

            //------------------------      MENU LOGIC    ------------------------------------//

            if(m_currentScene == gc::tool::Scene::MENU)
            {
                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Down){
                    m_menu.moveDown();
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Up){
                    m_menu.moveUp();
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Return)
                {
                    if(m_menu.getSelectedItem() == gc::menu::MAZE_SOLVING)
                    {
                        m_currentScene = gc::tool::Scene::MAZE_SOLVING;
                        m_grid.restoreVisitedNodes();
                        m_grid.createWalls();
                        m_mazeVisitedNodes.push(m_grid.getNodeAtPosition(0, 0));
                        m_numberOfVisitedNodes = 1;
                    }

                    if(event.type == sf::Event::KeyReleased and m_menu.getSelectedItem() == gc::menu::WALL_BUILDING)
                    {
                        m_currentScene = gc::tool::Scene::WALL_BUILDING;
                        m_grid.restoreVisitedNodes();
                        m_grid.removeWalls();
                    }

                    if(event.type == sf::Event::KeyReleased and m_menu.getSelectedItem() == gc::menu::EXIT)
                    {
                        m_window.close();
                    }
                }
            }

            if(m_currentScene == gc::tool::Scene::WALL_BUILDING || m_currentScene == gc::tool::Scene::MAZE_SOLVING)
            {
                
                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Escape)
                {
                    m_currentScene = gc::tool::Scene::MENU;

                    while (!m_bfsVisitedNodes.empty()) {
                        m_bfsVisitedNodes.pop();
                    }

                    while (!m_dfsVisitedNodes.empty()) {
                        m_dfsVisitedNodes.pop();
                    }

                    m_algorithm = gc::tool::Algorithm::NOT_SELECTED;
                    m_grid.restoreVisitedNodes();
                    m_isTargetReached = false;
                    m_isPathCreated = false;
                    m_numberOfVisitedNodes = 1;

                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::R)
                {

                    while (!m_bfsVisitedNodes.empty()) {
                        m_bfsVisitedNodes.pop();
                    }

                    while (!m_dfsVisitedNodes.empty()) {
                        m_dfsVisitedNodes.pop();
                    }

                    m_algorithm = gc::tool::Algorithm::NOT_SELECTED;
                    m_grid.restoreVisitedNodes();
                    m_grid.createWalls();
                    m_isTargetReached = false;
                    m_isPathCreated = false;
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::D)
                {
                    m_algorithm = gc::tool::Algorithm::DFS;
                    m_dfsVisitedNodes.push(m_start);
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::B)
                {
                    m_algorithm = gc::tool::Algorithm::BFS;
                    m_bfsVisitedNodes.push(m_start);
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::J)
                {
                    //DIJKSTA
                }
                
            }

        }


        //------------------------      LOGICAL LOGIC    ------------------------------------//


        //------------------------      DRAW STUFF    ------------------------------------//

        m_window.clear(sf::Color(3, 11, 28));

        if(m_currentScene == gc::tool::MENU)
        {
            m_menu.draw();
        }

        if(m_currentScene == gc::tool::MAZE_SOLVING)
        {
            if(m_numberOfVisitedNodes <= gc::grid::ROWS * gc::grid::COLUMNS)
            {
                drawMaze(m_grid, m_mazeVisitedNodes, m_numberOfVisitedNodes);
            }
            else 
            {

                if(!m_isTargetReached)
                {

                    if(m_algorithm == gc::tool::NOT_SELECTED)
                    {
                        m_grid.restoreVisitedNodes();

                        m_start = m_grid.getNodeAtPosition(0, 0);
                        m_start->setType(gc::node::START);

                        m_end = m_grid.getNodeAtPosition(10, 12);
                        m_end->setType(gc::node::TARGET);
                    }

                    if(m_algorithm == gc::tool::DFS)
                    {
                        dfs(m_grid, m_start, m_window, m_isTargetReached);
                    }

                    if(m_algorithm == gc::tool::Algorithm::BFS)
                    {
                        bfs(m_grid, m_bfsVisitedNodes, m_isTargetReached);
                    }
                }
                else if(!m_isPathCreated)
                {
                    recreatePath(m_end, m_grid, &m_window);
                    m_isPathCreated = true;
                }
           }

            m_grid.draw();
            //m_legend.draw();

            std::thread tada([this](){ m_legend.draw();});
            tada.join();
        }

        if(m_currentScene == gc::tool::WALL_BUILDING)
        {
            m_grid.draw();
            m_legend.draw();
        }

        m_window.display();

    }
}



/*
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

*/

/*
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

*/

