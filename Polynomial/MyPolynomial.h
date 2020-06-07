#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>
#include "MyTerm.h"

using namespace std;

#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_

class myPolynomial {
private:
    int degree;
    int numTerm;
    myTerm Mterm[111];
public:
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    myPolynomial(const myPolynomial& poly);

    bool operator == (const myPolynomial& poly) const;
    bool operator != (const myPolynomial& poly) const;

    myPolynomial& operator += (const myPolynomial& poly);
    myPolynomial& operator -= (const myPolynomial& poly);
    myPolynomial& operator *= (const myPolynomial& poly);
    myPolynomial& operator *= (int k);

    myPolynomial operator -() const;
    myPolynomial operator *(int k) const;
    myPolynomial operator +(const myPolynomial& poly) const;
    myPolynomial operator -(const myPolynomial& poly) const;
    myPolynomial operator *(const myPolynomial& poly) const;

    long operator() (int x) const;
    int getDegree() const;
    unsigned getNumTerms() const;

    myPolynomial ddx() const;

    friend myPolynomial operator *(int k, const myPolynomial& poly);
    friend ostream& operator <<(ostream& outStream, const myPolynomial& poly);

    static const myPolynomial ZERO;
    static const myPolynomial ONE;
    static const myPolynomial X;
};
#endif
