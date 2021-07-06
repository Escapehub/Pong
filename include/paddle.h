#include <SFML/Graphics.hpp>

#ifndef PADDLE
#define PADDLE

class Paddle : public sf::RectangleShape
{
public:
    enum Player {
        Player1, Player2
    };

private:
    float m_x = 20;
    float m_y = 100;
    float m_speed = 0.2;

public:
    Paddle(Player, float);
    virtual ~Paddle();
    float getSpeed() { return m_speed; }

public:
    static Paddle* GetPlayer1(float);
    static Paddle* GetPlayer2(float);
};

#endif
