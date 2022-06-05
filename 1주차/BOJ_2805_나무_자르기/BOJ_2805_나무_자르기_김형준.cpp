//
// BOJ - 2805
// 나무 자르기
//
// 난이도: S2
// 제출자: wasuphj @Github
// 

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int tree[1000000];

int main() {
    // 표준 입력 속도 증가 코드
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    // 나무 길이를 오름차순 정렬해준다
    sort(tree, tree + N);

    // 나무길이 0부터 입력받은 최대 나무 길이까지 이분탐색
    int l = 0;
    int r = tree[N - 1];
    int m = 0; 
    int s = 0, e = 0;
    long long h = 0; // 조금만 스쳐도 int 범위를 넘어간다. 넉넉하게 long long을 준다.
    int ans = 0; // 나무 1개 길이 자체는 int 범위 내
    while (l <= r) {
        m = (l + r) >> 1;

        s = lower_bound(tree, tree + N, m) - tree; // 길이 m 이상인 나무의 최소 index를 찾는다
        e = N;

        for (int i = s; i < e; i++) {
            h += tree[i]; // 나무 길이를 더해주고
        }

        h -= m * (long long)(e - s); // 해당 나무 개수 * m 만큼 빼준다

        // M 이상이면 왼쪽을 좁혀온다. m + 1이 r을 넘어가면 정답 확정
        if (h >= M) {
            ans = m;
            l = m + 1;
        }
        // 아니면 오른쪽을 좁힌다.
        else {
            r = m - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}

//
// 코멘트:
//
// 그래도 성장하긴 했나보다
// 
// 작년에 틀렸습니다 10개로 포기했던 문제인데 한번에 풀었다
//