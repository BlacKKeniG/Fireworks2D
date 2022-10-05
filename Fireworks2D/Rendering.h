#pragma once

#include<iostream>
#include<Windows.h>

#include "eColor.h"
#include "Cannon.h"

class Rendering {

public:

	explicit Rendering();
	~Rendering() = default;

	struct DrawingFieldInfo {
		HDC _hDC{};
		RECT _border{};
		USHORT _width{};
		USHORT _height{};
	};
	DrawingFieldInfo _drawingFieldInfo;

	void drawBackground() const;

	void drawCannon(const COORD& position) const;

	void drawFireworkObject(const COORD& position, const USHORT width, const USHORT height, const eColor color) const;

	BOOL ObjectIsInDrawingField(const COORD& position, const USHORT width, const USHORT height) const;

	void initializeDrawingFieldInfo(HWND hWnd);
};


