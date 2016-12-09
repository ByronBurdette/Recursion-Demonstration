
// Byron Burdette
// COP2551.001



/**********************************************************************************************************************************************************
***********************************************************************************************************************************************************
								The purpose of this program is to search a file of numbers for a particular number
								 entered by the user and to display whether or not that number exists in the file
***********************************************************************************************************************************************************
***********************************************************************************************************************************************************/






#include "recursiveMemberTest.h"												//	include the header file for the class "recursiveMemberTest"





/**********************************************************************************************************************************************************
***********************************************************************************************************************************************************
												THIS MARKS THE BEGINNING OF THE MAIN FUNCTION
***********************************************************************************************************************************************************
***********************************************************************************************************************************************************/

int main()
{
	recursiveMemberTest test;													//	declare object "test" of type "recursiveMemberTest"



	test.openFile();															//	open the file

	test.validateFile();														//	validate that the file was opened

	test.readFile();															//	store the contents of the file

	test.sortData();															//	sort the contents in ascending order

	test.setSearchRange();														//	the the inital range to be searched 

	test.promptUser();															//	prompt the user to enter a number

	test.getUserInput();														//	store the users input

	test.validateUserInput();													//	make sure the user entered good data

	test.convertInputToDbl();													//	convert the users data to a long double

	test.searchFile();															//	search the file for the number the user entered

	test.displayResults();														//	display whether or not the number exists in the file



	system("pause");															//	pause before terminating so the user can see the results
	return 0;																	//	terminate the program without errors
}
/**********************************************************************************************************************************************************
***********************************************************************************************************************************************************
														THIS MARKS THE END OF THE MAIN FUNCTION
***********************************************************************************************************************************************************
***********************************************************************************************************************************************************/