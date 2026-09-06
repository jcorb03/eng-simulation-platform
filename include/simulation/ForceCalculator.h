#pragma once

#include <vector>
#include <algorithm>
#include "simulation/Vector3.h"
#include "simulation/Particle.h"
#include "simulation/ForceType.h"

class ForceCalculator
{
public:
  ForceCalculator(std::vector<Forces> enabled_forces);

  std::vector<Vector3> calculateForces(const std::vector<Particle>& particles) const;

private:
  std::vector<Forces> enabled_forces_;
};