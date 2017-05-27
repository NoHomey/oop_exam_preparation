#include "Appointment.h"

size_t Appointment::stringLength(const char* str) {
    if(str == NULL) {
        return 0;
    }
    size_t index = 0;
    while(true) {
        if(str[index] == '\0') {
            return index;
        }
        ++index;
    }
}

char* Appointment::copyDescription(const char* descriptionOfAppointment) {
    const size_t length = stringLength(descriptionOfAppointment);
    char* description;
    try {
        description = new char[length + 1];
    } catch(std::bad_alloc& err) {
        throw err;
    }
    for(size_t index = 0; index < length; ++index) {
        description[index] = descriptionOfAppointment[index];
    }
    description[length] = '\0';
    return description;
}

Appointment::Appointment()
: description(NULL), timestamp() {}

Appointment::Appointment(const char* descriptionOfAppointment, const Timestamp& timeOfAppointment)
: description(copyDescription(descriptionOfAppointment)), timestamp(timeOfAppointment) {}

Appointment::Appointment(const Appointment& other)
: Appointment(other.description, other.timestamp) {}

Appointment::~Appointment() {
    delete[] description;
    description = NULL;
}

Appointment& Appointment::operator=(const Appointment& other) {
    if(this != &other) {
        setDescription(other.description);
        timestamp = other.timestamp;
    }
    return *this;
}

const char* Appointment::getDescription() const {
    return description;
}

void Appointment::setDescription(const char* descriptionOfAppointment) {
    char* newDescription = copyDescription(descriptionOfAppointment);
    delete[] description;
    description = newDescription;
}

const Timestamp& Appointment::getTimestamp() const {
    return timestamp;
}

void Appointment::setTimestamp(const Timestamp& timeOfAppointment) {
    timestamp = timeOfAppointment;
}

std::ostream& operator<<(std::ostream& out, const Appointment& appointment) {
    out << appointment.getTimestamp().getValue() << ' ' << appointment.getDescription(); 
    return out;
}

char* readDescription(std::istream& in) {
    size_t copyLength = 0;
    size_t length = 0;
    const size_t bufferLength = 20;
    char* buffer = new char[bufferLength];
    char* description = NULL;
    char* tmp = NULL;
    while(true) {
        in.getline(buffer, bufferLength);
        if(in.bad()) {
            delete[] buffer;
            delete[] description;
            throw std::ios_base::failure("Uncoverable error while reading");
        }
        copyLength = in.gcount();
        tmp = new char[length + copyLength + 1];
        size_t index = 0;
        for(; index < length; ++index) {
            tmp[index] = description[index];
        }
        for(size_t c = 0; c < copyLength; ++c) {
            tmp[index + c] = buffer[c];
        }
        delete[] description;
        description = tmp;
        length += copyLength;
        if(in.fail()) {
            in.clear();
        } else {
            delete[] buffer;
            description[length] = '\0';
            return description;
        }
    }
}

std::istream& operator>>(std::istream& in, Appointment& appointment) {
    unsigned long timestamp;
    in >> timestamp;
    appointment.setTimestamp(Timestamp(timestamp));
    appointment.description = readDescription(in);
    return in;
}