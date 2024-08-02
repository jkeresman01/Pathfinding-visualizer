#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Grid.h"
#include "Legend.h"
#include "Node.h"

namespace pfv
{

void recreatePath(sf::RenderWindow *window, Legend &legend, Node *node, Grid &grid);

} // namespace pfv
