#include <iostream>
//#include <cmath>

using namespace std;

class Tvector {
protected:
    double x, y, z;

public:
    Tvector(double xcor, double ycor, double zcor) : x(xcor), y(ycor), z(zcor) {}

    virtual double length() {
        return sqrt((x * x) + (y * y) + (z * z));
    }

    virtual bool parallel(Tvector& other) {
        double eps = 1e-6; // Мале значення для порівняння з нулем
        double dot_product = x * other.x + y * other.y + z * other.z;
        double mag_product = length() * other.length();

        return fabs(dot_product - mag_product) < eps;
    }

    virtual bool perpendicular(Tvector& other) {
        double eps = 1e-6; 
        double dot_product = x * other.x + y * other.y + z * other.z;

        return fabs(dot_product) < eps;
    }
};


class TvectorR2 : public Tvector {
public:
    TvectorR2(double xcor, double ycor) : Tvector(xcor, ycor, 0) {}

    double length() override {
        return sqrt((x * x) + (y * y));
    }
};


class TvectorR3 : public Tvector {
public:
    TvectorR3(double xcor, double ycor, double zcor) : Tvector(xcor, ycor, zcor) {}

    double length() override {
        return sqrt((x * x) + (y * y) + (z * z));
    }
};

TvectorR2 inputR2();
TvectorR3 inputR3();
void result(Tvector& v1, Tvector& v2, Tvector& v3, Tvector& v4, Tvector& v5, Tvector& v6, Tvector& v7);