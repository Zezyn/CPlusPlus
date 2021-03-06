#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

template<class I>
void printContainer(I,I);

template<class I>
void reset(I);

int main()
{
	set<int> a,b;
	vector<int> c(20);

	a.insert(1);
	a.insert(3);
	a.insert(5);
	a.insert(7);
	a.insert(9);
	a.insert(10);

	b.insert(1);
	b.insert(2);
	b.insert(3);
	b.insert(4);
	b.insert(5);
	b.insert(6);
	b.insert(7);
	b.insert(8);
	
	cout << "a contains: "; 
	printContainer(a.begin(),a.end());
	cout << "b contains: "; 
	printContainer(b.begin(),b.end());
	cout << "b includes a? " << (includes(b.begin(),b.end(),a.begin(),a.end())?"Yes":"No")<<endl;
	cout << "union: ";
	vector<int>::iterator it;
	it = set_union(a.begin(),a.end(),b.begin(),b.end(),c.begin());
	set_union(a.begin(),a.end(),b.begin(),b.end(),c.begin());
	c.resize(it-c.begin());
	printContainer(c.begin(),c.end());
	reset(c);
	cout << "intersection: ";
	it = set_intersection(a.begin(),a.end(),b.begin(),b.end(),c.begin());
	c.resize(it-c.begin());
	printContainer(c.begin(),c.end());
	cout << "difference: ";
	it = set_difference(a.begin(),a.end(),b.begin(),b.end(),c.begin());
	c.resize(it-c.begin());
	printContainer(c.begin(),c.end());
	return 0;
}

template<class I>
void printContainer(I begin,I end){
	for(; begin!=end;++begin)
		cout << *begin << " ";
	cout << endl;
}

template<class I>
void reset(I c){
	c.erase(c.begin(),c.end());	
	c.resize(20);
}
