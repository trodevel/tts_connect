/*

Simple Text to Speech interface

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


#ifndef TTS_CONNECT_I_TEXT_TO_SPEECH_H
#define TTS_CONNECT_I_TEXT_TO_SPEECH_H

#include <string>               // std::string

#include "../lang_tools/language_enum.h"    // lang_e

namespace tts_connect
{

class ITextToSpeech
{
public:
    virtual ~ITextToSpeech() {};

    virtual bool say( const std::string & text, const std::string & filename, lang_tools::lang_e lang, std::string & error ) = 0;

    virtual void set_param( const std::string & param, const std::string & val ) {};

    virtual void set_param( const std::string & param, int val ) {};

    virtual void set_param( const std::string & param, double val ) {};
};

} // namespace tts_connect

#endif  // TTS_CONNECT_I_TEXT_TO_SPEECH_H
