#include<vector>
#include<iostream>

using namespace std;

class A {
	int x;
	int y;
	public:
	A(int a, int b) { x = a; y = b; }
	print() { cout << x << " " << y << endl;}
};

A get_item() {
	A i(2, 3);
	//A i = new A(2, 3);
	return i;
}

int main() {
	vector<A> v(4);
	v.push_back(get_item());
	v[0].print();
	return 0;
}
