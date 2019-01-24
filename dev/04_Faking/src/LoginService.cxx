/**
 * @file LoginService.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Sample implementation for unit test demo
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "user2/LoginService.hxx"

namespace user2
{
    LoginService::LoginService(AccountMgr::Ptr&& accMgr):
        accMgr_(std::move(accMgr))
    {}

    AccountMgr::UserId LoginService::login(std::string userName, std::string passWord)
    {
        if (currentUserId_ != INVALID_UID)
        {
            throw AlreadLoggedIn();
        }
        auto uId = accMgr_->getUserId(userName);
        if (uId != INVALID_UID)
        {
            if (accMgr_->checkPassword(uId,passWord))
            {
                currentUserId_ = uId;
            }
            else 
            {
                throw InvalidPassword();
            }
        }
        else
        {
            throw InvalidUser();
        }
        return currentUserId_;
    }

    void LoginService::logout()
    {
        currentUserId_ = INVALID_UID;
    }

    bool LoginService::userLoggedIn()
    {
        if(this->currentUserId_!=INVALID_UID)
        {
            return true;
        }
        return false;
    }

}