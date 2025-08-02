#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>

class Fraction {

  public:
    // ADD YOUR CODE HERE
    Fraction(int a) : m_num(a), m_denom(1) {}
    Fraction(int a, int b) : m_num(a), m_denom(b) {}

    friend auto equal(Fraction const &m, Fraction const &f) -> bool {
        return (m.m_num == f.m_num) && (m.m_denom == f.m_denom);
    }

    friend auto multiply(Fraction const &m, Fraction const &f) -> Fraction {
        return Fraction{m.m_num * f.m_num, m.m_denom * f.m_denom};
    }

    std::string str() const {
        std::ostringstream oss;
        oss << m_num << '/' << m_denom;
        return oss.str();
    }
    auto normalize() -> const Fraction {
        const int gcd = std::gcd(m_num, m_denom);
        int num = m_num = gcd;
        int denom = m_denom / gcd;
        return Fraction(num, denom);
    }

  private:
    int m_num, m_denom;
};

// ADD YOUR CODE HERE

// This is using the cpp, the C preprocessor to expand a bit of code
// (the what argument) to a pair containing a string representation
// of it and the code itself. That way, print is given a string and a
// value where the string is the code that lead to the value
#define CHECK(print, what) print(#what, what)

class TestResultPrinter {
  public:
    TestResultPrinter(unsigned int width) : WIDTH(width) {}

    auto process(std::string const &what, bool passed) -> void {
        std::cout << std::setw(WIDTH) << what << ": " << (passed ? "PASS" : "** FAIL **") << '\n';
    }

  private:
    unsigned int WIDTH;
};

int main() {

    // create a fraction with values 3 (which is 3/1) and 1/3
    std::cout << std::endl;
    const Fraction three{3};
    const Fraction third{1, 3};
    std::cout << three.str() << ' ' << third.str() << '\n';

    // equality
    std::cout << std::endl;
    auto pp = TestResultPrinter(20);
    CHECK(pp.process, equal(three, three));
    CHECK(pp.process, equal(third, third));
    CHECK(pp.process, equal(three, Fraction{3}));
    CHECK(pp.process, equal(three, Fraction{3, 1}));
    CHECK(pp.process, equal(third, Fraction{1, 3}));
    CHECK(pp.process, equal(Fraction{3}, three));
    CHECK(pp.process, equal(Fraction{1, 3}, third));
    CHECK(pp.process, equal(third, Fraction{2, 6}));

    // multiply
    std::cout << std::endl;
    CHECK(pp.process, equal(multiply(third, 2), Fraction{2, 3}));
    CHECK(pp.process, equal(multiply(2, third), Fraction{2, 3}));
    CHECK(pp.process, equal(multiply(three, third), Fraction{1, 1}));
    CHECK(pp.process, equal(multiply(3, third), 1));

    // end
    std::cout << std::endl;
}
