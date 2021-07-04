#include "paddle.h"

Paddle::Paddle(Player player, float height) {
    this->setSize(sf::Vector2f(_x, _y));
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

Paddle::~Paddle() {

}
