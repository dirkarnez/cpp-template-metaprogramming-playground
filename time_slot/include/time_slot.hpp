#ifndef TIME_SLOT_H
#define TIME_SLOT_H

#include <algorithm>
#include <vector>

using namespace std;

template<typename id_type, typename time>
struct Slot
{
	id_type id;
	time begin;
	time end;
};

template<typename id_type, typename time>
class SlotOptimizer {
public:
	vector<Slot<id_type, time>> solve(vector<Slot<id_type, time>> slots);
};

template <typename id_type, typename time>
vector<Slot<id_type, time>> SlotOptimizer<id_type, time>::solve(vector<Slot<id_type, time>> slots) {
	vector<Slot<id_type, time>> optimized_slots;

	sort(slots.begin(), slots.end(), [](Slot<id_type, time>& a, Slot<id_type, time>& b) {
		return a.end == b.end ? a.begin > b.begin : a.end < b.end;
	});

	//for (int i = 0; i < slots.size(); i++)
	//{
	//	auto slot = slots.at(i);
	//	cout << "   " << slot.id << "\t\t" << slot.begin << "\t" << slot.end << endl;
	//}

	auto first_slot = slots.at(0);
	time last = first_slot.end;
	optimized_slots.push_back(first_slot);

	for (int i = 1; i < slots.size(); ++i)
	{
		auto slot = slots.at(i);
		if (slot.begin >= last)
		{
			last = slot.end;
			optimized_slots.push_back(slot);
		}
	}

	return optimized_slots;
}

#endif