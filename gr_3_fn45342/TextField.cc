#include "TextField.h"

TextField::TextField(const String& htmlString, const TextFieldAttributes& htmlAttributes)
: description{htmlString}, attributes{htmlAttributes} {}

String TextField::convertToHtml() const {
    String html = description + String{" <input type=\"text\" align=\""};
    switch(attributes.allign) {
        case left:
            html += "left";
            break;
         case right:
            html += "right";
            break;
        default:
            html += "middle";
    }
    html += String{"\"/> </br>"};
    return html;
}