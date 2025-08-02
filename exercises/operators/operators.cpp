#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>

class Fraction {

  public:
    Fraction(int a_num, int a_denom = 1) : m_num(a_num), m_denom(a_denom) {}

    std::string str() const {
        std::ostringstream oss;
        oss << m_num << '/' << m_denom;
        return oss.str();
    }

    friend bool operator==(Fraction const &lhs, Fraction const &rhs) {
        return (lhs.m_num == rhs.m_num) && (lhs.m_denom == rhs.m_denom);
    }

    friend bool operator!=(Fraction const &lhs, Fraction const &rhs) {
        return !(lhs == rhs);
    }

    friend auto operator<=>(Fraction const &lhs, Fraction const &rhs) {
        return ((lhs.m_num * rhs.m_denom) <=> (rhs.m_num * lhs.m_denom));
    }

    friend Fraction operator*(Fraction const &lhs, Fraction const &rhs) {
        return {lhs.m_num * rhs.m_num, lhs.m_denom * rhs.m_denom};
    }

    friend Fraction &operator*=(Fraction &lhs, Fraction const &rhs) {
        return (lhs = lhs * rhs);
    }

    Fraction normalized() const {
        const int gcd = std::gcd(m_num, m_denom);
        return {m_num / gcd, m_denom / gcd};
    }

  private:
    int m_num, m_denom;
};

std::ostream &operator<<(std::ostream &os, Fraction const &f) {
    return (os << f.str());
}

class TestResultPrinter {

  public:
    TestResultPrinter(unsigned int a_width) : m_width(a_width) {}

    void operator()(std::string const &what, bool passed) {
        std::cout << std::left << std::setw(m_width) << what << ": "
                  << (passed ? "PASS" : "** FAIL **") << '\n';
    }

  private:
    unsigned int m_width;
};

// This is using the cpp, the C preprocessor to expand a bit of code
// (the what argument) to a pair containing a string representation
// of it and the code itself. That way, print is given a string and a
// value where the string is the code that lead to the value
#define CHECK(printer, what) printer(#what, what)

int main() {

    // create a fraction with values 3 (which is 3/1) and 1/3
    std::cout << std::endl;
    const Fraction three{3};
    const Fraction third{1, 3};
    std::cout << three << ' ' << third << std::endl;

    // equality
    std::cout << std::endl;
    TestResultPrinter p1{40};
    CHECK(p1, three == three);
    CHECK(p1, third == third);
    CHECK(p1, three == Fraction{3});
    CHECK(p1, (three == Fraction{3, 1}));
    CHECK(p1, (third == Fraction{1, 3}));
    CHECK(p1, (Fraction{3} == three));
    CHECK(p1, (Fraction{1, 3} == third));
    CHECK(p1, (third != Fraction{2, 6}));
    CHECK(p1, (third == Fraction{2, 6}.normalized()));

    // equivalence
    std::cout << std::endl;
    TestResultPrinter p2{32};
    CHECK(p2, (third <=> Fraction{2, 6}) == 0);
    CHECK(p2, (third <=> Fraction{1, 4}) > 0);
    CHECK(p2, (third <=> Fraction{2, 4}) < 0);

    // multiply
    std::cout << std::endl;
    TestResultPrinter p3{48};
    CHECK(p3, ((third * 2) == Fraction{2, 3}));
    CHECK(p3, ((2 * third) == Fraction{2, 3}));
    CHECK(p3, ((three * third) <=> Fraction{1, 1}) == 0);
    CHECK(p3, ((3 * third) <=> Fraction{1, 1}) == 0);
    CHECK(p3, ((3 * third).normalized() == 1));

    // mult. assignment
    std::cout << std::endl;
    TestResultPrinter p4{32};
    Fraction four = Fraction{4};
    four *= 2;
    CHECK(p4, (four == Fraction{8}));
    Fraction x = Fraction{1};
    (x *= 2) *= 2;
    CHECK(p4, (x == Fraction{4}));
    // end
    std::cout << std::endl;
}
