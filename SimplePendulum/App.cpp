#pragma once
#include "App.hpp"

using namespace std::literals;

App::App()
{
    m_window = new sf::RenderWindow(sf::VideoMode(m_windowLength, m_windowHeight), sf::String("Pendulum Simulation"s), sf::Style::Default);
    m_window->setFramerateLimit(120);
}

App::~App()
{
    delete m_window;
}

void App::run()
{
    // Initial configuration of pendulum
    m_pendulum.setPosition(m_windowLength / 2, m_windowHeight / 2); // Move pendulum to center of screen
    m_pendulum.setiAngle(50.f); // Angle from vertical
    m_pendulum.setDampCoeff(0.01f); // Setting the drag
    while (m_window->isOpen()) {
        m_handleEvents();
        m_update();
        m_render();
    }
}

void App::m_handleEvents()
{
    // Event handling
    while (m_window->pollEvent(m_eventHandler)) {
        switch (m_eventHandler.type) {
        case sf::Event::Closed:
            m_window->close();
            break;
        default:
            break;
        }
    }
}

void App::m_update()
{
    // Update logic
    m_dt = m_clock.restart();
    m_pendulum.update(m_dt);
}

void App::m_render()
{
    // By default clears previous frame with black color
    m_window->clear();

    m_window->draw(m_pendulum);

    m_window->display();
}