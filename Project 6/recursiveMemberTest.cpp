
// Byron Burdette
// COP2551.001



/************************************************************************************************************************************************
*************************************************************************************************************************************************
												MEMBER FUNCTION DEFINITIONS FOR CLASS "Cstring"
*************************************************************************************************************************************************
*************************************************************************************************************************************************/






#include "recursiveMemberTest.h"													//	include the header file for class "recursiveMemberTest"






/***********************************************************************************************************************************************
											THIS MARKS THE BEGINNING OF THE "openFile" FUNCTION

											The purpose of this function is to open the file
***********************************************************************************************************************************************/
void recursiveMemberTest::openFile()
{
	inputFile.open(fileName);														//	open the file
}
/***********************************************************************************************************************************************
												THIS MARKS THE END OF THE "promptUser" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
											THIS MARKS THE BEGINNING OF THE "validateFile" FUNCTION

		The purpose of this function is to validate that the file was opened properly, and to terminate the program if it was not
***********************************************************************************************************************************************/
void recursiveMemberTest::validateFile()
{
	if (!inputFile)																	//	if the file couldn't be opened...
	{
		cerr << "Error. Cannot open file. Terminating Program...";					//	display an error message
		system("pause");															//	pause so the user can read the message
		exit(555);																	//	terminate the program with an error
	}
}
/***********************************************************************************************************************************************
												THIS MARKS THE END OF THE "validateFile" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
										THIS MARKS THE BEGINNING OF THE "readFile" FUNCTION

								The purpose of this function is to store contents of the file in a vector
***********************************************************************************************************************************************/
void recursiveMemberTest::readFile()
{
	double num;																		//	declare a double to hold the current value

	while (inputFile >> num)														//	read in the first value in the file and stor it in "num"
		data.push_back(num);														//	store whatever's in "num" in the vector "data"
}
/***********************************************************************************************************************************************
												THIS MARKS THE END OF THE "readFile" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
											THIS MARKS THE BEGINNING OF THE "sortData" FUNCTION

							The purpose of this function is to sort the data sored in the vector in ascending order
***********************************************************************************************************************************************/
void recursiveMemberTest::sortData()
{
	for (int i = 1; i < data.size(); i++)											//	loop through the whole vector
	{
		for (int j = 0; j < data.size() - 1; j++)									//	check the currecnt value against ever value in the vector
		{
			if (data[j] > data[j+1])												//	if the current value is > the following value	
				swap(data[j], data[j+1]);											//	swap the values
		}
	}
}
/***********************************************************************************************************************************************
												THIS MARKS THE END OF THE "sortData" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
												THIS MARKS THE BEGINNING OF THE "swap" FUNCTION

					The purpose of this function is to take two values stored in the vecotr and have them switch places
***********************************************************************************************************************************************/
void recursiveMemberTest::swap(double &a, double &b)
{
	double temp;																	//	declare a temp variable to facilitate swapping

	temp = a;																		//	store the first value in "temp"
	a = b;																			//	store the second value in the first variable
	b = temp;																		//	store the first value in the second variable
}
/***********************************************************************************************************************************************
												THIS MARKS THE END OF THE "swap" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
										THIS MARKS THE BEGINNING OF THE "setSearchRange" FUNCTION

	  The purpose of this function is to set the inital range of elements in the vector to be searched for the value entered by the user
***********************************************************************************************************************************************/
void recursiveMemberTest::setSearchRange()
{
	first = 0;																		//	set the lower limit to the first element in the vector
	last = data.size();																//	set the upper limit to the last element in the vactor
}
/***********************************************************************************************************************************************
										THIS MARKS THE END OF THE "setSearchRange" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
											THIS MARKS THE BEGINNING OF THE "promptUser" FUNCTION

										The purpose of this function is to prompt the user for input
***********************************************************************************************************************************************/
void recursiveMemberTest::promptUser()
{
	cout << "Enter a number and I'll check and see if it's in the file: ";			//	prompt the user to enter a number
}
/***********************************************************************************************************************************************
											THIS MARKS THE END OF THE "promptUser" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
										THIS MARKS THE BEGINNING OF THE "getUserInput" FUNCTION

		The purpose of this function is to store the user input. It is stored as a string to better facilitate bad data checking, later
***********************************************************************************************************************************************/
void recursiveMemberTest::getUserInput()
{
	cin.sync();																		//	clear out the buffer
	cin.clear();																	//	reset the io state

	getline(cin, userInput);														//	store the whole line in "userInput"
}
/***********************************************************************************************************************************************
											THIS MARKS THE END OF THE "getUserInput" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
									THIS MARKS THE BEGINNING OF THE "validateUserInput" FUNCTION

The purpose of this function is to ensure the user input good data, i.e., a rational number in decimal notation (this function is potentially
indirectly recursive)
***********************************************************************************************************************************************/
void recursiveMemberTest::validateUserInput()
{
	int numOfPeriods = 0;															//	a variable to track how many periods the user entered

	for (int i = 0; i < userInput.size(); i++)										//	loop through all of the users input
	{
		if (userInput[i] == '.')													//	if the current char is a period...
			numOfPeriods++;															//	then add 1 to the sum of periods in the input

		if (numOfPeriods > 1 || (userInput.size() == 1 && userInput[0] == '.'))		//	if the first char was a period or there are > 1 periods
			rePromptUser();															//	re-prompt the user to enter good data
		else if (!isdigit(userInput[i]) && userInput[i] != '.')						//	if the current char is not a number or a period
			rePromptUser();															//	re-prompt the user to enter good data
	}
}
/***********************************************************************************************************************************************
											THIS MARKS THE END OF THE "validateUserInput" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
											THIS MARKS THE BEGINNING OF THE "rePromptUser" FUNCTION

		The purpose of this function is to display an alternative prompt with further clarification when the user enters bad data
***********************************************************************************************************************************************/
void recursiveMemberTest::rePromptUser()
{
	cout << endl << "You have to enter a rational number in decimal notation: ";	//	display a message clarifying the users directions
	getUserInput();																	//	get the users input
	validateUserInput();															//	validate the users input
}
/***********************************************************************************************************************************************
											THIS MARKS THE END OF THE "rePromptUser" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
										THIS MARKS THE BEGINNING OF THE "convertInputToDbl" FUNCTION

						The purpose of this function is to convert the stored, user input from a string to a long double
***********************************************************************************************************************************************/
void recursiveMemberTest::convertInputToDbl()
{
	sentinel = stold(userInput);													//	convert the users input to a long doulbe and store it
}
/***********************************************************************************************************************************************
											THIS MARKS THE END OF THE "convertInputToDbl" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
											THIS MARKS THE BEGINNING OF THE "searchFile" FUNCTION

		The purpose of this function is to search the vector for the number entered by the user. This function is executed recursively
***********************************************************************************************************************************************/
void recursiveMemberTest::searchFile()
{
	while (first <= last && sentinel != data[mid] && first != data.size())
	{
		mid = (first + last) / 2;													//	calculate the middle of the upper and lower limits

		if (sentinel > data[mid])													//	if the value in the middle is less the the users input
		{
			first = mid + 1;														//	move the lower limit to the middle
			searchFile();															//	search the file with the new range
		}
		else if (sentinel < data[mid])												//	if the value in the middle is greater than the users input
		{
			last = mid - 1;															//	move the upper limit the the middle
			searchFile();															//	search the file with the new range
		}
	}
}
/***********************************************************************************************************************************************
											THIS MARKS THE END OF THE "searchFile" FUNCTION
***********************************************************************************************************************************************/




/***********************************************************************************************************************************************
										THIS MARKS THE BEGINNING OF THE "displayResults" FUNCTION

					The purpose of this function is to display whether or not the users input number exits in the file
***********************************************************************************************************************************************/
void recursiveMemberTest::displayResults()
{
	if (sentinel == data[mid])														//	if the number was found
		cout << endl << "Found it!" << endl << endl ;								//	display a message saying it was found
	else																			//	otherwise, it was not found
		cout << endl << "That's not in the file" << endl << endl;					//	display that it was not found
}
/***********************************************************************************************************************************************
												THIS MARKS THE END OF THE "displayResults" FUNCTION
***********************************************************************************************************************************************/