#pragma once

#include <string>;
#include <SFML/Graphics/Font.hpp>

static class Font {
public:
	static sf::Font GET(std::string path) {
		sf::Font font;
		
		std::string fontName = path.substr(path.find_last_of('/'), path.length() - 1);

		if (!font.loadFromFile(path))
		{
			std::string message = "[EXCEPTION] Could not load \"" + fontName + "\"";
			throw std::exception(message.c_str());
		}

		return font;
	}
};