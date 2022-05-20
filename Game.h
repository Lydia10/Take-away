#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include <string>
#include <unistd.h>


int setRandomNum(int x, int y);
std::vector<int> getArguments(int argc, char* argv[]);
void display(std::vector<int> &num);
void play(std::string name, std::vector<int> &num);
void playGame(std::string name1, std::string name2, std::vector<int> &num);
int continuePlaying();
void playComp(std::vector<int> &num);
void playCompGame(std::string name1, std::vector<int> &num);


#endif
