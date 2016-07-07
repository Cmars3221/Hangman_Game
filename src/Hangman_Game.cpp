//============================================================================
// Name        : Hangman_Game.cpp
// Author      : Christopher Mars
// Version     :
// Copyright   : Demo Series
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
#include <ctime>
#include <cctype>  // functions for converting characters.
using namespace std;

int main() {

	int MAX_WRONG = 8; //  max number of incorrect guesses allowed.

	vector<string>words;  //collection of possible words to guess.

	words.push_back("BANANA");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("RANGER");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());  //randomizing our vector.
	const string THE_WORD = words[0];    //after shuffle, the shuffled word at the 0 index is selected and equated
										 // to a const variable named THE_WORD
	int wrong = 0;                       //incorrect guesses
	string soFar(THE_WORD.size(), '-');  //word guessed so far. string created string object notation.  the randomized word selected size is the first param, and it will be filled with "-" character
											// imagine it being a husk for when the word is correctly guessed, then it will fill up with correct values.
	string used=""; 			         //letters already guessed. this will be filled with guessed letters...


	cout<<"Welcome..the game starts now.\n";

	while ((wrong <  MAX_WRONG) &&(soFar !=THE_WORD)){

		cout<<"You have "<<(MAX_WRONG-wrong) <<" guesses left\n";
		cout<<"You have used the following letters:\n"<<used<<endl;
		cout <<"\nThe word is currently :"<< soFar<<endl;


		//getting player input.

		cout <<"\n Enter your guess: ";
		char guess;
		cin >> guess;      //exactly what it means.
		guess = toupper(guess);   //converting player guess to upper case. via cctype class.  Secret words in our vector are uppercase.

		while(used.find(guess) !=string::npos){   //string member method for if guess is NOT found...
			 cout << "Here's what you used already:" <<guess <<endl;

			 cout <<"Enter your guess: "<<flush;
			 cin >>guess;
			 guess = toupper(guess);
		} //inner while loop.
			used+= guess;  // updating "used" with the uppercase letter the user guesses.   "" now contains a letter.



		if(THE_WORD.find(guess) !=string::npos){  //if you can find the letter guessed in the vector word
			cout <<" That's correct! <"<< guess <<">is in the word.\n";


		 //soFar will now be updated to include newly guessed letter
			for (int i = 0; i<THE_WORD.length(); ++i) {

				if(THE_WORD[i]==guess){    // matching the letter to the vector word's array.
					soFar[i] = guess;     //so far will mimic the placement of the correct letter parallel to THE_WORD.
				}
			}

		}

		else{
			cout <<"\n Sorry [" <<guess<< "]is not in the word!.\n";
			++wrong; //  wrong counter updates.
		}
	}  	 //outer while loop.
		// The shutdown.

		if(wrong ==MAX_WRONG){
			cout<<"You're out of guesses";
		}
		else{
			cout<<"\n Congrats you guessed all the letters!";
		}

			cout <<"\n The word was: "<<THE_WORD <<endl;








	return 0;
}
