#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	N;

	cin >> N;
	for (int i = 1; i <= N / 4; i++)
		cout << "long" << ' ';
	cout << "int";
	return (0);
}
