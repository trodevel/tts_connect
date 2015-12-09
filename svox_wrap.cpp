/*

Wrapper over Svox

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

// $Revision: 2948 $ $Date:: 2015-12-08 #$ $Author: serge $

#include "svox_wrap.h"          // self

#include <map>                  // std::map

#include "../svox/svox.h"       // Svox

namespace tts_connect
{

SvoxWrap::~SvoxWrap()
{
}

bool SvoxWrap::say( const std::string & text, const std::string & filename, lang_tools::lang_e lang, std::string & error )
{
    svox::Svox g;

    const std::string & voice = lang_to_voice( lang );

    if( voice.empty() )
    {
        error = "unsupported language";
        return false;
    }

    return g.say( text, filename, voice, error );
}


const std::string & SvoxWrap::lang_to_voice( lang_tools::lang_e lang )
{
    static const std::map<lang_tools::lang_e, std::string> lang_to_voice =
    {
            { lang_tools::lang_e::EN, "en-GB" },
            { lang_tools::lang_e::DE, "de-DE" },
            { lang_tools::lang_e::FR, "fr-FR" },
            { lang_tools::lang_e::IT, "it-IT" },
            { lang_tools::lang_e::ES, "es-ES" }
    };

    auto it = lang_to_voice.find( lang );

    if( it != lang_to_voice.end() )
        return it->second;

    static const std::string def;

    return def;
}

} // namespace tts_connect
