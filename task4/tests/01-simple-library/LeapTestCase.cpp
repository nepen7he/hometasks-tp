//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST_F(LeapTestCase, AccurateYears) {
    EXPECT_EQ(IsLeap(1600), true);
    EXPECT_EQ(IsLeap(1700), false);
    EXPECT_EQ(IsLeap(2020), true);
    EXPECT_EQ(IsLeap(3333), false);
}

TEST_F(LeapTestCase, Month) {
    EXPECT_EQ(GetMonthDays(2020, 2), 29);
    EXPECT_EQ(GetMonthDays(2021, 2), 28);
    EXPECT_EQ(GetMonthDays(2019, 6), 30);
    EXPECT_EQ(GetMonthDays(2018, 7), 31);
}

TEST_F(LeapTestCase, ExceptionAssertion) {
    EXPECT_THROW(IsLeap(-1000), std::invalid_argument);
    EXPECT_THROW(GetMonthDays(2000, -5), std::invalid_argument);
}
