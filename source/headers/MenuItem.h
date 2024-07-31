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

    void draw();

    bool isSelected() const;
    void move(float positionX, float positionY);

    void setWindow(sf::RenderWindow *window);
    void setSelected(bool isSelected);
    void setText(const std::string &text);

  private:
    void initMenuItem();

    void loadFont(const std::filesystem::path &path);

    void setDefaultSettings();

  private:
    sf::RenderWindow *m_window;
    sf::Text m_menuItem;
    sf::Font m_font;

    bool m_isSelected;
};

} // namespace pfv
