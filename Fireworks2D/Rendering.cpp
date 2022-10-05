#include"Rendering.h"

Rendering::Rendering() : _drawingFieldInfo{} {};

void Rendering::initializeDrawingFieldInfo(HWND hWnd) {
	GetClientRect(hWnd, &_drawingFieldInfo._border);
	_drawingFieldInfo._hDC = GetDC(hWnd);
	_drawingFieldInfo._width = _drawingFieldInfo._border.right - _drawingFieldInfo._border.left;
	_drawingFieldInfo._height = _drawingFieldInfo._border.bottom - _drawingFieldInfo._border.top;
}

void Rendering::drawBackground() const {

	SelectObject(_drawingFieldInfo._hDC, GetStockObject(DC_BRUSH));
	SetDCBrushColor(_drawingFieldInfo._hDC, eColor::BLACK);

	Rectangle(_drawingFieldInfo._hDC
		, _drawingFieldInfo._border.left, _drawingFieldInfo._border.top
		, _drawingFieldInfo._border.right, _drawingFieldInfo._border.bottom
	);
};

void Rendering::drawCannon(const COORD& position) const {

	RECT cannonBorder{ position.X, position.Y
		,position.X + CANNON_WIDTH, position.Y + CANNON_HEIGHT
	};
	
	SelectObject(_drawingFieldInfo._hDC, GetStockObject(DC_BRUSH));
	SetDCBrushColor(_drawingFieldInfo._hDC, eColor::YELLOW);
	Ellipse(_drawingFieldInfo._hDC
		, cannonBorder.left + 10
		, cannonBorder.top
		, cannonBorder.right - 10
		, cannonBorder.bottom
	);

	SetDCBrushColor(_drawingFieldInfo._hDC, eColor::WHITE);
	Ellipse(_drawingFieldInfo._hDC
		, cannonBorder.left + 14
		, cannonBorder.top
		, cannonBorder.right - 14
		, cannonBorder.bottom - 34
	);

	SetDCBrushColor(_drawingFieldInfo._hDC, eColor::ORANGE);
	RoundRect(_drawingFieldInfo._hDC
		, cannonBorder.left
		, cannonBorder.top + 20
		, cannonBorder.right - 31
		, cannonBorder.bottom
		, 5, 5
	);
	RoundRect(_drawingFieldInfo._hDC
		, cannonBorder.left + 31
		, cannonBorder.top + 20
		, cannonBorder.right
		, cannonBorder.bottom
		, 5, 5
	);
}

void Rendering::drawFireworkObject(const COORD& position, const USHORT width, const USHORT height, const eColor color) const {

	if (ObjectIsInDrawingField(position, width, height)) {

		SelectObject(_drawingFieldInfo._hDC, GetStockObject(DC_BRUSH));
		SetDCBrushColor(_drawingFieldInfo._hDC, color);
		Ellipse(_drawingFieldInfo._hDC
			, position.X
			, position.Y
			, position.X + width
			, position.Y + height
		);
	}
}

BOOL Rendering::ObjectIsInDrawingField(const COORD& position, const USHORT width, const USHORT height) const {
	return position.X >= 0 && position.X + width <= _drawingFieldInfo._width
		&& position.Y >= 0 && position.Y + height <= _drawingFieldInfo._height;
}