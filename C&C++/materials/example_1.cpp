#include <iostream>
#include <math.h>

class Shape{
    protected:
        double volume=0;
        double area=0;
    public:
    double getVolume(){
        return volume;
    }    
    double getArea(){
        return area;
    }
};
class cube:public Shape{
    public:
        double side;
    cube(double s){
        side=s;
        volume=pow(side,3);
        area=6*pow(side,2);
    }
};
class sphere:public Shape{
    public:
        double radius;
    sphere(double r){
        radius=r;
        volume=(4.0/3.0)*M_PI*pow(radius,3);
        area=4*M_PI*pow(radius,2);
    }
};
class cylinder:public Shape{
    public:
        double radius;
        double height;
    cylinder(double r, double h){
        radius=r;
        height=h;
        volume=M_PI*pow(radius,2)*height;
        area=2*M_PI*radius*(radius+height);
    }
};
int main(){
    using std::cout, std::endl;
    cube kubic(5);
    sphere sfera(5.5);
    cylinder cylindr(3, 7);
    cout<<"Kubik: "<<endl;
    // cout<<"Area: "<<kubic.area<<endl;       //error
    // cout<<"Volume: "<<kubic.volume<<endl;   //error
    cout<<"Area: "<<kubic.getArea()<<endl;
    cout<<"Volume: "<<kubic.getVolume()<<endl;
    cout<<"Sfera: "<<endl;
    cout<<"Area: "<<sfera.getArea()<<endl;
    cout<<"Volume: "<<sfera.getVolume()<<endl;
    cout<<"Cylindr: "<<endl;
    cout<<"Area: "<<cylindr.getArea()<<endl;
    cout<<"Volume: "<<cylindr.getVolume()<<endl;
    
    return 0;
} 