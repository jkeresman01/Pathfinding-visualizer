#pragma once

#include "Global.h"
#include "MenuItem.h"
#include "Backgorund.h"

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
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
        sf::SoundBuffer m_soundBuffer;
        sf::Sound m_sound;
        MenuItem *m_menuItems;
        Background m_backgorund;
        int m_currentSelectedOption;
};
