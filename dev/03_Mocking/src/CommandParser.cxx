/**
 * @file CommandParser.cxx
 * @author Peter Maurer (p.maurer@maurer-treutner.de)
 * @brief 
 * 
 * @copyright Copyright (c) 2019 Maurer & Treutner GmbH & Co. KG
 * 
 * @license SPDX-License-Identifier: BSL-1.0
 */

#include "cmdproc/CommandParser.hxx"
#include <iostream>
namespace cmdproc
{

CommandParser::CommandParser(const Listener::Ptr& listener,const Processor::Ptr& processor):
    listener_(listener),
    processor_(processor)
{};

bool CommandParser::processNextCommand()
{
    bool rv=false;
    auto message = listener_->readCommand();
    auto tokens = tokenize(message);
    try{
        auto cmd = commandMap_.at(tokens.at(0));
        processor_->processCommand(cmd,tokens);
        rv=true;
    }
    catch (std::out_of_range &ex)
    {
    }
    return rv;    
}

std::vector<std::string> CommandParser::tokenize(std::string& s)
{
    std::vector<std::string> result;
    std::vector<size_t> blank_pos;
    size_t p = 0;
    while ((p=s.find(" ",p+1))!=std::string::npos)
    {
        blank_pos.emplace_back(p);
    }
    size_t p_start = 0;
    for (auto p_end : blank_pos)
    {
        auto len = p_end - p_start;
        result.emplace_back(s.substr(p_start,len));
        p_start = p_end+1;
    }
    result.emplace_back(s.substr(p_start,std::string::npos));
    return result;
}


}