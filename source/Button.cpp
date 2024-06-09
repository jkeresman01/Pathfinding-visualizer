#include "headers/Button.h"
#include "headers/Global.h"

#include <SFML/Graphics/RenderWindow.hpp>

Button::Button(const std::string t_path)
{
    m_path = t_path;
    m_texture.loadFromFile(m_path);
    m_texture.setSmooth(true);
    m_button.setTexture(m_texture);
    m_button.setOrigin(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().height / 2);
    m_button.setPosition(gc::button::POSITION_X, gc::button::POSITION_Y);
    m_button.setColor(sf::Color(204, 255, 229));
    setWindow(nullptr);
    setScale(gc::button::SCALE);
}

void Button::draw()
{
    m_window->draw(m_button);
}

void Button::move(const float t_positionX, const float t_positionY)
{
    m_button.move(t_positionX, t_positionY);
}

void Button::setScale(const float t_scaleFactor)
{
    m_scaleFactor = t_scaleFactor;
    m_button.setScale(m_scaleFactor, m_scaleFactor);
}

void Button::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

bool Button::isPressed()
{
    auto mousePosition = sf::Mouse::getPosition(*m_window); 
    auto translatedPosition = m_window->mapPixelToCoords(mousePosition);

    bool isMouseOnButton = m_button.getGlobalBounds().contains(translatedPosition); 
    bool isMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    isMouseOnButton ? m_button.setScale(m_scaleFactor * 1.1f, m_scaleFactor * 1.1f)
                    : m_button.setScale(m_scaleFactor, m_scaleFactor);

    return isMousePressed and isMouseOnButton;
}
