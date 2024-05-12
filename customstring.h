#include <iostream>
#include <cstring>

class customstring {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    customstring() ;

    // Constructor with char array
    customstring(const char* str);

    // Copy constructor
    customstring(const customstring& other);

      // Move constructor
    customstring(customstring&& other);
    // Destructor
    ~customstring() ;

    // Assignment operator
    customstring& operator=(const customstring& other);

    // Getter for length
    size_t size() const;
    //Getter for data
    char *c_str() const;
    //Getter for character at index
    char& at(size_t index) ;

    // Find the first occurrence of a character from another string
    size_t find_first_of(const customstring &other) const;

    // Append another string to the end of this string
    customstring append(const customstring& other) const;

    // Assign another string to this string
    customstring assign(const customstring &other);

    // Get a substring of this string
    customstring substr(size_t start, size_t end) const;

    int compare(const customstring &other) const;

    // Overloaded + operator for concatenation
    customstring operator+(const customstring& other) const;

    // Overloaded [] operator for accessing individual characters
    char& operator[](size_t index) ;
    // Overloaded << operator for output stream
    friend std::ostream& operator<<(std::ostream& os, const customstring& str);
};