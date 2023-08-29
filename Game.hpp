#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <functional>
#include "PianoKey.hpp"
#include "Config.hpp"

namespace mikuPiano {
	class Game {
		std::vector<std::reference_wrapper<PianoKey>> blackKeyShapes;
		std::vector<std::reference_wrapper<PianoKey>> whiteKeyShapes;
		std::map<sf::Keyboard::Key, PianoKey> keyMap;
		sf::RenderWindow window;
		sf::Font font;

		void initKeyMaps() {
			using namespace mikuPiano::config;

			// calculate the positions of each piano key.
			std::array<sf::Vector2f, config::WHITE_KEY_NUM> whiteKeyPositions;
			std::array<sf::Vector2f, config::BLACK_KEY_NUM> blackKeyPositions;

			for (uint16_t i = 0; i < config::WHITE_KEY_NUM; ++i) {
				whiteKeyPositions[i].x = static_cast<float>(i * config::WHITE_KEY_WIDTH);
				whiteKeyPositions[i].y = 0.0f;
			}

			// be careful here, still WHITE_KEY_NUM for loop, not BLACK_KEY_NUM
			uint16_t blackKeyIndex = 0;
			for (uint16_t i = 0; i < config::WHITE_KEY_NUM; ++i) {
				auto res = i % 7;
				if (res != 0 && res != 3) {
					blackKeyPositions[blackKeyIndex].x = static_cast<float>(i * config::WHITE_KEY_WIDTH) - static_cast<float>(config::BLACK_KEY_WIDTH / 2.0f);
					blackKeyPositions[blackKeyIndex].y = 0.0f;
					++blackKeyIndex;
				}
			}

			// construct our keyMap.
			keyMap.emplace(sf::Keyboard::Num1, PianoKey{ true,  font, STR_1, C3 , PIANO_C3 , whiteKeyPositions[0]  });
			keyMap.emplace(sf::Keyboard::Num2, PianoKey{ false, font, STR_2, Db3, PIANO_Db3, blackKeyPositions[0]  });
			keyMap.emplace(sf::Keyboard::Num3, PianoKey{ true,  font, STR_3, D3 , PIANO_D3 , whiteKeyPositions[1]  });
			keyMap.emplace(sf::Keyboard::Num4, PianoKey{ false, font, STR_4, Eb3, PIANO_Eb3, blackKeyPositions[1]  });
			keyMap.emplace(sf::Keyboard::Num5, PianoKey{ true,  font, STR_5, E3 , PIANO_E3 , whiteKeyPositions[2]  });
			keyMap.emplace(sf::Keyboard::Num6, PianoKey{ true,  font, STR_6, F3 , PIANO_F3 , whiteKeyPositions[3]  });
			keyMap.emplace(sf::Keyboard::Num7, PianoKey{ false, font, STR_7, Gb3, PIANO_Gb3, blackKeyPositions[2]  });
			keyMap.emplace(sf::Keyboard::Num8, PianoKey{ true,  font, STR_8, G3 , PIANO_G3 , whiteKeyPositions[4]  });
			keyMap.emplace(sf::Keyboard::Num9, PianoKey{ false, font, STR_9, Ab3, PIANO_Ab3, blackKeyPositions[3]  });
			keyMap.emplace(sf::Keyboard::Num0, PianoKey{ true,  font, STR_0, A3 , PIANO_A3 , whiteKeyPositions[5]  });
			keyMap.emplace(sf::Keyboard::Q,    PianoKey{ false, font, STR_Q, Bb3, PIANO_Bb3, blackKeyPositions[4]  });
			keyMap.emplace(sf::Keyboard::W,    PianoKey{ true,  font, STR_W, B3 , PIANO_B3 , whiteKeyPositions[6]  });
			keyMap.emplace(sf::Keyboard::E,    PianoKey{ true,  font, STR_E, C4 , PIANO_C4 , whiteKeyPositions[7]  });
			keyMap.emplace(sf::Keyboard::R,    PianoKey{ false, font, STR_R, Db4, PIANO_Db4, blackKeyPositions[5]  });
			keyMap.emplace(sf::Keyboard::T,    PianoKey{ true,  font, STR_T, D4 , PIANO_D4 , whiteKeyPositions[8]  });
			keyMap.emplace(sf::Keyboard::Y,    PianoKey{ false, font, STR_Y, Eb4, PIANO_Eb4, blackKeyPositions[6]  });
			keyMap.emplace(sf::Keyboard::U,    PianoKey{ true,  font, STR_U, E4 , PIANO_E4 , whiteKeyPositions[9]  });
			keyMap.emplace(sf::Keyboard::I,    PianoKey{ true,  font, STR_I, F4 , PIANO_F4 , whiteKeyPositions[10] });
			keyMap.emplace(sf::Keyboard::O,    PianoKey{ false, font, STR_O, Gb4, PIANO_Gb4, blackKeyPositions[7]  });
			keyMap.emplace(sf::Keyboard::P,    PianoKey{ true,  font, STR_P, G4 , PIANO_G4 , whiteKeyPositions[11] });
			keyMap.emplace(sf::Keyboard::A,    PianoKey{ false, font, STR_A, Ab4, PIANO_Ab4, blackKeyPositions[8]  });
			keyMap.emplace(sf::Keyboard::S,    PianoKey{ true,  font, STR_S, A4 , PIANO_A4 , whiteKeyPositions[12] });
			keyMap.emplace(sf::Keyboard::D,    PianoKey{ false, font, STR_D, Bb4, PIANO_Bb4, blackKeyPositions[9]  });
			keyMap.emplace(sf::Keyboard::F,    PianoKey{ true,  font, STR_F, B4 , PIANO_B4 , whiteKeyPositions[13] });
			keyMap.emplace(sf::Keyboard::G,    PianoKey{ true,  font, STR_G, C5 , PIANO_C5 , whiteKeyPositions[14] });
			keyMap.emplace(sf::Keyboard::H,    PianoKey{ false, font, STR_H, Db5, PIANO_Db5, blackKeyPositions[10] });
			keyMap.emplace(sf::Keyboard::J,    PianoKey{ true,  font, STR_J, D5 , PIANO_D5 , whiteKeyPositions[15] });
			keyMap.emplace(sf::Keyboard::K,    PianoKey{ false, font, STR_K, Eb5, PIANO_Eb5, blackKeyPositions[11] });
			keyMap.emplace(sf::Keyboard::L,    PianoKey{ true,  font, STR_L, E5 , PIANO_E5 , whiteKeyPositions[16] });
			keyMap.emplace(sf::Keyboard::Z,    PianoKey{ true,  font, STR_Z, F5 , PIANO_F5 , whiteKeyPositions[17] });
			keyMap.emplace(sf::Keyboard::X,    PianoKey{ false, font, STR_X, Gb5, PIANO_Gb5, blackKeyPositions[12] });
			keyMap.emplace(sf::Keyboard::C,    PianoKey{ true,  font, STR_C, G5 , PIANO_G5 , whiteKeyPositions[18] });
			keyMap.emplace(sf::Keyboard::V,    PianoKey{ false, font, STR_V, Ab5, PIANO_Ab5, blackKeyPositions[13] });
			keyMap.emplace(sf::Keyboard::B,    PianoKey{ true,  font, STR_B, A5 , PIANO_A5 , whiteKeyPositions[19] });
			keyMap.emplace(sf::Keyboard::N,    PianoKey{ false, font, STR_N, Bb5, PIANO_Bb5, blackKeyPositions[14] });
			keyMap.emplace(sf::Keyboard::M,    PianoKey{ true,  font, STR_M, B5 , PIANO_B5 , whiteKeyPositions[20] });
		}

