#include "canvas.hh"

Canvas::Canvas(const Point &center, double width, double height, int horPixels, int vertPixels) : _center(center.x(), center.y()), _width(width), _height(height), _horPixels(horPixels), _vertPixels(vertPixels), _pixels(horPixels, {{vertPixels}}) {}

int Canvas::brightness(int i, int j) const
{
    return _pixels[i][j];
}

void Canvas::setBrightness(int i, int j, int brightness)
{
    _pixels[i][j] = brightness;
}

Point Canvas::coord(int i, int j) const
{
    if (i <= _pixels.size() - 1 && j <= _pixels[i][0] - 1 && i >= 0 && j >= 0)
    {
        Point coordinate(i, j);
        return coordinate;
    }
    throw std::invalid_argument("The number you entered is not inside the canvas!");
}

void Canvas::write(const std::string &filename) const
{
    write_pgm(_pixels, filename);
    read_pgm(filename);
}
