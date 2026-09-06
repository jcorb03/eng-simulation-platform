#pragma once

#include <vector>
#include "simulation/Vector3.h"
#include "simulation/Particle.h"

enum class IntegrationMethod
{
  EULER
};

class Integrator
{
public:
  Integrator(double timestep, IntegrationMethod intMethod);

  void advance(std::vector<Particle>& particles, const std::vector<Vector3>& forces);

private:
  IntegrationMethod integration_method_;

};