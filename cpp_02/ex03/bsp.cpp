#include "Point.hpp"

/**
 * https://hackmd.io/@ChloeIsCoding/r19Mge-fll
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float ax = a.getX().toFloat();
	float bx = b.getX().toFloat();
	float cx = c.getX().toFloat();
	float px = point.getX().toFloat();

	float ay = a.getY().toFloat();
	float by = b.getY().toFloat();
	float cy = c.getY().toFloat();
	float py = point.getY().toFloat();

	float ap = (bx - ax) * (py - ay) - (by - ay) * (px - ax);
	float bp = (cx - bx) * (py - by) - (cy - by) * (px - bx);
	float cp = (ax - cx) * (py - cy) - (ay - by) * (px - cx);

	if (ap == 0 || bp == 0 || cp == 0) // is on some edge
		return false;
	
	bool hasNegative = ap < 0 || bp < 0 || cp < 0;
	bool hasPositive = ap > 0 || bp > 0 || cp > 0;

	return !(hasNegative && hasPositive); // inside if all have the same sign
}