		void initKeyShapes() {
			for (auto& elem : keyMap) {
				if (elem.second.isWhiteKey()) {
					whiteKeyShapes.emplace_back(std::ref(elem.second));
				}
				else {
					blackKeyShapes.emplace_back(std::ref(elem.second));
				}
			}
		}

		void processEvents() {
			sf::Event event{};

			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				else if (event.type == sf::Event::KeyPressed) {
					auto iter = keyMap.find(event.key.code);
					if (iter != keyMap.cend()) {
						iter->second.play();
						iter->second.setColor(config::HATSUNE_MIKU_COLOR);
					}
				}
				else if (event.type == sf::Event::KeyReleased){
					auto iter = keyMap.find(event.key.code);
					if (iter != keyMap.cend()) {
						iter->second.resetColor();
					}
				}
			}
		}

		void render() {
			window.clear();

			for (auto& key : whiteKeyShapes) { key.get().draw(window); }
			for (auto& key : blackKeyShapes) { key.get().draw(window); }

			window.display();
		}
	public:
		Game() :
			window{ sf::VideoMode{ mikuPiano::config::WINDOW_WIDTH, mikuPiano::config::WINDOW_HEIGHT }, mikuPiano::config::WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close },
			font{}
		{
			if (!font.loadFromFile(config::PIANO_FONT_FILE_PATH)) {
				std::cerr << "can't load file: " << config::PIANO_FONT_FILE_PATH << "\n";
				std::exit(EXIT_FAILURE);
			}

			initKeyMaps();
			initKeyShapes();
		}

		void play() {
			while (window.isOpen()) {
				processEvents();
				render();
			}
		}
	};
};
