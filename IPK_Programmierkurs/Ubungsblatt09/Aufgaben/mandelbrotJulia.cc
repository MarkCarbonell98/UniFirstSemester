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


IterationResult iterateJulia(Point z, Point c, double threshold, int maxIt) {
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
        c.setX(newX);
        c.setY(newY);
    }

    result.setOperations(maxIt);
    Point newCoords(newX, newY);
    result.changePoint(newCoords);
    return result;
}

void mandelbrot(Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth = false) {
    if(!smooth) {
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
    } else {
        for(int i = 0; i < canvas.horPixels(); i++) {
            for(int j = 0; j < canvas.vertPixels(); i++) {
                Point z(0.0,0.0), c(i + 0.0,j + 0.0);
                if(iterate(z, c, threshold, maxIt).getOperations() < maxIt) {
                    canvas(i,j) = 0;
                } else {
                    canvas(i,j) = iterate(z, c, threshold, maxIt).getOperations() - std::log2(std::log(std::abs(std::sqrt(std::pow(iterate(z,c,threshold, maxIt).x(),2) + std::pow(iterate(z,c,threshold,maxIt).y(), 2))/std::log(threshold))));
                }
            }
        }
        canvas.write(filename);

    }
}

void julia(Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth = false) {
    if(!smooth) {
        for(int i = 0; i < canvas.horPixels(); i++) {
            for(int j = 0; j < canvas.vertPixels(); i++) {
                Point z(i+0.0,j+0.0), c(0.0,0.0);
                if(iterateJulia(z, c, threshold, maxIt).getOperations() < maxIt) {
                    canvas(i,j) = 0;
                } else {
                    canvas(i,j) = iterate(z, c, threshold, maxIt).getOperations() - std::log2(std::log(std::abs(std::sqrt(std::pow(iterate(z,c,threshold, maxIt).x(),2) + std::pow(iterate(z,c,threshold,maxIt).y(), 2))/std::log(threshold))));
                }
            }
        }
        canvas.write(filename);
    } else {

    }
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
    Canvas canvas(center, 1000, 1000, 4000, 3000);
    mandelbrot(canvas, 1000,1000, "theMandelbrot", true);

    Point newCenter(-.8,.156);
    Canvas newCanvas(newCenter, 1000,1000,4000,3000);
    julia(canvas, 1000, 1000, "theJuliaSet", true);
    return 0;
}