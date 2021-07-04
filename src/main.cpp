#include "paddle.h"
#include "score.h"
#include "ball.h"
#include "menu.h"

int main()
{
    float width = 1920;
    float height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "Pong");

    Paddle player1(Paddle::Player::Player1, height);
    Paddle player2(Paddle::Player::Player2, height);
    Score score(window.getSize().x);
    Ball ball(window.getSize().x, window.getSize().y);
    Menu menu(window.getSize().x, window.getSize().y);
    bool isPlaying = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
              case sf::Event::Closed:
                window.close();
                break;
              case sf::Event::Resized:
                width = event.size.width;
                height = event.size.height;
                break;
              case sf::Event::LostFocus:
                isPlaying = false;
                break;
              case sf::Event::KeyPressed:
                if (isPlaying) {
                  switch (event.key.code) {
                    case sf::Keyboard::Escape:
                      isPlaying = false;
                      break;
                    case sf::Keyboard::Space:
                      ball.Start();
                      break;
                    case sf::Keyboard::Z:
                      ball.Reset();
                      break;
                    default:
                      break;
                  }
                }
                else {
                  switch (event.key.code) {
                    case sf::Keyboard::Up:
                      menu.moveUp();
                      break;
                    case sf::Keyboard::Down:
                      menu.moveDown();
                      break;
                    case sf::Keyboard::Return:
                      switch(menu.getPressedItem()) {
                        case 0:
                          isPlaying = true;
                          break;
                        case 1:
                        window.close();
                      }
                      break;
                    default:
                      break;
                  }
                }
                break;
            }
        }

        // Player 1 movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          player1.move(0, -player1.getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          player1.move(0, player1.getSpeed());
        }
        // Player 2 movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          player2.move(0, -player2.getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          player2.move(0, player2.getSpeed());
        }

        // Collision
        if (player1.getGlobalBounds().intersects(ball.getGlobalBounds()) || player2.getGlobalBounds().intersects(ball.getGlobalBounds()))
          ball.Deflect();

        // Score detection
        if (ball.getPosition().x > window.getSize().x) {
          score.addPlayer1();
          ball.Reset();
        }
        if (ball.getPosition().x < 0) {
          score.addPlayer2();
          ball.Reset();
        }

        window.clear();
        if (isPlaying) {
          window.draw(player1);
          window.draw(player2);
          window.draw(score.getScore());
          ball.Update(window);
        }
        else {
          menu.Draw(window);
        }

        window.display();
    }

    return 0;
}
