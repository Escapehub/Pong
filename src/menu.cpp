#include "menu.h"

Menu::Menu(float width, float height) 
{
  m_font.loadFromFile("assets/fonts/arcade.ttf");

  // Title
  m_title.setFont(m_font);
  m_title.setCharacterSize(100);
  m_title.setFillColor(sf::Color::White);
  m_title.setString("Pong");
  m_title.setPosition(sf::Vector2f(width / 3, 20));

  // Player 1 controls
  m_controlsP1.setFont(m_font);
  m_controlsP1.setCharacterSize(30);
  m_controlsP1.setFillColor(sf::Color::White);
  m_controlsP1.setString("Controls \n w \n s");
  m_controlsP1.setPosition(sf::Vector2f(20, 20));

  // Player 2 controls
  m_controlsP2.setFont(m_font);
  m_controlsP2.setCharacterSize(30);
  m_controlsP2.setFillColor(sf::Color::White);
  m_controlsP2.setString("Controls \n Arrow Up \n Arrow Down");
  m_controlsP2.setPosition(sf::Vector2f(width - 40, 20));

  // Menu items
  m_menu[0].setFont(m_font);
  m_menu[0].setCharacterSize(50);
  m_menu[0].setFillColor(sf::Color::Red);
  m_menu[0].setString("Play");
  m_menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

  m_menu[1].setFont(m_font);
  m_menu[1].setCharacterSize(50);
  m_menu[1].setFillColor(sf::Color::White);
  m_menu[1].setString("Exit");
  m_menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

  m_selectedItem = 0;
}

Menu::~Menu() 
{

}

void Menu::Draw(sf::RenderWindow& window)
{
  window.draw(m_title);
  window.draw(m_controlsP1);
  window.draw(m_controlsP2);
  for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    window.draw(m_menu[i]);
}

void Menu::moveUp() 
{
  if (m_selectedItem - 1 >= 0) 
  {
    m_menu[m_selectedItem].setFillColor(sf::Color::White);
    m_selectedItem--;
    m_menu[m_selectedItem].setFillColor(sf::Color::Red);
  }
}

void Menu::moveDown() 
{
  if (m_selectedItem + 1 < MAX_NUMBER_OF_ITEMS) 
  {
    m_menu[m_selectedItem].setFillColor(sf::Color::White);
    m_selectedItem++;
    m_menu[m_selectedItem].setFillColor(sf::Color::Red);
  }
}
