//
// BOJ - 10815
// 숫자 카드
//
// 난이도: S4
// 제출자: wasuphj @Github
// 

#include <iostream>
#include <algorithm>
using namespace std;

int card[500000];
int target[500000];

int main() {
	// 표준 입력 속도 증가 코드
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N; // 보유 카드 개수 입력

	for (int i = 0; i < N; i++)
		cin >> card[i]; // 보유 카드 입력
	
	sort(card, card + N); // 이분 탐색을 위해 보유 카드를 오름차순 정렬

	int M;
	cin >> M; // 찾을 카드 개수 입력

	for (int i = 0; i < M; i++)
		cin >> target[i]; // 찾을 카드 입력

	// 찾을 카드 배열을 돌면서 이분 탐색
	// 찾으면 1, 못 찾으면 0
	for (int i = 0; i < M; i++)
		cout << (target[i] == *lower_bound(card, card + N, target[i])) << " ";

	cout << "\n";

	return 0;
}

//
// 코멘트:
//
// 직접 이분 탐색을 구현하는 것 보다는
// 이제 STL 사용 연습이 필요한 것 같아서 사용했다.
//