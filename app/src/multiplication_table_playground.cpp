#include <iostream>
#include "multiplication_table_playground.h"
#include "multiplication_table.h"

using namespace std;

void multiplication_table_playground::play() {
	using namespace multiplication_table;

	//multiplication_table::MultiplicationLine<10, 9> s;
	//std::cout << reinterpret_cast<int*>(&s)[9] << std::endl;

	constexpr int length = 10;
	constexpr int width = 9;

	multiplication_table::MultiplicationTable<length, width> ss;

	for (int i = 0; i <= width; i++) {
		cout << "i = " << i << endl;
		for (int j = 0; j < length; j++) {
			cout << reinterpret_cast<int*>(
				&reinterpret_cast<multiplication_table::MultiplicationLine<length, width>*>(&ss)[j]
			)[i] << endl;
		}
		cout << "====" << endl;
	}
}