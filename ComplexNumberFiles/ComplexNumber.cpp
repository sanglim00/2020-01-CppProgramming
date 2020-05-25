#include "ComplexNumber.h"

myComplex::myComplex(int real, int imag){
	realPart = real;
	imaginaryPart = imag;
}
myComplex::myComplex(const myComplex& number){
	realPart = number.realPart;
	imaginaryPart = number.imaginaryPart;
}
int myComplex::getRealPart() const{
	return realPart;
}
int myComplex::getImaginaryPart() const{
	return imaginaryPart;
}
void myComplex::setRealPart(int real){
	realPart = real;
}
void myComplex::setImaginaryPart(int imag){
	imaginaryPart = imag;
}
void myComplex::set(int real, int imag){
	realPart = real;
	imaginaryPart = imag;
}
int myComplex::norm() const {
	return realPart * realPart + imaginaryPart * imaginaryPart;
}
ostream& operator <<(ostream& outStream, const myComplex& number) {
	outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
	return outStream;
}
istream& operator >>(istream& inStream, myComplex& number) {
	inStream >> number.realPart >> number.imaginaryPart;
	return inStream;
}

myComplex operator +(int value, const myComplex& number){
	myComplex tmp = number;
	tmp.realPart += value;
	return tmp;
}
myComplex operator -(int value, const myComplex& number){
	myComplex tmp = number;
	tmp.realPart = value - tmp.realPart;
	tmp.imaginaryPart *= -1;
	return tmp;
}
myComplex operator *(int value, const myComplex& number){
	myComplex tmp = number;
	tmp.realPart *= value;
	tmp.imaginaryPart *= value;
	return tmp;
}
myComplex myComplex::operator +(const myComplex& number) const {
	int C_Real = realPart + number.realPart;
	int C_Imag = imaginaryPart + number.imaginaryPart;
	return myComplex(C_Real, C_Imag);
}
myComplex myComplex::operator +(int value) const {
	return myComplex(value) + (*this);
}
myComplex myComplex::operator -(const myComplex& number) const {
	int C_Real = realPart - number.realPart;
	int C_Imag = imaginaryPart - number.imaginaryPart;
	return myComplex(C_Real, C_Imag);
}
myComplex myComplex::operator -(int value) const {
	int C_Real = realPart - value;
	return myComplex(C_Real, imaginaryPart);
}
myComplex myComplex::operator *(const myComplex& number) const {
	int C_Real = (realPart * number.realPart) - (imaginaryPart * number.imaginaryPart);
	int C_Imag = (realPart * number.imaginaryPart) + (imaginaryPart * number.realPart);
	return myComplex(C_Real, C_Imag);
}
myComplex myComplex::operator *(int value) const {
	int C_Real = realPart * value;
	int C_Imag = imaginaryPart * value;
	return myComplex(C_Real, C_Imag);
}
myComplex& myComplex::operator =(const myComplex& number) {
	this->realPart = number.realPart;
	this->imaginaryPart = number.imaginaryPart;
	return *this;
}
myComplex& myComplex::operator =(int value) {
	realPart = value;
	imaginaryPart = 0;
	return *this;
}

myComplex& myComplex::operator +=(const myComplex& number) {
	realPart += number.realPart;
	imaginaryPart += number.imaginaryPart;
	return *this;
}
myComplex& myComplex::operator +=(int value) {
	realPart += value;
	return *this;
}
myComplex& myComplex::operator -=(const myComplex& number) {
	realPart -= number.realPart;
	imaginaryPart -= number.imaginaryPart;
	return *this;
}
myComplex& myComplex::operator -=(int value) {
	realPart -= value;
	return *this;
}
myComplex& myComplex::operator *=(const myComplex& number) {
	int C_Real = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
	int C_Imag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
	realPart = C_Real;
	imaginaryPart = C_Imag;
	return *this;
}
myComplex& myComplex::operator *=(int value) {
	realPart *= value;
	imaginaryPart *= value;
	return *this;
}

bool myComplex::operator ==(const myComplex& number) const {
	return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const {
	return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart);
}
bool myComplex::operator >(const myComplex& number) const {
	return norm() > number.norm();
}
bool myComplex::operator >=(const myComplex& number) const {
	return norm() >= number.norm();
}
bool myComplex::operator <(const myComplex& number) const {
	return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const {
	return norm() <= number.norm();
}
myComplex myComplex::operator -() {
	return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex :: operator ~() {
	imaginaryPart = -imaginaryPart;
	return *this;
}
myComplex myComplex :: operator ++() {
	realPart++;
	return *this;
}
myComplex myComplex :: operator ++(int) {
	myComplex tmp(getRealPart(), getImaginaryPart());
	realPart++;
	return tmp;
}
myComplex myComplex :: operator --() {
	realPart--;
	return *this;
}
myComplex myComplex :: operator --(int) {
	myComplex tmp(getRealPart(), getImaginaryPart());
	realPart--;
	return tmp;
}