#include <vector>
#include <type_traits>
#include <memory>
#include <tuple>
#include <iostream>


template <class TreeTrait>
struct Node {
	using ObjType = typename TreeTrait::ObjType;

	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	std::array<ObjType, TreeTrait::Size> value;
	
	void print(){
		std::cout << "(";
		for (auto start = value.begin();start != value.end();start++){
			std::cout << *start << ",";	
		}
		std::cout << ")";
	}
};

template <class Trait>
class KDTree {
	public:
		using Node =::Node< KDTree<Trait> >;
		using NodePtr = typename std::shared_ptr<Node>;
		using ObjType = typename Trait::ObjType;
		static const unsigned int Size = Trait::Size;

	private:
		NodePtr root;

	public:
		template <class ... Args>
		void insert(Args ... obj);
		void describe();
};

class Int2DTree {
	public:
		using ObjType = int;
		constexpr static unsigned int Size = 2;
};


