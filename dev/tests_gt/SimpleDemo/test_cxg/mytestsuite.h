/**
 * @file mytestsuite.h
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief 
 * @version 0.1
 * @date 2019-01-14
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

class MyTestSyite1: public CxxTest::TestSuite
{
    public:
    void testAddition(void)
    {
        TS_ASSERT(1+1 > 1);
        TS_ASSERT_EQUALS(1+1,2);
    }
};