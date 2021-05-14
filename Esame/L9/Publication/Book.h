//Book.h
//classe derivata da Publications

#ifndef BOOK_H
#define BOOK_H

#include "Publication.h"

class Book: public Publication {
    public:

    //constructor
    Book(std::string ti, std::string au, int y, std::string pub, std::string code)
        : Publication(ti,au,y), publisher{pub}, ISBN {code} {}

    //destructor
    virtual ~Book() = default;

    //set e get
    void setPublisher (std::string const pub) {publisher=pub;}
    std::string getPublisher () const {return publisher;}

    void setIsbn (std::string const code) {ISBN=code;}
    std::string getIsbn () const {return ISBN;}

    //to string
    std::string toString () const {
        std::ostringstream out;
        out << Publication::toString();
        out << ". " << publisher << " - " << ISBN;
        return out.str();
    }
    private:
    std::string publisher;
    std::string ISBN;
};

#endif
