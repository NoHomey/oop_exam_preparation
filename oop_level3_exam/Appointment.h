#pragma once
#include "Timestamp.h"
#include <cstddef>
#include <iostream>

class Appointment {
    friend std::istream& operator>>(std::istream& in, Appointment& appointment);
public:
    Appointment();

    Appointment(const char* descriptionOfAppointment, const Timestamp& timeOfAppointment);

    Appointment(const Appointment& other);

    ~Appointment();

    Appointment& operator=(const Appointment& other);

    const char* getDescription() const;

    void setDescription(const char* descriptionOfAppointment);

    const Timestamp& getTimestamp() const;

    void setTimestamp(const Timestamp& timeOfAppointment);

private:
    static size_t stringLength(const char* str);

    static char* copyDescription(const char* descriptionOfAppointment);

    char* description;
    Timestamp timestamp;
};

std::ostream& operator<<(std::ostream& out, const Appointment& appointment);

std::istream& operator>>(std::istream& in, Appointment& appointment);