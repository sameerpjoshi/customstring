#include "customstring.h"


    // Default constructor
    customstring::customstring() : data(nullptr), length(0) {}

    // Constructor with char array
    customstring::customstring(const char* str) : length(std::strlen(str)) {
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Copy constructor
    customstring::customstring(const customstring& other) : length(other.length) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    customstring::customstring(customstring &&other) : length(other.length)
    {
       if (data != nullptr)
       {
           delete[] data;
       }
       data= other.data;
       other.data =nullptr;
    }

    // Destructor
    customstring::~customstring() {
        delete[] data;
    }

    // Assignment operator
    customstring& customstring::operator=(const customstring& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // Getter for length
    size_t customstring::size() const {
        return length;
    }

    //Getter for data 
    char* customstring::c_str() const {
        return data;
    }

    char &customstring::at(size_t index)
    {
        if (index >= length)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t customstring::find_first_of(const customstring &other) const
    {
        for (size_t i = 0; i < length; i++)
        {
            for (size_t j = 0; j < other.length; j++)
            {
                if (data[i] == other.data[j])
                {
                    return i;
                }
            }
        }
        return -1;
    }

    customstring customstring::append(const customstring &other) const
    {
        customstring result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        strncpy_s(result.data, length+1, data, length);
        strncpy_s(result.data+ length, other.length+1, other.data, other.length);
        return result;      
    }

    customstring customstring::assign(const customstring& other)  {
        length = other.length;
        data = new char[length + 1];
        strncpy_s(data, length + 1, other.data, length);
    }

    customstring customstring::substr(size_t start, size_t end) const
    {
        if (start >= length || end >= length || start > end)
        {
            throw std::out_of_range("Index out of range");
        }
        customstring result;
        result.length = end - start + 1;
        result.data = new char[result.length + 1];
        strncpy_s(result.data, result.length + 1, data + start, result.length);
        return result;
    }

    int customstring::compare(const customstring &other) const
    {
        return strcmp(data, other.data);
    }


    // Overloaded + operator for concatenation
    customstring customstring::operator+(const customstring& other) const {
        return append(other); 
    }

    // Overloaded [] operator for accessing individual characters
    char& customstring::operator[](size_t index) {
        return at(index);
    }

    bool customstring::operator==(const customstring& other) const {
        return compare(other) == 0;
    }



    // Overloaded << operator for output stream
    std::ostream& operator<<(std::ostream& os, const customstring& str) {
        os << str.data;
        return os;
    }
