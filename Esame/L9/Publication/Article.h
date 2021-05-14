//Article.h
//classe derivata di Publicaton: articolo da rivista scentifica

#ifndef ARTICLE_H
#define ARTICLE_H

#include "Publication.h"
#include <array>

class Article: public Publication {
    public:

    //constructor
    Article(std::string ti, std::string au, int y, std::string mag, int n, int beg, int end)
        : Publication(ti,au,y), magazine{mag}, number {n}, pages{beg,end} {}

    //destructor
    virtual ~Article() = default;

    //set e get
    void setMagazine (std::string const mag) {magazine=mag;}
    std::string getMagazine () const {return magazine;}

    void setNumber (const int n) {number=n;}
    int getNumber () const {return number;}

    void setPages (const int beg, const int end) {pages[0]=beg; pages[1]=end;}
    std::array<int,2> getPages() {return pages;}

    //to string
    std::string toString () const {
        std::ostringstream out;
        out << Publication::toString();
        out << ". " << magazine << ",#" << number << " (";
        out << pages[0] << ", " << pages[1] << ")";
        return out.str();
    }
    private:
    std::string magazine;
    int number;
    std::array <int,2> pages; 
};

#endif
