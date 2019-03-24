#include<iostream>
#include "printlib.h"
#include "tuplelib.h"

using namespace std;
using namespace tuplelib;
using namespace printlib;

int main(int argc, char *argv[]) {
	Tuple<int, char> t = makeTuple(10, 's');
	print(get<0>(t), get<1>(t), 345, 45.6);
	cin.get();
	return 0;
}