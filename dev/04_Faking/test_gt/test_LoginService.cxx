/**
 * @file test_LoginService.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Unit test demonstrating use of a stub
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "user2/LoginService.hxx"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

using namespace user2;

class FakeAccountMgr : public AccountMgr
{
public:
    const std::string invalidUserName = "invalidUser";
    const std::string invalidPasswd = "invalidPasswd";

    UserId getUserId(std::string userName)
    {
        for (auto userEntry : accountMap_)
        {
            if (std::get<1>(userEntry)==userName)
            {
                return std::get<0>(userEntry);
            }
        }
        return INVALID_UID;
    }
    
    bool checkPassword(UserId id, std::string passWd)
    {
        for (auto userEntry : accountMap_)
        {
            if (std::get<0>(userEntry)==id && std::get<2>(userEntry)==passWd)
            {
                return true;
            }
        }
        return false;
    }

    std::vector<std::tuple<UserId,std::string,std::string>> accountMap_ =
    {
        std::make_tuple(0,"root","abcdef"),
        std::make_tuple(100,"pm","qwe123"),
        std::make_tuple(200,"kt","asd456")
    };
};

class test_LoginService : public testing::Test
{
public:
    void SetUp() override
    {
        testee_ = std::make_unique<LoginService>(std::make_unique<FakeAccountMgr>());
    };

    void TearDown() override{};

    LoginService::Ptr testee_;
};

TEST_F(test_LoginService,validLogin)
{
    auto uid = testee_->login("root","abcdef");
    ASSERT_NE(uid,INVALID_UID);
    ASSERT_TRUE(testee_->userLoggedIn());
}

TEST_F(test_LoginService,invalidUserName)
{
    ASSERT_THROW(testee_->login("xxxxxx","abcdef"),LoginService::InvalidUser);
    ASSERT_FALSE(testee_->userLoggedIn());
}

TEST_F(test_LoginService,invalidPassword)
{
    ASSERT_THROW(testee_->login("pm","invalidPasswd"),LoginService::InvalidPassword);
    ASSERT_FALSE(testee_->userLoggedIn());
}

TEST_F(test_LoginService,loginLogout)
{
    testee_->login("pm","qwe123");
    ASSERT_TRUE(testee_->userLoggedIn());
    ASSERT_THROW(testee_->login("kt","asd456"),LoginService::AlreadLoggedIn);
    testee_->logout();
    ASSERT_FALSE(testee_->userLoggedIn());
    ASSERT_NO_THROW(testee_->login("kt","asd456"));
    ASSERT_TRUE(testee_->userLoggedIn());
}