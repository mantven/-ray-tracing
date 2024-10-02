#pragma once
#include "Figure.h"
#include "functions.h"

class Box :public Figure
{   private:
    std::vector<double> min;
    std::vector<double> max;
    std::vector<unsigned char> col;
public:
    Box() {};
    Box(std::vector<double> v_min,std::vector<double> v_max, std::vector<unsigned char> col);
    bool ray_intersection(std::vector<double> cam,std::vector<double> dir,double* result);
    double light(std::vector<double> cam, std::vector<double> dir, double dist, std::vector<double> light);
    std::vector<unsigned char> color() { return col; }
    ~Box() {};
};
