#include "header.h"



int main() {

    cout << "\nYou should enter coordinates: for 2D (x, y), for 3D (x, y, z)\n\n";
    cout << "\nCoordinates for 2D vector:\n";
    cout << "--------------------------------------\n";
    TvectorR2 v1 = inputR2();
    TvectorR2 v2 = inputR2();
    TvectorR2 v3 = inputR2();

    cout << "\n\nCoordinates for 3D vector:\n";
    cout << "--------------------------------------\n";

    TvectorR3 v4 = inputR3();
    TvectorR3 v5 = inputR3();
    TvectorR3 v6 = inputR3();
    TvectorR3 v7 = inputR3();


    result(v1, v2, v3, v4, v5, v6, v7);

    cout << "\n\nExitting program\n";
    return 0;
};