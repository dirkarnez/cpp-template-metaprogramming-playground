#include <iostream>
#include <string>
#include "printlib.h"
#include "tuplelib.h"
#include "multiplication_table.h"

using namespace std;
using namespace tuplelib;
using namespace printlib;
using namespace multiplication_table;

class Entity 
{
public:
	Entity()
	{
		cout << "Created Entity!" << endl;
	}

	~Entity()
	{
		cout << "Destroyed Entity!" << endl;
	}

	void say_hello() {
		cout << "Hello" << endl;
	}
};

int main(int argc, char *argv[]) {
	{
		cout << "Smart Pointers: wrapper for raw pointer, no more new and delete" << endl;

		cout << "===================================" << endl;
		{
			cout << "Unique Pointer: the memory block allocated for unique pointers does not allow another pointer referencing it" << endl;
			// NOT WORKING! 
			// unique_ptr<Entity> entity = new Entity();
			
			// NOT RECOMMENDED!
			// unique_ptr<Entity> entity(new Entity());

			unique_ptr<Entity> entity = make_unique<Entity>();

			// NOT WORKING! unique_ptr cannot be referenced!
			// unique_ptr<Entity> entityCopied = entity;
			// Entity* entityCopied = entity;
			// weak_ptr<Entity> weak = entity;
		}   // memory for entity is going to be deleted when exiting this scope!

		cout << "===================================" << endl;
		{
			cout << "Shared Pointer: reference-counting pointers, the memory block automatically freed if no more pointer referencing it" << endl;

			shared_ptr<Entity> entity;
			{
				shared_ptr<Entity> entityInner = make_shared<Entity>();
				entity = entityInner;
			} 
		} // memory for entity is going to be deleted when exiting this scope since no more pointers are referencing it!

		cout << "===================================" << endl;
		{
			cout << "Weak Pointer: pointers that won't increase reference count of it referencing shared pointer, and actually weak_ptr is not a pointer" << endl;
			weak_ptr<Entity> weak; // no make_weak;
			{
				shared_ptr<Entity> entity = make_shared<Entity>();
				weak = entity;
			} // memory for entity is going to be deleted when exiting this scope! 
			cout << "weak " << (weak.expired() ? "is" : "is not yet") << " expired" << endl; // weak referencing entity is expired!
		}
	}

	//cout << Table<10>::value << endl;
	//calc<1, 10, 1, 9>();
	

	//Tuple<int, char> t = makeTuple(10, 's');
	//print(get<0>(t), get<1>(t), 345, 45.6);

	system("pause");

	return 0;
}