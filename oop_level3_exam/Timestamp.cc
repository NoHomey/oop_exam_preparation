#include "Timestamp.h"
#include <ctime>

Timestamp::Timestamp()
: timestamp((unsigned long)std::time(0)) {}

Timestamp::Timestamp(unsigned long timestampValue)
: timestamp(timestampValue) {}

unsigned long Timestamp::getValue() const {
    return timestamp;
}

void Timestamp::setValue(unsigned long timestampValue) {
    timestamp = timestampValue;
}

bool Timestamp::operator>(const Timestamp& other) {
    return timestamp > other.timestamp;
}

bool Timestamp::operator<(const Timestamp& other) {
    return timestamp < other.timestamp;
}

bool Timestamp::operator>=(const Timestamp& other) {
    return timestamp >= other.timestamp;
}

bool Timestamp::operator<=(const Timestamp& other) {
    return timestamp <= other.timestamp;
}

bool Timestamp::operator==(const Timestamp& other) {
    return timestamp == other.timestamp;
}

bool Timestamp::operator!=(const Timestamp& other) {
    return !operator==(other);
}