#include<cassert>//provides assert
#include "bigInt.h" //big int class
#include <iostream> //we are adding ostream and istream
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;

//Default constructor
bigInt::bigInt()
{
	//a 2 element array with an initial value of zero and a NULL
	//character  ie: 0th element is 0 and 1st element is NULL

	/* for(int i = 0; i < 1; i++)
		{
		bigIntArray = new char [i+1];
		bigIntArray[i] = '0' + (i+1);
		}
	*/
	
	bigIntArray = new char [2];
	bigIntArray[0] = '0';
	bigIntArray[1] = '\0';
}

//"c_str" constructor
bigInt::bigInt(const char initialValue[])
{ 
	//make your bigInt array equal to this c_str
	//being passed in  (i.e. use strlen to allocate
	//memory (remember to add +1 to it though for the null character...
	// and strcpy to copy the stuff over (strcpy adds the null automatically)
	bigIntArray = new char [strlen(initialValue) + 1];
	strcpy(bigIntArray, initialValue);
	
}

//"integer" constructor
bigInt::bigInt(int initialValue)
{
	//use a loop to count the numberOfDigits in initial value
	//Allocate that memory and copy it over (that good ol divide
	//by 10 and modulo 10 thing
	int numberOfDigits = 0;
	int passedValue = initialValue;
	while(passedValue > 0)
	{
		numberOfDigits = numberOfDigits + 1;
		passedValue = passedValue / 10;
	}

	bigIntArray = new char[numberOfDigits + 1];
	sprintf(bigIntArray, "%i", initialValue);
	
	
}

//"double" constructor
bigInt::bigInt (double initialValue)
{
	//very similar to the integer constructor strategy above
	//in fact you get this into an int and you can use the same
	//code...	
	
	int numberOfDigits = 0;
	int passedValue = initialValue;
	while(passedValue > 0)
	{
		numberOfDigits = numberOfDigits + 1;
		passedValue = passedValue / 10;
	}
	
	bigIntArray = new char[numberOfDigits + 1];
	sprintf(bigIntArray, "%i", int(initialValue));
	
}

//Copy Constructor
bigInt::bigInt (const bigInt& toCopyFrom)
{

	bigIntArray = toCopyFrom.getBigIntArray();
}

bigInt::~bigInt()
{
	delete[] bigIntArray;
}


//Returns a dynamically allocated copy to the bigIntArray
char* bigInt::getBigIntArray() const
{
	//Implemented to help you.
		//RETURNS A POINTER TO A COPY of our bigIntArray
		//with memory already allocated. You can set this 
		//to another char * etc.
	char *toReturn;
	toReturn=new char[strlen(bigIntArray)+1];
	strcpy(toReturn, bigIntArray);
	return toReturn;
}

//operator "="
void bigInt::operator = (const bigInt& toEqual)
{
	//use getBigIntArray on toEqual to set your int array to 
	//the intArray of toEqual	
	
	bigIntArray = toEqual.getBigIntArray();
}

//operator "=="
bool operator ==(const bigInt &firstInt, const bigInt &secondInt)	
{
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) == 0)
		{
		return true;
		}
	else
		{
		return false;
		}
}

//operator !=
bool operator !=(const bigInt &firstInt, const bigInt &secondInt)
{
	if (firstInt.getBigIntArray() == secondInt.getBigIntArray())
		{
		return false;
		}
	else 
		{
		return true;
		}
}

//operator <
bool operator < (const bigInt &firstInt, const bigInt &secondInt)
{
	//if(strlen(firstInt) < strlen(secondInt)){
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) == -1)
		{
			return true;
		}
	//}
	else
		{
		return true;
		}
}

//operator >
bool operator >(const bigInt &firstInt, const bigInt &secondInt)
{
	int i = strlen(firstInt.getBigIntArray());
	int j = strlen(secondInt.getBigIntArray());
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) == 1 && i > j)
		{
			return true;
		}
	else
		{
			return false;
		}
}

//operator <=
bool operator <=(const bigInt &firstInt, const bigInt &secondInt)
{
	if ((strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) == -1) || strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray())==0)
		{
		return true;
		}
	else
		{
		return false;
		}
}

//operator >=
bool operator >=(const bigInt &firstInt, const bigInt &secondInt)
{
	if (strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray()) == 1 || strcmp(firstInt.getBigIntArray(), secondInt.getBigIntArray())==0)
		{
		return true;
		}
	else
		{
		return false;
		}
}

