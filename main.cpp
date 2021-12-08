#include <SFML/Graphics.hpp>
#include <iostream>
#ifdef __linux__
#error not yet supported you cuckold
#elif _WIN32
#include <windows.h>
#endif
#include "states.hpp"
int game()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "The Epic Boohbah Game");
    switchState<MainState>();
    sf::Music music;
    /* Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    */
    app.setFramerateLimit(60);
	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            switch(event.type){
            case sf::Event::Closed:
                app.close();
            case sf::Event::KeyPressed:
                curState->keyPress();
            }
        }
        // Clear screen
        app.clear(sf::Color::White);

        // Draw the sprite
        //app.draw(logo.sprite);
        curState->updateObj(&app);
        curState->update();

        // Update the window
        app.display();
    }
    delete curState;
    return EXIT_SUCCESS;
}

int main(){
#ifdef _WIN32
    int msgboxID = MessageBoxW(
        NULL,
        L"the boohbah game will most likely make you blow your brains out\nYou sure you want to continue?",
        L"VERY IMPORTANT WARNING",
        MB_ICONWARNING | MB_YESNO
    );
    return msgboxID==IDYES?game():0;
#elif __linux__
    return game();
#endif // __linux__

}
