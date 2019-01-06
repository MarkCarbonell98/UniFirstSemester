#ifndef ITERATION_RESULT
#define ITERATION_RESULT

#include <iostream>
#include "point.hh"
#include <cmath>
#include <iterator>

class IterationResult {
    private:
        Point _lastPoint;
        int _operations;

    public:
        IterationResult();
        IterationResult(const Point& p, int number);
        double x() const;
        double y() const;
        void changePoint(Point& p);
        int getOperations() const;
        void setOperations(const int x);

};

#endif // ITERATION_RESULT