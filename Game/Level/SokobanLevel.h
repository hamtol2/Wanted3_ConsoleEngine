#pragma once

#include "Level/Level.h"
#include "Interface/ICanPlayerMove.h"

class SokobanLevel : public Level, public ICanPlayerMove
{
	RTTI_DECLARATIONS(SokobanLevel, Level)
public:
	SokobanLevel();

private:
	void ReadMapFile(const char* filename);
public:

	// Inherited via ICanPlayerMove.
	virtual bool CanPlayerMove(
		const Vector2& playerPosition, 
		const Vector2& newPosition) override;
};