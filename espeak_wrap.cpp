/*

Wrapper over ESpeak

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

// $Revision: 2931 $ $Date:: 2015-12-07 #$ $Author: serge $

#include "espeak_wrap.h"        // self

#include <map>                  // std::map

#include "../espeak_cpp/espeak_cpp.h"   // ESpeakCpp

namespace tts_connect
{

ESpeakWrap::ESpeakWrap()
{
}

ESpeakWrap::~ESpeakWrap()
{
}

bool ESpeakWrap::say( const std::string & text, const std::string & filename, lang_tools::lang_e lang, std::string & error )
{
    const std::string & voice = lang_to_voice( lang );

    return tts_.say( text, filename, voice, error );
}

void ESpeakWrap::set_param( const std::string & param, int val )
{
    if( param == "gap_between_words" )
        tts_.set_gap_between_words( val );
    else if( param == "word_rate" )
        tts_.set_word_rate( val );
}

const std::string & ESpeakWrap::lang_to_voice( lang_tools::lang_e lang )
{
    static const std::map<lang_tools::lang_e, std::string> lang_to_voice =
    {
            { lang_tools::lang_e::EN, "mb-en1" },
            { lang_tools::lang_e::DE, "mb-de5" },
            { lang_tools::lang_e::RU, "ru" },
            { lang_tools::lang_e::FR, "fr" },
            { lang_tools::lang_e::IT, "it" },
            { lang_tools::lang_e::ES, "es" }
    };

    auto it = lang_to_voice.find( lang );

    if( it != lang_to_voice.end() )
        return it->second;

    static const std::string def("en");

    return def;
}

} // namespace tts_connect
