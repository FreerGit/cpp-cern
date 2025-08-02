#include "Polygons.hpp"
#include <iostream>

int main()
{
    // create a Pentagon, call its perimeter method
    auto p = Pentagon(5.0);
    p.computePerimeter();
    // create a Hexagon, call its perimeter method
    auto h = Hexagon(4.0);
    h.computePerimeter();
    // create a Hexagon, call the perimeter method through a reference to Polygon
    auto hexa2 = Hexagon(1.0);
    RegularPolygon& poly = hexa2;
    hexa2.computePerimeter();
    poly.computePerimeter();

    // retry virtual method
}
