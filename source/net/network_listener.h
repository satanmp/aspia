//
// Aspia Project
// Copyright (C) 2020 Dmitry Chapyshev <dmitry@aspia.ru>
//
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
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef NET__NETWORK_LISTENER_H
#define NET__NETWORK_LISTENER_H

#include "base/memory/byte_array.h"
#include "net/network_error.h"

namespace net {

class Listener
{
public:
    virtual ~Listener() = default;

    virtual void onConnected() = 0;
    virtual void onDisconnected(ErrorCode error_code) = 0;
    virtual void onMessageReceived(const base::ByteArray& buffer) = 0;
    virtual void onMessageWritten() = 0;
};

} // namespace net

#endif // NET__NETWORK_LISTENER_H
