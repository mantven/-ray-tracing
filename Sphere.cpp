#include "Sphere.h"
Sphere::Sphere(double r, std::vector<double> v, std::vector<unsigned char> c)
{
    radius = r;
    col = c;
    centre.resize(3);
    centre = v;
}
bool Sphere::ray_intersection(std::vector<double> cam, std::vector<double> dir, double* r) {
    std::vector<double> diff={cam[0]-centre[0],cam[1]-centre[1],cam[2]-centre[2]};
    //double dir_scal=scalar_product(dir,dir);
    double dir_scal=1;
    double projection=2*scalar_product(dir,diff)/sqrt(scalar_product(dir,dir));
    double dist=scalar_product(diff,diff)-pow(radius,2);
    double D=projection*projection-4*/*dir_scal*/dist;
    if (D>0){
        double x1=(-projection+sqrt(D))/2;
        double x2=(-projection-sqrt(D))/2;
        if (x1>0 && x2>0){
            *r=std::min(x1,x2);
            return true;
        }
    }
    return false;
}
double Sphere::light(std::vector<double> cam, std::vector<double> dir,double d,std::vector<double> light) {
    std::vector<double> intersect(3);
    double l_dir=sqrt(scalar_product(dir,dir));
    intersect = {cam[0]+d*dir[0]/l_dir,cam[1]+d*dir[1]/l_dir,cam[2]+d*dir[2]/l_dir};
    std::vector<double> normal(3);
    normal = {intersect[0]-centre[0],intersect[1]-centre[1],intersect[2]-centre[2]};
    double normal_length = scalar_product(normal,normal); const double koefficient=0.2;
    normal = {normal[0]/sqrt(normal_length),normal[1]/sqrt(normal_length),normal[2] / sqrt(normal_length) };
    light = { light[0] - intersect[0],light[1] - intersect[1] ,light[2] - intersect[2] };
    light = { light[0]/sqrt(scalar_product(light,light)),light[1] / sqrt(scalar_product(light,light)),light[2] / sqrt(scalar_product(light,light)) };
    std::vector<double> reflected(3);
    reflected={-light[0]+2*scalar_product(normal,light)*normal[0],-light[1]+2*scalar_product(normal,light)*normal[1],-light[2]+2*scalar_product(normal,light)*normal[2]};
    reflected={reflected[0]/sqrt(scalar_product(reflected,reflected)),reflected[1]/sqrt(scalar_product(reflected,reflected)),reflected[2]/sqrt(scalar_product(reflected,reflected))};
    intersect={intersect[0]/sqrt(scalar_product(intersect,intersect)),intersect[1]/sqrt(scalar_product(intersect,intersect)),intersect[2]/sqrt(scalar_product(intersect,intersect))};
    double specular=-scalar_product(reflected,intersect);
    specular=koefficient*pow(std::max(0.0,specular),40);
    double result = std::max(0.0,scalar_product(light,normal));
    return result+specular;
}
