#pragma once
class Vector2
{
public:
	int x = 0;
	int y = 0;
	int z = 1;
	Vector2(int x, int y);
	Vector2 GetVector2();
	void SetVector2(int x, int y);

	Vector2 SumaVector2(Vector2 V1, Vector2 V2);

	~Vector2();
};

