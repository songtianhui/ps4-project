#ifndef GRAPHLIBRARY_GLEXCEPTION_H
#define GRAPHLIBRARY_GLEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class GLException : public std::exception {
private:
    std::string msg;
public:
    GLException(std::string s): msg(s) {}
    virtual std::string get_msg() const {
        return msg;
    }
};

std::ostream& operator<<(std::ostream& os, const GLException& e) {
    return os << e.get_msg();
}

#endif //GRAPHLIBRARY_GLEXCEPTION_H
