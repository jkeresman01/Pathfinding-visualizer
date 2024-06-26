#pragma once

#include <filesystem>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class MenuItem
{
    public:
        MenuItem();

        void draw();

        bool isSelected() const;
        void move(float t_positionX, float t_positionY);

        void setWindow(sf::RenderWindow *t_window);
        void setSelected(bool t_isSelected);
        void setText(const std::string &t_text);
    
    private:
        void loadFont(const std::filesystem::path &t_path);

    private:
        sf::RenderWindow *m_window;
        sf::Text m_menuItem;
        sf::Font m_font;

        bool m_isSelected;
};
