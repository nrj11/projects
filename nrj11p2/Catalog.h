#ifndef CATALOG_H
#define CATALOG_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "Book.h"
#include "Date.h"
#include "Paperback.h"
#include "Audiobook.h"

using namespace std;

/**
  * A class for storing a list of books. Books come in two flavors: paperback
  * and audiobook, each with slightly different member fields. Provides functions to
  * * Read and write the catalog to/from text files in an internal format
  * * Print the contents of the catalog to the terminal in an external format
  * * Search the catalog for a book by title and/or author
  * * Display the books checked out by a single patron
  * * Display the books which are checked out and overdue
  */
class Catalog {
  public:
    /**
      * Default constructor. Default catalog has an empty books list.
      */
    Catalog();

    /**
      * Read catalog data in internal format. Reads from the parameter input stream and
      * stores the contained Books it describes in the vector of books.
      *
      * Since Books come in different subtypes, this function must deduce the type of
      * book from the ID string (e.g., by using peek() to see its leading character).
      *
      * @param in the input stream containing the books
      */

     ~Catalog(){ }
    void read(istream& in);

    /**
      * Read catalog data in internal format. Attempt to open an input file stream using
      * the parameter filename and, if successful, read from the stream and store the Books
      * it describes in the vector books. May invoke read(istream&) internally. Throws an
      * exception if the file fails to open.
      *
      * @param filename a string containing the filename to open
      *
      * @throws logic_error if the file fails to open properly
      */
    void read(const string& filename);

    /**
      * Write catalog data in internal format. Write to the parameter output stream in the
      * internal format.
      *
      * @param out the output stream to write to
      */
    void write(ostream& out = cout) const;

    /**
      * Write catalog data in internal format. Attempt to open an input file stream using
      * the parameter filename and, if successful, write to the stream in the internal format.
      * May invoke write(ostream&) internally. Throws an exception if the file fails to open.
      *
      * @param filename a string containing the filename to open
      *
      * @throws logic_error if the file fails to open properly
      */
    void write(const string& filename) const;

    /**
      * Print catalog contents in an external format (i.e., human-readable). Throws an exception
      * if the catalog is currently empty.
      *
      * @param out the output stream to print to (default is cout)
      *
      * @throws logic_error if the catalog is currently empty
      */
    void print(ostream& out = cout) const;

    /**
      * Print *overdue* catalog contents in an external format (i.e., human-readable). Similar to
      * Catalog::print() but prints only items which are (a) checked out and (b) overdue (per the
      * parameter date). Throws an exception if no overdue items exist (i.e., this subset is empty).
      *
      * @param today the Date to compare due dates to; Books due before today are overdue
      * @param out the output stream to print to (default is cout)
      * 
      * @throws invalid_argument if the catalog contains no overdue items
      */
    void printOverdue(const Date& today, ostream& out = cout) const;

    /**
      * Print catalog contents currently checked out by a borrower in an external format (i.e.,
      * human-readable). Similar to Catalog::print() but prints only items which are (a) checked out
      * and (b) whose borrower matches the query string. Throws an exception if no matching items
      * exist (i.e,. this subset is empty).
      *
      * @param query the borrower name to search for
      * @param out the output stream to print to (default is cout)
      *
      * @throws invalid_argument if the catalog contains no items matching this borrower
      */
    void printBorrowed(const string& query, ostream& out = cout) const;
    
    /**
      * Print items matching a query in an external format (i.e., human-readable). Similar to
      * Catalog::print() but prints only items whose fields match the query string. Search should
      * consider the title and author of all books, and the narrator of audiobooks. Throws an
      * exception if no matching items exist (i.e., this subset is empty).
      *
      * @param query the strign to serach titles, authors (and narrator, if applicable) for
      * @param out the output stream to print to (default is cout)
      *
      * @throws invalid_argument if the catalog contains no items matching this query
      */
    void printMatching(const string& query, ostream& out = cout) const;

    /**
      * Check out an available book. Locate the book with the given id, confirm that it is available,
      * and then check it out. Due date should be calculated based on check-out date (today). Throws
      * an exception if either (a) the book id provided does not exist, or (b) the book id provided
      * is already checked out.
      *
      * @param id the unique id of the book to check out
      * @param today the check-out date, from which the due date is determined
      *
      * @throws invalid_argument if the catalog does not contain a book with the given id
      * @throws logic_error if the book with the given id is already checked out
      */
    void checkOut(const string& id, const Date& today, const string& newBorrower);

    /**
      * Check in a book. Locate the book with the given id, confirm that it was checked out, then
      * check it in. Throws an exception if either (a) the book id provided does not exist, or (b) the
      * book id provide is not checked out.
      *
      * @param id the unique id of the book to check out
      * 
      * @throws invalid_argument if the catalog does not contain a book with the given id
      * @throws logic_error if the book with the given id is not checked out
      */
    void checkIn(const string& id);

  private:
    vector<Book*> books; /**< Vector of books in this catalog */
};

#endif

