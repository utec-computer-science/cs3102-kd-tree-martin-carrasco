#include "../include/kdtree.hpp"
#include <stdexcept>
#include <utility>
#include <vector>
#include <queue>
#include <experimental/array>
#include <tuple>
#include <algorithm>



using namespace std;

template<typename Target, typename... Ts>
using areT = conjunction<std::is_same<Ts,Target>...>;

template <class Trait>
template <class ... Args>
void KDTree<Trait>::insert(Args ... objs){
	const int size = sizeof...(objs);

	static_assert(size == Size);
	static_assert(areT<ObjType, Args...>::value);

	int dim_counter = 0;

	auto* current_node = &root;

	array<ObjType, Size> obj_unpacked = {objs...};

	while(current_node and *current_node){
		if (dim_counter == Trait::Size)
			dim_counter = 0;
		
		if (obj_unpacked[dim_counter] < (*current_node)->value[dim_counter])
				current_node = &((*current_node)->left);
		else 
			current_node = &((*current_node)->right);
		dim_counter++;
	}


	auto new_node = new Node();
	new_node->value = obj_unpacked;
	*current_node = shared_ptr<Node>(new_node);
}

template <class Trait>
void KDTree<Trait>::describe(){
    queue<NodePtr> node_queue;
    node_queue.push(root);
    while(!node_queue.empty()){

				int count = node_queue.size();

				while(count > 0){
					NodePtr current = node_queue.front();
					node_queue.pop();
					
					current->print();
					if (current->left)
						node_queue.push(current->left);

					if (current->right)
						node_queue.push(current->right);	
					count--;
				}
				cout << endl;
    }
}
