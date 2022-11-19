// DeCypher version 1.0
// by Daniel Chavez

//include libraries
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include "main.h"

//this functions return type is string
std::string GetUserName();


int main()
{ //start of main function

	//create int variable for number of decryptions needed to win or lose
	//3 words aka attempts make up one game
	//const makes variable non editable aka read only
	const int NEEDED_DECRYPTIONS = 3;

	//set number of decryptions
	int decryptions = 0;

	//bool variable created for playAgain loop
	bool playAgain = false;

	do
	{
		// Welcome player
		DisplayIntro();

		//gets the users input/name
		std::string userNameMain = GetUserName();

		// Loop for every turn
		for (int i = 0; i < 3; i++)
		{ //start scope operator 
			//maximum number of failed attempts
			//const makes the variable read only.
			const int MAX_FAILED_ATTEMPTS = 6;

			// vector of strings
			// vector is a dynamic array meaning it can grow and shrink as needed.
			std::vector<std::string> wordList;

			// 15 words added to wordList vector
			wordList.push_back("GALAXY");
			wordList.push_back("ASTEROID");
			wordList.push_back("METEOR");
			wordList.push_back("COMET");
			wordList.push_back("MOON");
			wordList.push_back("PLANET");
			wordList.push_back("STAR");
			wordList.push_back("SATELLITE");
			wordList.push_back("SPACESHIP");
			wordList.push_back("INTERSTELLAR");
			wordList.push_back("NOVA");
			wordList.push_back("ORBIT");
			wordList.push_back("TELESCOPE");
			wordList.push_back("COSMOS");
			wordList.push_back("ASTRONAUT");

			// Seeds the random num generator
			srand(static_cast<unsigned int>(time(0)));
			//shuffle the wordList order
			std::random_shuffle(wordList.begin(), wordList.end());

			//the current word to guess is the first word in the vector
			const std::string WORD_TO_DECRYPT = wordList[0];

			//variable that keeps track of incorrect attempts
			int failedAttempts = 0;


			// Word guessed so far
			//the '_' is put in place of the characters until guessed correctly
			std::string WordSoFar(WORD_TO_DECRYPT.size(), '*');


			// Letters already guessed
			std::string attempted = "";

			//keeps track of decryption levels
			decryptions = i + 1;
			std::cout << "\nDecrypting security code: " << decryptions << " of " << NEEDED_DECRYPTIONS << " to gain access.\n" << std::endl;

			//main game loop
			while ((failedAttempts < MAX_FAILED_ATTEMPTS) && (WordSoFar != WORD_TO_DECRYPT))
			{
				// Display the current status for the user aka hacker 
				std::cout << "Attempts left: " << (MAX_FAILED_ATTEMPTS - failedAttempts) << "\nbefore security is alerted.\n";
				std::cout << "\nLetters used: <  " << attempted << "  >\n";
				std::cout << "\nPartially decrypted code:\n <  " << WordSoFar << "  >\n";

				//stores hackers guess
				char guess;
				//tell the hacker to guess a letter
				std::cout << "\n\nType a letter to decrypt: ";
				//get the players guess
				std::cin >> guess;
				//make the guess uppercase
				guess = toupper(guess);


				//created while loop to check the guessed letter
				while (attempted.find(guess) != std::string::npos) //npos means no position
				{
					//tell the user/hacker they already guessed this letter and to guess again
					std::cout << "\nYou have already attempted letter: " << guess << std::endl;
					std::cout << "Try another letter: ";
					//get hackers new guess
					std::cin >> guess;
					//makes guess uppercase
					guess = toupper(guess);
				}

				//adds the guess to the list of attempted letters
				attempted += guess; //same as attempted = attempted + guess


				//if the 'guess'ed letter is in the word, it means they guessed right.
				if (WORD_TO_DECRYPT.find(guess) != std::string::npos)
				{
					//display to hacker they guessed correctly
					std::cout << "\nWell done. " << "Letter '" << guess << "' is in the security code.\n";

					//update WordSoFar to include newly guessed letter
					for (int i = 0; i < WORD_TO_DECRYPT.length(); i++)
					{
						//if the guess is in the word
						if (WORD_TO_DECRYPT[i] == guess)
						{
							WordSoFar[i] = guess;
						}
					}
				}
				//else the guessed letter is not in the word, it means they guessed wrong.
				else
				{
					//display to hacker they guessed incorrectly
					std::cout << "\nNegative. " << guess << " is not in the security code.\n\n";

					//increment the failedAttempts
					++failedAttempts;
				}
			}

			//when player runs out of attempts
			if (failedAttempts == MAX_FAILED_ATTEMPTS)
			{
				//tell the hacker they lost
				std::cout << "\n\nYou have failed this level of hacking into Reaktech Industries.\n";
				//tell the hacker what the word was 
				std::cout << "\nThe security code was " << WORD_TO_DECRYPT << ".\n" << std::endl;
			}
			//if user guessed the security code word correctly
			else
			{
				//user has cracked the code
				std::cout << "\nExcellent work, recruit. The Underground Cypher's will reward you for hacking passed this security level\nof Reaktech Industries.\n";
			}
			//tells user to press a key to exit
			system("pause");

		} //end scope operator


		//prompt user that 3 codes have been attempted
		std::cout << "\n\nAll three codes have been attempted. Hack over.\n" << std::endl;
		system("pause");

		//ask user if they would like to play again
		std::cout << "Would you like to DeCypher Reaktech's security system again? (y/n): ";

		//
		char userChoice;

		//gets users input
		std::cin >> userChoice;
		userChoice = toupper(userChoice);

		//if user input is not Y
		if (userChoice != 'Y')
		{
			//set playAgain to false to exit loop
			playAgain = false;
		}
		//if input IS Y
		else
		{
			//set playAgain to true
			playAgain = true;
		}


	} while (playAgain == true);


	//display outro
	std::cout << "\n\nGood luck on your hacking journey recruit. Thank you for playing!\n" << std::endl;
	system("pause");

} //end of main function

void DisplayIntro()
{
	std::cout << "\n\n\t *** Welcome to the Underground Cyphers ***\n\n\n";
	std::cout << "It is the year 2055. The world has become fully digital. You are a new recruit to a cybercriminal\n";
	std::cout << "faction. They created and use their program called 'DeCypher' to gain access to companies mainframes.\n";
}

std::string GetUserName() {
	//get the users name

	/* things to note :
	datatype of the variable is std::string
	variable name is userName */
	std::string userName;

	//asks the user for input by displaying a prompt
	std::cout << "\nFor a personalized experience, please enter your name: ";

	//gets the users name and stores it in the vaiable userName
	std::getline(std::cin, userName);

	//Introduces the user with a prologue discription and also by name
	std::cout << "\n" << userName << ", your first task is to hack into ReakTech Industries using the UC's program.\n" << std::endl;
	std::cout << "\n*" << userName << " HAS RECEIVED INTEL THAT THE CODES ARE RELATED TO: SPACE*\n";

	//returns the users name
	return userName;
}