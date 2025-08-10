/*

In the code below, replace inheritance with the use of a `std::variant<Electron, Proton, Neutron>`.
There is no more need for a base class, and no more need pointers.
Two solutions are provided :
1. with `std::get_if`,
2. with `std::visit`.

*/

#include <iostream>
#include <memory>
#include <variant>
#include <vector>

struct Electron {
    void print() const {
        std::cout << "E\n";
    }
};

struct Proton {
    void print() const {
        std::cout << "P\n";
    }
};

struct Neutron {
    void print() const {
        std::cout << "N\n";
    }
};

using Particle = std::variant<Electron, Proton, Neutron>;

int main() {
    std::vector<Particle> ps;
    ps.push_back(Electron{});
    ps.push_back(Proton{});
    ps.push_back(Neutron{});

    for (auto const &p : ps) {
        std::visit([](const auto &p) { p.print(); }, p);
    }
}
