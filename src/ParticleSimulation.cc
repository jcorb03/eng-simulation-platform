#include "simulation/ParticleSimulation.h"

ParticleSimulation::ParticleSimulation() 
  : sim_length_(10.0), timestep_(0.01)
{
}
ParticleSimulation::ParticleSimulation(std::vector<Particle> particles, double sim_length,
                                       double timeStep)
    : particles_(particles), sim_length_(sim_length), timestep_(timeStep)
{
}

void ParticleSimulation::addParticle(const Particle& particle) {
  particles_.push_back(particle);
}
void ParticleSimulation::setSimulationLength(double length) 
{
  sim_length_ = length;
}

void ParticleSimulation::setForces(const std::vector<Forces>& forces)
{
  std::vector<Forces> cleaned_forces = forces;

  std::sort(cleaned_forces.begin(), cleaned_forces.end());
  
  // Move all duplicates to last of vector
  auto it = std::unique(cleaned_forces.begin(), cleaned_forces.end());

  // Remove all duplicates
  cleaned_forces.erase(it, cleaned_forces.end());
    
  enabled_forces_ = cleaned_forces;
}

void ParticleSimulation::addForce(Forces force)
{
  if (std::find(enabled_forces_.begin(), enabled_forces_.end(), force) == enabled_forces_.end())
  enabled_forces_.push_back(force);
}

void ParticleSimulation::setTimeStep(double timeStep) 
{
  timestep_ = timeStep;
}

void ParticleSimulation::runSimulation() {
  
}



