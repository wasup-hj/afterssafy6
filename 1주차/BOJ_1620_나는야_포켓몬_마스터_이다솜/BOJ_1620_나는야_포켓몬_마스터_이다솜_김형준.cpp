//
// BOJ - 1620
// 나는야 포켓몬 마스터 이다솜
//
// 난이도: S4
// 제출자: wasuphj @Github
// 

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<int, string> pokemon_name_dict;
unordered_map<string, int> pokemon_index_dict;
string target[100000];

int main() {
	// 표준 입력 속도 증가 코드
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M; // 포켓몬의 개수와 문제의 개수

	for (int i = 0; i < N; i++) {
		string buf;
		cin >> buf; // 포켓몬 입력
		
		pokemon_name_dict[i + 1] = buf; // 이름 사전에 등록
		pokemon_index_dict[buf] = i + 1; // 인덱스 사전에 등록
	}

	for (int i = 0; i < M; i++) {
		cin >> target[i]; // 문제 입력
	}
		
	for (int i = 0; i < M; i++) {
		// 인덱스 사전에서 발견 시 출력하고
		// 미 발견시, 숫자로 바꿔 이름 사전에서 검색
		if (pokemon_index_dict.find(target[i]) != pokemon_index_dict.end())
			cout << pokemon_index_dict[target[i]] << "\n";
		else
			cout << pokemon_name_dict[stoi(target[i])] << "\n";
	}

	return 0;
}

//
// 코멘트:
//
// 이게 다라면 정말 허무한 문제라고 생각했지만
//
// 진짜 이게 다였던 문제
//
// 이 문제도 티어 설정에 실패한 문제인 것 같다
//