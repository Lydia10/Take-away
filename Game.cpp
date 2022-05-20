// Jiao Ma
// student ID: 5550045131

#include "Game.h"
#include <iostream>
#include <vector>
#include <random>
#include <cstring>
#include <limits>


int setRandomNum(int x, int y){
	 std::random_device r;
	 std::default_random_engine eng(r());  // make a random number generator
	 return std::uniform_int_distribution<int> {x, y} (eng);
}



void display(std::vector<int> &num){
	for(size_t i = 0; i < num.size(); ++i){
		std::cout << "Heap " << i + 1 << " [" << num[i] << "]:    ";
	    for(int j = 0; j < num[i]; ++j){
	    	std::cout << "*";
	    }
		std::cout << std::endl;
	}
}



void play(std::string name, std::vector<int> &num){
		size_t heap = 0;
		int stones = 0;

		std::cout << name << "'s turn\n";
		std::cout << "Which heap?\n";

		// validate input, only integers are allowed
		while(!(std::cin >> heap)){
			std::cout << "Error. Enter a number: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // without this characters cause infinite loops
		}
		while(heap < 1 || heap > num.size()){
			std::cout << "No such heap. Try again\n";
			std::cin >> heap;
		}
		std::cout << "How many stones?\n";
		while(!(std::cin >> stones)){
			std::cout << "Error. Enter a number: ";
			std::cin.clear();
			std::cin.ignore(123, '\n');
		}

		while(stones > num[heap-1] || stones < 1){
			std::cout << "Invalid input. Try again.\n";
			std::cin >> stones;
		}

		num[heap-1] = num[heap-1] - stones;

		if(num[heap-1] == 0){
			num.erase(num.begin() + (heap-1));
		}
		std::cout << "\n";
		display(num);
}

void playGame(std::string name1, std::string name2, std::vector<int> &num){
	std::string winner = " ";
	while(!num.empty()){
		play(name1,num);
		if(num.empty()){
			winner = name1;
			break;
		}
		winner = name1;
		std::cout << "\n";
		play(name2,num);
		if(num.empty()){
			winner = name2;
		}
		std::cout << "\n";
	}


	std::cout << winner << " wins!" << std::endl << std::endl;
}

void playCompGame(std::string name1, std::vector<int> &num){
	std::string winner = " ";
	while(!num.empty()){
		play(name1,num);
		if(num.empty()){
			winner = name1;
			break;
		}
		winner = name1;
		std::cout << "\n";
		std::string name2 = "HAL 10000";
		std::cout << name2 << " 's turn";
		playComp(num);
		if(num.empty()){
			winner = name2;
		}
		std::cout << "\n";
	}


	std::cout << "\n" << winner << " wins!" << std::endl;
}

void playComp(std::vector<int> &num){
	int heap =(int)(num.size());
	int randomStone = num[0];
	int randomHeap = 1;
	if(heap == 1){ // if there is only one pile left, the computer takes all stones and wins
		num.pop_back();
	}
	else{
		randomHeap = setRandomNum(1, heap);
		randomStone = setRandomNum(1, num[randomHeap - 1]);
		num[randomHeap - 1] = num[randomHeap - 1] - randomStone;

		if(num[randomHeap - 1] == 0){
			num.erase(num.begin() + (randomHeap -1));
		}
	}
	std::cout << "\n";
	std::cout << "HAL 10000 removed " << randomStone << " stone(s) from heap " << randomHeap << std::endl << std::endl;
	display(num);
	std::cout << std::endl;
}


int continuePlaying(){
	char answer;
	std::cout << "\n\nPlay another game? [y/n]" ;
	std::cin >> answer;
	if(answer == 'y' || answer == 'Y'){
		return 1;
	}
	return 0;
}




















