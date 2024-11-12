// timerepresent-ANSWER.cpp: a basic program to represent time.
//
// 2024 FA -- CSCI 77800 -- Edgar E. Troudt, Ph.D.
//
#include <iostream>

using namespace std;

int main () {

	// Later we can discuss size of data types.
	//
	// useful reference -- https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm
	// cout << "-------------------------------------" << endl;
	// cout << "size   time_ushort:\t" << sizeof(time_ushort) << endl; // 2 bytes
	// cout << "size   time_int:\t"    << sizeof(time_int)    << endl; // 4 bytes with half of values as negative.
	// cout << "size   time_uint:\t"   << sizeof(time_uint)   << endl; // 4 bytes
	// cout << "size   time_ulong:\t"  << sizeof(time_ulong)  << endl; // 8 bytes


	// =========START HERE=============
	// Remember: time represented as number of seconds from January 1, 1970.

	// EXERCISE 1: Fix the below calculations.
	const int DAY  = 24*3600;		// NEED TO FIX THIS.  HOW MANY SECONDS IN A DAY?
	const int YEAR = int (DAY*365.25);		// NEED TO FIX THIS.  HOW MANY SECONDS IN A YEAR?

	cout << "-------------------------------------" << endl;
	cout << "A YEAR is " << YEAR << " in seconds."  << endl;
	cout << "A DAY is  " << DAY  << " in seconds."  << endl;


	// EXERCISE 2: What is the date for 157,766,400 seconds?  
	//		HINT: use division and mod.
	//		Fix the year and date variable calculation below.
	int year = 157766400 / YEAR;
	int day  = ( 157766400 % YEAR ) / DAY;
	cout << endl << "Exercise 1 date: # of years " << year << " # of days: " << day << endl;


	// EXERCISE 3: What is the num of seconds representing January 2, 2001?  
	//		HINT: use multiplication.
	//		Fix the seconds calculation below.
	short seconds = (short) ( YEAR * 31 + DAY * 2);

	year  = seconds / YEAR;
	day   = ( seconds % YEAR ) / DAY;
	cout << endl << "Seconds to January 2, 2001: " << seconds << endl;
	cout << endl << "Exercise 2 date: # of years " << year << " # of days: " << day << endl;


	// EXERCISE 4: Store and print the seconds for January 2, 2038.
	int seconds2 = (int) ( 68 * YEAR + 19 * DAY );

	year  = seconds2 / YEAR;
	day   = ( seconds2 % YEAR ) / DAY;
	cout << endl << "Seconds to January 2, 2038: " << seconds2 << endl;
	cout << endl << "Exercise 3 date: # of years " << year << " # of days: " << day << endl;

}
