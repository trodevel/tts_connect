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

// $Revision: 2916 $ $Date:: 2015-12-07 #$ $Author: serge $

#ifndef TTS_CONNECT_SVOX_WRAP_H
#define TTS_CONNECT_SVOX_WRAP_H

#include "i_text_to_speech.h"   // ITextToSpeech

namespace tts_connect
{

class SvoxWrap: public ITextToSpeech
{
public:

    virtual ~SvoxWrap();

    virtual bool say( const std::string & text, const std::string & filename, lang_tools::lang_e lang, std::string & error );

private:
    static const std::string & lang_to_voice( lang_tools::lang_e lang );
};

} // namespace tts_connect

#endif  // TTS_CONNECT_SVOX_WRAP_H
