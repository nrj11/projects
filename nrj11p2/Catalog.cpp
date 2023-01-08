#include <iostream>
#include <fstream>
#include "Catalog.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

Catalog::Catalog(){
    books = {};
    }

void Catalog::read(istream& in){

    Book *thisbook{};

    if(!in){
        in.setstate(std::ios::failbit);
    }
    char peekCh;
    in >> std::ws;
    peekCh = in.peek();


    while(in){
        
        if(peekCh == 'A'){
            thisbook = new Audiobook;
        }
        else if(peekCh = 'P'){
            thisbook = new Paperback;
        }
        else{
            thisbook = new Book;
        }
        in >> *thisbook;
        books.push_back(thisbook);
        in >> std::ws;
    }
    delete thisbook;
    return ;}
    



void Catalog::read(const string& filename){
    std::ifstream file;
    file.open(filename.c_str());
    if (!file.is_open()){
        throw logic_error("file didn't open");
    }
    else{
        read(file); //call other read function
    }
}


    void Catalog::write(ostream& out) const{
        for(int i; i < books.size(); i++){
            out << *books[i] << endl;
        }
        /*char trash{};
        for(int i = 0; i < books.size(); i++){
            out << books[i]->getID() << trash << books[i]->getTitle() << trash << books[i]->getAuthor() << trash << books[i]->getAvailable() << trash << books[i]->getDueDate() << trash << books[i]->getBorrower();
        }
        return ;*/
    }

    void Catalog::write(const string& filename) const{
        char trash{};
        std::ofstream file;
        file.open(filename.c_str());
        if(!file.good()){
            throw logic_error("file didn't open");
        }

        else{
            write(file);
            /*for(int i = 0; i < books.size(); i++){
            file << books[i]->getID() << trash << books[i]->getTitle() << trash << books[i]->getAuthor() << trash << books[i]->getAvailable() << trash << books[i]->getDueDate() << trash << books[i]->getBorrower();*/
            }
        return ;
    }
    void Catalog::print(ostream& out) const{
        if (books.size() == 0){
            throw logic_error("catalog is empty");
        }
        else{
            for(int index = 0; index < books.size(); index++){
                books[index]->print();
            }
        }

        return ;
    }

    void Catalog::printOverdue(const Date& today, ostream& out) const{
        bool overdue = false;
        for(int index = 0; index < books.size(); index++){
            {if (books[index]->getAvailable() == 0){
                if(books[index]->isOverdue(today)){
                    overdue = true;
                    books[index]->print();
                }
            }

        if(overdue == false){
            throw logic_error("no overdue books exist.");
        }
        
        return ;
        }}}


    void Catalog::printBorrowed(const string& query, ostream& out) const{
        bool borrowed = false;
        for(int index = 0; index < books.size(); index++){
            if (books[index]->getAvailable() == 0){
                if(books[index]->matchBorrower(query)){
                    borrowed = true;
                    out << books[index] << endl;
                    books[index]->print();
            }
        }

        if(borrowed == false){
                throw invalid_argument("this person has not borrowed anything");
            }

        return ;
    }}

    void Catalog::printMatching(const string& query, ostream& out) const{
        bool matched = false;
        for(int index = 0; index < books.size(); index++){
            if(books[index]->match(query)){
                matched = true;
                books[index]->print();
            }
        }
        if(matched = false){
            throw invalid_argument("we don't have this");
        }

        return ;
    }

    void Catalog::checkOut(const string& id, const Date& today, const string& newBorrower){
        bool bookfound = false;
        for (int index = 0; index < books.size(); index++){
            if(books[index]->getID() == id){
                books[index]->checkOut(today, newBorrower); //will throw an exception if book is unavailable
                bookfound = true;
            }
        }
        if (bookfound == false){
            throw invalid_argument("no book found");
        }
        return ;
    }

    void Catalog::checkIn(const string& id){
        bool bookfound = false;
        for (int index = 0; index < books.size(); index++){
            if(books[index]->getID() == id){
                books[index]->checkIn(); //will throw an exception if book is already checked in
                bookfound = true; 
            }
        }
        if (bookfound == false){
            throw invalid_argument("no book found");
        }
        return ;
    }
