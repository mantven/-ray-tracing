#pragma once
#include "Figure.h"
#include "functions.h"
class Sphere : public Figure {
private:
    double radius;
    std::vector<double> centre;
    std::vector<unsigned char> col;
public:
    Sphere() {};
    Sphere(double r, std::vector<double> v, std::vector<unsigned char> c);
    bool ray_intersection(std::vector<double> cam, std::vector<double> dir, double* r);
    double light(std::vector<double> cam, std::vector<double> dir,double d,std::vector<double> light);
    std::vector<unsigned char> color() { return col; }
    ~Sphere()=default;
};

