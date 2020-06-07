#include "MyPolynomial.h"

myPolynomial::myPolynomial(int c , unsigned e ) : numTerm(1) {
    Mterm = new myTerm[1];
    Mterm[0].setCoeff(c);
    Mterm[0].setExp(e);
}
myPolynomial::myPolynomial(int nTerms, int mono[]) {
    numTerm = nTerms;
    Mterm = new myTerm[numTerm];

    for (int i = 0; i < numTerm; i++) {
        Mterm[i].setCoeff(mono[i * 2]);
        Mterm[i].setExp(mono[i * 2 + 1]);
    }
    ///sort
    for (int i = 0; i < numTerm - 1; i++) {
        if (Mterm[i].getExp() < Mterm[i + 1].getExp()) {
            myTerm temp = Mterm[i + 1];
            Mterm[i + 1] = Mterm[i];
            Mterm[i] = temp;
            i = -1;
        }
    }
    degree = getDegree();
}

myPolynomial::myPolynomial(const myPolynomial& poly) {
    numTerm = poly.getNumTerms();
    Mterm = new myTerm[numTerm];

    for (int i = 0; i < numTerm; i++) {
        Mterm[i] = poly.Mterm[i];
    }
    degree = poly.getDegree();
}

bool myPolynomial::operator == (const myPolynomial& poly) const {
    if (numTerm != poly.numTerm)  return false;
    
    for (int i = 0; i < numTerm; i++) {
        if (Mterm[i].coeff != poly.Mterm[i].coeff || Mterm[i].exp != poly.Mterm[i].exp)  return false;
    }

    return true;
}
bool myPolynomial::operator != (const myPolynomial& poly) const {
    return !(operator ==(poly));
}

myPolynomial& myPolynomial::operator += (const myPolynomial& poly) {
    *this = *this+poly;
    return *this;
}
myPolynomial& myPolynomial::operator -= (const myPolynomial& poly) {
    *this = *this-poly;
    return *this;
}
myPolynomial& myPolynomial::operator *= (const myPolynomial& poly) {
    *this = *this* poly;
    return *this;
}
myPolynomial& myPolynomial::operator *= (int k) {
    *this = *this * myPolynomial(k, (unsigned)0);
    return *this;
}
myPolynomial myPolynomial::operator -() const {
    myPolynomial myP = *this;

    for (int i = 0; i < numTerm; i++) myP.Mterm[i].coeff = -myP.Mterm[i].coeff ;
    return myP;
}
myPolynomial myPolynomial::operator *(int k) const {
    if (k == 0)
        return myPolynomial::ZERO;

    myPolynomial myP = *this;
    for (int i = 0; i < numTerm; i++) {
        myP.Mterm[i].setCoeff(myP.Mterm[i].getCoeff() * k);
    }
    return myP;
}
myPolynomial myPolynomial::operator +(const myPolynomial& poly) const {
    int arr[102] = { 0 };
    int a = 0, b = 0, size = 0;
    for (size; a != numTerm && b != poly.numTerm; size++) {
        if (Mterm[a].exp > poly.Mterm[b].exp) {
            arr[2 * size] = Mterm[a].coeff;
            arr[2 * size + 1] = Mterm[a].exp, a++;
        }
        else if (Mterm[a].exp < poly.Mterm[b].exp) {
            arr[2 * size] = poly.Mterm[b].coeff;
            arr[2 * size + 1] = poly.Mterm[b].exp, b++;
        }
        else {
            arr[2 * size] = Mterm[a].coeff + poly.Mterm[b].coeff;
            arr[2 * size + 1] = Mterm[a].exp, a++, b++;
        }
    }
    for(a; a != numTerm; a++, size++) {
        arr[2 * size] = Mterm[a].coeff;
        arr[2 * size + 1] = Mterm[a].exp;
    }
    for(b; b!=poly.numTerm; b++, size++){
        arr[2 * size] = poly.Mterm[b].coeff, arr[2 * size + 1] = poly.Mterm[b].exp;
    }
    return myPolynomial(size, arr);
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
        myP += Mterm[i].getCoeff() * pow(x, Mterm[i].getExp());
    }
    return myP;
}
int myPolynomial::getDegree() const {
    return Mterm[0].getExp();
}
unsigned myPolynomial::getNumTerms() const {
    return numTerm;
}
myPolynomial myPolynomial::ddx() const {
    myPolynomial myP(*this);
    for (int i = 0; i < numTerm; i++) 
        myP.Mterm[i] = Mterm[i].ddx();
    
    return myP;
}

myPolynomial operator *(int k, const myPolynomial& poly) {
    myPolynomial myP(poly);
    for (int i = 0; i < myP.numTerm; i++) {
        myP.Mterm[i].setCoeff((myP.Mterm[i].getCoeff() * k));
    }
    return myP;
}

ostream& operator <<(ostream& outStream, const myPolynomial& poly){
    bool Check = false;
    if (poly == myPolynomial::ZERO)  return outStream << 0;
    outStream << poly.Mterm[0];

    if (poly.Mterm[0].getCoeff() != 0)  Check = true;
  
    for (int i = 1; i < poly.numTerm; i++) {
        if (poly.Mterm[i].getCoeff() != 0) Check = true;
        if (poly.Mterm[i].getCoeff() > 0) outStream << '+';
        
        outStream << poly.Mterm[i];
    }
    if (Check == false)  return outStream << '0';
    
    return outStream;
}
const myPolynomial myPolynomial::ZERO(0); 
const myPolynomial myPolynomial::ONE(1, (unsigned)0);
const myPolynomial myPolynomial::X(1, 1); 