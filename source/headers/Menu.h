#pragma once

#include "Global.h"
#include "MenuItem.h"
#include "Background.h"

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
        void initMenuItems();

    private:
        sf::RenderWindow *m_window;
        sf::SoundBuffer m_soundBuffer;
        sf::Sound m_soundEffect;

        Background m_background;
        MenuItem *m_menuItems;

        int m_currentSelectedOption;
};
