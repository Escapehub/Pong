#include "../header/ball.h"

Ball::Ball(float width, float height) {
  this->setPosition(sf::Vector2f(width / 2, height / 2));

}

Ball::~Ball() {
  
}

void Ball::Update(sf::RenderWindow& window) {

}
