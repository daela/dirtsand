/******************************************************************************
 * This file is part of dirtsand.                                             *
 *                                                                            *
 * dirtsand is free software: you can redistribute it and/or modify           *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * dirtsand is distributed in the hope that it will be useful,                *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with dirtsand.  If not, see <http://www.gnu.org/licenses/>.          *
 ******************************************************************************/

#ifndef _MOUL_NETMSGPLAYERPAGE_H
#define _MOUL_NETMSGPLAYERPAGE_H

#include "NetMessage.h"
#include "Key.h"

namespace MOUL
{
    class NetMsgPlayerPage : public NetMessage
    {
        FACTORY_CREATABLE(NetMsgPlayerPage)

        virtual void read(DS::Stream* stream);
        virtual void write(DS::Stream* stream);

    protected:
        NetMsgPlayerPage(uint16_t type) : NetMessage(type) { }

    public:
        unsigned char m_unload;
        MOUL::Uoid m_uoid;
    };
}

#endif