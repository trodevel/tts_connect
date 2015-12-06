#include <iostream>         // cout
#include <vector>           // std::vector

#include "tts_connect.h"    // TtsConnect

void say( tts_connect::ITextToSpeech * tts, const std::string & name )
{
    std::string error;

    std::map<std::string, std::string> texts =
    {
            { "en",     "hello world" },
            { "de",     "hallo welt" },
            { "ru",     "привет мир" },
    };

    for( auto & s : texts )
    {
        auto & lang = s.first;

        std::string filename = "tts_" + name + "_" + lang + ".wav";

        bool b = tts->say( s.second, filename, lang, error );

        if( b == false )
            std::cout << "ERROR: cannot generate text using engine '" << name << "', " << error << std::endl;
        else
            std::cout << "OK: generated text OK using engine '" << name << "', lang '" << lang << "'" << std::endl;

    }
}

int main()
{
    std::vector<std::string>    engines = { "gspeak", "espeak", "voicerss" };

    for( auto & n : engines )
    {
        tts_connect::ITextToSpeech * tts = tts_connect::TtsConnect::get().get_engine( n );

        if( tts == nullptr )
        {
            std::cout << "ERROR: engine '" << n << "' is unknown" << std::endl;
            continue;
        }

        say( tts, n );
    }

    return 0;
}
