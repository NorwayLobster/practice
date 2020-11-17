///
/// @file    test_set_range-based-for.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-04-12 11:22:41
///

#include <iostream>
using std::cout;
using std::endl;
#include <set>
#include <iostream>

int main() {
	std::set<int> set = { 6, 1, 3, 4, 2, 5 };
	for (auto e:set)
		std::cout<<e<<std::endl;
//	for (auto it = set.begin(); it != set.end(); ++it)
//		std::cout << *it << "\n";
}
