#ifndef CurrencyOverload_
#define CurrencyOverload_
#include "myExceptions.h"
#include<iostream>
using namespace std;

enum signType {p,m};

class currency
{
    public:
        currency(signType theSign = p,
                unsigned long theDollars = 0,
                unsigned int theCents = 0);
        ~currency(){}

        void setValue(signType,unsigned long,unsigned int);
        void setValue(double);
        signType getSign() const;
        unsigned long getDollars() const;
        unsigned int getCents() const;
        currency operator+ (const currency&) const;
        currency& operator+= (const currency&);
        void output(ostream&) const;

    private:
        long amount;
};

currency::currency(signType theSign,unsigned long theDollars,unsigned int theCents){
    setValue(theSign,theDollars,theCents);
}

void currency::setValue(signType theSign,unsigned long theDollars,unsigned int theCents){
    if(theCents>99)
        throw illegalParameterValue("Cents should be < 100");
    
    amount = theDollars*100 + theCents;
    if(theSign == m) amount = -amount;
}  

void currency::setValue(double theAmount){
	if(theAmount<0)
        amount = (long)((theAmount - 0.001) * 100);
    else
        amount = (long)((theAmount + 0.001) * 100);
}

signType currency::getSign() const{
    if(amount<0) return m;
    else return p;
}

unsigned long currency::getDollars() const{
    if(amount<0) return (-amount)/100;
    else return amount/100;
}

unsigned int currency::getCents() const{
    if(amount<0) return (-amount - getDollars() * 100);
    else return (amount - getDollars() * 100);
}

currency currency::operator+(const currency& a)const{
// add this currency and a then return the result     
    currency result;
    result.setValue(amount/100.0 + a.amount/100.0);
    //result.amount = amount + a.amount;
    return result;
}

currency& currency::operator+=(const currency& x){
// add another x on the currency;
    *this = *this + x;
    return *this;
}

void currency::output(ostream& out) const{
// show the value in the standard form
    if(this->getSign() == m) out << "-";
    out << "$" << this->getDollars() << ".";
    if(this->getCents()<10) out << "0";
    out << this->getCents();
}

ostream& operator<<(ostream& out,const currency&x){
    x.output(out);
    return out;
}
#endif