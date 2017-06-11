#pragma once

#include "String.h"
#include "HTMLElement.h"

enum TextFieldAligment {
    left,
    right,
    middle
};

struct TextFieldAttributes {
    TextFieldAligment allign;
};

class TextField: public HTMLElement {
public:
    TextField(const String& htmlString, const TextFieldAttributes& htmlAttributes);

    String convertToHtml() const final;

private:
    String description;
    TextFieldAttributes attributes;
};