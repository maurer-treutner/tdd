/**
 * @file test_LoginService.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Unit test demonstrating use of a stub
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "user/LoginService.hxx"

#include <gtest/gtest.h>

using namespace user;

class StubAccountMgr : public AccountMgr
{
public:
    const std::string invalidUserName = "invalidUser";
    const std::string invalidPasswd = "invalidPasswd";

    UserId getUserId(std::string userName)
    {
        if (userName==invalidUserName)
            return INVALID_UID;
        else
            return 42;
    }
    
    bool checkPassword(UserId id, std::string passWd)
    {
        if (passWd != invalidPasswd)
            return true;
        else 
            return false;
    }
};

class test_LoginService : public testing::Test
{
public:
    void SetUp() override
    {
        testee_ = std::make_unique<LoginService>(std::make_unique<StubAccountMgr>());
    };

    void TearDown() override{};

    LoginService::Ptr testee_;
};

TEST_F(test_LoginService,validLogin)
{
    auto uid = testee_->login("user1","passwd1");
    ASSERT_NE(uid,INVALID_UID);
    ASSERT_TRUE(testee_->userLoggedIn());
}

TEST_F(test_LoginService,invalidUserName)
{
    ASSERT_THROW(testee_->login("invalidUser","passwd1"),LoginService::InvalidUser);
    ASSERT_FALSE(testee_->userLoggedIn());
}

TEST_F(test_LoginService,invalidPassword)
{
    ASSERT_THROW(testee_->login("user1","invalidPasswd"),LoginService::InvalidPassword);
    ASSERT_FALSE(testee_->userLoggedIn());
}

TEST_F(test_LoginService,loginLogout)
{
    testee_->login("user1","passwd1");
    ASSERT_TRUE(testee_->userLoggedIn());
    ASSERT_THROW(testee_->login("user1","passwd1"),LoginService::AlreadLoggedIn);
    testee_->logout();
    ASSERT_FALSE(testee_->userLoggedIn());
    ASSERT_NO_THROW(testee_->login("user1","passwd1"));
    ASSERT_TRUE(testee_->userLoggedIn());
}