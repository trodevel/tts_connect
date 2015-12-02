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

// $Revision: 2875 $ $Date:: 2015-12-02 #$ $Author: serge $

#ifndef TTS_CONNECT_TTS_CONNECT_H
#define TTS_CONNECT_TTS_CONNECT_H

#include <map>                  // std::map

#include "i_text_to_speech.h"   // ITextToSpeech

namespace tts_connect
{

class TtsConnect
{
private:
    TtsConnect();

public:

    ~TtsConnect();

    static TtsConnect & get();

    ITextToSpeech* get_engine( const std::string & name );

private:

private:

    typedef std::map<std::string, ITextToSpeech*> MapNameToEngine;

private:

    MapNameToEngine     engines_;
};

} // namespace tts_connect

#endif  // TTS_CONNECT_TTS_CONNECT_H
