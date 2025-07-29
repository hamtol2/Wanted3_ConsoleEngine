#include "MenuLevel.h"
#include "Game/Game.h"

MenuLevel::MenuLevel()
{
	// 메뉴 아이템 추가.
	items.emplace_back(new MenuItem(
		"Resume Game",
		[]() { /* Todo: 메뉴 토글 기능 추가 해야함.*/ }
	));

	items.emplace_back(new MenuItem(
		"Quit Game",
		[]() { Game::Get().Quit(); }
	));

	// 아이템 수 미리 저장.
	length = static_cast<int>(items.size());
}

MenuLevel::~MenuLevel()
{
	for (MenuItem* item : items)
	{
		SafeDelete(item);
	}

	items.clear();
}