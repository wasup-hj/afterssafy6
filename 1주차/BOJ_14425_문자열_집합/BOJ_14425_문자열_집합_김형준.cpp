//
// BOJ - 14425
// 문자열 집합
//
// 난이도: S3
// 제출자: wasuphj @Github
// 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string card[10000];
string target[10000];
int ans = 0;

int main() {
	// 표준 입력 속도 증가 코드
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M; // 집합 내 문자열 개수 및 검사 문자열 개수 입력

	for (int i = 0; i < N; i++)
		cin >> card[i]; // 집합 내 문자열 입력

	for (int i = 0; i < M; i++)
		cin >> target[i]; // 검사 문자열 입력
	
	sort(card, card + N); // 이분 탐색을 위해 보유 문자열을 오름차순 정렬
	
	// 찾을 문자열을 돌면서 이분 탐색
	// 찾으면 1, 못 찾으면 0
	for (int i = 0; i < M; i++)
		ans += (target[i] == *lower_bound(card, card + N, target[i]));

	cout << ans << "\n";

	return 0;
}

//
// 코멘트:
//
// 문자열 탐색도 STL로 이분 탐색이 정말 간단하게 가능하다
//