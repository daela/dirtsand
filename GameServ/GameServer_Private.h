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

#include "GameServer.h"
#include "NetIO/CryptIO.h"
#include "NetIO/MsgChannel.h"
#include "Types/Uuid.h"
#include <list>

struct GameClient_Private
{
    DS::SocketHandle m_sock;
    DS::CryptState m_crypt;
    DS::BufferStream m_buffer;
    DS::MsgChannel m_channel;
};

struct GameHost_Private
{
    DS::Uuid m_instanceId;
    std::list<GameClient_Private*> m_clients;
    pthread_mutex_t m_clientMutex;
    DS::MsgChannel m_channel;
};

typedef std::tr1::unordered_map<DS::Uuid, GameHost_Private*, DS::UuidHash> hostmap_t;
extern hostmap_t s_gameHosts;
extern pthread_mutex_t s_gameHostMutex;

enum GameHostMessages
{
    e_GameShutdown, e_GameCleanup,
};

GameHost_Private* start_game_host(const DS::Uuid& ageId);