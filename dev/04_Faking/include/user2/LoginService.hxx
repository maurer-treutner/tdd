/**
 * @file LoginService.hxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Demo class for unit tests
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "user2/AccountMgr.hxx"

#include <memory>

namespace user2
{
    class LoginService
    {
    public:
        using Ptr = std::unique_ptr<LoginService>;

        LoginService(AccountMgr::Ptr&& accMgr);

        struct InvalidUser : public std::runtime_error
        {
            InvalidUser():std::runtime_error("Invalid User Name"){}
        };
        struct InvalidPassword : public std::runtime_error
        {
            InvalidPassword():std::runtime_error("Invalid Password"){}
        };
        struct AlreadLoggedIn : public std::runtime_error
        {
            AlreadLoggedIn():std::runtime_error("Already Logged In"){}
        };

        /**
         * @brief Trys to login a user
         *
         * @param userName 
         * @param passWord 
         * 
         * @throws InvalidUser when user name is not accepted
         * @throws InvalidPassword when password is not accepted for user
         * @throws AlreadyLoggedIn when a user is already logged in
         */
        AccountMgr::UserId login(std::string userName, std::string passWord);

        /**
         * @brief Trys to log off
         * 
         * @throws NotLoggedIn when no user is logged in
         */
        void logout();

        /**
         * @brief returns true if a user is logged in
         * 
         */
        bool userLoggedIn();

    private:
        AccountMgr::Ptr accMgr_;
        
        AccountMgr::UserId currentUserId_{INVALID_UID};
    };
}