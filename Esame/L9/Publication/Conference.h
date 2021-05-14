//Conference.h
//articolo di conferenza

#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "Publication.h"
#include <array>

class Conference: public Publication {
    public:

    //constructor
    Conference(std::string ti, std::string au, int y, std::string con, int p, std::string place)
        : Publication(ti,au,y), conference{con}, page {p}, location{place} {}

    //destructor
    virtual ~Conference() = default;

    //set e get
    void setConference (std::string const con) {conference= con;}
    std::string getConference () const {return conference;}

    void setLocation (std::string const place) {location=place;}
    std::string getLocation () const {return location;}

    void setPage (const int n) {page=n;}
    int getPage () const {return page;}

    //to string
    std::string toString () const {
        std::ostringstream out;
        out << Publication::toString();
        out << ". " << conference << ",@" << location << " (";
        out << page << ")";
        return out.str();
    }
    private:
    std::string conference;
    std::string location;
    int page; 
};

#endif