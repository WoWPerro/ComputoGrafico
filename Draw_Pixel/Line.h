#pragma once
class Line
{
private:
	int _x1;
	int _y1;
	int _x2;
	int _y2;
	float _m;
	float _c;
public:
	Line(int x1, int y1, int x2, int y2);
	~Line();
};

