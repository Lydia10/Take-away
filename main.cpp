#include <iostream>
#include <cstring>
#include "Game.h"
#include <stdlib.h>


int main(int argc, char* argv[]){
	std::string name1, name2;

		int computerOption = 0; //flag for computer player
		for(int i = 0; i < argc; ++i){
			if(strcmp(argv[i], "-c") == 0){
			   computerOption = 1;
			}
		}
		// deciding if player 2 is human or computer
		if(computerOption == 0){
			do{
				std::vector<int> num = getArguments(argc, argv);
				std::cout << "First player's name: ";
				std::cin >> name1;
				std::cout << "Second player's name: ";
				std::cin >> name2;
				std::cout << std::endl;
				display(num);
				playGame(name1, name2, num);
			}while(continuePlaying());
		}
		else {
			do{
				std::vector<int> num = getArguments(argc, argv);
				std::cout << "First player's name: ";
				std::cin >> name1;
				display(num);
				playCompGame(name1, num);
			}while(continuePlaying());
		}
		return 0;
}













