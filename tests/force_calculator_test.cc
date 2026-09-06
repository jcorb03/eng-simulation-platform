#include "simulation/ForceCalculator.h"
#include <gtest/gtest.h>

namespace simulation_tests
{
TEST(ForceCalculatorTest, Constructs)
{
  std::vector<Forces> enabled_forces = {Forces::GRAVITY, Forces::DRAG};

  EXPECT_NO_THROW(ForceCalculator force_calculator(enabled_forces));
}
TEST(ForceCalculatorTest, Gravity)
{
  std::vector<Forces> enabled_forces = {Forces::GRAVITY};
  std::vector<Particle> particles = {
      Particle(1.0, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0))};

  ForceCalculator force_calculator(enabled_forces);

  std::vector<Vector3> forces = force_calculator.calculateForces(particles);

  EXPECT_NEAR(forces.at(0).z(), -9.81, 1e-10);
}
TEST(ForceCalculatorTest, Drag)
{
  std::vector<Forces> enabled_forces = {Forces::DRAG};
  std::vector<Particle> particles = {
      Particle(1.0, Vector3(0, 0, 0), Vector3(5, 4, 3), Vector3(0, 0, 0))};

  ForceCalculator force_calculator(enabled_forces);

  std::vector<Vector3> forces = force_calculator.calculateForces(particles);

  EXPECT_NEAR(forces.at(0).x(), -50.0, 1e-10);
  EXPECT_NEAR(forces.at(0).y(), -40.0, 1e-10);
  EXPECT_NEAR(forces.at(0).z(), -30.0, 1e-10);
}
TEST(ForceCalculatorTest, MultipleParticles)
{
  std::vector<Forces> enabled_forces = {Forces::GRAVITY};

  std::vector<Particle> particles = {
      Particle(1.0, Vector3(0, 0, 0), Vector3(5, 4, 3), Vector3(0, 0, 0)),
      Particle(5.0, Vector3(5, 0, 0), Vector3(2, 4, 3), Vector3(6, 0, 0))
  };

  ForceCalculator force_calculator(enabled_forces);

  std::vector<Vector3> forces = force_calculator.calculateForces(particles);

  EXPECT_EQ(forces.size(), 2);

  EXPECT_NEAR(forces.at(0).z(), -9.81, 1e-10);
  EXPECT_NEAR(forces.at(1).z(), 5.0*-9.81, 1e-10);
  
}
} // namespace simulation_tests