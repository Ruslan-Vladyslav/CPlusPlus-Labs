#pragma once
#include "func.h"
#include <iostream>

using namespace std;



class Point {
	float x, y; // За замовчуванням private

public:
	Point() { x = 0; y = 0; }

	Point(float px, float py) {
		x = px;
		y = py;
	}

	float Get_x() { return x; }
	float Get_y() { return y; }

};


class Cone {
	// За замовчуванням private
	Point p1, p2;
	float radius;


	float change(Point& p1, Point& p2) { return sqrt(pow(p1.Get_x() - p2.Get_x(), 2) + pow(p1.Get_y() - p2.Get_y(), 2)); }

public:
	Cone() {
		p1 = {0,0};
		p2 = {0,0};
		radius = 0;
	}

	Cone(Point& point1, Point& point2, float r) {
		p1 = point1;
		p2 = point2;
		radius = r;
	}

	float square();
};


Cone add_Cone(int num);
int tvirna(Cone* cones, int n);
void result(Cone* cones, int n, int max);
