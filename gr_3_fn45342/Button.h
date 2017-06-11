#pragma once

#include "String.h"
#include "HTMLElement.h"

struct ButtonAttributes {
    String value;
};

class Button: public HTMLElement {
public:
    Button(const ButtonAttributes& htmlAttributes);

    String convertToHtml() const final;

private:
    ButtonAttributes attributes;
};