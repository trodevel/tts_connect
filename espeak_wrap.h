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

// $Revision: 2901 $ $Date:: 2015-12-06 #$ $Author: serge $

#ifndef TTS_CONNECT_ESPEAK_WRAP_H
#define TTS_CONNECT_ESPEAK_WRAP_H

#include "i_text_to_speech.h"   // ITextToSpeech

#include "../espeak_cpp/espeak_cpp.h"   // ESpeakCpp

namespace tts_connect
{

class ESpeakWrap: public ITextToSpeech
{
public:

    ESpeakWrap();

    virtual ~ESpeakWrap();

    virtual bool say( const std::string & text, const std::string & filename, const std::string & lang, std::string & error );

    virtual void set_param( const std::string & param, int val );

private:

    static const std::string & lang_to_voice( const std::string & lang );

private:

    espeak_cpp::ESpeakCpp       tts_;
};

} // namespace tts_connect

#endif  // TTS_CONNECT_ESPEAK_WRAP_H
