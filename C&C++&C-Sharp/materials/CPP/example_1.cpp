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
    virtual void printName(){
        std::cout<<"Some shape"<<std::endl;
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
    void printName() override{
        std::cout<<"Cube"<<std::endl;
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
    void printName() override{
        std::cout<<"Sphere"<<std::endl;
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
    void printName() override{
        std::cout<<"Cylinder"<<std::endl;
    }
};
int main(){
    using std::cout, std::endl;

    cube kubic(5);
    sphere sfera(5.5);
    cylinder cylindr(3, 7);

    cout<<"Kubik: "<<endl;
    kubic.printName();
    // cout<<"Area: "<<kubic.area<<endl;       //error
    // cout<<"Volume: "<<kubic.volume<<endl;   //error
    cout<<"Area: "<<kubic.getArea()<<endl;
    cout<<"Volume: "<<kubic.getVolume()<<endl;

    cout<<"Sfera: "<<endl;
    sfera.printName();
    cout<<"Area: "<<sfera.getArea()<<endl;
    cout<<"Volume: "<<sfera.getVolume()<<endl;

    cout<<"Cylindr: "<<endl;
    cylindr.printName();
    cout<<"Area: "<<cylindr.getArea()<<endl;
    cout<<"Volume: "<<cylindr.getVolume()<<endl;

    return 0;
} 