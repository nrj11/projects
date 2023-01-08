#ifndef PAPERBACK_H
#define PAPERBACK_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Book.h"

using namespace std;

class Paperback: public Book{


public:
Paperback();

~Paperback(){ };
virtual bool match(const string& query) const;
virtual void print(ostream& out = cout) const;

virtual ostream& write(ostream& out) const;

virtual istream& read(istream& in);

private:
    int pagenums;
    
};
#endif
