#pragma once

#include "Node.h"
#include "Grid.h"

#include <SFML/Graphics/RenderWindow.hpp>

void recreatePath(Node *node, 
                  Grid &grid,
                  sf::RenderWindow *window);
