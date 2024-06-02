#include "headers/Backgorund.h"

Background::Background(){
    setImage("./resources/images/background_01.jpg");
    this->m_Background.setScale(0.23, 0.23);
}

void Background::setWindow(sf::RenderWindow *window){
    this->m_Window = window;
}

void Background::setImage(std::string t_path){
    this->m_Path = t_path;
    this->m_Texture.loadFromFile(t_path);
    this->m_Background.setTexture(m_Texture);
}

void Background::draw(){
    this->m_Window->draw(m_Background);
}
