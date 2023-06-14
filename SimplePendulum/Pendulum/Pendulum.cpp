#pragma once
#include "Pendulum.hpp"
#include <cmath>
#include <numbers>

// Specify initial angle, length and mass of pendulum
Pendulum::Pendulum(const float angle, const float length, const float mass)
    : m_mass { mass }
    , m_length { length }
    , m_iAngle { angle }
    , m_currAngle { angle }
{
    m_line = sf::RectangleShape(sf::Vector2f(1, length)); // Using a rectangle as a rod
    m_circle.setOrigin(m_circle.getRadius(), m_circle.getRadius()); // Setting origin of circle to the center
}

float Pendulum::getLength() const
{
    return m_length;
}

float Pendulum::getMass() const
{
    return m_mass;
}

float Pendulum::getCurrAngle() const
{
    return m_currAngle;
}

float Pendulum::getAVel() const
{
    return m_aVel;
}

float Pendulum::getAAcc() const
{
    return m_aAcc;
}

float Pendulum::getGravity() const
{
    return m_gravity;
}

float Pendulum::getDampCoeff() const
{
    return m_dampCoeff;
}

void Pendulum::setPosition(float X, float Y)
{
    // Initially setting pendulum in vertical configuration
    m_X = X, m_Y = Y;
    m_line.setPosition(m_X, m_Y);
    m_circle.setPosition(
        m_X, m_Y + m_length);
}

void Pendulum::setLength(float length)
{
    m_length = length;
    m_line.setSize(sf::Vector2f(1, length));
}

void Pendulum::setMass(float mass)
{
    m_mass = mass;
}

void Pendulum::setiAngle(float angle)
{
    m_iAngle = angle;
    m_currAngle = angle;
    m_line.setRotation(-angle); // negative angle because SFML considers clockwise as positive and anticlockwise as negative
    m_circle.setPosition(
        m_X + m_length * std::sin((angle * std::numbers::pi) / 180), // Rotating the bob
        m_Y + m_length * std::cos((angle * std::numbers::pi) / 180));
}

// Gravity has been purposfully kept modifiable
void Pendulum::setGravity(float g)
{
    m_gravity = g;
}

void Pendulum::setDampCoeff(float b)
{
    m_dampCoeff = b;
}

void Pendulum::rotate()
{
    m_line.setRotation(-m_currAngle);
    m_circle.setPosition(
        m_X + m_length * std::sin((m_currAngle * std::numbers::pi) / 180),
        m_Y + m_length * std::cos((m_currAngle * std::numbers::pi) / 180));
}

void Pendulum::update(sf::Time dt /* dt time is used for updating movement of pendulum */)
{
    m_aAcc = -((m_gravity / m_length) * std::sin(m_currAngle * std::numbers::pi / 180) + (m_dampCoeff * m_aVel) / 2);
    m_aVel += (m_aAcc * dt.asSeconds()) * 50; // factor of 50 increases the speed of swing else movement takes a long time kind of fast forwarding the motion
    m_currAngle += (m_aVel * dt.asSeconds()) * 50;
    rotate();
}