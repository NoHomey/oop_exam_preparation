#include "Button.h"
#include "Password.h"
#include "Checkbox.h"
#include "TextField.h"

int main() {
    Button b{{"description"}};
    std::cout << b.convertToHtml() << std::endl;
    Password p{"Password :", {true}};
    std::cout << p.convertToHtml() << std::endl;
    Checkbox c{{true}, "I agree!"};
    std::cout << c.convertToHtml() << std::endl;
    TextField t{"User :", {middle}};
    std::cout << t.convertToHtml() << std::endl;
    return 0;
}