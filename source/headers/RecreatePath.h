#pragma once

#include "Node.h"
#include "Grid.h"
#include "Legend.h"

#include <SFML/Graphics/RenderWindow.hpp>

void recreatePath(sf::RenderWindow *t_window,
                  Legend &t_legend,
                  Node *t_node, 
                  Grid &t_grid);
