#ifndef MULTIPLICATION_TABLE_H
#define MULTIPLICATION_TABLE_H

#include <iostream>
#include <array>

using namespace std;

namespace multiplication_table
{
	template <int size, int target>
	struct MultiplicationLine {
		MultiplicationLine<size - 1, target> rest;
		const int value = (size * target);
	};

	template <int target>
	struct MultiplicationLine<0, target> {
		const int value = 0;
	};

	template <int size, int width>
	struct MultiplicationTable {
		MultiplicationTable<size, width - 1> rest;
		MultiplicationLine<size, width> line;
	};

	template <int size>
	struct MultiplicationTable<size, 0> {
		MultiplicationLine<size, 0> line;
	};

	//using namespace std;

	//template <int N> 
	//struct Table {
	//	string value = "->" + to_string(N) + "<-" + Table<N - 1>::value;
	//};

	//template <>
	//struct Table<0> {
	//	static string value;
	//};

	//template <int start, int end, int columnsStart, int columnEnd>
	//void calc() {
	//	for (int i = columnsStart; i <= columnEnd; i++) {
	//		for (int j = start; j <= end; j++) {
	//			cout << i << " * " << j << " = " << i * j << endl;
	//		}
	//	}
	//}

	/*struct Cal
	{
		enum { result = X + Y };
	};

	template<unsigned char byte> class BITS_SET
	{
	public:
		enum {
			B0 = (byte & 0x01) ? 1 : 0,
			B1 = (byte & 0x02) ? 1 : 0,
			B2 = (byte & 0x04) ? 1 : 0,
			B3 = (byte & 0x08) ? 1 : 0,
			B4 = (byte & 0x10) ? 1 : 0,
			B5 = (byte & 0x20) ? 1 : 0,
			B6 = (byte & 0x40) ? 1 : 0,
			B7 = (byte & 0x80) ? 1 : 0
		};
	public:
		enum { RESULT = B0 + B1 + B2 + B3 + B4 + B5 + B6 + B7 };
	};*/
	/*	
	class Tuple<Tvalue, Trest...> : public Tuple<Trest...> {
	public:
		Tvalue value;
	};

	void print() {
		cout << endl;
	}

	template<typename TFirst, typename...TRest>
	void print(TFirst first, TRest... rest) {
		cout << first << " ";
		print(rest...);
	}*/
}

#endif