

#include <iostream>
#include<string>
#include<stdexcept>
#include "Audiobook.h"

using namespace std;
    Audiobook::Audiobook(){
      narrator = "";
      hours = 0;
      minutes = 0;
    }
    bool Audiobook::match(const string& query) const{
        bool tan = false; 
        size_t titlefinder = title.find(query);
        size_t authorfinder = author.find(query);
        size_t narratorfinder = narrator.find(query);

        if (titlefinder!= string::npos || authorfinder!= string::npos || narratorfinder != string::npos) { 
        tan = true;
      }
        else{ 
        tan = false;
      }
      return tan;
    }
    void Audiobook::print(ostream& out) const{
      string avail;
      if(available == true){
        avail = "available";
        out << "Title:" << title << "\t" << "Author" << author << "\t" << "Narrator:" << narrator << "\t" << endl;
        out << endl << "Availability:" << avail << endl;
      }
      else{
        avail = "not available";
        out << "Title:" << title << "\t" << "Author" << author << "\t" << "Narrator:" << narrator << "\t" << endl;
        out << endl << "Availability:" << avail << endl;

      }
      return ;
    }

    std::ostream& Audiobook::write(ostream& out) const{
        out << id << " ";
        out << '"' << title << '"' << " ";
        out << '"' << author << '"' << " ";
        out << '"' << narrator << '"' << " ";
        out << hours << " ";
        out << minutes << " ";
        out << available;

        if(!available){
            out << " " << dueDate << " " << " " << '"' << borrower << '"';
        }
        return out;
    }


    std::istream& Audiobook::read(istream& in){
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
        getline(in, trash, '"');
        getline(in, narrator, '"');
        in >> hours;
        in >> minutes;
        in >> available;
        if(!available){
            in >> dueDate;
            getline(in, trash, '"');
            getline(in, borrower, '"');
        }
        return in;

    }