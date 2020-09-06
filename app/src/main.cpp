#include <iostream>
#include <string>
#include "printlib.h"
#include "tuplelib.h"
#include "multiplication_table.h"
#include "time_slot_playground.h"
#include "smart_pointers_playground.h"

using namespace std;
using namespace tuplelib;
using namespace printlib;
using namespace multiplication_table;

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
	time_slot_playground().play();
	smart_pointers_playground().play();
	system("pause");
	return 0;
}