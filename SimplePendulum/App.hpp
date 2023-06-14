#pragma once
#include "../Pendulum/Pendulum.cpp"
#include "SFML/Graphics.hpp"

class App {
private:
    // Custom Object
    Pendulum m_pendulum {};

    // App properties
    static const unsigned short m_windowLength { 800 };
    static const unsigned short m_windowHeight { 600 };
    sf::RenderWindow* m_window {};
    sf::Event m_eventHandler {};
    sf::Clock m_clock {}; // Internal Clock for the app
    sf::Time m_dt {}; // Delta time -> duration between each frame

private:
    void m_handleEvents();
    void m_update();
    void m_render();

public:
    void run();

public:
    App();
    ~App();
};