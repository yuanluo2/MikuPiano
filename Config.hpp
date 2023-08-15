#pragma once

#include <cstdint>
#include <string>
#include <SFML/Graphics.hpp>

namespace mikuPiano {
	namespace config {
		// we only consider 36 keys on a piano, from C3 -> B5, there are 15 black keys and 21 white keys.
		constexpr uint16_t BLACK_KEY_NUM = 15;
		constexpr uint16_t WHITE_KEY_NUM = 21;

		// the piano key's width and height.
		constexpr uint16_t WHITE_KEY_WIDTH  = 46;
		constexpr uint16_t WHITE_KEY_HEIGHT = 390;
		constexpr uint16_t BLACK_KEY_WIDTH  = 30;
		constexpr uint16_t BLACK_KEY_HEIGHT = 254;

		// info of the window.
		constexpr const char* WINDOW_TITLE = "MikuPiano";
		constexpr uint16_t WINDOW_WIDTH = WHITE_KEY_WIDTH * WHITE_KEY_NUM;
		constexpr uint16_t WINDOW_HEIGHT = WHITE_KEY_HEIGHT;

		// character size.
		constexpr unsigned int CHARACTER_SIZE = 15;

		// my own hobby.
		const sf::Color HATSUNE_MIKU_COLOR{ 0x39C5BBFF };

		// key names on the keyboard.
		const std::string STR_1 = "1";
		const std::string STR_2 = "2";
		const std::string STR_3 = "3";
		const std::string STR_4 = "4";
		const std::string STR_5 = "5";
		const std::string STR_6 = "6";
		const std::string STR_7 = "7";
		const std::string STR_8 = "8";
		const std::string STR_9 = "9";
		const std::string STR_0 = "0";
		const std::string STR_Q = "Q";
		const std::string STR_W = "W";
		const std::string STR_E = "E";
		const std::string STR_R = "R";
		const std::string STR_T = "T";
		const std::string STR_Y = "Y";
		const std::string STR_U = "U";
		const std::string STR_I = "I";
		const std::string STR_O = "O";
		const std::string STR_P = "P";
		const std::string STR_A = "A";
		const std::string STR_S = "S";
		const std::string STR_D = "D";
		const std::string STR_F = "F";
		const std::string STR_G = "G";
		const std::string STR_H = "H";
		const std::string STR_J = "J";
		const std::string STR_K = "K";
		const std::string STR_L = "L";
		const std::string STR_Z = "Z";
		const std::string STR_X = "X";
		const std::string STR_C = "C";
		const std::string STR_V = "V";
		const std::string STR_B = "B";
		const std::string STR_N = "N";
		const std::string STR_M = "M";

		// piano tone names.
		const std::string C3  = "C3";
		const std::string Db3 = "Db3";
		const std::string D3  = "D3";
		const std::string Eb3 = "Eb3";
		const std::string E3  = "E3";
		const std::string F3  = "F3";
		const std::string Gb3 = "Gb3";
		const std::string G3  = "G3";
		const std::string Ab3 = "Ab3";
		const std::string A3  = "A3";
		const std::string Bb3 = "Bb3";
		const std::string B3  = "B3";
		const std::string C4  = "C4";
		const std::string Db4 = "Db4";
		const std::string D4  = "D4";
		const std::string Eb4 = "Eb4";
		const std::string E4  = "E4";
		const std::string F4  = "F4";
		const std::string Gb4 = "Gb4";
		const std::string G4  = "G4";
		const std::string Ab4 = "Ab4";
		const std::string A4  = "A4";
		const std::string Bb4 = "Bb4";
		const std::string B4  = "B4";
		const std::string C5  = "C5";
		const std::string Db5 = "Db5";
		const std::string D5  = "D5";
		const std::string Eb5 = "Eb5";
		const std::string E5  = "E5";
		const std::string F5  = "F5";
		const std::string Gb5 = "Gb5";
		const std::string G5  = "G5";
		const std::string Ab5 = "Ab5";
		const std::string A5  = "A5";
		const std::string Bb5 = "Bb5";
		const std::string B5  = "B5";

		// sound files' path.
		const std::string PIANO_RESOURCES_PATH = R"(resources\)";
		
		// sound file suffix.
		const std::string PIANO_SOUND_SUFFIX = ".wav";

		// font file path.
		const std::string PIANO_FONT_FILE_PATH = PIANO_RESOURCES_PATH + "arial.ttf";

		// complete sound file path.
		const std::string PIANO_C3  = PIANO_RESOURCES_PATH + C3  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Db3 = PIANO_RESOURCES_PATH + Db3 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_D3  = PIANO_RESOURCES_PATH + D3  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Eb3 = PIANO_RESOURCES_PATH + Eb3 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_E3  = PIANO_RESOURCES_PATH + E3  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_F3  = PIANO_RESOURCES_PATH + F3  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Gb3 = PIANO_RESOURCES_PATH + Gb3 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_G3  = PIANO_RESOURCES_PATH + G3  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Ab3 = PIANO_RESOURCES_PATH + Ab3 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_A3  = PIANO_RESOURCES_PATH + A3  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Bb3 = PIANO_RESOURCES_PATH + Bb3 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_B3  = PIANO_RESOURCES_PATH + B3  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_C4  = PIANO_RESOURCES_PATH + C4  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Db4 = PIANO_RESOURCES_PATH + Db4 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_D4  = PIANO_RESOURCES_PATH + D4  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Eb4 = PIANO_RESOURCES_PATH + Eb4 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_E4  = PIANO_RESOURCES_PATH + E4  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_F4  = PIANO_RESOURCES_PATH + F4  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Gb4 = PIANO_RESOURCES_PATH + Gb4 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_G4  = PIANO_RESOURCES_PATH + G4  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Ab4 = PIANO_RESOURCES_PATH + Ab4 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_A4  = PIANO_RESOURCES_PATH + A4  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Bb4 = PIANO_RESOURCES_PATH + Bb4 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_B4  = PIANO_RESOURCES_PATH + B4  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_C5  = PIANO_RESOURCES_PATH + C5  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Db5 = PIANO_RESOURCES_PATH + Db5 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_D5  = PIANO_RESOURCES_PATH + D5  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Eb5 = PIANO_RESOURCES_PATH + Eb5 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_E5  = PIANO_RESOURCES_PATH + E5  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_F5  = PIANO_RESOURCES_PATH + F5  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Gb5 = PIANO_RESOURCES_PATH + Gb5 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_G5  = PIANO_RESOURCES_PATH + G5  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Ab5 = PIANO_RESOURCES_PATH + Ab5 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_A5  = PIANO_RESOURCES_PATH + A5  + PIANO_SOUND_SUFFIX;
		const std::string PIANO_Bb5 = PIANO_RESOURCES_PATH + Bb5 + PIANO_SOUND_SUFFIX;
		const std::string PIANO_B5  = PIANO_RESOURCES_PATH + B5  + PIANO_SOUND_SUFFIX;
	};
};
