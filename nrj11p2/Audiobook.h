#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Book.h"

using namespace std;

class Audiobook: public Book {

public:
    Audiobook();
    ~Audiobook() { };
    virtual bool match(const string& query) const;
    virtual void print(ostream& out = cout) const;

    virtual ostream& write(ostream& out) const;

    virtual istream& read(istream& in);

private:

    string narrator;
    int hours;
    int minutes;
};
#endif

    
