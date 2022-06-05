//
// BOJ - 2805
// ���� �ڸ���
//
// ���̵�: S2
// ������: wasuphj @Github
// 

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int tree[1000000];

int main() {
    // ǥ�� �Է� �ӵ� ���� �ڵ�
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    // ���� ���̸� �������� �������ش�
    sort(tree, tree + N);

    // �������� 0���� �Է¹��� �ִ� ���� ���̱��� �̺�Ž��
    int l = 0;
    int r = tree[N - 1];
    int m = 0; 
    int s = 0, e = 0;
    long long h = 0; // ���ݸ� ���ĵ� int ������ �Ѿ��. �˳��ϰ� long long�� �ش�.
    int ans = 0; // ���� 1�� ���� ��ü�� int ���� ��
    while (l <= r) {
        m = (l + r) >> 1;

        s = lower_bound(tree, tree + N, m) - tree; // ���� m �̻��� ������ �ּ� index�� ã�´�
        e = N;

        for (int i = s; i < e; i++) {
            h += tree[i]; // ���� ���̸� �����ְ�
        }

        h -= m * (long long)(e - s); // �ش� ���� ���� * m ��ŭ ���ش�

        // M �̻��̸� ������ �����´�. m + 1�� r�� �Ѿ�� ���� Ȯ��
        if (h >= M) {
            ans = m;
            l = m + 1;
        }
        // �ƴϸ� �������� ������.
        else {
            r = m - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}

//
// �ڸ�Ʈ:
//
// �׷��� �����ϱ� �߳�����
// 
// �۳⿡ Ʋ�Ƚ��ϴ� 10���� �����ߴ� �����ε� �ѹ��� Ǯ����
//