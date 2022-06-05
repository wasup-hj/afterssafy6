//
// BOJ - 1269
// 대칭 차집합
//
// 난이도: S3
// 제출자: wasuphj @Github
// 

#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, bool> a_b;
int ans = 0;

int main() {
    // 표준 입력 속도 증가 코드
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x = 0;
        cin >> x;
        a_b[x] = true; // 입력 받으면서 동시에 체크
    }

    for (int i = 0; i < M; i++) {
        int x = 0;
        cin >> x;
        if (a_b[x]) ans++; // A에 존재한다면 체크
    }

    cout << N + M - ans * 2 << "\n"; // 중복 개수만큼 양 집합에서 빼면 된다. 따라서 두 집합의 합 - 2 * 중복개수

    return 0;
}

//
// 코멘트:
//
// 이 문제도 티어 설정에 실패한 문제인 것 같다
// 
// 오늘도 쉬어가는 문제.. 화이팅하자...
//