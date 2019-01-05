#undef NDEBUG
#include <cassert>
#include "canvas.hh"

auto create_canvas(double width, double height, int horPixels, int vertPixels) {
    Point center(width/2, height/2);
    Canvas testCanvas(center, width, height, horPixels, vertPixels);
    return testCanvas;
}

int main() {
    //linke untere ecke
    auto canvas = create_canvas(100, 50, 200, 250);
    printf("linke untere ecke: i = %i, j = %i, x = %g, y = %g", canvas.coord(0,0).x(), canvas.coord(0,0).y(), canvas.coord(100/2, 0).x() - 100/2, canvas.coord(0, 50/2).y() - 50/2);

    printf("\nrechte untere ecke: i = %g, j = %g, x = %g, y = %g", canvas.coord(200 - 1, 0).x(), canvas.coord(0,0).y(), canvas.coord(100/2, 0).x() + 100/2, canvas.coord(0, 50/2).y() - 50/2);

    printf("\nlinke obere ecke: i = %g, j = %g, x = %g, y = %g", canvas.coord(0, 0).x(), canvas.coord(0,250-1).y(), canvas.coord(100/2, 0).x() - 100/2, canvas.coord(0, 50/2).y() + 50/2);

    printf("\nrechte obere ecke: i = %g, j = %g, x = %g, y = %g", canvas.coord(200 - 1, 250 - 1).x(), canvas.coord(200 - 1,250-1).y(), canvas.coord(100/2, 0).x() + 100/2, canvas.coord(0, 50/2).y() + 50/2);

    return 0;
}