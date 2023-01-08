#include "Date.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>

using namespace std;


std::ostream& operator<<(ostream& out, const Date& d) {
    char trash = '/';
    out << std::setfill('0') << std::setw(2) << d.mm << trash << std::setfill('0') << std::setw(2) << d.dd << trash << std::setfill('0') << std::setw(2) << d.yy; 
    return out;   
}

std::istream& operator>>(istream& in, Date& d) {
    char trash{};
    in >> d.mm >> trash >> d.dd >> trash >> d.yy;
    d.setDate(d.mm, d.dd, d.yy);  
    return in; 
}


Date::Date(){ 
    mm = 1; 
    dd = 1; 
    yy = 00; }
     
Date::Date(int mm, int dd, int yy) {
    mm = mm; 
    dd = dd; 
    yy = yy; 
 setDate(mm, dd, yy);
}
 
int Date::getMonth() const{ return mm; }

int Date::getDay() const{ return dd; }

int Date::getYear() const{ return yy; }

bool Date::operator==(const Date& d) const {
    bool datebool = false; 
 
    if (mm == d.mm && dd == d.dd && yy == d.yy) 
      datebool = true; 
    else 
        datebool = false; 

    return datebool;  
}
 
bool Date::operator!=(const Date& d) const {
    bool datebool = false; 

    if (mm != d.mm || dd != d.dd || yy != d.yy) 
        datebool = true; 
    else 
        datebool = false; 

    return datebool; 
}
 
bool Date::operator<(const Date& d) const {
    bool datebool = false; 

    if ((yy < d.yy) || (yy == d.yy && mm < d.mm) || yy == d.yy && mm == d.mm && dd < d.dd) 
        datebool = true; 
    else 
        datebool = false; 

    return datebool; 
}
  
bool Date::operator>(const Date& d) const {
    bool datebool = false; 

    if ((yy > d.yy) || (yy == d.yy && mm > d.mm) || yy == d.yy && mm == d.mm && dd > d.dd) 
        datebool = true; 
    else 
        datebool = false; 

    return datebool; 
}

void Date::setDate(int month, int day, int year) {

if (month < 1 || month > 12) { 
    throw invalid_argument("invalid argument: not a month!");
 }

else if (year < 0) {
    throw invalid_argument("year");
}

else if (year > 99){
    throw overflow_error("not a valid year");
}

else if (day < 1 || day > 31){
    throw invalid_argument("invalid day");
}

else if ((month == 4 || month == 6 || month ==9 || month == 11) && day > 30){ 
    throw invalid_argument("invalid argument: that month doesn't even have that many days");
}

else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
    throw invalid_argument("day problem");
}

else if (month == 2 && day > 28){
    throw invalid_argument("day");
}
else {
    mm = month;
   dd = day; 
   yy = year;
}
return ;
}


Date Date::findFutureDate(int nd) const { 
    int newmonth = mm;
    int newday = dd;
    int newyear = yy;
Date newDate(mm, dd, yy);
    for (int i = 0 ; i < nd ; i++) { 
        if (newDate.dd == 28 && newDate.mm == 2) {
            newDate.dd = 01; 
            newDate.mm = 03; 
        }

        else if (newDate.dd == 30 && (newDate.mm == 4 || newDate.mm == 6 || newDate.mm == 9 || newDate.mm == 11)) {
            newDate.dd = 01; 
            newDate.mm++; 
        }

        else if (newDate.dd == 31 && (newDate.mm == 1 || newDate.mm == 3 || newDate.mm == 5 || newDate.mm == 7 || newDate.mm == 8 || newDate.mm == 10)) {
            newDate.dd = 01; 
            newDate.mm++; 
        }
        else if(newDate.dd== 31 && newDate.mm == 12){
            newDate.dd = 01; 
            newDate.mm = 01; 
            newDate.yy++; 

            if (newDate.yy > 99){
            throw overflow_error("invalid date");
            };
        }
        else {
            newDate.dd++; 
        }
    } 
    return newDate;
}
