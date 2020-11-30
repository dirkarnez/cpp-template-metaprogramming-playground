#include <iostream>
#include <string>
#include <array>
#include "printlib.h"
#include "tuplelib.h"
#include "multiplication_table_playground.h"
#include "time_slot_playground.h"
#include "smart_pointers_playground.h"
#include "lookup_table.h"

using namespace std;
using namespace tuplelib;
using namespace printlib;

template <typename T>
auto get_value(T t) {
	if constexpr (std::is_pointer_v<T>)
		return *t;
	else
		return t;
}

//cout << Table<10>::value << endl;
//calc<1, 10, 1, 9>();


//Tuple<int, char> t = makeTuple(10, 's');
//print(get<0>(t), get<1>(t), 345, 45.6);

//char* a = "ad";
//auto s = get_value(a);
//auto sss = get_value("a");

int main(int argc, char *argv[]) 
{
	// time_slot_playground().play();
	// smart_pointers_playground().play();
	//multiplication_table_playground().play();

	int array[10];
	GetRandomNumberArrayOfLength10(array);
	for (int i = 0; i < 10; i++) {
		cout << array[i] << endl;
	}

	system("pause");
	return 0;
}