#include <nbody/Body>
#include <nbody/Vector3.h>
#include <gtest/gtest.h>

//Testing the bodies getter and setter methods
TEST( bodyTest, initTest ){
	auto body1 = Body{};

	body.position() = Vector3f {1 , 2, 3};

	ASSERT_FLOAT_EQ( body.position().x(), 1.0f);
	ASSERT_FLOAT_EQ( body.position().y(), 2.0f);
	ASSERT_FLOAT_EQ( body.position().z(), 3.0f);

	body.velocity() = Vector3f {4, 5, 6};

	ASSERT_FLOAT_EQ( body.velocity().x(), 4.0f);
	ASSERT_FLOAT_EQ( body.velocity().y(), 5.0f);
	ASSERT_FLOAT_EQ( body.velocity().z(), 6.0f);

	body.force() = Vector3f {4, 5, 6};

	ASSERT_FLOAT_EQ( body.force().x(), 4.0f);
	ASSERT_FLOAT_EQ( body.force().y(), 5.0f);
	ASSERT_FLOAT_EQ( body.force().z(), 6.0f);

	ASSERT_FLOAT_EQ( body.mass(), 0);
}