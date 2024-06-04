#pragma once

#include "Node.h"
#include "Grid.h"

#include <SFML/Graphics/RenderWindow.hpp>

void recreatePath(Node *t_node, 
                  Grid &t_grid,
                  sf::RenderWindow *t_window);
