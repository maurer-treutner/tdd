/**
 * @file Account.hxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Demo class for unit test example
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include <memory>
#include <string>
#include <limits>

namespace user2 
{
    class AccountMgr
    {
    public:
        using Ptr = std::unique_ptr<AccountMgr>;
        using UserId = std::uint16_t;       

        virtual ~AccountMgr()=default;

        virtual UserId getUserId(std::string userName)=0;

        virtual bool checkPassword(UserId uId, std::string passWd)=0;
    };

    const AccountMgr::UserId INVALID_UID = std::numeric_limits<AccountMgr::UserId>::max();

}