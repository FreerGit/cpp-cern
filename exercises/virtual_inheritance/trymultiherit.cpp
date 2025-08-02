#include "TextBox.hpp"
#include <iostream>

int main() {
    // create a TextBox and call draw
    TextBox tb = TextBox("content", 1080, 1080);

    // Fix the code to call both draws by using types
    static_cast<Text>(tb).draw();
    static_cast<Rectangle>(tb).draw();
    // try with virtual inheritance
}
