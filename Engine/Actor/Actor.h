#pragma once

#include "Core.h"
#include "Math/Vector2.h"
#include "RTTI.h"

// 물체 뭘해야할까?를 정의.
// 위치 점령.
// 콘솔 창에 그리기(How?What?).
// 엔진의 이벤트 함수 호출.
// BeginPlay/Tick/Draw.

// 색상.
enum class Color : int
{
	Blue = 1,
	Green = 2,
	Red = 4,
	White = Red | Green | Blue,
	Intensity = 8,
};

class Engine_API Actor : public RTTI
{
	RTTI_DECLARATIONS(Actor, RTTI)

public:
	Actor(const char image = ' ', Color color = Color::White);
	virtual ~Actor();

	// 이벤트 함수.

	// 객체 생애주기(Lifetime)에 1번만 호출됨 (초기화 목적).
	virtual void BeginPlay();

	// 프레임 마다 호출 (반복성 작업/지속성이 필요한 작업).
	virtual void Tick(float deltaTime);

	// 그리기 함수.
	virtual void Render();

	// BeginPlay 호출 여부 확인.
	inline bool HasBeganPlay() const { return hasBeganPlay; }

	// 위치 설정/값 읽는 함수.
	void SetPosition(const Vector2& newPosition);
	Vector2 Position() const;

private:
	// 개체의 위치.
	Vector2 position;

	// 그릴 값.
	char image = ' ';

	// 텍스트 색상 값.
	Color color;

	// BeginPlay 호출이 되었는지 확인.
	bool hasBeganPlay = false;
};