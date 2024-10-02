#pragma once
#include "tetra.h"
#include "Factory.h"
#include "Figure.h"
class Factory_tetra: public Factory {
public:
    Factory_tetra() = default;
    Figure* Create(std::vector<double> p1,std::vector<double> p2,std::vector<double> p3,std::vector<double> p4, std::vector<unsigned char> col)override {
        return new Tetrahedron(p1,p2,p3,p4,col);
    }
    Figure* Create(std::vector<double> min,std::vector<double> max, std::vector<unsigned char> col) override {
        min=min;
        max=max;
        col = col;
        return new Tetrahedron();
    }
    Figure* Create(double radius, std::vector<double> centre, std::vector<unsigned char> col) override {
        centre=centre;
        radius=radius;
        col = col;
        return new Tetrahedron();
    }
    ~Factory_tetra() = default;
};
