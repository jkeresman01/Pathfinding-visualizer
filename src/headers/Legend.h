#pragma once

#include <filesystem>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "PfvConstants.h"

namespace pfv
{

class Legend
{
  public:
    Legend();
    ~Legend();

    void render(sf::RenderWindow &window) const;

  private:
    sf::Text *m_items;
};

} // namespace pfv
