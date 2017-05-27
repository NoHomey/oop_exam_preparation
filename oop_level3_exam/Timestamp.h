#pragma once

class Timestamp {
public:
    Timestamp();

    Timestamp(unsigned long timestampValue);

    unsigned long getValue() const;

    void setValue(unsigned long timestampValue);

    bool operator>(const Timestamp& other);

    bool operator<(const Timestamp& other);

    bool operator>=(const Timestamp& other);

    bool operator<=(const Timestamp& other);

    bool operator==(const Timestamp& other);

    bool operator!=(const Timestamp& other);

private:
    unsigned long timestamp;
};