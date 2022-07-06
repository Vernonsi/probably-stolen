#include <iostream>
using namespace std;

int main() {
	int n;
	bool d = true;
	cin >> n;
	for (int i = 2; i < n; i++) {
		if (n % i ==0) d=false;
	}
	if (d) cout << "prostoe";
	else cout << "ne prostoe";
}

// S(l)=n+2 Емкостная сложность 
// T(l)=cn Временная сложность  
// l=n+1 Размерность
// полиномиальныq алгоритм