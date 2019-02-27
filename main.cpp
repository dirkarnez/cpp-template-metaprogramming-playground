#include<iostream>

using namespace std;

void print() {
	cout << endl;
}

template<typename TFirst, typename...TRest>
void print(TFirst first, TRest... rest) {
	cout << first << " ";
	print(rest...);
}

int main(int argc, char *argv[]) {
	print("2143", 345, 45.6);
	cin.get();
	return 0;
}