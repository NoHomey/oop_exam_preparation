#include "Checkbox.h"

Checkbox::Checkbox(const CheckboxAttributes& htmlAttributes, const String& htmlString)
: description{htmlString}, attributes{htmlAttributes} {}

String Checkbox::convertToHtml() const {
    String html = String{"<input type=\"checkbox\""};
    if(attributes.checked) {
        html += " checked";
    }
    html += String{"/> "} + description + String{" </br>"};
    return html;
}