//
// BOJ - 2447 
// 별찍기
//
// 난이도: S1
// 제출자: wasuphj @Github
// 

#include <iostream>
using namespace std;

int rec(int y, int x, int n) {
	if (n == 1) return 1;

	int xs = n / 3;
	int ys = n / 3;
	int xe = n / 3 + n / 3 - 1;
	int ye = n / 3 + n / 3 - 1;

	if (y >= ys && y <= ye && x >= xs && x <= xe)
		return 0;

	return rec(y % (n / 3), x % (n / 3), n / 3);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << (rec(y, x, N) ? "*" : " ");
		}
		cout << "\n";
	}

	return 0;
}

//
// 코멘트:
//
// 처음엔 접근 조차 못했다
// 도대체 재귀로 출력을 어떻게 해야할까 생각하다가
// 결과값 buffer라도 만들어야하나 생각했다
// 자존심 상하지만 풀이를 보고 다음날 푼 문제
// 
// for문 없이 재귀 만으로 풀어보고 싶었다
// 
