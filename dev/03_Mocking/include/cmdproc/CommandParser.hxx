/**
 * @file CommandParser.hxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief Sample for Unit test with Mock
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#pragma once

#include "cmdproc/CommandListener.hxx"
#include "cmdproc/CommandProcessor.hxx"

#include <map>
#include <memory>
#include <string>

namespace cmdproc{

    class CommandParser
    {
    public:
        using Listener = CommandListener;
        using Processor = CommandProcessor;

        CommandParser(const Listener::Ptr& listener,const Processor::Ptr& processor);
        virtual ~CommandParser()=default;

        // virtual bool processNextCommand();

        Listener& getListener()
        {
            return *listener_;
        }

    private:
        const std::map<std::string,Command> commandMap=
        {
            std::make_pair("Hello",Command::HELLO),
            std::make_pair("GetName",Command::GET_NAME),
            std::make_pair("Exit",Command::EXIT)
        };

        Listener::Ptr listener_;
        Processor::Ptr processor_;
    };

}