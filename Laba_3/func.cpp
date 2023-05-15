#include "func.h"


Cone add_Cone(int num) {
	float x, y, r;

	cout << "\n\nCone " << num + 1 << "\n";
	cout << "=======================================\n";
	cout << "Enter coordinates of the center: ";
	cin >> x >> y;
	Point p1(x, y);

	cout << "Enter coordinates of the height: ";
	cin >> x >> y;
	Point p2(x, y);

	// Перевірка на співпадання точок
	if (p1.Get_x() == p2.Get_x() && p1.Get_y() == p2.Get_y()) {
		cout << "\nInvalid coordinates! Enter valid coordinates!\n";
		return add_Cone(num);
	}

	// Перевірка на існування такої довжини
	float height = sqrt(pow(p1.Get_x() - p2.Get_x(), 2) + pow(p1.Get_y() - p2.Get_y(), 2));
	if (height <= 0) {
		cout << "Invalid height! Please enter valid coordinates!\n";
		return add_Cone(num); 
	}

	bool f = true;

	do {
		cout << "Enter radius of the cone: ";
		cin >> r;
		if (r < 1) {
			cout << "Radius cannot be 0 or lower!\n\n";
			f = false;
		}
		else {
			f = true;
		}
	} while (!f);

	cout << "=======================================\n";

	return Cone(p1, p2, r);
}

// Обчислення твірної конуса
float Cone::square() {
	float b = change(p2, p1);

	float l = sqrt(pow(b, 2) + pow(radius, 2));
	return l;
}

// Пошук найбільшої твірної
int tvirna(Cone* cones, int num) {
	int max = 0;
	float maxtvir = cones[0].square();

	for (int i = 1; i < num; i++) {
		float Cone = cones[i].square();
		if (Cone > maxtvir) {
			maxtvir = Cone;
			max = i;
		}
	}

	return max;
}

// Виведення результату
void result(Cone* cones, int num, int max) {
	cout << "\n\nResult\n";
	cout << "=======================================" << endl;
	for (int i = 0; i < num; i++) {
		float Cone = cones[i].square();
		cout << "Tvirna of cone " << i + 1 << ": " << Cone << endl;
	}

	cout << "\nCone " << max + 1 << " has the biggest tvirna - " << cones[max].square() << endl;
	cout << "=======================================" << endl;
}