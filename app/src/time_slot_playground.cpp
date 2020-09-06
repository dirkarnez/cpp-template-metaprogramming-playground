#include <iostream>
#include "time_slot_playground.h"
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "time_slot.hpp"

using namespace std;
using namespace boost::uuids;

void time_slot_playground::play() {
	using namespace boost::property_tree;

	ptree root;
	json_parser::read_json("time_slot_data.json", root);

	vector<Slot<uuid, int>> slots;

	BOOST_FOREACH(ptree::value_type const& v, root)
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
}