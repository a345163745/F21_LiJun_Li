#include "BobaUnit.h"

BobaUnit::BobaUnit(const std::string& imageFile, int xPos, int yPos,int speed):
	bPosX(xPos),bPosY(yPos),bSpeed(speed),bDirection(Direction::None)
{
	bImage.LoadImage(imageFile);
}

int BobaUnit::GetUnitWidth() const
{
	return bImage.GetWidth();
}

int BobaUnit::GetUnitHeight() const
{
	return bImage.GetHeight();
}

void BobaUnit::SetPosX(int newX)
{
	bPosX = newX;
}

void BobaUnit::SetPosY(int newY)
{
	bPosY = newY;
}

int BobaUnit::GetPosX() const
{
	return bPosX;
}

int BobaUnit::GetPosY() const
{
	return bPosY;
}

int BobaUnit::GetSpeed() const
{
	return bSpeed;
}

bool BobaUnit::CollideWith(const BobaUnit& other) const
{
	int oXleft{ other.GetPosX() };
	int oXright{ other.GetPosX() + other.GetUnitWidth() };
	int oYbottom{ other.GetPosY() };
	int oYtop{ other.GetPosY() + other.GetUnitHeight() };

	bool intersectOnX{
		(bPosX <= oXleft && oXleft <= bPosX + GetUnitWidth()) ||
		(bPosX <= oXright && oXright <= bPosX + GetUnitWidth()) ||
		(oXleft <= bPosX && bPosX + GetUnitWidth() <=oXright)};
	bool intersectOnY{
		(bPosY <= oYbottom && oYbottom <= bPosY + GetUnitHeight()) ||
		(bPosX <= oYtop && oYtop <= bPosY + GetUnitHeight()) ||
		(oYbottom <= bPosY && bPosY+GetUnitHeight()<=oYtop)};
	return intersectOnX && intersectOnY;
}

void BobaUnit::Draw(Boba::BobaShader& shader)
{
	Boba::BobaRenderer::Draw(bImage, bPosX, bPosY, bImage.GetWidth(), bImage.GetHeight(), shader);
}

BobaUnit::Direction BobaUnit::GetDirection() const
{
	return bDirection;
}

void BobaUnit::SetDirection(BobaUnit::Direction newDirection)
{
	bDirection = newDirection;
}

void BobaUnit::UpdatePosition()
{
	switch (bDirection)
	{
	case Direction::Down:
		if(IsPositionPossible(bPosX,bPosY-bSpeed))
			bPosY -= bSpeed;
		break;
	case Direction::Up:
		if (IsPositionPossible(bPosX, bPosY + bSpeed))
			bPosY += bSpeed;
		break;
	case Direction::Left:
		if (IsPositionPossible(bPosX - bSpeed, bPosY ))
			bPosX -= bSpeed;
		break;
	case Direction::Right:
		if (IsPositionPossible(bPosX + bSpeed, bPosY))
			bPosX += bSpeed;
		break;
	}
}

bool BobaUnit::IsPositionPossible(int newX, int newY) const
{
	if ((newX < 0) ||
		(newY < 0) ||
		(newX + bImage.GetWidth() > 800) ||
		(newY + bImage.GetHeight() > 800)) 
		return false;
	else
		return true;
}


