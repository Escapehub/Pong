#include <SFML/Graphics.hpp>

#ifndef __MENU__
#define __MENU__
#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
private:
  sf::Font m_font;
  sf::Text m_title;
  sf::Text m_controlsP1;
  sf::Text m_controlsP2;
  sf::Text m_menu[MAX_NUMBER_OF_ITEMS];
  int m_selectedItem;

public:
  Menu(float, float);
  virtual ~Menu();
  void Draw(sf::RenderWindow&);
  void moveUp();
  void moveDown();
  int getPressedItem() { return m_selectedItem; }
};

#endif // !__MENU__
