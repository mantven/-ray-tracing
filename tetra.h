#pragma once
#include "Figure.h"
#include "functions.h"
class Tetrahedron: public Figure
{
private:
    std::vector<double> A;
    std::vector<double> B;
    std::vector<double> C;
    std::vector<double> D;
    std::vector<unsigned char> col;
public:
    Tetrahedron()=default;
    Tetrahedron(std::vector<double> AA,std::vector<double> BB, std::vector<double> CC, std::vector<double> DD, std::vector<unsigned char> c);
    bool ray_intersection(std::vector<double> cam,std::vector<double> dir,double* t);
    double ray_intersection_triangular(std::vector<double> cam,std::vector<double> dir,std::vector<double> v0,std::vector<double> v1,std::vector<double> v2);
    double light(std::vector<double> cam,std::vector<double> dir,double t,std::vector<double>light);
    std::vector<unsigned char> color() { return col; }
    ~Tetrahedron()=default;
};

