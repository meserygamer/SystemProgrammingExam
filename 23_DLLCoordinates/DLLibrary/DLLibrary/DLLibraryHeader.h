#pragma once
typedef struct Coordinates
{
	double x;
	double y;
} Coordinates;

_declspec(dllexport) double _cdecl SegmentLengh(Coordinates dot1, Coordinates dot2);