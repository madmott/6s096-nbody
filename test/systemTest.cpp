#include <nbody/System>
#include <gtest/gtest.h>

//Testing to make sure that the system can sucessfully add and retreive bodies
TEST( systemTest, bodyTest ){
	auto testSystem = System{};
	auto testBody = Body{};
	auto testBody2 = Body{};

	testSystem.addBody(testBody);
	testSystem.addBody(testBody2);

	ASSERT_TRUE( *testSystem.getBodies()[0] == *testBody);
	ASSERT_TRUE( *testSystem.getBodies()[1] == *testBody2);
}