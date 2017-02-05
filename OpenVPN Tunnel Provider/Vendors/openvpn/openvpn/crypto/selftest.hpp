//    OpenVPN -- An application to securely tunnel IP networks
//               over a single port, with support for SSL/TLS-based
//               session authentication and key exchange,
//               packet encryption, packet authentication, and
//               packet compression.
//
//    Copyright (C) 2012-2016 OpenVPN Technologies, Inc.
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License Version 3
//    as published by the Free Software Foundation.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program in the COPYING file.
//    If not, see <http://www.gnu.org/licenses/>.

// A general purpose container for OpenVPN protocol encrypt and decrypt objects.

#ifndef OPENVPN_CRYPTO_SELFTEST_H
#define OPENVPN_CRYPTO_SELFTEST_H

#include <string>

#ifdef USE_OPENSSL
//#include <openvpn/openssl/util/selftest.hpp>
#endif

#ifdef USE_APPLE_SSL
//#include <openvpn/applecrypto/util/selftest.hpp>
#endif

#ifdef USE_POLARSSL
#include <openvpn/polarssl/util/selftest.hpp>
#endif

#ifdef USE_POLARSSL_APPLE_HYBRID
//#include <openvpn/applecrypto/util/selftest.hpp>
#include <openvpn/polarssl/util/selftest.hpp>
#endif

namespace openvpn {
  namespace SelfTest {
    inline std::string crypto_self_test()
    {
      std::string ret;
#     ifdef USE_OPENSSL
        //ret += crypto_self_test_openssl();
#     endif
#     ifdef USE_APPLE_SSL
        //ret += crypto_self_test_apple();
#     endif
#     if defined(USE_POLARSSL) || defined(USE_POLARSSL_APPLE_HYBRID)
        ret += crypto_self_test_polarssl();
#     endif
      return ret;
    }
  }
} // namespace openvpn

#endif // OPENVPN_CRYPTO_CRYPTO_H
