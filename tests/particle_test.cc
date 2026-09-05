#include "simulation/Particle.h"
#include <gtest/gtest.h>
namespace simulation_tests
{

TEST(ParticleTest, DefaultConstruction)
{
  EXPECT_NO_THROW({ Particle p; });
  Particle p;
  Vector3 v;
  EXPECT_EQ(p.getMass(), 1.0);
  EXPECT_EQ(p.getPosition().x(), 0.0);
  EXPECT_EQ(p.getVelocity().y(), 0.0);
}

TEST(ParticleTest, Construction)
{
  EXPECT_NO_THROW({ Particle p(1.0, {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}); });
  Particle p(1.0, {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0});
  EXPECT_EQ(p.getMass(), 1.0);
  EXPECT_EQ(p.getPosition().x(), 1.0);
  EXPECT_EQ(p.getPosition().y(), 2.0);
  EXPECT_EQ(p.getPosition().z(), 3.0);
  EXPECT_EQ(p.getVelocity().x(), 4.0);
  EXPECT_EQ(p.getVelocity().y(), 5.0);
  EXPECT_EQ(p.getVelocity().z(), 6.0);
}

TEST(ParticleTest, SetMass)
{
  Particle p;
  EXPECT_NO_THROW(p.setMass(2.0););
  EXPECT_EQ(p.getMass(), 2.0);

  EXPECT_THROW(p.setMass(-2.0), std::invalid_argument);
  EXPECT_EQ(p.getMass(), 2.0);

  EXPECT_THROW(p.setMass(0.0), std::invalid_argument);
  EXPECT_EQ(p.getMass(), 2.0);
}

TEST(ParticleTest, SetPosition)
{
  Particle p;
  Vector3 v(1.0, 2.0, 3.0);
  EXPECT_NO_THROW(p.setPosition(v));
  EXPECT_EQ(p.getPosition().x(), 1.0);
  
}

TEST(ParticleTest, SetVelocity)
{
  Particle p;
  Vector3 v(1.0, 2.0, 3.0);
  EXPECT_NO_THROW(p.setVelocity(v));
  EXPECT_EQ(p.getVelocity().x(), 1.0);
  
}
} // namespace simulation_tests