#include "simulation/Integrator.h"
#include <stdexcept>

Integrator::Integrator(IntegrationMethod int_method) : integration_method_(int_method) {
}

void Integrator::advance(std::vector<Particle>& particles, const std::vector<Vector3>& forces,
                         double timestep)
{

  if (particles.size() != forces.size())
  {
    throw std::invalid_argument("Particle and force vectors are not equal size");
  }
  if (timestep <= 0.0)
  {
    throw std::invalid_argument("Timestep must be positive");
  }

  if (integration_method_ == IntegrationMethod::EULER)
  {
    doEulerStep(particles, forces, timestep);
  }
}

void Integrator::doEulerStep(std::vector<Particle>& particles, const std::vector<Vector3>& forces,
                 double timestep)
{
  for (std::size_t i = 0; i < particles.size(); ++i)
  {
    particles.at(i).setAcceleration(forces.at(i) / particles.at(i).getMass());

    particles.at(i).setPosition(particles.at(i).getPosition() +
                                particles.at(i).getVelocity() * timestep);

    particles.at(i).setVelocity(particles.at(i).getVelocity() + 
      particles.at(i).getAcceleration() * timestep);

  }
}
