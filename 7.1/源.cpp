#include<iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n % 2 != 0) {
			cout << 0 << " " << 0 << endl;
		}
		else {
			//min
			int bunny = 0, chiken = 0;
			bunny = n / 4;
			if (n % 4 == 2)chiken = 1;
			cout << bunny + chiken << " ";
			//max
			chiken = n / 2;
			cout << chiken << endl;
		}
	}
	return 0;
}