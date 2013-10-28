#ifndef POINT_H
#define POINT_H

#include <stdlib.h>
#include "../std_lib_facilities.h"

class Point {
public:
	int x,y;

	Point (void);
	Point (int nx, int ny);

	bool operator == (const Point &p) {
		return x == p.x && y == p.y;
	}
};


#endif