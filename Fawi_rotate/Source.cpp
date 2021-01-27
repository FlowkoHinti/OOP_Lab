
#include "RString.h"
#include <chrono>
#include <thread>
#include <iostream>

int main() {
	rStr str("Ja Moin!!!");
	char c;
	 int x= 70;
	while (1) {
		//Gegen den Urzeigersinn
		str++;
		//im Uhrzeigersinn
		//str--;

		std::this_thread::sleep_for(std::chrono::milliseconds(x));
	}


}