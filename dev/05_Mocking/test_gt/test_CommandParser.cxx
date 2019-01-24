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

class CommandParserTestHelper : public CommandParser
{
public:
    using Ptr = std::shared_ptr<CommandParserTestHelper>;
    using CommandParser::CommandParser;

    auto helper_tokenize(std::string& s)
    {
        return tokenize(s);
    }
};

class MockListener : public CommandListener
{
  public:
    using Ptr = std::shared_ptr<MockListener>;
    MockListener()
    {
    }

    MOCK_METHOD0(readCommand, std::string(void));
    MOCK_METHOD1(writeResponse, void(std::string));
};

class MockProcessor : public CommandProcessor
{
  public:
    using Ptr = std::shared_ptr<MockProcessor>;
    MockProcessor() {}

    MOCK_METHOD2(processCommand, Result(Command cmd, const std::vector<std::string> &params));
    MOCK_METHOD0(getResponse, std::string(void));
};

class test_CommandParser : public testing::Test
{
  public:
    void SetUp() override
    {
        testListener_ = std::make_shared<MockListener>();
        testProcessor_ = std::make_shared<MockProcessor>();
        testee_ = std::make_shared<CommandParserTestHelper>(testListener_, testProcessor_);
    };

    void TearDown() override
    {
        testee_ = nullptr;
        ASSERT_EQ(testListener_.use_count(), 1);
        ASSERT_EQ(testProcessor_.use_count(), 1);
    };

    CommandParserTestHelper::Ptr testee_;

    MockListener::Ptr testListener_;
    MockProcessor::Ptr testProcessor_;
};

TEST_F(test_CommandParser, constuct)
{
    ASSERT_EQ(testListener_.use_count(), 2);
    ASSERT_EQ(testProcessor_.use_count(), 2);
}

TEST_F(test_CommandParser, tokenize)
{
    std::string s1 = "a b c";
    std::vector<std::string> s1_tokens = {"a","b","c"};
    auto result = testee_->helper_tokenize(s1);
    ASSERT_EQ(s1_tokens,result);
}

TEST_F(test_CommandParser, cmdHello)
{
    std::string msgString = "HELLO Peter";
    std::vector<std::string> msgTokens={"HELLO","Peter"};

    EXPECT_CALL(*testListener_, readCommand())
        .WillOnce(testing::Return(msgString));
    EXPECT_CALL(*testProcessor_,processCommand(Command::HELLO,msgTokens));
    EXPECT_TRUE(testee_->processNextCommand());
}

TEST_F(test_CommandParser, unknownCmd)
{
    std::string msgString = "XXXX";
    
    EXPECT_CALL(*testListener_,readCommand()).WillOnce(testing::Return(msgString));
    EXPECT_FALSE(testee_->processNextCommand());
}

TEST_F(test_CommandParser, emptyCmd)
{
    std::string msgString = "";
    
    EXPECT_CALL(*testListener_,readCommand()).WillOnce(testing::Return(msgString));
    EXPECT_FALSE(testee_->processNextCommand());
}