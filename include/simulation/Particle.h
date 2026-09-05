#pragma once

#include <vector>
#include <iostream>

class Particle
{
  public:
    Particle();
    Particle(double mass, std::vector<double> position, std::vector<double> velocity);
    
    double getMass() const;
    std::vector<double> getPosition() const;
    std::vector<double> getVelocity() const;

    void setMass(double mass);
    void setPosition(std::vector<double> position);
    void setVelocity(std::vector<double> velocity);

  private:
    double mass_;
    std::vector<double> position_;
    std::vector<double> velocity_;
};