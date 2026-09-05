#include "../include/simulation/Particle.h"

Particle::Particle()
{
    mass_ = 0;
    position_ = {0.0, 0.0, 0.0};
    velocity_ = {0.0, 0.0, 0.0};
}
Particle::Particle(double mass, std::vector<double> position, std::vector<double> velocity)
    : mass_(mass), position_(position), velocity_(velocity)
{
    if (mass_ < 0)
    {
        throw std::invalid_argument("Mass cannot be negative.");
    }

    if (position_.size() != 3)
    {
        throw std::invalid_argument("Position must be a 3D vector.");
    }

    if (velocity_.size() != 3)
    {
        throw std::invalid_argument("Velocity must be a 3D vector.");
    }
}

double Particle::getMass() const
{
    return mass_;
}

std::vector<double> Particle::getPosition() const
{
    return position_;
}

std::vector<double> Particle::getVelocity() const
{
    return velocity_;
}

void Particle::setMass(double mass)
{
    mass_ = mass;
    if (mass_ < 0)
    {

        throw std::invalid_argument("Mass cannot be negative.");
    }
}

void Particle::setPosition(std::vector<double> position)
{
    position_ = position;
    if (position_.size() != 3)
    {
        throw std::invalid_argument("Position must be a 3D vector.");
    }
}

void Particle::setVelocity(std::vector<double> velocity)
{
    velocity_ = velocity;
    if (velocity_.size() != 3)
    {
        throw std::invalid_argument("Velocity must be a 3D vector.");
    }
}
