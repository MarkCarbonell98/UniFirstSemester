#include "IterationResult.hh"

IterationResult::IterationResult() : _lastPoint(0.0, 0.0), _operations(0) {}

IterationResult::IterationResult(const Point& p, int number) : _lastPoint(p), _operations(number) {}

double IterationResult::x() const {
    return _lastPoint.x();
}

double IterationResult::y() const {
    return _lastPoint.y();
}

void IterationResult::changePoint(Point& p){
    _lastPoint.setX(p.x());
    _lastPoint.setY(p.y());
}

int IterationResult::getOperations() const {
    return _operations;
}

void IterationResult::setOperations(const int x) {
    _operations = x;
}



