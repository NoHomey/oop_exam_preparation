#pragma once

#include "String.h"
#include "HTMLElement.h"

struct PasswordAttributes {
    bool required;
};

class Password: public HTMLElement {
public:
    Password(const String& htmlString, const PasswordAttributes& htmlAttributes);

    String convertToHtml() const final;

private:
    String description;
    PasswordAttributes attributes;
};