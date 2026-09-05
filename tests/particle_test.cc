#include "simulation/Particle.h"
#include <gtest/gtest.h>
namespace simulation_tests
{

TEST(ParticleTest, DefaultConstruction)
{
    EXPECT_NO_THROW({ Particle p; });
    Particle p;
    EXPECT_EQ(p.getMass(), 0.0);
    EXPECT_EQ(p.getPosition(), std::vector<double>({0.0, 0.0, 0.0}));
    EXPECT_EQ(p.getVelocity(), std::vector<double>({0.0, 0.0, 0.0}));
}

TEST(ParticleTest, Construction)
{
    EXPECT_NO_THROW({ Particle p(1.0, {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}); });
    Particle p(1.0, {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0});
    EXPECT_EQ(p.getMass(), 1.0);
    EXPECT_EQ(p.getPosition(), std::vector<double>({1.0, 2.0, 3.0}));
    EXPECT_EQ(p.getVelocity(), std::vector<double>({4.0, 5.0, 6.0}));
}

TEST(ParticleTest, SetMass)
{
    Particle p;
    EXPECT_NO_THROW(p.setMass(2.0););
    EXPECT_EQ(p.getMass(), 2.0);

    EXPECT_ANY_THROW(p.setMass(-1.0));
}

TEST(ParticleTest, SetPosition)
{
    Particle p;
    EXPECT_NO_THROW(p.setPosition({1.0, 2.0, 3.0}));
    EXPECT_EQ(p.getPosition(), std::vector<double>({1.0, 2.0, 3.0}));
    EXPECT_ANY_THROW(p.setPosition({1.0, 2.0})); // Not a 3D vector
}

TEST(ParticleTest, SetVelocity)
{
    Particle p;
    EXPECT_NO_THROW(p.setVelocity({1.0, 2.0, 3.0}));
    EXPECT_EQ(p.getVelocity(), std::vector<double>({1.0, 2.0, 3.0}));
    EXPECT_ANY_THROW(p.setVelocity({1.0, 2.0})); // Not a 3D vector
}
} // namespace simulation_tests