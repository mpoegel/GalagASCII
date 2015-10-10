#include <vector>
#include <map>

#define ESCAPE "\033["
#define ESC_COLOR ESCAPE "%dm"

using namespace std;


class Screen {
public:
    typedef vector<vector<pair<string, char> > > graphic;
    typedef map<string, unsigned int> color_map;

    Screen(unsigned int h, unsigned int w): height(h), width(w) {}
    Screen(): height(10), width(300) {}

    static void resetColor();
    void clearArea();
    static void clearFull();
    static void fullCleanup();
    bool updateAll(const graphic& g);
    void updateOne(string& str, const pair<unsigned int, unsigned int>& loc, const string& color, const char c);

    static void setCursorVisible(bool visible);

    unsigned int width;
    unsigned int height;
private:
    static color_map COLORS;
    
    unsigned int getColorCode(const string& color) const;
};
