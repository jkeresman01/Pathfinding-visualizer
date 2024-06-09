#pragma once

#include "Global.h"
#include "MenuItem.h"
#include "Backgorund.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class Menu
{
    public:
        Menu();
        ~Menu();
        void draw();
        void moveUp();
        void moveDown();
        void setWindow(sf::RenderWindow *t_window);
        int getSelectedItem() const;

    private:
        void initilazeMenuItems();

    private:
        sf::RenderWindow *m_window;
        MenuItem *m_menuItems;
        Background m_backgorund;
        int m_currentSelectedOption;
};
