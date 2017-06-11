#pragma once

#include "String.h"
#include "HTMLElement.h"

struct CheckboxAttributes {
    bool checked;
};

class Checkbox: public HTMLElement {
public:
    Checkbox(const CheckboxAttributes& htmlAttributes, const String& htmlString);

    String convertToHtml() const final;

private:
    String description;
    CheckboxAttributes attributes;
};