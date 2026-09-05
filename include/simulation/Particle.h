#pragma once

#include <iostream>
#include "simulation/Vector3.h"

class Particle
{
  public:
    Particle();
    Particle(double mass, Vector3 position, Vector3 velocity);
    
    double getMass() const;
    Vector3 getPosition() const;
    Vector3 getVelocity() const;

    void setMass(double mass);
    void setPosition(const Vector3& position);
    void setVelocity(const Vector3& velocity);

  private:
    double mass_;
    Vector3 position_;
    Vector3 velocity_;
};