bigInt operator + (const bigInt &firstInt, const bigInt &secondInt)
{
	//Creating two temporary char* to hold the bigIntArray of firstInt and 
	//secondInt
	char* temp1;
		temp1 = firstInt.getBigIntArray();
	char* temp2;
		temp2 = secondInt.getBigIntArray();
	
    //Checking for which bigInt is largest and making a third array to hold result of sum
	char* result;
	if(strlen(temp1) >= strlen(temp2)){
		result = firstInt.getBigIntArray();
		}
	else{
		result = secondInt.getBigIntArray();
		}
	

	
	// definitions for index values of char* arrays.
	int i = strlen(temp1);
	int j = strlen(temp2);
	int k = strlen(result);
	int carryFlag = 0; // carryFlag for numbers > 10.
					   // set to 0, because there is no initial carry
	
	
	while (k >= 0){
		if (i > 0 && j > 0){ // Adding element by element
			// checking for sum less than 10 and carry.
			if(((temp1[i-1]-'0') + (temp2[j-1]-'0') + carryFlag) < 10){
				int result_int = temp1[i-1]-'0' + temp2[j-1]-'0' + carryFlag;
				
				// Adding carry to sum and placing in result, removing carryFlag.
				result[k-1] = '0'+result_int;
				carryFlag = 0;
			
				}
					
			// checking for sum greater than or equal to 10 and carry.
			else if(((temp1[i-1]-'0') + (temp2[j-1]-'0') + carryFlag) >= 10){
				//int result_int = ;
				
				// Placing modulo 10 of sum in result and adding carryFlag.
				result[k-1] = '0'+(((temp1[i-1]-'0') + (temp2[j-1]-'0') + carryFlag) % 10);
				carryFlag = 1;
				
				}
			}
			
		else if (i <= 0 && j > 0){ // Adding j element if i is empty.
			// checking for less than 10 
			if(((temp2[j-1]-'0') + carryFlag) < 10){
				result[k-1] = '0'+((temp2[j-1]-'0')+carryFlag);

				carryFlag = 0;
				}
			
			// checking for greater or equal to 10 and adding carry
			else if(((temp2[j-1]-'0') + carryFlag) >=10){
				int result_int = ((temp2[j-1]-'0' + carryFlag) % 10);
				result[k-1] = '0'+result_int;

				carryFlag = 1;
			}
		}
			
		else if (i > 0 && j <= 0){ // Adding i element if j is empty.
			
			// checking for less than 10
			if(((temp1[i-1]-'0') + carryFlag) < 10){
				int result_int = temp1[i-1]-'0'+carryFlag;
				result[k-1] = '0'+result_int;
				carryFlag = 0;
				}
			
			// checking for greater than or equal to 10 and adding carry.
			else if(((temp1[i-1]-'0') + carryFlag) >= 10){
				int result_int = ((temp1[i-1]-'0') % 10);
				result[k-1] = '0'+result_int;
			
				carryFlag = 1;
				}
				
			}
			
		else if (k==0 && carryFlag==1)
		{
				
				char* result_temp;
				result_temp = new char[strlen(result) + 2];
				
				size_t z;
				result_temp[0] = '1';
				result_temp[strlen(result)+1] = '\0';
				
				for(z=1; z <= strlen(result); z++){
					result_temp[z] = result[z-1];
					}
				
				result = result_temp;
				
		}
		
	// iterating through strlen.
				i = i - 1;
				j = j - 1;
				k = k - 1;
	}

	return bigInt(result);
	
	delete [] result;
}

void bigInt::operator += (const bigInt& intToAdd)
{
	bigInt temp1 = intToAdd + this->getBigIntArray();
	bigIntArray = temp1.getBigIntArray();
}

bigInt operator - (const bigInt &firstInt, const bigInt &secondInt)
{
	char* temp1;
		temp1 = firstInt.getBigIntArray();
	char* temp2;
		temp2 = secondInt.getBigIntArray();
	
	
	char* result;
			result = firstInt.getBigIntArray();

	
	int i = strlen(temp1); // last index for temp1
	int j = strlen(temp2); // last index for temp2
	int k = strlen(result); // last index for result
	int result_int;
	int carryFlag = 0;
	
	while (k >= 0){
		if (i > 0 && j > 0){ //Checking if both indexes are still positive
			
			// Adding 10 to temp1 if temp1-temp2 is negative
			if((temp1[i-1]-'0') - (temp2[j-1]-'0') + carryFlag < 0){
				result_int = (10 + temp1[i-1]-'0' - (temp2[j-1]-'0' + carryFlag));
				
				// adding carryflag
				result[k-1] = '0'+result_int;
				carryFlag = 1;
				}
					
			// subtracting regularly
			else if(((temp1[i-1]-'0') - ((temp2[j-1]-'0') + carryFlag)  >= 0)){
				result_int = (temp1[i-1]-'0') - (temp2[j-1]-'0') - carryFlag;
				// removing carryFlag
				result[k-1] = '0'+result_int;
				carryFlag = 0;
				}
			}
			
		else if (i > 0 && j <= 0){ // checking if second index is negative
			// Adding 10 to temp1 and subtracting carryFlag, if negative
			if((temp1[i-1]-'0') - carryFlag < 0){
				result_int = (10 + (temp1[i-1]-'0')) - carryFlag;
				result[k-1] = '0'+result_int;
				// Adding a carryFlag
				carryFlag = 1;
				}
			
			// subtracting carryflag, if positive.
			else if(((temp1[i-1]-'0')) - carryFlag >= 0){
				result_int = ((temp1[i-1]-'0') - carryFlag);
				result[k-1] = '0'+result_int;
				carryFlag = 0;
				}
				
			}
			
		i = i - 1;
		j = j - 1;
		k = k - 1;
		
	}
	
	int p=0;
	
	while(result[p] == '0'){
		++p;
	}
	cout << "p is:" << p <<endl;
	
	char* result_shift = new char[strlen(result)+1-p];
	
	size_t z;
	size_t y;
	result_shift[strlen(result)+1-p] = '\0';
	
	
	for(z=0; z <= strlen(result)-p; z++){
		for(y=p; y <= strlen(result); y++){
			result_shift[z] = result[p+z];
			}
		}
	result = result_shift;

	return bigInt(result);
	delete [] result;
}

void bigInt::operator -= (const bigInt& intToSubtract)
{
	//If you've done minus, this should be easy
	//you can even use the this ptr.
	
	bigInt temp1 = this->getBigIntArray() - intToSubtract;
	bigIntArray = temp1.getBigIntArray();
}

//ostream is implemented for you
ostream& operator << (ostream& outs, const bigInt& source)
{  
	outs<<source.bigIntArray;
	return outs;
}

//istream is implemented for you in a cheating manner
std::istream& operator >>(std::istream& ins, bigInt& target)
{
	delete [] target.bigIntArray;
	string hello;
	ins>>hello;
	bigInt temp(hello.c_str());
	target.bigIntArray=temp.getBigIntArray();
    return ins;
}
