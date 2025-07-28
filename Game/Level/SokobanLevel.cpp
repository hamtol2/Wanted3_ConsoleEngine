#include "SokobanLevel.h"
#include <iostream>
#include "Math/Vector2.h"

SokobanLevel::SokobanLevel()
{
	ReadMapFile("Map.txt");
}

void SokobanLevel::ReadMapFile(const char* filename)
{
	// ���� �ּ� ��� �ϼ�.
	char filepath[256] = { };
	sprintf_s(filepath, 256, "../Assets/%s", filename);

	FILE* file = nullptr;
	fopen_s(&file, filepath, "rb");

	// ����ó��.
	if (file == nullptr)
	{
		std::cout << "�� ���� �б� ����: " << filename << "\n";
		__debugbreak();
		return;
	}

	// �Ľ�(Parcing, �ؼ�).
	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);
	rewind(file);

	// Ȯ���� ���� ũ�⸦ Ȱ���� ���� �Ҵ�.
	char* buffer = new char[fileSize + 1];
	//buffer[fileSize] = '\0';
	memset(buffer, 0, fileSize + 1);
	size_t readSize = fread(buffer, sizeof(char), fileSize, file);

	if (fileSize == readSize)
	{
		std::cout << "fileSize = readSize.\n";
	}

	// �迭 ��ȸ�� ���� �ε��� ����.
	int index = 0;

	// ���ڿ� ���� ��.
	int size = (int)readSize;

	// x, y ��ǥ.
	Vector2 position;

	// ���� �迭 ��ȸ.
	while (index < size)
	{
		// �� ���� Ȯ��.
		char mapCharacter = buffer[index];
		++index;

		// ���� ���� ó��.
		if (mapCharacter == '\n')
		{
			// ���� �ٷ� �ѱ�鼭, x ��ǥ �ʱ�ȭ.
			++position.y;
			position.x = 0;

			// @Todo: �׽�Ʈ�뵵. ���߿� �����ؾ���.
			std::cout << "\n";
			continue;
		}

		// �� ���� ���� ó��.
		switch (mapCharacter)
		{
		case '#':
			std::cout << "#";
			break;
		case '.':
			std::cout << ".";
			break;
		case 'p':
			std::cout << "p";
			break;
		case 'b':
			std::cout << "b";
			break;
		case 't':
			std::cout << "t";
			break;
		}
	}

	// ���� ����.
	delete[] buffer;

	// ���� �ݱ�.
	fclose(file);
}