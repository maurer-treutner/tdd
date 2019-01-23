/**
 * @file CommandProcessor.hxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Sample interface for a command processor
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include <memory>
#include <string>
#include <vector>

namespace cmdproc
{

    enum struct Command
    {
        HELLO,
        GET_NAME,
        EXIT
    };

    enum struct Result
    {
        OK,
        NOT_SUPPORTED,
        ERROR
    };

    class CommandProcessor
    {
    public:
        using Ptr = std::shared_ptr<CommandProcessor>;

        CommandProcessor()=default;
    
        virtual ~CommandProcessor()=default;

        virtual Result processCommand(Command cmd,const std::vector<std::string> &params)=0;

        virtual std::string getResponse()=0;

    };

}