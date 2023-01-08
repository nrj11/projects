#include <iostream>
#include <string>
#include <stdexcept>
#include "Paperback.h"

using namespace std;
Paperback::Paperback(){
    int pagenums = 0;
}

bool Paperback::match(const string& query) const{
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
void Paperback::print(ostream& out) const{
      string avail;
      if(available){
        avail = "available";
        out << "Title:" << title << "\t" << "Author" << author << "\t" << "Page Numbers:" << pagenums << "\t" << endl;
        out << endl << "Availability:" << avail << endl;
      }
      else{
        avail = "not available";
        out << "Title:" << title << "\t" << "Author" << author << "\t" << "Page Numbers:" << pagenums << "\t" << endl;
        out << endl << "Availability:" << avail << endl;

      }
      return ;
    }
    std::ostream& Paperback::write(ostream& out) const{
        out << id << " ";
        out << '"' << title << '"' << " ";
        out << '"' << author << '"' << " ";
        out << pagenums << " ";
        out << available;

        if(!available){
            out << " " << dueDate << " " << '"' << borrower << '"';
        }
        return out;
    }
    std::istream& Paperback::read(istream& in){
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
        in >> pagenums;
        in >> available;
        if(!available){
            in >> dueDate;
            getline(in, trash, '"');
            getline(in, borrower, '"');
        }
        return in;

    }