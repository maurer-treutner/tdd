/**
 * @file test_CommandParser.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Google Test unit test example using Mocks
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "cmdproc/CommandParser.hxx"

using namespace cmdproc; 

class MockListener : public CommandListener
{
public:
    MockListener()
    {}

    MOCK_METHOD0(readCommand,std::string(void));
    MOCK_METHOD1(writeResponse,void(std::string));
};

class MockProcessor : public CommandProcessor
{
public:
    MockProcessor(){}

    MOCK_METHOD2(processCommand,Result(Command cmd,const std::vector<std::string> &params));
    MOCK_METHOD0(getResponse,std::string(void));

};


class test_MockListener : public testing::Test
{
public:
    void SetUp() override
    {
        testListener_ = std::make_shared<MockListener>();
        testProcessor_ = std::make_shared<MockProcessor>();
    };

    void TearDown() override
    {
        ASSERT_EQ(testListener_.use_count(),1);
        ASSERT_EQ(testProcessor_.use_count(),1);
    };

    CommandListener::Ptr testListener_;
    CommandProcessor::Ptr testProcessor_;

};

TEST_F(test_MockListener,constuct)
{
    CommandParser myParser(testListener_,testProcessor_);
    ASSERT_EQ(testListener_.use_count(),2);
    ASSERT_EQ(testProcessor_.use_count(),2);
}

