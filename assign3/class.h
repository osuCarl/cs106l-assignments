#include <string>

class Laptop {
public:
    Laptop();
    Laptop(std::string name, int size, int year);
    ~Laptop();

    std::string getName() const;
    int getSize() const;
    int getYear() const;

    void setName(std::string name);
    void setSize(int size);
    void setYear(int year);

private:
    std::string _name;
    int _size;
    int _year;

    bool _isValid();
};