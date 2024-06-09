#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "MenuItem.h"

class Menu
{
    public:
        Menu();
        ~Menu();
        void draw();
        void update(sf::Event *t_event);
        void setWindow(sf::RenderWindow *t_window);

    private:
        void initilazeMenuItems();

    private:
        sf::RenderWindow *m_window;
        MenuItem *m_menuItems;
        int m_currentSelectedOption;
};
