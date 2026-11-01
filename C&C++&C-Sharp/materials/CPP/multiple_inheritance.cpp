#include <iostream>
#include <fstream>
using std::endl, std::cout, std::ostream, std::istream;

class figure{
    protected:
        double x0{0},y0{0},x1{0},y1{0};
    public:
        figure(double a=0,double s=0, double d=0, double f=0): x0{a},y0{s},x1{d},y1{f}{}
        virtual ~figure(){}
        virtual void printer()const=0;
};
class figurelog{
    protected:
        bool fig_saved{false};
    public:
        virtual ~figurelog(){}
        virtual void save(ostream& out) const=0;
        virtual void load(istream& in)=0;
};
class line:public figure, public figurelog{
    public:
        void printer() const override final {
            cout<<"Line: "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<< endl;
        }
        line (double q=0,double w=0,double e=0,double r=0): figure(q,w,e,r){}
        void save(ostream& out) const override  {
            out.write((char*)this,sizeof(*this));}
        void load(istream& in) override {
            in.read((char*)this,sizeof(*this));}

};


int main(){
    
    line ln(44,3,22,1);
    figure* ptr_f=&ln;          //ok
    figurelog* ptr_fl=&ln;      //ok
    figure& lnk_f=ln;           //ok
    figurelog& lnk_fl=ln;       //ok

    ptr_f->printer();
    std::ofstream ofs("output.txt", std::ios::out | std::ios::binary);
    lnk_fl.save(ofs);

    return 0;
}