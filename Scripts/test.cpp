#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    const int TEXTURE_WIDTH = 16;
    const int TEXTURE_HEIGHT = 16;
    const int WINDOW_WIDTH = 500;
    const int WINDOW_HEIGHT = 500;
    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Simple Sprite Editor");
    sf::Uint8* pixels = new sf::Uint8[TEXTURE_WIDTH * TEXTURE_HEIGHT * 4];
    sf::Texture texture;
    sf::Sprite sprite;
    bool pressed = false;
    texture.create(TEXTURE_WIDTH, TEXTURE_HEIGHT);
    for(int i = 0; i < TEXTURE_WIDTH * TEXTURE_HEIGHT * 4; i+=4)
    {
        pixels[i] = 255;
        pixels[i+1] = 255;
        pixels[i+2] = 255;
        pixels[i+3] = 255;
    }
    // run the program as long as the window is open
    while (window.isOpen())
    {        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if(event.type == sf::Event::MouseButtonReleased){
                pressed = false;
                sf::Image image;
                image.create(TEXTURE_WIDTH, TEXTURE_HEIGHT, pixels);
                image.saveToFile("test.png");
            }
            if(event.type == sf::Event::MouseButtonPressed){
                pressed = true;
            }
            if (event.type == sf::Event::Closed)
                window.close();
            if (pressed){
                int mx = sf::Mouse::getPosition(window).x;
                int my = sf::Mouse::getPosition(window).y;
                int x = mx * TEXTURE_WIDTH / WINDOW_WIDTH;
                int y = my * TEXTURE_HEIGHT / WINDOW_HEIGHT;
                    int currIndex = (x + (TEXTURE_WIDTH * y)) * 4;
                    std::cout << currIndex << std::endl;
                        pixels[currIndex] = 0; // obviously, assign the values you need here to form your color
                        pixels[currIndex+1] = 0;
                        pixels[currIndex+2] = 0;
                }
        }
        texture.update(pixels);

        sprite.setTexture(texture);
        sprite.setScale(WINDOW_WIDTH / TEXTURE_WIDTH, WINDOW_HEIGHT / TEXTURE_HEIGHT);
        // clear the window with black color
        window.clear(sf::Color::Black);
        // draw everything here...
        window.draw(sprite);

        // end the current frame
        window.display();
    }

    return 0;
}