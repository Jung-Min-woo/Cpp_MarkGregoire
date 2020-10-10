#include <initializer_list>
using namespace std;
int makeSum(initializer_list<int> lst) {
	int total = 0;
	for (int value : lst) total += value;
	return total;
}
int main(void) {
	int a = makeSum({ 1, 2, 3 });
	int b = makeSum({ 10, 20, 30, 40, 50, 60 });
	/* TYPE SAFED */ //int c = makeSum({ 1, 2, 3.0 }); 
}