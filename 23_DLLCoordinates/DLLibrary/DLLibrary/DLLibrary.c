#include "DLLibraryHeader.h"
#include <Math.h>

double SegmentLengh(Coordinates dot1, Coordinates dot2)
{
	return sqrt(pow(dot1.x - dot2.x, 2) + pow(dot1.y - dot2.y, 2));
}