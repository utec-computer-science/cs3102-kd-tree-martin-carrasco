#include "kdtree.cpp"


int main(){
	KDTree<Int2DTree> base_kd;


	base_kd.insert(3, 2);

	base_kd.insert(4, 5);
	
	base_kd.insert(2, 1);

	base_kd.insert(5, 2);

	base_kd.insert(6, 7);
	
	base_kd.describe();

	return 0;
}
