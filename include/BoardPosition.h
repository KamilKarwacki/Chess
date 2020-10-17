#pragma once

// holds the X and Y position the coordinates are kind
// of badly chosen because they start at the left upper corner
// (1,1) (2,1) ...
// (1,2) (2,2) ...
//  ..    ..  (X,Y)
struct BoardPosition
{
	int X, Y;
	BoardPosition() = default;
	BoardPosition(int X, int Y) : X(X), Y(Y) {};
	bool operator==(const BoardPosition& other) const {return X == other.X and Y == other.Y;};

};
