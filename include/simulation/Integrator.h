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
  Integrator(IntegrationMethod intMethod);

  void advance(std::vector<Particle>& particles, const std::vector<Vector3>& forces,
                           double timestep);

private:
  void doEulerStep(std::vector<Particle>& particles, const std::vector<Vector3>& forces,
                   double timestep);
  IntegrationMethod integration_method_;

};