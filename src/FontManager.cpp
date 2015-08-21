#include "FontManager.h"
#include <ofTrueTypeFont.h>

FontManager& FontManager::instance() {
	static FontManager fm;
	return fm;
}

std::shared_ptr<ofTrueTypeFont> FontManager::getFont(std::string fontname, int size) {
	auto key = std::make_pair(fontname, size);

	auto it = m_map.find(key);

	if (it == std::end(m_map)) {
		// not found
		auto font = std::make_shared<ofTrueTypeFont>();
		font->load(fontname, size);

		m_map.insert({key, font});

		return font;
	}
	else {
		// found, return value
		return it->second;
	}
}
