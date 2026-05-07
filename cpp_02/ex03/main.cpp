#include <iostream>
#include "Point.hpp"

void test(
    Point const a,
    Point const b,
    Point const c,
    Point const p,
    std::string const& name
) {
    std::cout << name << ": ";

	/**
	 * True if the point is inside the triangle. False otherwise.
	 * Thus, if the point is a vertex or on an edge, it will return False
	 */
    if (bsp(a, b, c, p))
        std::cout << "INSIDE";
    else
        std::cout << "OUTSIDE";

    std::cout << std::endl;
}

int main() {

    // triangle
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    // in
    test(a, b, c, Point(5, 5), "Inside center [in]");
    
	// out
    test(a, b, c, Point(5, -5), "Inside down [out]");

    // out
    test(a, b, c, Point(15, 5), "Outside right [out]");

    // out
    test(a, b, c, Point(-1, -1), "Outside near A [out]");

    // vertex
    test(a, b, c, Point(0, 0), "On vertex A [out]");

    // out
    test(a, b, c, Point(5, 0), "On edge AB [out]");

    // in
    test(a, b, c, Point(5, 0.1f), "Near edge inside [in]");

    // out
    test(a, b, c, Point(5, -0.1f), "Near edge outside [out]");

    return 0;
}