#include "header.h"



TvectorR2 inputR2() {
	double x, y;
	cout << "Enter coordinates for 2D vector: ";
	cin >> x >> y;
	return TvectorR2(x, y);
};


TvectorR3 inputR3() {
	double x, y, z;
	cout << "Enter coordinates for 3D vector: ";
	cin >> x >> y >> z;
	return TvectorR3(x, y, z);
};


void result(Tvector& v1, Tvector& v2, Tvector& v3, Tvector& v4, Tvector& v5, Tvector& v6, Tvector& v7) {
    double sumD2 = 0.0;
    double sumD3 = 0.0;

    if (v1.length() > 0) {
        if (v1.parallel(v2))
            sumD2 += v2.length();
        if (v1.parallel(v3))
            sumD2 += v3.length();
    }

    if (v4.length() > 0) {
        if (v4.perpendicular(v5))
            sumD3 += v5.length();
        if (v4.perpendicular(v6))
            sumD3 += v6.length();
        if (v4.perpendicular(v7))
            sumD3 += v7.length();
    }

    cout << "\n\nSum of lengths of vectors parallel to the first 2D vector: " << sumD2 << endl;
    cout << "Sum of lengths of vectors perpendicular to the first 3D vector: " << sumD3 << endl;
}