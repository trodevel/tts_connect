/*

TTS Engines Factory

Copyright (C) 2015 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 2907 $ $Date:: 2015-12-06 #$ $Author: serge $


#include "tts_connect.h"                // self

#include "gspeak_wrap.h"                // GSpeakWrap
#include "espeak_wrap.h"                // ESpeakWrap

using namespace tts_connect;

TtsConnect::TtsConnect()
{
    engines_["gspeak"]  = new GSpeakWrap;
    engines_["espeak"]  = new ESpeakWrap;
}

TtsConnect::~TtsConnect()
{
    for( auto e : engines_ )
    {
        delete e.second;
    }
}

TtsConnect & TtsConnect::get()
{
   static TtsConnect t;

   return t;
}

ITextToSpeech* TtsConnect::get_engine( const std::string & name )
{
    auto it = engines_.find( name );

    if( it == engines_.end() )
        return nullptr;

    return it->second;
}

