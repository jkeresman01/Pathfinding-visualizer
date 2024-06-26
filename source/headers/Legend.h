#pragma once

#include <filesystem>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Global.h"

class Legend
{
    public:
        Legend();

        void draw();

        void move(float t_positionX, float t_positionY);

        void setWindow(sf::RenderWindow *t_window);

    private:
        void initLegendItems();

        void loadFont(const std::filesystem::path &t_path);

        void setTextLegendItems();
        void setDefaultSettingsLegendItems();
        void setColorLegendItems();

    private:
        sf::RenderWindow *m_window;
        sf::Font m_font;
        sf::Text m_items[gc::legend::NUMBER_OF_ITEMS];
};
