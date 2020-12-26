#include "header/paddle.h"
#include "header/score.h"
#include "header/ball.h"

int main()
{
    float width = 1920;
    float height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "Pong");

    Paddle player1(Paddle::Player::Player1);
    Paddle player2(Paddle::Player::Player2);
    Score score(window.getSize().x);
    Ball ball(window.getSize().x, window.getSize().y);

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
                //pause();
                break;
              case sf::Event::GainedFocus:
                //resume();
                break;
              case sf::Event::KeyPressed:
                switch (event.key.code) {
                  case sf::Keyboard::Escape:
                    window.close();
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
        if (ball.getPosition().y < 0) {
          score.addPlayer2();
          ball.Reset();
        }

        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.draw(score.getScore());
        ball.Update(window);
        window.display();
    }

    return 0;
}
