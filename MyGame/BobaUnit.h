#pragma once
#include "Boba.h"

class BobaUnit
{
public:
	BobaUnit() = delete;
	BobaUnit(const std::string& imageFile, int xPos,int yPos,int speed);
	int GetUnitWidth() const;
	int GetUnitHeight() const;
	void SetPosX(int newX);
	void SetPosY(int newY);
	int GetPosX() const;
	int GetPosY() const;
	int GetSpeed() const;
	

	bool CollideWith(const BobaUnit& other) const;

	void Draw(Boba::BobaShader& shader);

	enum class Direction {
		None,
		Up,
		Down,
		Left,
		Right
	};
	BobaUnit::Direction GetDirection() const;
	void SetDirection(BobaUnit::Direction newDirection);

	void UpdatePosition();

private:
	bool IsPositionPossible(int newX, int newY) const;
	Boba::BobaSprite bImage;
	int bPosX;
	int bPosY;
	int bSpeed;

	Direction bDirection;
};

