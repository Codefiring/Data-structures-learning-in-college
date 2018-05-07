#ifndef Currency_
#define Currency_
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
        signType getSign() const {return sign;}
        unsigned long getDollars()const {return dollars;}
        unsigned int getCents() const {return cents;}
        currency add(const currency&) const;
        currency& increment(const currency&);
        void output() const;

    private:
        signType sign;
        unsigned long dollars;
        unsigned int cents;
};

currency::currency(signType theSign,unsigned long theDollars,unsigned int theCents){
    setValue(theSign,theDollars,theCents);
}

void currency::setValue(signType theSign,unsigned long theDollars,unsigned int theCents){
    if(theCents>99)
        throw illegalParameterValue("Cents should be < 100");
    
    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}  

void currency::setValue(double theAmount){
	if(theAmount<0){sign = m;theAmount = -theAmount;}
    else sign = p;

    dollars = (unsigned long)theAmount;
    cents = (unsigned long)(theAmount+0.001-dollars)*100;
}

currency currency::add(const currency& a)const{
// add this currency and a then return the result     
    currency result;
    result.setValue(0);

    if(sign == a.sign){
        result.sign = sign;
        if(cents + a.cents>=100){
            result.cents = cents + a.cents-100;
            result.dollars = dollars + a.dollars+1;
        }
        else{
            result.cents = cents + a.cents;
            result.dollars = dollars + a.dollars;
        }
    }
    else{
        if(dollars == a.dollars){
            if(cents == a.cents) result.setValue(0);
            else if(cents > a.cents) result.setValue(sign,0,cents-a.cents);
            else result.setValue(a.sign,0,a.cents-cents);
        }
        else if(dollars > a.dollars){
            if(cents == a.cents) result.setValue(0);
            else if(cents > a.cents) result.setValue(sign,dollars - a.dollars, cents - a.cents);
            else result.setValue(sign,dollars - a.dollars - 1,a.cents - cents);
            }          
        else{
            if(cents == a.cents) result.setValue(0);
            else if(cents > a.cents) result.setValue(a.sign,a.dollars - dollars, cents - a.cents);
            else result.setValue(a.sign,a.dollars - dollars - 1,a.cents - cents);
        }
    }
    return result;
}

currency& currency::increment(const currency& x){
// add another x on the currency;
    *this = add(x);
    return *this;
}

void currency::output() const{
    if(sign == m) cout << "-";
    cout << "$" << dollars << ".";
    if(cents<10) cout << "0";
    cout << cents;
}
#endif