#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
  * A class for storing due dates. Dates are in the format MM/DD/YY 
  * where YY is assumed to be "20YY"
  */
class Date {
  /**
    * Stream insertion operator. Inserts a string represntation of this date in
    * the format "MM/DD/YY" where each of DD, MM, YY are precisely two characters
    * and literal '/' separate them.
    * @param out the output stream for insertion
    * @param d the Date to print to the stream
    * @return a reference to out
    */
  friend ostream& operator<<(ostream& out, const Date& d);
  /**
    * Stream extraction operator. Extracts a Date of the format "MM/DD/YY" from
    * the input stream. If the input stream is improperly formatted, set the
    * fail bit of the stream. If the extracted date is invalid, throw an exception.
    * May invoke Date::setDate() internally.
    * @param in the input stream for extraction
    * @param d the Date object to store the extracted date into
    * @return a reference to in
    * @throws invalid_argument if the extracted date is invalid
    */
  friend istream& operator>>(istream& in, Date& d);

  public:
    /**
      * Default constructor. Creates a default object with the date "01/01/00"
      */
    Date();
    /**
      * Explicit constructor. Sets the date using the arguments provided. Throws
      * an exception if the arguments represent an invalid date. May invoke
      * Date::setDate() internally.
      * @throws invalid_argument if any argument value is invalid
      */
    Date(int mm, int dd, int yy);
    /**
      * Returns this date's (numerical) month
      * @return the month, as an integer in [1, 12]
      */
    int getMonth() const;
    /**
      * Returns this date's (numerical) day
      * @return the day, as an integer (whose range is month-dependent)
      */
    int getDay() const;
    /**
      * Returns this date's year. The return value is YY for the year 20YY.
      * @return the year, as an integer in [0, 99]
      */
    int getYear() const;
    /**
      * Equality comparison operator. Returns true if this Date is equal to the
      * parameter date; returns false otherwise.
      * @param d the Date to be compared
      * @return boolean indicating whether this object is equal to the parameter
      */
    bool operator==(const Date& d) const;
    /**
      * Inequality comparison operator. Returns true if this Date is not equal to the
      * parameter date; returns false otherwise.
      * @param d the Date to be compared
      * @return boolean indicating whether this object is not equal to the parameter
      */
    bool operator!=(const Date& d) const;
    /**
      * Comparison operator. Returns true if this Date is earlier than the parameter
      * Date object; returns false otherwise.
      * @param d the Date to be compared
      * @return boolean indicating whether this object is before the parameter
      */
    bool operator<(const Date& d) const;
    /**
      * Comparison operator. Returns true if this Date is later than the parameter
      * Date object; returns false otherwise.
      * @param d the Date to be compared
      * @return boolean indicating whether this object is after the parameter
      */
    bool operator>(const Date& d) const;
    /**
      * Set the date of this object. Throws an exception if the passed parameters
      * represent an invalid date.
      * @param mm the month, an int in the range [1, 12]
      * @param dd the day, an int in the range [1, 28]; [1, 30]; or [1, 31] depending
      *   on the value of mm
      * @param yy the year, an int value in the range [00, 99]
      * @throws invalid_argument if the parameters represent an invalid date
      */
    void setDate(int month, int day, int year);
    /**
      * Construct a future date. Counts forward from this date the number of days
      * indicated by the passed parameter, accounting for the number of days in
      * each month and/or months in a year as appropriate. Throws an exception if
      * the new date causes the value of YY to exceed 99.
      * @param nd the number of days in the future to construct the new date
      * @return a new Date object representing the future date
      * @throws overflow_error if counting forward results in YY exceeding 99
      */
    Date findFutureDate(int nd) const;
  private:
    int mm; /**< The month of the year, in the range [1, 12] */
    int dd; /**< The day of the year, in the range [1, 28]; [1, 30]; or [1, 31] */
    int yy; /**< The year, in the range [00, 99] representing 20YY */
};

#endif


