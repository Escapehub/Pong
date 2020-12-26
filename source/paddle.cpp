#include "../header/paddle.h"

Paddle::Paddle(Player player) {
    this->setSize(sf::Vector2f(_x, _y));
    this->setFillColor(sf::Color::White);
    switch (player) {
        case Player::Player1:
            this->setPosition(0, 0);
            break;
        case Player::Player2:
            this->setPosition(1890, 0);
            break;
    }
}

Paddle::~Paddle() {

}