/*
 * AllTests.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: ranran9991
 */
#include "gtest/gtest.h"

#include "boardTest.cpp"

int main(int argc, char* argv[]){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
