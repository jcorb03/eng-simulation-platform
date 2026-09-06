#include "simulation/ForceCalculator.h"

ForceCalculator::ForceCalculator(std::vector<Forces> enabled_forces) {
  enabled_forces_ = enabled_forces;
}

std::vector<Vector3> ForceCalculator::calculateForces(const std::vector<Particle>& particles) const
{
  std::vector<Vector3> forces;
  forces.reserve(particles.size());
  
  bool gravity_enabled = std::find(enabled_forces_.begin(), enabled_forces_.end(),
                                   Forces::GRAVITY) != enabled_forces_.end();

  bool drag_enabled = std::find(enabled_forces_.begin(), enabled_forces_.end(), Forces::DRAG) !=
                      enabled_forces_.end();

  for (const Particle& particle : particles)
  {
    Vector3 force(0.0, 0.0, 0.0);
    if (gravity_enabled)
    {
      force = force + Vector3(0.0, 0.0, -9.81 * particle.getMass());
    }
    if (drag_enabled)
    {
      Vector3 v = particle.getVelocity();
      Vector3 drag = -10.0 * v;
      force = force + drag;
    }
    forces.push_back(force);
  }
  
  return forces;
}