#include "text.h"
#include "FontManager.h"

Text::Text() {

}

void Text::setFont(string font, int size) {
	//ofFont = std::make_shared<ofTrueTypeFont>();
	//ofFont->load(font, size, true, true);
	ofFont = FontManager::instance().getFont(font, size);
}

void Text::drawString(string s, float x, float y) {
	ofRectangle bounds = ofFont->getStringBoundingBox(s, x, y);
	ofFont->drawString(s, x, y + bounds.height);
}

void Text::drawStringFromTopRight(string s, float x, float y) {
	ofRectangle bounds = ofFont->getStringBoundingBox(s, x, y);
	ofFont->drawString(s, x - bounds.width, y + bounds.height);
}
