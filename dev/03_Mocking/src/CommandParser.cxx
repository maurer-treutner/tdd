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

namespace cmdproc
{

CommandParser::CommandParser(const Listener::Ptr& listener,const Processor::Ptr& processor):
    listener_(listener),
    processor_(processor)
{};

}