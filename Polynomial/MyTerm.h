#ifndef _MYTERM_H_
#define _MYTERM_H_
#include <iostream>

using namespace std;

class myPolynomial;

class myTerm {
private:
    int coeff;
    unsigned exp;
public:
    myTerm(int c = 0, unsigned e = 0);
    myTerm(const myTerm& term);

    bool operator == (const myTerm& term) const;
    bool operator != (const myTerm& term) const;
    bool operator < (const myTerm& term) const;

    myTerm operator - () const;

    int getCoeff() const { return coeff; }
    unsigned getExp() const { return exp; }

    void setCoeff(int c) { coeff = c; }
    void setExp(unsigned e) { exp = e; }

    myTerm ddx() const;

    friend ostream& operator <<(ostream& outStream, const myTerm& term);
    friend myPolynomial;

};
#endif _MYTERM_H_
