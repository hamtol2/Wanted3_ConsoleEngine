#include "TestActor.h"
#include <iostream>
#include "Engine.h"
#include <Windows.h>

void TestActor::Tick(float deltaTime)
{
	//Actor::Tick(deltaTime);
	super::Tick(deltaTime);

	std::cout 
		<< "TestActor::Tick. FPS: " 
		<< (1.0f / deltaTime) 
		<< "\n";

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().Quit();
	}
}