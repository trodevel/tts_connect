#include <iostream>         // cout
#include <vector>           // std::vector

#include "../lang_tools/str_helper.h"       // to_string()

#include "tts_connect.h"    // TtsConnect

void say( tts_connect::ITextToSpeech * tts, const std::string & name )
{
    std::string error;

    std::map<lang_tools::lang_e, std::string> texts =
    {
            { lang_tools::lang_e::EN,     "hello world" },
            { lang_tools::lang_e::DE,     "hallo welt" },
            { lang_tools::lang_e::RU,     "привет мир" },
    };

    for( auto & s : texts )
    {
        auto & lang = s.first;

        auto lang_s = lang_tools::to_string( lang );

        std::string filename = "tts_" + name + "_" + lang_s + ".wav";

        bool b = tts->say( s.second, filename, lang, error );

        if( b == false )
            std::cout << "ERROR: cannot generate text using engine '" << name << "', " << error << std::endl;
        else
            std::cout << "OK: generated text OK using engine '" << name << "', lang '" << lang_s << "'" << std::endl;

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
