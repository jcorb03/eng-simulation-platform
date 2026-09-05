#include <gtest/gtest.h>
#include "simulation/Vector3.h"

namespace simulation_tests
{
TEST(Vector_Test, DefaultConstruction)
{
  EXPECT_NO_THROW({ Vector3 v; });
  Vector3 v;
  EXPECT_EQ(v.x(), 0.0);
  EXPECT_EQ(v.y(), 0.0);
  EXPECT_EQ(v.z(), 0.0);
}

TEST(Vector_Test, Parameterized)
{
  EXPECT_NO_THROW({ Vector3 v(1.0, 2.0, 3.0); });
  Vector3 v(1.0, 2.0, 3.0);
  EXPECT_EQ(v.x(), 1.0);
  EXPECT_EQ(v.y(), 2.0);
  EXPECT_EQ(v.z(), 3.0);
}

TEST(Vector_Test, Addition)
{
  Vector3 v1(1.0, 2.0, 3.0);
  Vector3 v2(4.0, 5.0, 6.0);
  Vector3 v3 = v1 + v2;
  EXPECT_EQ(v3.x(), 5.0);
  EXPECT_EQ(v3.y(), 7.0);
  EXPECT_EQ(v3.z(), 9.0);
}

TEST(Vector_Test, Subtraction)
{
  Vector3 v1(4.0, 5.0, 6.0);
  Vector3 v2(1.0, 2.0, 3.0);
  Vector3 v3 = v1 - v2;
  EXPECT_EQ(v3.x(), 3.0);
  EXPECT_EQ(v3.y(), 3.0);
  EXPECT_EQ(v3.z(), 3.0);
}
TEST(Vector_Test, DotProduct)
{
  Vector3 v1(1.0, 2.0, 3.0);
  Vector3 v2(2.0, 4.0, 6.0);
  Vector3 v3 = v1.dot(v2);

  EXPECT_EQ(v3.x(), 2.0);
  EXPECT_EQ(v3.y(), 8.0);
  EXPECT_EQ(v3.z(), 18.0);
}
TEST(Vector_Test, ScalarMultiplication)
{
  Vector3 v(1.0, 2.0, 3.0);
  Vector3 v2 = v * 2.0;
  EXPECT_EQ(v2.x(), 2.0);
  EXPECT_EQ(v2.y(), 4.0);
  EXPECT_EQ(v2.z(), 6.0);
}
TEST(Vector_Test, ReverseScalarMultiplication)
{
  Vector3 v(1.0, 2.0, 3.0);
  Vector3 v2 = 2.0 * v;
  EXPECT_EQ(v2.x(), 2.0);
  EXPECT_EQ(v2.y(), 4.0);
  EXPECT_EQ(v2.z(), 6.0);
}

TEST(Vector_Test, Magnitude) {
  Vector3 v(0.0, 4.0, 3.0);

  EXPECT_NEAR(v.magnitude(), 5.0, 1e-10);
}
}
 
