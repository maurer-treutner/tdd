/**
 * @file CommandListener.hxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Sample class defining an interface to read commands from some serial interface as strings
 *     and to send back a response
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include <memory>
#include <string>

namespace cmdproc
{
    class CommandListener
    {
    public:
        using Ptr = std::shared_ptr<CommandListener>;

        virtual ~CommandListener()=default;
        virtual std::string readCommand()=0;
        virtual void writeResponse(std::string rsp)=0;
    };
}