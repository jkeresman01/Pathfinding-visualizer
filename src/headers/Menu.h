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

    void render(sf::RenderWindow &window) const;

    void moveUp();
    void moveDown();

    uint32_t getSelectedItem() const { return m_selectedItem; }

  private:
    void renderMenuItems(sf::RenderWindow &window) const;

  private:
    sf::Sound m_soundEffect;
    Background m_background;
    MenuItem *m_menuItems;
    uint32_t m_selectedItem;
};

} // namespace pfv
