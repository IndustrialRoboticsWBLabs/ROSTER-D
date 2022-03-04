// Example of unit test script: http://wiki.ros.org/gtest

// This script is the unit test for the library, this is run when during compilation process the run tests flag is called.(see gtest link above) 

#include </opt/ros/melodic/include/ros/ros.h>

// Bring in any headers needed to run the system during the unit test

// Bring in gtest
#include <gtest/gtest.h>
#include "../src/generic.h"

#include <climits> // C limit on integers is grbabbed from this library

// Declare a test
TEST(NumberCmpTest, ShouldPass){
	ASSERT_EQ(3, add(1,2));
}

// This test should fail due to inputs not matching expected output
TEST(NumberCmpTest, ShouldFail){
	ASSERT_EQ(3, add(1, 1));
}

// This test should also fail due to overflow
TEST(NumberCmpTest, ShouldFail2){
	ASSERT_EQ(INT_MAX, add(INT_MAX, 1));
}

// Declare a test
TEST(TestSuite, testCase1)
{
	ASSERT_EQ( 5 , 5); 	// this test will pass
	ASSERT_EQ( 2 , 5);	// this test will FAIL
	// can write as many assertions as required
}

// Declare a second test (can declare as many tests as needed)
TEST(TestSuite, testCase2)
{
	ASSERT_EQ( 5 , 5); 	// this test will pass
}

//  Further assertion functions: http://google.github.io/googletest/reference/assertions.html

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);	//Standard main code for ros unit test
  ros::init(argc, argv, "tester");	//Standard main code for ros unit test
  ros::NodeHandle nh;	//Standard main code for ros unit test
  return RUN_ALL_TESTS();	//Standard main code for ros unit test (starts TEST functions)
}
