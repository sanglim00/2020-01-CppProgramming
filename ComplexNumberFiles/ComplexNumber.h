#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
#include <iostream>

using namespace std;

class myComplex {
private:
    int realPart;
    int imaginaryPart;
    int norm() const;
public:
    //생성자와 복사생성자
    myComplex(int real = 0, int imag = 0);
    myComplex(const myComplex& number);
    //접근자
    int getRealPart() const;
    int getImaginaryPart() const;
    //변경자
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);

    friend ostream& operator<<(ostream& outStream, const myComplex& number);
    friend istream& operator>>(istream& inStream, myComplex& number);
    friend myComplex operator+(int value, const myComplex& number);
    friend myComplex operator-(int value, const myComplex& number);
    friend myComplex operator*(int value, const myComplex& number);

    myComplex operator +(const myComplex& number) const;
    myComplex operator +(int value) const;
    myComplex operator -(const myComplex& number) const;
    myComplex operator -(int value) const;
    myComplex operator *(const myComplex& number) const;
    myComplex operator *(int value) const;
    myComplex& operator =(const myComplex& number);
    myComplex& operator =(int value);

    myComplex& operator +=(const myComplex& number);
    myComplex& operator +=(int value);
    myComplex& operator -=(const myComplex& number);
    myComplex& operator -=(int value);
    myComplex& operator *=(const myComplex& number);
    myComplex& operator *=(int value);

    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;
    bool operator >(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;
    bool operator <(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;

    myComplex operator -();
    myComplex operator ~();
    myComplex operator ++();
    myComplex operator ++(int);
    myComplex operator --();
    myComplex operator --(int);

};
#endif