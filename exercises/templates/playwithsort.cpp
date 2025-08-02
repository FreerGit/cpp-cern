#include "Complex.hpp"
#include "OrderedVector.hpp"
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>

struct ReverseStringLess {
    bool operator()(const std::string &s, const std::string &t) const {
        return std::ranges::lexicographical_compare(std::views::reverse(s), std::views::reverse(t));
    }
};

int main() {
    std::cout << "Integer\n";
    OrderedVector<int> v(10);
    for (int i = 10; i > 0; i--)
        v.add(i);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << "\n\n";

    std::cout << "String\n";
    OrderedVector<std::string> vs(5);
    vs.add(std::string("one"));
    vs.add(std::string("two"));
    vs.add(std::string("three"));
    vs.add(std::string("four"));
    vs.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vs[i] << " ";
    std::cout << "\n\n";

    // TODO: Demonstrate OrderedVector with Complex as element type similar to above
    OrderedVector<Complex> vc(3);
    vc.add(Complex_t<float>(1., 0.));
    vc.add(Complex_t<float>(2., 0.));
    vc.add(Complex_t<float>(3., 0.));

    // TODO: Extend OrderedVector to allow to customize the ordering via an additional template
    // paramter.
    //       Then, demonstrate the new functionality by ordering an OrderedVector<std::string>,
    //       where the strings are compared starting at their last letters.

    std::cout << "String\n";
    OrderedVector<std::string, ReverseStringLess> vss(5);
    vss.add(std::string("one"));
    vss.add(std::string("two"));
    vss.add(std::string("three"));
    vss.add(std::string("four"));
    vss.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vss[i] << " ";
    std::cout << "\n\n";
    // TODO: Order an OrderedVector of Complex based on the Manhattan distance
}
