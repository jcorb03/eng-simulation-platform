#include <gtest/gtest.h>
#include "simulation/ParticleSimulation.h"

namespace simulation_tests
{
TEST(ParticleSimulationTest, DefaultConstruction)
{
  EXPECT_NO_THROW({ ParticleSimulation sim; });
}

TEST(ParticleSimulationTest, Construction)
{
  std::vector<Particle> particles;
  particles.emplace_back(1.0, Vector3(0.0, 0.0, 0.0), Vector3(1.0, 1.0, 1.0),
                         Vector3(0.0, 0.0, 0.0));
  EXPECT_NO_THROW({ ParticleSimulation sim(particles, 5.0, 0.02); });
  ParticleSimulation sim(particles, 5.0, 0.02);
}
TEST(ParticleSimulationTest, SetForces)
{
  ParticleSimulation sim;
  Particle p(1.0, Vector3(0.0, 0.0, 0.0), Vector3(1.0, 1.0, 1.0), Vector3(0.0, 0.0, 0.0));
  std::vector<Forces> forces = {Forces::GRAVITY, Forces::DRAG};
  EXPECT_NO_THROW(sim.setForces(forces));
}
} // namespace simulation_tests