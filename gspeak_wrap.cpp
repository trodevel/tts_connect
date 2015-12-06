/*

Wrapper over GSpeak

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

// $Revision: 2912 $ $Date:: 2015-12-07 #$ $Author: serge $

#include "gspeak_wrap.h"        // self

#include <map>                  // std::map

#include "../gspeak/gspeak.h"   // GSpeak

namespace tts_connect
{

GSpeakWrap::~GSpeakWrap()
{
}

bool GSpeakWrap::say( const std::string & text, const std::string & filename, lang_tools::lang_e lang, std::string & error )
{
    gspeak::GSpeak g;

    const std::string & voice = lang_to_voice( lang );

    return g.say( text, filename, voice, error );
}


const std::string & GSpeakWrap::lang_to_voice( lang_tools::lang_e lang )
{
    static const std::map<lang_tools::lang_e, std::string> lang_to_voice =
    {
            { lang_tools::lang_e::EN, "en" },
            { lang_tools::lang_e::DE, "de" },
            { lang_tools::lang_e::RU, "ru" }
    };

    auto it = lang_to_voice.find( lang );

    if( it != lang_to_voice.end() )
        return it->second;

    static const std::string def("en");

    return def;
}

} // namespace tts_connect
