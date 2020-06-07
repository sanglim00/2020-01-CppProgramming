#include "MyPolynomial.h"

myPolynomial::myPolynomial(int c, unsigned e) : numTerm(1) {

    Mterm[0].coeff = c;
    Mterm[0].exp = e;
}
myPolynomial::myPolynomial(int NT, int mono[]) : numTerm(NT) {
    for (int i = 0; i < numTerm; i++) {
        Mterm[i].coeff = mono[2 * i];
        Mterm[i].exp = mono[2 * i + 1];
    }
    sort(Mterm, Mterm + numTerm);

    if (NT == 1 && Mterm[0].coeff == 0 && Mterm[0].exp == 0)  degree = 0;
    else  degree = Mterm[0].exp;
    
}
myPolynomial::myPolynomial(const myPolynomial& poly) :numTerm(poly.numTerm), degree(poly.degree) {
    for (int i = 0; i < numTerm; i++) {
        Mterm[i].coeff = poly.Mterm[i].coeff;
        Mterm[i].exp = poly.Mterm[i].exp;
    }
}
bool myPolynomial::operator == (const myPolynomial& poly) const {
    if (numTerm != poly.numTerm)   return false;
    
    for (int i = 0; i < numTerm; i++) {
        if (Mterm[i].coeff != poly.Mterm[i].coeff || Mterm[i].exp != poly.Mterm[i].exp) return false;
    }
    return true;
}
bool myPolynomial::operator != (const myPolynomial& poly) const {
    return !(*this == poly);
}

myPolynomial& myPolynomial::operator += (const myPolynomial& poly) {
    *this = *this + poly;
    return *this;
}
myPolynomial& myPolynomial::operator -= (const myPolynomial& poly) {
    *this = *this - poly;
    return *this;
}
myPolynomial& myPolynomial::operator *= (const myPolynomial& poly) {
    *this = *this * poly;
    return *this;
}
myPolynomial& myPolynomial::operator *= (int k) {
    *this = (*this) * k;
    return *this;
}

myPolynomial myPolynomial::operator -() const {
    return (*this) * -1;
}
myPolynomial myPolynomial::operator *(int k) const {
    return *this * myPolynomial(k, (unsigned)0);
}
myPolynomial myPolynomial::operator +(const myPolynomial& poly) const {

    int arr[111] = { 0 };
    int a = 0, b = 0;
    int index = 0;

    for (index; a != numTerm && b != poly.numTerm; index++) {
        if (Mterm[a].exp > poly.Mterm[b].exp) {
            arr[index * 2] = Mterm[a].coeff;
            arr[index * 2 + 1] = Mterm[a].exp;
            a++;
        }
        else if (Mterm[a].exp < poly.Mterm[b].exp) {
            arr[index * 2] = poly.Mterm[b].coeff;
            arr[index * 2 + 1] = poly.Mterm[b].exp;
            b++;
        }
        else {
            arr[index * 2] = Mterm[a].coeff + poly.Mterm[b].coeff;
            arr[index * 2 + 1] = Mterm[a].exp;
            a++;
            b++;
        }
    }
    for(a; a !=numTerm; a++) {
        arr[index * 2] = Mterm[a].coeff;
        arr[index * 2 + 1] = Mterm[a].exp;
        index++;
    }
    for(b; b!=poly.numTerm; b++) {
        arr[index * 2] = poly.Mterm[b].coeff;
        arr[index * 2 + 1] = poly.Mterm[b].exp;
        index++;
    }
    return myPolynomial(index, arr);
}
myPolynomial myPolynomial::operator -(const myPolynomial& poly) const {
    return *this + (-poly);
}
myPolynomial myPolynomial::operator *(const myPolynomial& poly) const {
    myPolynomial myP(0, (unsigned)0);

    for (int i = 0; i < numTerm; i++) {
        myPolynomial myP2(poly);

        for (int j = 0; j < poly.numTerm; j++) {
            myP2.Mterm[j].coeff *= Mterm[i].coeff;
            myP2.Mterm[j].exp += Mterm[i].exp;
        }
        myP += myP2;
    }
    return myP;
}
long myPolynomial::operator() (int x) const {
    long myP = 0;
    for (int i = 0; i < numTerm; i++) {
        myP += Mterm[i].coeff *  pow(x, Mterm[i].exp);
    }
    return myP;
}
int myPolynomial::getDegree() const {
    return degree;
}
unsigned myPolynomial::getNumTerms() const {
    return numTerm;
}
myPolynomial myPolynomial::ddx() const {
    myPolynomial myP(*this);

    for (int i = 0; i < numTerm; i++)  myP.Mterm[i] = Mterm[i].ddx();
    return myP;
}
myPolynomial operator *(int k, const myPolynomial& poly) {
    return myPolynomial(k, (unsigned)0) * poly;
}
ostream& operator <<(ostream& outStream, const myPolynomial& poly) {

    bool Check = false;

    if (poly == myPolynomial::ZERO) return outStream << 0; 
    outStream << poly.Mterm[0];

    if (poly.Mterm[0].getCoeff() != 0)  Check = true;
   

    for (int i = 1; i < poly.numTerm; i++) {
        if (poly.Mterm[i].getCoeff() != 0)  Check = true;
        if (poly.Mterm[i].getCoeff() > 0)  outStream << '+';

        outStream << poly.Mterm[i];
    }
    if (Check == false)  return outStream << '0';
    return outStream;
}
const myPolynomial myPolynomial::ZERO(0);
const myPolynomial myPolynomial::ONE(1, (unsigned)0);
const myPolynomial myPolynomial::X(1, 1);
