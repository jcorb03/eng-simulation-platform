#include "simulation/Particle.h"

Particle::Particle()
{
  mass_ = 1;
  position_ = {0.0, 0.0, 0.0};
  velocity_ = {0.0, 0.0, 0.0};
}
Particle::Particle(double mass, Vector3 position, Vector3 velocity, Vector3 acceleration)
    : mass_(mass), position_(position), velocity_(velocity), acceleration_(acceleration)
{
  if (mass_ < 0)
  {
    throw std::invalid_argument("Mass cannot be negative.");
  }
  if (mass_ == 0)
  {
    throw std::invalid_argument("Mass cannot be zero.");
  }

  
}

double Particle::getMass() const
{
  return mass_;
}

Vector3 Particle::getPosition() const
{
  return position_;
}

Vector3 Particle::getVelocity() const
{
  return velocity_;
}

Vector3 Particle::getAcceleration() const
{
  return acceleration_;
}

void Particle::setMass(double mass)
{
  
  if (mass < 0)
  {

    throw std::invalid_argument("Mass cannot be negative.");
  }

  if (mass == 0)
  {
    throw std::invalid_argument("Mass cannot be zero.");
  }

  mass_ = mass;
}

void Particle::setPosition(const Vector3& position)
{
  
  
  position_ = position;
}

void Particle::setVelocity(const Vector3& velocity)
{
  velocity_ = velocity;
}

void Particle::setAcceleration(const Vector3& acceleration)
{
  acceleration_ = acceleration;
}
