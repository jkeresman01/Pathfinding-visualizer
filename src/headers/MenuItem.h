#pragma once

#include <filesystem>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

namespace pfv
{

class MenuItem
{
  public:
    MenuItem();

    void render(sf::RenderWindow &window) const;

    bool isSelected() const { return m_isSelected; }
    void move(float positionX, float positionY);

    void setSelected(bool isSelected);
    void setText(const std::string &text);

  private:
    sf::Text m_menuItem;
    bool m_isSelected;
};

} // namespace pfv
