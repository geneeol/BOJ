//더러운 코드

#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <utility>

using std::cout;
using std::cin;

//스택 안쓰고 반복문 + 인덱스 리턴하는 함수로 구현 가능할듯..
//그러나 위처럼 하면 시간복잡도상 시간초과 날듯
//
//스택을 두개 사용하면 어떨까?

int	main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int	N;
	int	data;
	std::stack<std::pair<int, int>>	tower; //왜 탭인데 위 아래 간격이 달라보이지?
	std::stack<std::pair<int, int>>	stk;
	std::vector<int>	ans;//둘다 탭인데 왜 정렬이 위 아래 다르지?(vector일 때였음)

	cin >> N;
	ans.resize(N);
	fill(ans.begin(), ans.end(), 0);
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		tower.push(std::make_pair(data, i));
	}
	while (!tower.empty())
	{
		if (stk.empty() == true)
		{
			stk.push(tower.top());
			tower.pop();
		}
		if (tower.empty() == false)
		{
			if (tower.top() > stk.top()) //pair의 > 연산자가 적용됨, 우연히 맞았네..
			{
				ans[stk.top().second] = tower.size();
				stk.pop();
			}
			else
			{
				stk.push(tower.top());
				tower.pop();
			}
		}
	}
	for (auto i : ans)
		cout << i << ' ';
	return (0);
}

/*
cnt = 1;
		while (!tower.empty() && tower.top() < tmp) //empty반환값 0 이랑 비교하면 당연히 거짓.. 
		{
			printf("top: %d\n", tower.top());
				tower.pop();
				cnt++;
		}
		while (cnt--)
			ans.push_front(tower.size());

*/
