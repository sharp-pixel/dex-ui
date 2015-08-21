#pragma once

#include <unordered_map>
#include <memory>

class ofTrueTypeFont;

struct FontHasher {
	size_t operator()(std::pair<std::string, int> const & t) const {
		auto h1 = std::hash<std::string>()(t.first);
		auto h2 = std::hash<int>()(t.second);

		return h1 + h2; // not so good
	}
};

class FontManager {
public:
	static FontManager& instance();
	std::shared_ptr<ofTrueTypeFont> getFont(std::string fontname, int size);

private:
	std::unordered_map<std::pair<std::string, int>, std::shared_ptr<ofTrueTypeFont>, FontHasher> m_map;
};
