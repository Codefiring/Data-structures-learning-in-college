#ifndef CurrencyNew_
#define CurrencyNew_
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
        currency add(const currency&) const;
        currency& increment(const currency&);
        void output() const;

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

currency currency::add(const currency& a)const{
// add this currency and a then return the result     
    currency result;
    result.setValue(amount/100.0 + a.amount/100.0);
    //result.amount = amount + a.amount;
    return result;
}

currency& currency::increment(const currency& x){
// add another x on the currency;
    *this = add(x);
    return *this;
}

void currency::output() const{
// show the value in the standard form
    if(this->getSign() == m) cout << "-";
    cout << "$" << this->getDollars() << ".";
    if(this->getCents()<10) cout << "0";
    cout << this->getCents();
}
#endif