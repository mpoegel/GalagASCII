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
        char buffer[width];
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

void Screen::updateOne(string& str, const pair<unsigned int, unsigned int>& loc, const string& color, 
                       const char c) {
    char buf[50];
    sprintf(buf, ESCAPE "%d;%dH", loc.second, loc.first);
    str += buf;
    sprintf(buf, ESC_COLOR "%c", getColorCode(color), c);
    str += buf;
    sprintf(buf, ESC_COLOR, 0);
    str += buf;
}

void Screen::clearArea() {
    string buffer;
    for(int y=0; y<height; y++) {
        for(int x=0;x<width; x++) {
            updateOne(buffer, make_pair(x,y), "", ' ');
        }
    }
    cout << buffer;
    cout.flush();
}

void Screen::clearFull() {
    cout << ESCAPE "2J";
    cout.flush();
}

void Screen::setCursorVisible(bool visible) {
    if(visible) {
        cout << ESCAPE "?25h";
    } else {
        cout << ESCAPE "?25l";
    }
    cout.flush();
}

void Screen::fullCleanup() {
    cout << endl;
    Screen::resetColor();
    Screen::setCursorVisible(true);
    (void)system("stty sane");
    Screen::clearFull();
}
