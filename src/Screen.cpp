#include <cstdio>
#include <iostream>
#include "Screen.h"

using namespace std;

Screen::color_map Screen::COLORS = {
	{"red", 31},
	{"green", 32}
};

unsigned int Screen::getColorCode(const string& color) const {
	color_map::iterator itr = COLORS.find(color);
	if (itr != COLORS.end()) {
		return itr->second;
	}
	return 39; // default
}

void Screen::resetColor() {
	printf(ESC_COLOR, 0);
}

bool Screen::updateAll(const graphic& g) {
	// move the cursor to the top
	printf(ESCAPE "%d;%dH\n", 1,1);

	// print the new graphic
	for (unsigned int i=0; i<height; i++) {
		string line = "";
		char buffer [width];
		for (unsigned int k=0; k<width; k++) {
			sprintf(buffer, ESC_COLOR "%c", getColorCode(g[i][k].first), 
				g[i][k].second);
			line += string(buffer);
		}
		cout << line << endl;
	}
	resetColor();
	return true;
}

bool Screen::updateOne(const pair<unsigned int, unsigned int>& loc, const string& color, 
					   const char c) {
	printf(ESCAPE "%d;%dH", loc.second, loc.first);
	printf(ESC_COLOR "%c", getColorCode(color), c);
	resetColor();
	return true;
}

void Screen::clear() {
    for(int y=0; y<height; y++) {
        for(int x=0;x<width; x++) {
            updateOne(make_pair(x,y), "", ' ');
        }
    }
}
