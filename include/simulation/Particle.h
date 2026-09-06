#pragma once

#include <iostream>
#include "simulation/Vector3.h"

class Particle
{
  public:
    Particle();
    Particle(double mass, Vector3 position, Vector3 velocity, Vector3 acceleration);
    
    double getMass() const;
    Vector3 getPosition() const;
    Vector3 getVelocity() const;
    Vector3 getAcceleration() const;

    void setMass(double mass);
    void setPosition(const Vector3& position);
    void setVelocity(const Vector3& velocity);
    void setAcceleration(const Vector3& acceleration);

  private:
    double mass_;
    Vector3 position_;
    Vector3 velocity_;
    Vector3 acceleration_;
};