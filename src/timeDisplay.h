/*

 timeDisplay.h

 Clock and system uptime-esque stuff on the left panel

 */

#pragma once
#include "ofMain.h"
#include "text.h"
#include <time.h>
#include <string.h>
#include "animated.h"
#include <vector>

class TimeDisplay : public Animated {

public:
	TimeDisplay();
	void update();
	void updateClockTime();
	void draw();

	void setPos(float x_, float y_);

	float x;
	float y;
	float w;
	float h;

	int t;

	void updateDependencyEvents();
	void updateDependencyDelays(int delay_);
private:
	time_t currentTime;
	struct tm *localizedTime;

	time_t initTime;
	double diff_sec;

	std::string sec_s;
	std::string min_s;
	std::string hour_s;
	char* mon_s;
	std::string year_s;
	std::string uptime_s;

	int upperTextDelay;
	int lowerTextDelay;
	AnimatedTickLine tline1;
	AnimatedTickLine tline2;
	AnimatedTickLine tline3;
	AnimatedText mainTime;
	std::vector<AnimatedText> upperTexts;
	std::vector<AnimatedText> lowerTexts;
};
