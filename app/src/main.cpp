#include <iostream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "printlib.h"
#include "tuplelib.h"
#include "multiplication_table.h"
#include "time_slot.hpp"

using namespace std;
using namespace tuplelib;
using namespace printlib;
using namespace multiplication_table;
using namespace boost::uuids;

template <typename T>
auto get_value(T t) {
	if constexpr (std::is_pointer_v<T>)
		return *t;
	else
		return t;
}

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
	//	cout << "Smart Pointers: wrapper for raw pointer, no more new and delete" << endl;

	//	cout << "===================================" << endl;
	//	{
	//		cout << "Unique Pointer: the memory block allocated for unique pointers does not allow another pointer referencing it" << endl;
	//		// NOT WORKING! 
	//		// unique_ptr<Entity> entity = new Entity();
	//		
	//		// NOT RECOMMENDED!
	//		// unique_ptr<Entity> entity(new Entity());

	//		unique_ptr<Entity> entity = make_unique<Entity>();

	//		// NOT WORKING! unique_ptr cannot be referenced!
	//		// unique_ptr<Entity> entityCopied = entity;
	//		// Entity* entityCopied = entity;
	//		// weak_ptr<Entity> weak = entity;
	//	}   // memory for entity is going to be deleted when exiting this scope!

	//	cout << "===================================" << endl;
	//	{
	//		cout << "Shared Pointer: reference-counting pointers, the memory block automatically freed if no more pointer referencing it" << endl;

	//		shared_ptr<Entity> entity;
	//		{
	//			shared_ptr<Entity> entityInner = make_shared<Entity>();
	//			entity = entityInner;
	//		} 
	//	} // memory for entity is going to be deleted when exiting this scope since no more pointers are referencing it!

	//	cout << "===================================" << endl;
	//	{
	//		cout << "Weak Pointer: pointers that won't increase reference count of it referencing shared pointer, and actually weak_ptr is not a pointer" << endl;
	//		weak_ptr<Entity> weak; // no make_weak;
	//		{
	//			shared_ptr<Entity> entity = make_shared<Entity>();
	//			weak = entity;
	//		} // memory for entity is going to be deleted when exiting this scope! 
	//		cout << "weak " << (weak.expired() ? "is" : "is not yet") << " expired" << endl; // weak referencing entity is expired!
	//	}
	//}

	//cout << Table<10>::value << endl;
	//calc<1, 10, 1, 9>();
	

	//Tuple<int, char> t = makeTuple(10, 's');
	//print(get<0>(t), get<1>(t), 345, 45.6);

	//char* a = "ad";
	//auto s = get_value(a);
	//auto sss = get_value("a");

	//Slot<uuid, random_generator, int>(1, 2);

	using namespace boost::property_tree;

	ptree root;
	json_parser::read_json("time_slot_data.json", root);

	vector<Slot<uuid, int>> slots;

	BOOST_FOREACH(ptree::value_type const &v, root)
	{
		auto node = v.second;
		slots.push_back(Slot<uuid, int> {
			node.get<uuid>("id"),
			node.get<int>("begin"),
			node.get<int>("end")
		});
	}

	SlotOptimizer<uuid, int> so;
	auto optimized_slots = so.solve(slots);
	
	int max = optimized_slots.size();
	for (int i = 0; i < max; i++)
	{
		auto slot = optimized_slots.at(i);
		cout << "\t" << slot.id << "\t\t" << slot.begin << "\t" << slot.end << endl;
	}

	cout << "\nMax" << "\t" << max << endl;

	system("pause");
	return 0;
}