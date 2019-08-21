#include "pch.h"
#include "Line.h"


Line::Line(int x1, int y1, int x2, int y2)
{
	_x1 = x1;
	_y1 = y1;
	_x2 = x2;
	_y2 = y2;
	_m = ((_y2 - _y1) / (_x2 - _x1));
	_c = _y1 - (((_y2 - _y1) / (_x2 - _x1)) * _x1);
}


Line::~Line()
{
}
