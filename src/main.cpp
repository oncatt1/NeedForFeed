#include <iostream>

#include <SFML/Graphics.hpp>
#include "car.h"
#include "map.h"

const unsigned short screen_type_resolution[4][2] = { {3840, 2160}, {1920, 1080}, {1366, 768} ,{1680, 1050} };
sf::RenderWindow window;

sf::Clock sim_clock;
unsigned short frameCount = 0;
float fpsTimer = 0.0f;
unsigned short fps = 1;
float time_accumulator = 0.0f;

const bool fullscreen = true;
const unsigned short screen_type = 0;
const int max_fps = 60;  


int WIDTH = static_cast<int>(screen_type_resolution[screen_type][0]);
int HEIGHT = static_cast<int>(screen_type_resolution[screen_type][1]);

int main(){
    if(fullscreen) window.create(sf::VideoMode({ static_cast<unsigned int>(screen_type_resolution[screen_type][0]), static_cast<unsigned int>(screen_type_resolution[screen_type][0]) }), "Need for Feed", sf::State::Fullscreen);
    else window.create(sf::VideoMode({ static_cast<unsigned int>(screen_type_resolution[screen_type][0]), static_cast<unsigned int>(screen_type_resolution[screen_type][0]) }), "Need For Feed");
    window.setFramerateLimit(max_fps);

    while (window.isOpen())
    {
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) { window.close(); }
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::LShift) { }
            }
        }

        float deltaTime = sim_clock.restart().asSeconds();
        fpsTimer += deltaTime;
        time_accumulator += deltaTime;
        frameCount++;

        window.clear();


        if (fpsTimer >= 1.0f) {
            fps = frameCount / fpsTimer;
            frameCount = 0;
            fpsTimer = 0.0f;
        }

        
        window.display();
    }
    return 0;
}