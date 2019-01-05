#include "polygon.hh"

Polygon::Polygon() : _points() {}

Polygon::Polygon(const std::vector<Point>& corners) : _points(corners) {}

Polygon::Polygon(const std::vector<double>& x, const std::vector<double>& y) {
    for(unsigned int i = 0; i <= x.size() -1; i++) {
        Point p(x[i],y[i]);
        _points.push_back(p);
    }
}

std::size_t Polygon::corners() const {
    return _points.size();
}

const Point& Polygon::corner(std::size_t i) const {
    return _points[i - 1];
}

//aufgabe c
double Polygon::volume() const {
    double area;
    std::size_t n = _points.size();
    if(n <= 2) return 0;
    for(unsigned int i = 0; i <= n; i++) {
        area += (_points[i].x() * _points[i + 1].y() - _points[i+1].x() * _points[i].y());
    }
    return .5*area;
}




