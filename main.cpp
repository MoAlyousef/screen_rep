#include <FL/Fl.H>
#include <stdio.h>
#include <vector>

struct Point {
    int x;
    int y;
    Point(int x_, int y_): x(x_), y(y_) {}
};

int main() {
    for (auto count = 0; count < Fl::screen_count(); count ++) {
        int x = 0, y = 0, w = 0, h = 0;
        Fl::screen_xywh(x, y, w, h);
        printf("%d: (%d, %d, %d, %d)\n", count, x, y, w, h);
    }
    std::vector<Point> points = {
        Point(0, 0),
        Point(0, 1439),
        Point(2559, 0),
        Point(2559, 1439),
        Point(1450, 933),
        Point(1357, 1099),  // x
        Point(1357, 331),
        Point(1323, 1241),  // x
        Point(23, 234),
        Point(23, 1099),
    };
    for (auto point: points) {
        printf("point: %d, %d => screen_num: %d\n", point.x, point.y, Fl::screen_num(point.x, point.y));
    }
}