#ifndef TUPLE_LIB_H
#define TUPLE_LIB_H

namespace tuplelib
{
	template <typename... Ttypes>
	class Tuple;

	template <>
	class Tuple<> {};

	template <typename Tvalue, typename... Trest>
	class Tuple<Tvalue, Trest...> : public Tuple<Trest...> {
	public:
		Tvalue value;
	};

	template <size_t idx, typename Ttuple> struct TupleElement;

	template <typename Tvalue, typename... Trest>
	struct TupleElement<0, Tuple<Tvalue, Trest...>> {
		using type_t = Tvalue;
		using TupleType_t = Tuple<Tvalue, Trest...>;
	};

	template <size_t idx, typename Tvalue, typename... Trest>
	struct TupleElement<idx, Tuple<Tvalue, Trest...>>
		: public TupleElement<idx - 1, Tuple<Trest...>> { };

	template <size_t idx, typename... Ttypes>
	typename TupleElement<idx, Tuple<Ttypes...>>::type_t&
		get(Tuple<Ttypes...>& tuple) {
		using TupleType_t = typename TupleElement<idx, Tuple<Ttypes...>>::TupleType_t;
		return static_cast<TupleType_t&>(tuple).value;
	}

	template <typename... Ttypes>
	Tuple<Ttypes...> makeTuple(Ttypes... args) {
		Tuple<Ttypes...> result;
		fillTuple<0>(result, args...);
		return result;
	}

	template <size_t idx, typename Ttuple>
	void fillTuple(Ttuple& toFill) {};

	template <size_t idx, typename Ttuple, typename Tfirst, typename... Trest>
	void fillTuple(Ttuple& toFill, const Tfirst& first, Trest... rest) {
		get<idx>(toFill) = first;
		fillTuple<idx + 1>(toFill, rest...);
	}
}

#endif