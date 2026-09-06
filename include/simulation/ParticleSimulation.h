#pragma once
#include "simulation/Particle.h"
#include "simulation/ForceType.h"
#include <vector>
#include <algorithm>

class ParticleSimulation
{
public:
  ParticleSimulation();
  ParticleSimulation(std::vector<Particle> particles, double sim_length, double timeStep);

  void addParticle(const Particle& particle);
  void setSimulationLength(double length);
  void setTimeStep(double timeStep);
  void runSimulation();
  void setForces(const std::vector<Forces>& forces);
  void addForce(const Forces forces);

private:
  std::vector<Particle> particles_;
  double timestep_ = 0.01;
  double sim_length_ = 10.0;
  std::vector<Forces> enabled_forces_ = {};
};

