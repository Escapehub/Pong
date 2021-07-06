#include "paddle.h"

Paddle::Paddle(Player player, float height) 
{
    this->setSize(sf::Vector2f(m_x, m_y));
    this->setFillColor(sf::Color::White);
    switch (player) {
        case Player::Player1:
            this->setPosition(20, height / 2);
            break;
        case Player::Player2:
            this->setPosition(1890, height / 2);
            break;
    }
}

Paddle::~Paddle() 
{

}

Paddle*
Paddle::GetPlayer1(float windowHeight)
{
    return new Paddle(Paddle::Player1, windowHeight);
}

Paddle*
Paddle::GetPlayer2(float windowHeight)
{
    return new Paddle(Paddle::Player2, windowHeight);
}