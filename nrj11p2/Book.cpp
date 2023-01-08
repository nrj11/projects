#include <iostream>
#include <string>
#include <stdexcept>
#include "Book.h"

using namespace std;
    Book::Book(){
      id = " ";
      title = " ";
      author = " ";
      available = true;
      dueDate.setDate(01,01,00);
      borrower = " ";
    }

    Date Book::getDueDate() const{
      if(available == 1){
        throw logic_error("this book is available");
      }
      else{
      return dueDate;
      }
    }
 
    string Book::getBorrower() const{
      if(available == 1){
        throw logic_error("this book is available");
      }
      else{
        return borrower;
        }
    }


    bool Book::match(const string& query) const{
      bool titleauthor = false; 
      size_t titlefinder = title.find(query);
      size_t authorfinder = author.find(query);

      if (titlefinder!= string::npos || authorfinder!= string::npos) { 
        titleauthor = true;
      }
      else{ 
        titleauthor = false;
      }
      return titleauthor;
    }

    bool Book::matchBorrower(const string& query) const{
      bool foundborrower = false;
      if(available == 1){
        throw logic_error("Book is available.");
      }
      size_t borrowerfinder = borrower.find(query);

      if(borrowerfinder!=string::npos){
        foundborrower = true;
      }
      else{
        foundborrower = false;
      }
      return foundborrower;
    };

    bool Book::isOverdue(const Date& today) const{
      bool overdue = false;
      if(available == 1){
        throw logic_error("Book is available.");
      }
      if(available == false){
        if(today > dueDate){
          overdue = true;
        }
        else{
          overdue = false;
        }
      }
      return overdue;
    }

    void Book::checkOut(const Date& today, const string& newBorrower){
      if(available == 0){
      throw logic_error("Book is already checked out.");
    }
      else{
      available = false;
      dueDate = today.findFutureDate(14);
      borrower = newBorrower;
    }}

    void Book::checkIn(){
    if(available == true){
      throw logic_error("Book is not checked out.");
      }
    if(available == false){
      available = true;
    }
    return ;
  }
   

    void Book::print(ostream& out) const{
      string avail;
      if(available == true){
        avail = "available";
        out << "Title:" << title << "\t" << "Author:" << author << endl;
        out << endl << "Availability:" << avail << endl;
      }
      else{
        avail = "not available";
        out << "Title:" << title << "\t" << "Author" << author << endl;
        out << endl << "Availability:" << avail << endl;

      }
      return ;
    }

    std::ostream& Book::write(ostream& out) const{
        out << id << " ";
        out << '"' << title << '"' << " ";
        out << '"' << author << '"' << " ";
        out << available;

        if(!available){
            out << " " << dueDate << " " << " " << '"' << borrower << '"';
        }
        return out;
    }


    std::istream& Book::read(istream& in){
        if(!in.good()){
            return in;
        }
        in >> id;
        //if read in fails return in stream
        if(in.fail()){
            return in;
        }

        string trash;
        getline(in, trash, '"');
        getline(in, title, '"');
        getline(in, trash, '"');
        getline(in, author, '"');
        in >> available;
        if(!available){
            in >> dueDate;
            getline(in, trash, '"');
            getline(in, borrower, '"');
        }
        return in;

    }