#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Config.hpp"

namespace mikuPiano {
	class PianoKey {
		bool isWhiteFlag;
		sf::Text keyName;
		sf::Text toneName;
		sf::RectangleShape shape;
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;

		void setKeyNamePosition(const sf::Vector2f& position) {
			sf::FloatRect bounds = keyName.getLocalBounds();

			keyName.setOrigin(bounds.width / 2, bounds.height / 2);
			keyName.setPosition(position.x + shape.getSize().x / 2,
				position.y + shape.getSize().y * 17 / 18);
		}

		void setToneNamePosition(const sf::Vector2f& position) {
			sf::FloatRect bounds = toneName.getLocalBounds();

			toneName.setOrigin(bounds.width / 2, bounds.height / 2);
			toneName.setPosition(position.x + shape.getSize().x / 2,
				position.y + shape.getSize().y * 5 / 6);
		}
	public:
		PianoKey(bool _isWhiteFlag, 
			const sf::Font& font,
			const std::string& _keyName, 
			const std::string& _toneName,
			const std::string& soundFilePath,
			const sf::Vector2f& position) :
			isWhiteFlag{ _isWhiteFlag },
			keyName{ _keyName, font, config::CHARACTER_SIZE },
			toneName{ _toneName, font, config::CHARACTER_SIZE },
			shape{},
			soundBuffer{},
			sound{}
		{
			// load sound file.
			if (!soundBuffer.loadFromFile(soundFilePath)) {
				std::cerr << "can't load file: " << soundFilePath << "\n";
				std::exit(EXIT_FAILURE);
			}

			// distinct white and black piano keys.
			if (isWhiteFlag) {
				shape.setSize(sf::Vector2f{ config::WHITE_KEY_WIDTH, config::WHITE_KEY_HEIGHT });
				shape.setFillColor(sf::Color::White);
				shape.setOutlineThickness(1.0f);
				shape.setOutlineColor(sf::Color::Black);

				keyName.setFillColor(sf::Color::Black);
				toneName.setFillColor(sf::Color::Black);
			}
			else {
				shape.setSize(sf::Vector2f{ config::BLACK_KEY_WIDTH, config::BLACK_KEY_HEIGHT });
				shape.setFillColor(sf::Color::Black);

				keyName.setFillColor(sf::Color::White);
				toneName.setFillColor(sf::Color::White);
			}

			shape.setPosition(position);
			setKeyNamePosition(position);
			setToneNamePosition(position);
		}

		bool isWhiteKey() const noexcept {
			return isWhiteFlag;
		}

		void play() {
			sound.setBuffer(soundBuffer);
			sound.play();
		}

		void setColor(const sf::Color& newColor) {
			shape.setFillColor(newColor);
		}

		void resetColor() {
			shape.setFillColor(isWhiteFlag ? sf::Color::White : sf::Color::Black);
		}

		void draw(sf::RenderTarget& rt) {
			rt.draw(shape);
			rt.draw(keyName);
			rt.draw(toneName);
		}
	};
};
