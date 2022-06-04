//
// BOJ - 1764
// 듣보잡
//
// 난이도: S4
// 제출자: wasuphj @Github
// 

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main() {
	// 표준 입력 속도 증가 코드
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	unordered_map<string, bool> data;
	priority_queue<string, vector<string>, greater<>> ans; // 정답 리스트 (우선순위큐라서 삽입시 자동 정렬)
	for (int i = 0; i < N; i++) {
		string buf;
		cin >> buf;

		data[buf] = true; // 입력받을때 unordered_map에 입력
	}

	for (int i = 0; i < M; i++) {
		string buf;
		cin >> buf;

        // 입력 받을 때 unordered_map을 count(exists) 하면서 true이면 정답 리스트 추가
		if (data.count(buf)) 
			ans.push(buf);
	}

	cout << ans.size() << "\n";

    // 입력 받을 때 이미 정렬 되었으므로 쭉 뽑아내면 된다
	while (!ans.empty()) {
		cout << ans.top() << "\n";
		ans.pop();
	}

	return 0;
}

//
// 코멘트:
//
// 바쁜 하루였어서 그냥 쉬어가는 문제
//