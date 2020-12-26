#include <SFML/Graphics.hpp>

#ifndef MENU
#define MENU
#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
private:
  sf::Font _font;
  sf::Text _title, _controlsP1, _controlsP2, _menu[MAX_NUMBER_OF_ITEMS];
  int _selectedItem;
public:
  Menu(float, float);
  virtual ~Menu();
  void Draw(sf::RenderWindow&);
  void moveUp();
  void moveDown();
  int getPressedItem() { return _selectedItem; }
};

#endif
