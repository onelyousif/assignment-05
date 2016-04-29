#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "point.h"
#include "shapes.h"

using std::cout;
using std::endl;


void draw(const vector<Shape> & v) {
	const double xSize = 80;
	const double ySize = 25;

	const double xScale = 1;
	const double yScale = 1.9;

	for (double yp = 0; yp < ySize; yp++) {
		double y = yp * yScale;

		for (double xp = 0; xp < xSize; xp++) {
			double x = xp * xScale;

			if (yp == 0 || yp == ySize - 1) {
				cout << "-";
				continue;
			}

			if (xp == 0 || xp == xSize - 1) {
				cout << "|";
				continue;
			}

			bool includePoint = false;

			for (int c = 0; c < v.size(); c++){
				if (v[c]->contains(Point(x, y)))
					includePoint = true;
			}
			
			if (includePoint)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

int main() {
	}
