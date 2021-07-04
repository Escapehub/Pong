#include "menu.h"

Menu::Menu(float width, float height) {
  _font.loadFromFile("assets/fonts/arcade.ttf");

  // Title
  _title.setFont(_font);
  _title.setCharacterSize(100);
  _title.setFillColor(sf::Color::White);
  _title.setString("Pong");
  _title.setPosition(sf::Vector2f(width / 3, 20));

  // Player 1 controls
  _controlsP1.setFont(_font);
  _controlsP1.setCharacterSize(30);
  _controlsP1.setFillColor(sf::Color::White);
  _controlsP1.setString("Controls \n w \n s");
  _controlsP1.setPosition(sf::Vector2f(20, 20));

  // Player 2 controls
  _controlsP2.setFont(_font);
  _controlsP2.setCharacterSize(30);
  _controlsP2.setFillColor(sf::Color::White);
  _controlsP2.setString("Controls \n Arrow Up \n Arrow Down");
  _controlsP2.setPosition(sf::Vector2f(width - 40, 20));

  // Menu items
  _menu[0].setFont(_font);
  _menu[0].setCharacterSize(50);
  _menu[0].setFillColor(sf::Color::Red);
  _menu[0].setString("Play");
  _menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

  _menu[1].setFont(_font);
  _menu[1].setCharacterSize(50);
  _menu[1].setFillColor(sf::Color::White);
  _menu[1].setString("Exit");
  _menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

  _selectedItem = 0;
}

Menu::~Menu() {

}

void Menu::Draw(sf::RenderWindow& window) {
  window.draw(_title);
  window.draw(_controlsP1);
  window.draw(_controlsP2);
  for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
    window.draw(_menu[i]);
  }
}

void Menu::moveUp() {
  if (_selectedItem - 1 >= 0) {
        _menu[_selectedItem].setFillColor(sf::Color::White);
        _selectedItem--;
        _menu[_selectedItem].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (_selectedItem + 1 < MAX_NUMBER_OF_ITEMS) {
        _menu[_selectedItem].setFillColor(sf::Color::White);
        _selectedItem++;
        _menu[_selectedItem].setFillColor(sf::Color::Red);
    }
}
