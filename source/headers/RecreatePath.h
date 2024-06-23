#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Grid.h"
#include "Legend.h"
#include "Node.h"

void recreatePath(sf::RenderWindow *t_window,
                  Legend &t_legend,
                  Node *t_node, 
                  Grid &t_grid);
