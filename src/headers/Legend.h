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

    void draw();

    void move(float positionX, float positionY);

    void setWindow(sf::RenderWindow *window);

  private:
    void initLegendItems();

    void loadFont(const std::filesystem::path &path);

    void setTextLegendItems();

    void setTextAlgorithms();
    void setTextCellTypes();

    void setDefaultSettingsLegendItems();
    void setColorLegendItems();

  private:
    sf::RenderWindow *m_window;
    sf::Font m_font;
    sf::Text m_items[legend::NUMBER_OF_ITEMS];
};

} // namespace pfv
