#pragma once
class Vector2
{
private:

	int x;
	int y;
	int z = 1;
	//SDL_Renderer *gRenderer = 0;

public:
	Vector2(float x, float y);
	Vector2();

	Vector2 GetVector2();
	float GetVector2X();
	float GetVector2Y();
	float GetVector2Z();
	void SetVector2XM(float x);
	void SetVector2YM(float y);
	void SetVector2ZM(float z);
	void SetVector2M(int x, int y);

	Vector2 operator + (Vector2);
	Vector2 operator = (Vector2);
	Vector2 operator * (Vector2);
	Vector2 operator * (float);
	void SumaVector2M(Vector2 V2);
	void SumaVector2M(float F2, float F3);
	void RestaVector2M(Vector2 V2);
	void RestaVector2M(float F2, float F3);
	float PointProductVector2(Vector2 V2);
	float NormaVector2();
	void CrossProductVector2(Vector2 V2);

	//void SetRenderer(SDL_Renderer *gRenderer);
	//void DrawVector2();

	~Vector2();
};

