//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"


TEST_F(AddTestCase, AllNums) {
    EXPECT_EQ(Add(10, 15), 25);
    EXPECT_EQ(Add(32, 68), 100);
    EXPECT_EQ(Add(-10, 15), 5);
    EXPECT_EQ(Add(0, -10), -10);
}