////////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
////////////////////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////

// #ifdef __OTPCH__
// #error "Precompiled header should be included only once."
// #endif

#ifndef __OTPCH__
#define __OTPCH__
#if defined WINDOWS
#include <winerror.h>
#endif

//std
#include <random>
#include <iostream>

//libxml
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/threads.h>

//boost
#include <boost/config.hpp>
#include <boost/function.hpp>
#include <boost/bind/bind.hpp>
#include <boost/regex.hpp>
#include <boost/tokenizer.hpp>
using namespace boost::placeholders;

//otserv
#include "thing.h"

#endif // __OTPCH__