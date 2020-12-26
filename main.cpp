#include "header/paddle.h"
#include "header/score.h"
#include "header/ball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong");
    
    Paddle player1(Paddle::Player::Player1);
    Paddle player2(Paddle::Player::Player2);
    Score score(window.getSize().x);
    Ball ball(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        // Player 1 movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          player1.move(0, -player1.getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          player1.move(0, player1.getSpeed());
        }
        // Player 2 movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          player2.move(0, -player2.getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          player2.move(0, player2.getSpeed());
        }

        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.draw(score.getScore());
        window.draw(ball);
        window.display();
    }

    return 0;
}
