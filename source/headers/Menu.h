#pragma once

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Background.h"
#include "MenuItem.h"
#include "PfvConstants.h"

namespace pfv
{
    
class Menu
{
    public:
        Menu();
        ~Menu();

        void draw();

        void moveUp();
        void moveDown();

        void setWindow(sf::RenderWindow *t_window);

        uint32_t getSelectedItem() const;

    private:
        void initMenuItems();
        void drawMenuItems();

        void initMazeSolvingOption();
        void initWallBuildingOption();
        void initExitOption();

        void loadSound(const std::filesystem::path &t_path);

        void setWindowMenuItems(sf::RenderWindow *t_window);

    private:
        sf::RenderWindow *m_window;
        sf::SoundBuffer m_soundBuffer;
        sf::Sound m_soundEffect;

        Background m_background;
        MenuItem *m_menuItems;

        uint32_t m_selectedItem;
};

} // pfv
