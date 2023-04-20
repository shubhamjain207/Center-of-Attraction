#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,720), "SFML works!");
  

    float randPosX,randPosY;
    float dirX[2000];
    float dirY[2000];
    sf::Vector2i mousePos;
    
    sf::View view = window.getDefaultView();
    int r, g, b;

    std::vector<sf::CircleShape> circles;

    for (int i = 0; i < 2000;i++) {
        randPosX = rand() % 1280 + 1;
        randPosY = rand() % 720 + 1;
        r = rand() % 255 + 1;
        g = rand() % 255 + 1;
        b = rand() % 255 + 1;

        sf::CircleShape shape(2);
         shape.setFillColor(sf::Color::Color(r,g,b));
      
        shape.setPosition(randPosX,randPosY);
        

        dirX[i] = mousePos.x - shape.getPosition().x;
        dirY[i] = mousePos.y - shape.getPosition().y;

        
        circles.push_back(shape);


    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::Resized) {
                
                view.setSize({
                        static_cast<float>(event.size.width),
                        static_cast<float>(event.size.height)
                    });
                window.setView(view);

            }
        }

       
        mousePos = sf::Mouse::getPosition(window);

        
       

        

        window.clear();
       for (int i = 0; i < 2000; i++) {
            circles[i].move(10 * ((mousePos.x) - circles[i].getPosition().x - rand() % 1100 + 1) / 1000.0f, 10 * ((mousePos.y ) - circles[i].getPosition().y - rand() % 1100 + 1)/ 1000.0f);
           
            window.draw(circles[i]);

           
       }
        
        window.display();
        
        window.setFramerateLimit(90);
    }

    return 0;
}