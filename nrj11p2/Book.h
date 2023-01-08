#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include<string>
#include<stdexcept>

#include "Date.h"

using namespace std;

/**
  * Base class for storing information about a single book. All Book-derived types store
  * information including a unique identifier; the book's title; and the book's author.
  * All Book-derived types also track whether the book is checked out and, if so, the
  * name of the patron who borrowed the book and the Date when it is due back.
  *
  * Information about a book may be read/written according to an internal format (suitable
  * for storing or transferring the state of a Catalog) or printed in an external format
  * (suitable for display to a user through the terminal). These behaviors may be
  * overridden by Book-derived types to suit their needs.
  */
class Book {

  friend ostream& operator<<(ostream& out, const Book& b) {return b.write(out); }

  friend istream& operator>>(istream& in, Book& b) {return b.read(in);}
    
  public:
    /**
      * Default constructor. Default Book sets available to true; all string and Date members take
      * their default values.
      */
    Book();

    /**
      * Destructor. Declared virtual to support polymorphism.
      */
    virtual ~Book() { }
    
    /**
      * Returns the due date, if the book is checked out. Throws an exception if the book is
      * available (i.e,. not checked out).
      *
      * @return the due date
      *
      * @throws logic_error if this book is available
      */
    Date getDueDate() const;

    /**
      * Returns the borrower, if the book is checked out. Throws an exception if the book is
      * available (i.e., not checked out).
      *
      * @return the borrower
      *
      * @throws logic_error if this book is available
      */
    string getBorrower() const;

    /**
      * Compare book information to a search query (as a substring). Return true if the Book
      * matches the query, or return false otherwise. All Books should search both title and 
      * author for a match. Book-derived types may override to search additional fields 
      * (such as audiobooks searching a narrator).
      *
      * @param query a string to search for
      *
      * @return true if the book matches the query; false otherwise
      */
    virtual bool match(const string& query) const;

    /**
      * Compare borrower name to a search query (as a substring). Return true if the borrower
      * matches the query, or return false otherwise. Throw an exception if the book is available
      * (i.e., not checked out).
      *
      * @param query a string to search for
      *
      * @return true if the borrower matches the query; false otherwise
      *
      * @throws logic_error if this books is available (not checked out)
      */
    bool matchBorrower(const string& query) const;
    
    /**
      * Check if this book is overdue (relative to the parameter Date). Return true if the
      * parameter date is later than the book due date, or return false otherwise. Throw an
      * exception if the book is available (i.e., not checked out).
      *
      * @param today date to compare to
      *
      * @return true if the book is due before today; false otherwise
      *
      * @throws logic_error if the book is available (not checked out)
      */
    bool isOverdue(const Date& today) const;

    void checkOut(const Date& today, const string& newBorrower);

    /**
      * Check in the book. If teh book is currently unavailable, then
      * * set available to true
      * The dueDate and borrower need not be altered, as their values are not valid while the
      * book is available. Throws an exception if the book is avaialable (i.e, not checked out)
      *
      * @throws logic_error if the book is available (not checked out)
      */
    void checkIn();

    virtual void print(ostream& out = cout) const;

    string getID() const { return id; }

    string getTitle() const { return title; }

    string getAuthor() const { return author; }
    
    bool getAvailable() const { return available; }


  protected:
    virtual ostream& write(ostream& out) const;

    virtual istream& read(istream& in);
    
    // Member variables of Book are protected (to allow Book-derived types to access them directly

    string id;       /**< Unique id for this book */
    string title;    /**< Title of this book */
    string author;   /**< Author of this book */
    bool available;  /**< True if this book is available; false if checked out */
    Date dueDate;    /**< Due date for book (if checked out); value not defined if available */
    string borrower; /**< Name of borrower (if checked out); value not defined if available */
    friend class Catalog;
    
};
#endif
