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

#ifndef __RSA__
#define __RSA__

#include "gmp.h"
#include "otsystem.h"

namespace tfs
{
    class RSA
    {
      public:
        RSA();
        virtual ~RSA();

        void setKey(const char *p, const char *q, const char *d);
        bool setKey(const std::string &file);

        void decrypt(char *msg, int32_t size);

        int32_t getKeySize();
        void getPublicKey(char *buffer);

      protected:
        boost::recursive_mutex rsaLock;

        bool m_keySet;
        // use only GMP
        mpz_t m_p, m_q, m_u, m_d, m_dp, m_dq, m_mod;
    };

} // namespace tfs
#endif
