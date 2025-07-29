#include "MenuLevel.h"
#include "Game/Game.h"

MenuLevel::MenuLevel()
{
	// �޴� ������ �߰�.
	items.emplace_back(new MenuItem(
		"Resume Game",
		[]() { /* Todo: �޴� ��� ��� �߰� �ؾ���.*/ }
	));

	items.emplace_back(new MenuItem(
		"Quit Game",
		[]() { Game::Get().Quit(); }
	));

	// ������ �� �̸� ����.
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