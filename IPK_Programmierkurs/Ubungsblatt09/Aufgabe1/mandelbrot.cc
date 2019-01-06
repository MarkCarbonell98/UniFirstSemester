#include "IterationResult.hh"
#include "IterationResult.cc"
#include "point.cc"
#include "canvas.hh"

IterationResult iterate(Point z, Point c, double threshold, int maxIt) {
    double newX, newY;
    IterationResult result(z, 0);
    for(int i = 0; i < maxIt; i++) {
        if(std::abs(std::sqrt(std::pow(newX,2) + std::pow(newY, 2))) >= threshold) {
            result.setOperations(i);
            Point newCoords(newX, newY);
            result.changePoint(newCoords);
            return result;
        }
        newX = std::pow(z.x(),2) - std::pow(z.y(),2) + c.x();
        newY = 2 * (z.x()*z.y()) + c.y();
        z.setX(newX);
        z.setY(newY);
    }

    result.setOperations(maxIt);
    Point newCoords(newX, newY);
    result.changePoint(newCoords);
    return result;
}

void mandelbrot(Canvas& canvas, double threshold, int maxIt, std::string filename) {
    for(int i = 0; i < canvas.horPixels(); i++) {
        for(int j = 0; j < canvas.vertPixels(); i++) {
            Point z(0.0,0.0), c(i + 0.0,j + 0.0);
            if(iterate(z, c, threshold, maxIt).getOperations() < maxIt) {
                canvas(i,j) = 0;
            } else {
                canvas(i,j) = std::log(iterate(z, c, threshold, maxIt).getOperations()) * 100;
            }
        }
    }
    canvas.write(filename);
}

int main() {
    Point p(-1.5, 1), zero(0.0,0.0);
    IterationResult q(p, 10);
    printf("%g %g \n", q.x(), q.y());
    Point z(5,5);
    q.changePoint(z);
    printf("%g %g %d \n", q.x(), q.y(), q.getOperations());
    q.setOperations(26);
    printf("%d \n", q.getOperations());

    IterationResult iteratorTest = iterate(zero, p, 20, 10);

    IterationResult test(p, 0);
    printf("%d %g %g \n", iteratorTest.getOperations(), iteratorTest.x(), iteratorTest.y());

    Point center(-1,0);
    Canvas canvas(center, 500, 500, 4000, 3000);
    mandelbrot(canvas, 1000,1000, "theMandelbrot.pgm");
    return 0;
}