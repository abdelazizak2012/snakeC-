#include<iostream>
#include<vector>
#include <thread>
#include <windows.h>
#include <random>


using namespace std;
char x = 'd';
bool down = false;
bool newFood = true;
int big = 1;
void task1(string msg)
{
	while (true) {
		cin >> x;
		if (x == 'd' || x == 'a') {
			down = false;
		}
		else {
			down = true;
		}
	}
	
	
	
}


int main() {
	thread t1(task1, "Hello");
	//t1.join();
	vector<vector<char>> map
	{ 
	{ '*', '*', '*','*','*' },
	{ '*', '*', '*','*','*' },
	{ '*', '*', '*','*','*' },
	{ '*', '*', '*','*','*' },
	{ '*', '*', '*','*','*' }
	};

	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<> dist(0, 4);
	int foodX = 0;
	int foodY = 0;
	int counterX = 0; 
	int counterY = 0;
	while (true) {
		map = {
		{'*', '*', '*','*','*'},
		{'*', '*', '*','*','*'},
		{'*', '*', '*','*','*'},
		{'*', '*', '*','*','*'},
		{'*', '*', '*','*','*'}
		};
		if (newFood) {
			 foodX = dist(mt);
			 foodY = dist(mt);
			 newFood = false;
		}
		map.at(foodY).at(foodX) = '+';
		

		if (counterX == -1) {
			counterX = 4;
		}
		if (counterY == -1) {
			counterY = 4;
		}
		if (counterX == 5) {
			counterX = 0;
		}
		if (counterY == 5){
			counterY = 0;
		}
		if (down) {
			map.at(counterY).at(counterX) = '-';
			if (counterX == foodX && counterY == foodY) {
				newFood = true;
				big++;
			}
			if (x == 'w') {
				counterY--;
			}
			else if (x == 's') {
				counterY++;
			}
		}
		else {
			if (counterX == foodX && counterY == foodY) {
				newFood = true;
				big++;
			}
			map.at(counterY).at(counterX) = '-';
			if (x == 'd') {
				counterX++;
			}
			else if (x == 'a') {
				counterX--;
			}
		}
		
		
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map.at(i).size(); j++) {
				cout << map.at(i).at(j);
			}
			cout << endl;
		}
		Sleep(1000);
		system("CLS");
		Sleep(1000);
		
		
		
	}

	return 0;
}