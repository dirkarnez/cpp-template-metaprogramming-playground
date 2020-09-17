#pragma once

namespace printlib
{
	using namespace std;

	void print() {
		cout << endl;
	}

	template<typename TFirst, typename...TRest>
	void print(TFirst first, TRest... rest) {
		cout << first << " ";
		print(rest...);
	}
}