#include "Button.h"

Button::Button(const ButtonAttributes& htmlAttributes)
: attributes{htmlAttributes} {}

String Button::convertToHtml() const {
    return String{"<input type=\"button\" value=\""} + attributes.value + String{"\"/> </br>"};
}