#include <iostream>
#include <string>
#include "printlib.h"
#include "tuplelib.h"
#include "multiplication_table.h"

using namespace std;
using namespace tuplelib;
using namespace printlib;
using namespace multiplication_table;

int main(int argc, char *argv[]) {
	cout << Table<10>::value << endl;
	//calc<1, 10, 1, 9>();
	

	//Tuple<int, char> t = makeTuple(10, 's');
	//print(get<0>(t), get<1>(t), 345, 45.6);

	system("pause");

	return 0;
}