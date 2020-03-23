#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

//This string is called first to allow for user input, if it wasn't here I would have to put the function above the main function.
string getusername();

int main()
{
	//This is the maximum amount of tries that the person will have.
	const int MAX_WRONG = 8;
	//This is sim count
	const int MAX_SIMULATIONS = 10;
	//this is used for the do/while loop to allow for the player to play again.
	char again;

	//This is the title of the program
	cout << "/n/n***Welcome to the code breaker training program***/n/n";

	//This allows for user input
	string userName = getusername();

	//This tells the user hello and also it displays user name with in program.
	cout << "\nHello " << userName << " and welcome to your next training phase";
	cout << "\nMy name is the code breaker and I am here to see if you have waht it takes to become one.";

	//This is an explenation as to what they are going to be doing and why they are doing it.
	cout << "\nFirst things first, What is Keywords II? Well what this simulation does is evaluate you on your code breaking skills";
	cout << "\nThis training also will allow you to advance to the next step of training.";

	//I am telling the user about what to do with the game
	cout << "\nTo break the code word given, you are to come up with a number of leters. That will reveal the code word.";
	cout << "\nYou can come up with the keyword by simply guessing what ever letter to come up with the word, good luck ";


	
		//These are the ten words that I will be using for the code breaker training program
		//Each of the words are for the final result of the users guesses
		vector<string> words;
		words.push_back("WATCHING");
		words.push_back("HEARING");
		words.push_back("CHEATING");
		words.push_back("FORGIVEN");
		words.push_back("BLINDED");
		words.push_back("LYING");
		words.push_back("CRYING");
		words.push_back("SADNESS");
		words.push_back("DISAPPEAR");
		words.push_back("NIGHT");
	
	//This is for the play again loop
    do 
	{ 

		//This is where a random word is chosen
		srand(static_cast<unsigned int>(time(0)));
		//This is shuffling the words so it is not the same word each time
		random_shuffle(words.begin(), words.end());
		
		//This is for the guessed word
		const string THE_WORD = words[0];
		//This is the number of words that were guessed wrong
		int wrong = 0;
		//This is what the user has guessed so far
		string soFar(THE_WORD.size(), '-');
		//This displayes the letters that have been guessed
		string used = " ";

		//Create an int var to count the number of simulations being run starting at 1
		int count = 1;

			//Pick 3 new random words from your collection as the secret code word the recruit has to guess.

			//While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD) || (count > MAX_SIMULATIONS))
		{
			//This displays the simulation amount that is left for the user, starting from 10 to 1. for there last simulation trys.
			cout << "This is Simulation Number: " << (MAX_SIMULATIONS - count);
	
			//This displays The amount of wrong letters the player has guessed
			cout << "\n\n You have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left \n";

			//This shows what letters the player have already used
			cout << "\n You've used the following letters: \n" << used << endl;

			//This shows the user that you have this much of the word completed
			cout << "\nSo far, the word is:\n" << soFar << endl;


			//This is for user input for the users guesses
			char guess;
			cout << "\n\nEnter your guess: ";
			cin >> guess;
			guess = toupper(guess);

			//This is for the already guess loop
			while (used.find(guess) != string::npos)
			{

				//This is here for if the player has already guessed that letter
				cout << userName << "\n You've already guessed " << guess << endl;
				//This adds to the number of letters that have been guessed for the word
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			//This is for the guesses
			used += guess;

			//This is a statement for if they got the word right or wrong
			if (THE_WORD.find(guess) != string::npos)
			{

				//This is for if the user has got the word right
				cout << "That's right! " << userName << guess << " is in the word.\n";

				//This is for the guessed letters that were already for the word and displays the word but not the complete word
				//only the parts of the word they already have found
				for (int i = 0; i < THE_WORD.length(); ++i)
				{
					//This states if the word is already guessed and if not then what is guessed for the word so far.
					if (THE_WORD[i] == guess)
					{
						//This is for what the word has so far not the complete word
						soFar[i] = guess;
					}

				}
			}
			//Else, if they get it wrong then. The below will be displayed.
			else
			{

				//This displays if the player got the letter wrong
				cout << "Sorry, " << userName << guess << " isn't in the word.\n";

				//This is for wrong inputs
				++wrong;
			}



		}
		//This is a if statement for if the player has got to many of the letters wrong
		if (wrong == MAX_WRONG)
		{
			//This displays that they have lost the game
			cout << "\nOh no! " << userName << " you've have been hung";
		}

		//If they were to get the letters right and uncover the word then they would get a win
		else
		{
			//This displays to the user that they have got the word right
			cout << "\nGood job! " << userName << " you have guessed the words corretly";
		}

		//This is then displayed to tell the user what the word is
		cout << "\nThe word was " << THE_WORD << endl;

		//This is to ask the user if they wish to play again
		cout << userName << "\n\n Do you wish to do another simulation (Y/N)\n\n";
		//This allows for user input
		cin >> again;

	//This is for if the player plays again		
	if (again)
	{
		//This displays the text if the player plays again
		cout << "Thank you for playing again " << userName;
	}
	//This is for if the player leaves
	else
	{
		//This Displays the text and player name if they leave
		cout << "Thank you for playing " << userName;
	}

	//this is for user input if the wish to quit then 'Y' or 'y' and 'N' or 'n'
	} while (again == 'Y' || again == 'y');
	//This pauses the system at the end of the loop
	system("pause");
	return 0;
}

//This is a string that is called to get the users name
string getusername()
{
	//the string that is used to call the function
	string userName;
	//This displays what there will be when the type it in
	cout << "\nWhat is your name: ";
	//This is for getting the userName that was input and allowing it to display grabbing where ever said userName is called
	
	//returns the userName
	return userName;
}