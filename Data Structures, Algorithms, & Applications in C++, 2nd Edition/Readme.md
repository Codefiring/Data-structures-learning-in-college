# Code In Book _Data Structures, Algorithms, & Applications in C++, 2nd Edition_
* * *

## class `currency`

1. currency.h

	>This is the base file of class `currency`.

	>It has 2 member functions called `add` and `imprement`.

2. currencyNew.h

	>This new file has convert the storgage form of currency.
	
	>From _**"sign + dollars + cents"**_ to _**"amount"**_

3. currencyOverload.h

	>This file add the new feature `+` and `+=` instead of function `add` and `imprement`

4. currencyFriend.h

	>This file change the operator `<<` to a *friend member* so that it can access the *private* variable.

## class `arrayList`

1. linearList.h

	>This file is the virtual class of `linearList`.

	>It describes the *abstract data type* of a linearList.

	>It contains some *pure virtual function*s using '0' as the initialized value.

2. changeLength1D.h

	>This file contains a function template called `changeLength1D`.

	>The function can change the size of the array that put into it. 

3. arrayList.h

	>This file is the the implement of the class `arrayList`.
	
	>It contains the *integrety codes* of arrayList.