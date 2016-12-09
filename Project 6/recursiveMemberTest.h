
// Byron Burdette
// COP2551.001



/*************************************************************************************************************************************************
**************************************************************************************************************************************************
											CLASS SPECIFICATION FILE FOR THE CLASS "recursiveMemberTest"
**************************************************************************************************************************************************
*************************************************************************************************************************************************/






/**********************************************					 PREPROCESSOR DIRECTIVES				*****************************************/
#ifndef RECURSIVEMEMBERTEST_H								//	include guard checks if "RECURSIVEMEMBERTEST_H" has already been defined in the program
#define RECURSIVEMEMBERTEST_H								//	includes "RECURSIVEMEMBERTEST_H" if its not already

#include<iostream>											//	includes the library for standard i/o stream objects
#include<vector>											//	includes the library for vectory types
#include<string>											//	includes the library for string types
#include<fstream>											//	includes the library for operating on file stream objects
/*************************************************************************************************************************************************/



using namespace std;										//	lifts all entities from the standard namespace into the global namespace




class recursiveMemberTest									//	declares class "recursiveMemberTest
{
private: ifstream inputFile;								//	declares an input file object
		 string fileName = "recurData.txt";					//	declares a string to hole the filepath of the input file
		 vector<double> data;								//	declares a vectore to store the data from the input file
		 string userInput;									//	declares a string to hold the users input
		 int first;											//	declares an int to hold the lower value for binary searching
		 int last;											//	declares and int to hold the upper value for binary searching
		 int mid;											//	decalres an int to hold the middle value for binary searching
		 long double sentinel;								//	declares a long double to hold the converted users input
		 
public: void openFile();									//	prototype for function which opens the file
		void validateFile();								//	prototype for function that validates whether the file was opened correctly
		void readFile();									//	prototype for function which stores the file in a vector "data"
		void sortData();									//	prototype for function which sorts "data" in ascending order
		void swap(double&, double&);						//	prototype for function which handles swapping data during sorting
		void setSearchRange();								//	prototype for function which sets the initial range to search for a number in the data
		void promptUser();									//	prototype for function which prompts the user to enter a number 
		void getUserInput();								//	prototype for function which reads the users input
		void validateUserInput();							//	prototype for function which validates the users input
		void rePromptUser();								//	prototype for function which re-prompts the user for input while offering clarification
		void convertInputToDbl();							//	prototype for function which converts the users input to a long double
		void searchFile();									//	prototype for function which searches "data" for the number entered by the user
		void displayResults();								//	prototype for function which displays whether or not the number was found in "data"
};
#endif														//	skips to here if "RECURSIVEMEMBER_H" was already included in the program

/************************************************************************************************************************************************
*************************************************************************************************************************************************
											THIS MARKS THE END OF THE CLASS SPECIFICATION FILE
*************************************************************************************************************************************************
*************************************************************************************************************************************************/