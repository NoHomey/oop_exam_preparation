#include "Password.h"

Password::Password(const String& htmlString, const PasswordAttributes& htmlAttributes)
: description{htmlString}, attributes{htmlAttributes} {}

String Password::convertToHtml() const {
    String html = description + " <input type=\"password\"";
    if(attributes.required) {
        html += " required";
    }
    html += "/> </br>";
    return html;
}