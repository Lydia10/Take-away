// Jiao Ma
// student ID: 5550045131

#include <iostream>
#include <cstring>
#include "Game.h"
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <unistd.h>
#include <vector>

void displayOptions(){
	std::cout << "Usage: ./take-away [-h] [-c] [-p # piles] [-s # stones]\n\n\n";
	std::cout << "Options:\n-h    Show this text."
			  << "\n-c    Make player two the computer. Default = false.\n"
			  << "-p    Manually set the starting number of piles in the game.\n"
			  << "-s    Manually set the starting number of stones in each pile.\n"
			  << "      Max values for piles and stones: 9\n" << "      Min values for piles and stones: 2\n";
}

void displayUsage(){
	std::cout << "\nUsage: ./take-away [-h] [-c] [-p # piles] [-s # stones]\n";
}

void displayRange(){
	displayUsage();
	std::cout << "The minimum value for piles and stones is 2, and the maximum value is 9.\n";

}
std::vector<int> getArguments(int argc, char* argv[]){
	char *svalue = NULL;
	char *pvalue = NULL;
	int sflag = 0;
	int pflag = 0;
	int index;
	int c;
	opterr = 0;
	int cflag = 0;

	while((c = getopt(argc, argv, "s: p: h c")) != -1){
		switch (c)
		{
		case 's':
			sflag = 1;
			svalue = optarg;
			break;
		case 'p':
			pflag = 1;
			pvalue = optarg;
			break;
		case 'h':
			//call function to display help
			displayOptions();
			exit(0);
			break;
		case 'c':
			cflag = 1;
			break;
		case '?':
			if (optopt == 's'){
				fprintf(stderr, "Option -%c requires an argument\n", optopt);
				displayUsage();
				exit(0);
			}
			if (optopt == 'p'){
				fprintf(stderr, "Option -%c requires an argument\n", optopt);
				displayUsage();
				exit(0);
			}
			else if(isprint(optopt)){
				fprintf(stderr, "Unknown option '-%c'.\n", optopt);
				displayUsage();
				exit(0);
			}
			else{
				fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
				displayUsage();
				exit(0);
			}
		default:
			abort ();
		}
	}
	for(index = optind; index < argc; index++){
		printf("Non-option argument %s\n", argv[index + 1]);
		displayUsage();
	}

	optind = 1; //reset getopt. Otherwise multiple calls to this function won't work

	std::vector<int> numbers(0);
	int pileNum = 0;
	const int min = 2, max = 9; // setting range of allowed number of piles and stones

	if(argc == 1){
		pileNum = setRandomNum(min, max);
		for(int x = 0; x < pileNum; ++x){
			numbers.push_back(setRandomNum(min, max));
		}
	}
	else if(cflag == 1 && argc == 2){
			pileNum = setRandomNum(min, max);
			for(int x = 0; x < pileNum; ++x){
				numbers.push_back(setRandomNum(min, max));
			}
		}


	else if(cflag == 1 && pflag == 1 && sflag == 0){
			if(atoi(pvalue) < min || atoi(pvalue) > max ){
				displayRange();
				exit(0);
			}
			pileNum = atoi(pvalue);
			for(int x = 0; x < pileNum; ++x){
				numbers.push_back(setRandomNum(min, max));
			}
		}

	else if(cflag == 1 && pflag == 0 && sflag == 1){
			pileNum = setRandomNum(min, max);
			if(atoi(svalue) < min || atoi(svalue) > max){
				displayRange();
				exit (0);
			}
			for(int x = 0; x < pileNum; ++x){
				numbers.push_back(atoi(svalue));
			}

		}
	else if(cflag == 1 && pflag == 1 && sflag == 1){
			if(atoi(pvalue) < min || atoi(svalue) < min || atoi(pvalue) > max || atoi(svalue) > max){
				displayRange();
				exit (0);
			}
			pileNum = atoi(pvalue);
			for(int x = 0; x < pileNum; ++x){
				numbers.push_back(atoi(svalue));
			}
		}


	else if(pflag == 1 && sflag == 0){
		if(atoi(pvalue) < min || atoi(pvalue) > max ){
			displayRange();
			exit(0);
		}
		pileNum = atoi(pvalue);
		for(int x = 0; x < pileNum; ++x){
			numbers.push_back(setRandomNum(min, max));
		}
	}

	else if(pflag == 0 && sflag == 1){
		pileNum = setRandomNum(min, max);
		if(atoi(svalue) < min || atoi(svalue) > max){
			displayRange();
			exit (0);
		}
		for(int x = 0; x < pileNum; ++x){
			numbers.push_back(atoi(svalue));
		}

	}
	else if(pflag == 1 && sflag == 1){
		if(atoi(pvalue) < min || atoi(svalue) < min || atoi(pvalue) > max || atoi(svalue) > max){
			displayRange();
			exit (0);
		}
		pileNum = atoi(pvalue);
		for(int x = 0; x < pileNum; ++x){
			numbers.push_back(atoi(svalue));
		}
	}

	return numbers;

}











