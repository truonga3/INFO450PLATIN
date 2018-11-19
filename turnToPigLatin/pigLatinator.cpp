//INFO450PLATIN HW ASSIGNMENT
//Put together by Alexander Truong

#define _CRT_SECURE_NO_WARNINGS // a work around method in order to use strcpy 
#include <iostream>
#include <cstring>  // the power of cstrings to store and process words
using namespace std;

const int CHARACTERLIMIT = 50; //our constant with 50 character limit 

bool vowelChecker(char input);
int translateToarray(char input[CHARACTERLIMIT], char array[CHARACTERLIMIT]); 


int main() //our main function with greeting and do while loop so the user can translate more than once.
{
	char answer; 

	do
	{
		char input[CHARACTERLIMIT] = "";  //ctrings initialized with a blank
		char array[CHARACTERLIMIT] = ""; 

		cout << "--Welcome to the: Pig Latin Word Translator--" << endl;           
		cout << "Enter a word:" << endl;
		cin.getline(input, CHARACTERLIMIT); //store as c string, limit 50 
		cout << endl;

		translateToarray(input, array);

		cout << endl;
		cout << "Would you like to translate another word?" << endl;
		cout << "Enter Y or y, otherwise press any key to exit" << endl;
		cin >> answer;

		if (answer != 'y' && answer != 'Y')
		{
			cout << "Good Bye." << endl; 
			system("pause");
		}

		cin.ignore(CHARACTERLIMIT, '\n'); //ignore and clear needs to be used, in class we explain the reason why we need ignore and clear otherwise we get a "enter" cin vs. getline error
		cin.clear();                      //and it won't print correctly

	} while (answer == 'Y' || answer == 'y'); 
	return 0;
}

bool vowelChecker(char input) //this returns true on false depending on if it detects a vowel
							  //the translate ToPigLatin fuction uses this function to read for vowels in the first letter of the input 
{
	char letter[10] = { 'a','e','i','o','u','A','E','I','O','U' };
	int i;

	for (i = 0; i < 10; i++)
	{
		if (input == letter[i])

			return true;
	}
	return false;
}

int translateToarray(char input[CHARACTERLIMIT], char array[CHARACTERLIMIT]) //translate to pig latin function
{
	int replace, i;

	if (atoi(input) || input[0] == '\0') // a handy function that will parse a c string as an int
	{
		cout << "ERROR" << endl;
		return -1;
	}

	else if (input[2] == '\0') //if at the third position we see a null. We can't translate a letter if it has 2 or less letters. 
	{
		strcpy(array, input);  //Fills the char array dest with the content of string src. 
		cout << "Word:" << "'" << array << "'" << " remains the same." << endl;
		return 0;
	}

	else if //work around for case sensitivity if user enters an article
		    //holes here if the user decides to use awkard lettering
		   (
		      (strstr(input, "and") && strlen(input) == 3) //Returns a temporary string with a trade identifier.
		   || (strstr(input, "for") && strlen(input) == 3) 
		   || (strstr(input, "but") && strlen(input) == 3)
		   || (strstr(input, "yet") && strlen(input) == 3)
		   || (strstr(input, "And") && strlen(input) == 3) 
		   || (strstr(input, "For") && strlen(input) == 3)
           || (strstr(input, "But") && strlen(input) == 3)
     	   || (strstr(input, "Yet") && strlen(input) == 3)
	        )
	{
		strcpy(array, input);
		cout << "Word:" << "'" << array << "'" << " remains the same." << endl;
		return 0;
	}

	else if (vowelChecker(input[0])==true) //uses the vowel checker function to iterate through vowels and if it returns true append an ay immediately
	{
		strcat(array, input);
		strcat(array, "ay");
		cout << "translated: " << array << endl;
		return 0;
	}

	else //after it checks through categories for if it contains a number, if it has a word that has 2 or less letters, if it has an article, if it starts with a vowel, replace the 
		//first letter of the c string and append it to the end and add an ay. And print.
	{
		replace = strlen(input) - 1;
		for (i = 1; i <= replace; i++)
		{
			array[i - 1] = input[i];
		}
		array[strlen(input) - 1] = input[0];
		strcat(array, "ay");
		cout << "translated: " << array << endl;
		return 0;
	}

	return 0;
}

