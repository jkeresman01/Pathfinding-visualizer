#pragma once

#include "Global.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class Legend
{
    public:
        Legend();
        void draw();
        void move(const float t_positionX, const float t_positionY);
        void setWindow(sf::RenderWindow *t_window);

    private:
        void initilazeLegendItems();

    private:
        sf::RenderWindow *m_window;
        sf::Font m_font;
        sf::Text m_items[gc::legend::NUMBER_OF_ITEMS];
};
