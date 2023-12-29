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

#ifndef __OTSYSTEM__
#define __OTSYSTEM__

#include <string>
#include <bitset>
#include <queue>
#include <vector>

#include <boost/utility.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/foreach.hpp>

#include <cstddef>
#include <cstdlib>
#include <cstdint>

#include <sys/types.h>

#include <unistd.h>
#include <netdb.h>
#include <cerrno>
#include <chrono>

#define OTSERV_ACCESS(file, mode) access(file, mode);
inline int64_t OTSYS_TIME()
{
	const auto now = std::chrono::high_resolution_clock::now();
	const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());

	return milliseconds.count();
}

#ifdef __GNUC__
	#define __OTSERV_FUNCTION__ __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
	#define __OTSERV_FUNCTION__ __FUNCDNAME__
#endif

#define foreach BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

typedef std::vector<std::pair<uint32_t, uint32_t> > IpList;
#endif
