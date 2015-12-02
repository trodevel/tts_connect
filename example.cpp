#include <iostream>         // cout
#include <vector>           // std::vector

#include "tts_connect.h"    // TtsConnect

void say( tts_connect::ITextToSpeech * tts, const std::string & name )
{
    std::string filename = "tts_" + name;

    std::string error;

    std::string input = "Hello World";
    std::string lang = "en";

    bool b = tts->say( input, filename, lang, error );

    if( b == false )
        std::cout << "ERROR: cannot generate text using engine '" << name << "', " << error << std::endl;
    else
        std::cout << "OK: generated text OK using engine '" << name << "'" << std::endl;
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
