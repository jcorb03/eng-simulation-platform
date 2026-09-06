#include <gtest/gtest.h>
#include "simulation/Integrator.h"

namespace simulation_tests
{

  TEST(IntegratorTest, AdvanceWithMismatchedSizesThrows)
  {
	Integrator integrator(IntegrationMethod::EULER);
    std::vector<Particle> particles = {
    Particle(1.0, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0))};
	std::vector<Vector3> forces = {Vector3(1, 0, 0), Vector3(0, 1, 0)};
	double timestep = 0.01;
	EXPECT_THROW(integrator.advance(particles, forces, timestep), std::invalid_argument);
  }
  TEST(IntegratorTest, AdvanceWithNonPositiveTimestepThrows)
  {
	Integrator integrator(IntegrationMethod::EULER);
    std::vector<Particle> particles = {Particle(1.0, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0)),
    Particle(1.0, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0))};
	std::vector<Vector3> forces = {Vector3(1, 0, 0), Vector3(0, 1, 0)};
	double timestep = -0.01;
	EXPECT_THROW(integrator.advance(particles, forces, timestep), std::invalid_argument);
  }
  TEST(IntegratorTest, Advance) {
    Integrator integrator(IntegrationMethod::EULER);
    std::vector<Particle> particles = {
        Particle(1.0, Vector3(0, 0, 0), Vector3(0, 0, 1), Vector3(0, 0, 0)),
        Particle(1.0, Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 0))};
    std::vector<Vector3> forces = {Vector3(1, 0, 0), Vector3(0, 1, 0)};
    double timestep = 0.01;
    EXPECT_NO_THROW(integrator.advance(particles, forces, timestep));

    EXPECT_NEAR(particles.at(0).getAcceleration().x(), 1.0, 1e-6);
    EXPECT_NEAR(particles.at(1).getAcceleration().y(), 1.0, 1e-6);

    EXPECT_NEAR(particles.at(0).getPosition().z(), 0.01, 1e-6);
    EXPECT_NEAR(particles.at(1).getPosition().y(), 0.01, 1e-6);

    EXPECT_NEAR(particles.at(0).getVelocity().x(), 0.01, 1e-6);
    EXPECT_NEAR(particles.at(1).getVelocity().y(), 1.01, 1e-6);
  }
  } // namespace simulation_tests