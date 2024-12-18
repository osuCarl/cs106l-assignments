#include "class.h"

Laptop::Laptop() {
    _name = "default name";
    _year = 2000;
    _size = 10;
}

Laptop::Laptop(std::string name, int year, int size) : 
_name{name}, _year{year}, _size{size} {}


Laptop::~Laptop() {}

bool Laptop::_isValid() {
    return _size > 0 && _year > 1999;
}

std::string Laptop::getName() const {
    return _name;
}

int Laptop::getYear() const {
    return _year;
}

int Laptop::getSize() const {
    return _size;
}

void Laptop::setName(std::string name) {
    _name = name;
}

void Laptop::setYear(int year) {
    _year = year;
}

void Laptop::setSize(int size) {
    _size = size;
}