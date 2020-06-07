#include "MyTerm.h"

myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e) {}
myTerm::myTerm(const myTerm& term) : coeff(term.coeff), exp(term.exp) {}

bool myTerm::operator == (const myTerm& term) const {
    if (coeff == term.coeff && exp == term.exp) return true;
    return false;
}
bool myTerm::operator != (const myTerm& term) const {
    return !(*this == term);
}
bool myTerm::operator < (const myTerm& term) const {
    if (exp > term.exp) return true;
    return false;
}
myTerm myTerm::operator - () const {
    return myTerm(-coeff, exp);
}
myTerm myTerm::ddx() const {
    if (exp == 0) return myTerm(0, 0);
    return myTerm(exp * coeff, exp - 1);
}
ostream& operator <<(ostream& outStream, const myTerm& term) {
    if (term.exp == 0) {
        if (term.coeff == 0)  return outStream;
        else return outStream << term.coeff;
    }

    if (term.coeff == 0)  return outStream;

    if (term.coeff == 1)  outStream << "x";
    else if (term.coeff == -1) outStream << "-x";
    else  outStream << term.coeff << "x";

    if (term.exp == 1)  return outStream;
    else  return outStream << "^" << term.exp;
    
}
