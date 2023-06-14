#pragma once
#include "SFML/Graphics.hpp"

class Pendulum : public sf::Drawable, sf::Transformable {
private:
    float m_iAngle {};
    float m_gravity { 9.80665f };
    float m_aVel {};
    float m_aAcc {};
    float m_currAngle {};
    float m_dampCoeff {};

    float m_mass {};
    float m_length {};
    float m_X {};
    float m_Y {};

    sf::RectangleShape m_line {};
    sf::CircleShape m_circle { 5.f };

public:
    Pendulum(const float mass = 10.f, const float length = 70.f, const float angle = 15.f);

public:
    void setPosition(float X, float Y);
    void setLength(float length);
    void setMass(float mass);
    void setiAngle(float angle);
    void setGravity(float g);
    void setDampCoeff(float b);
    void rotate();

public:
    void update(sf::Time dt);

public:
    float getLength() const;
    float getMass() const;
    float getAVel() const;
    float getAAcc() const;
    float getCurrAngle() const;
    float getGravity() const;
    float getDampCoeff() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        // states.texture = NULL;

        target.draw(m_line, states);
        target.draw(m_circle, states);
    }
};