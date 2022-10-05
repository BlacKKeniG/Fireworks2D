#pragma once

class BaseObject {
public:

	explicit BaseObject() : BaseObject({}, 0, 0) {}

	explicit BaseObject(const COORD position, const USHORT width, const USHORT height)
		: _position{ position }, _width{ width }, _height{ height } {};

	virtual ~BaseObject() = default;

	COORD _position;
	USHORT _width;
	USHORT _height;

};
