//Publication.h
//base class of a generic publication

#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

void convertString (std::string s, std::vector <std::string>& v);

class Publication {
    public:
    //constructor
    Publication (std::string ti, std::string au, int y): title{ti}, year{y} {
        convertString(au,authors);
    }

    //destructor
    virtual ~Publication () = default;

    //set and get
    void setAuthors (std::string au) {convertString(au,authors);}
    std::string getAuthors () const {
        std::ostringstream out;
        for (int i=0; i<authors.size(); i++) out << authors[i] << ", ";
        return out.str();
    }

    void setYear (int y) {year=y;}
    int getYear () const {return year;}

    void setTitle (std::string ti) {title=ti;}
    std::string getTitle () const {return title;}

    //toString
    virtual std::string toString () const {
        std::ostringstream out;
        for (int i=0; i<authors.size(); i++)
            out << authors[i] <<( (i==authors.size()-1) ? " " : ", ");
        out << "(" << year << "): " << title;
        return out.str();
    }
    
    //overloading operator <
    bool operator< (const Publication& B) {
        if (authors==B.authors)
            return year<B.year;
        return authors<B.authors;
    }

    private:
    std::string title;
    std::vector <std::string> authors;
    int year;
};

void convertString (std::string s, std::vector <std::string>& v) {
    //function that identifies string as a sequence of names separated by commas
    int i{0}; //vector element index
    char token = ',';
    std::string name;
    for (char& c: s) {
        if (c != token) {
            name +=c;
        }
        else {
            v.push_back(name);
            name="";
            }
    }
    v.push_back(name); //pushs last name 
}

#endif