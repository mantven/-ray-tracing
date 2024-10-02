#pragma once
#include "Sphere.h"
#include "Factory.h"
#include "Figure.h"
class Factory_Sphere: public Factory {
public:
	Factory_Sphere() = default;
    Figure* Create(double radius, std::vector<double> centre, std::vector<unsigned char> col) override {
		return new Sphere(radius,centre, col);
	}
    Figure* Create(std::vector<double> p1,std::vector<double> p2,std::vector<double> p3,std::vector<double> p4, std::vector<unsigned char> col)override {
        p1=p1;
        p2=p2;
        p3=p3;
        p4=p4;
        col = col;
        return new Sphere();
    }
    Figure* Create(std::vector<double> min,std::vector<double> max, std::vector<unsigned char> col) override {
        min=min;
        max=max;
        col = col;
        return new Sphere();
    }
	~Factory_Sphere() = default;
};
