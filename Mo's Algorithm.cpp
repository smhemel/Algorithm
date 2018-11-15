//
//  main.cpp
//  Mo's Algorithm
//
//  Created by S M HEMEL on 2/8/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define pii pair <int,int>
using namespace std;
int N, Q, BLOCK_SIZE;
long long current_answer;
long long cnt[100];
long long answers[100500];
int arr[100500];
pair< pair<int, int>, int> queries[100500];
inline bool mo_cmp(const pair< pii, int> &x , const pair< pii, int> &y) {
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x == block_y)
        return x.first.second < y.first.second;
    return block_x < block_y;
}
inline void add(int x) {
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]++;
    current_answer += cnt[x] * cnt[x] * x;
}
inline void remove(int x) {
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]--;
    current_answer += cnt[x] * cnt[x] * x;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    BLOCK_SIZE = static_cast<int>(sqrt(N));
    for(int i=0; i<N; i++)
        cin >> arr[i];
    for(int i=0; i<Q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }
    sort(queries,queries+Q, mo_cmp);
    int mo_left = 0, mo_right = -1;
    for(int i=0; i<Q; i++) {
        int left = queries[i].first.first;
        int right = queries[i].first.second;
        while(mo_right<right) {
            mo_right++;
            add(arr[mo_right]);
        }
        while(mo_right>right) {
            remove(arr[mo_right]);
            mo_right--;
        }
        while(mo_left<left) {
            remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left>left) {
            mo_left--;
            add(arr[mo_left]);
        }
        answers[queries[i].second] = current_answer;
    }
    for(int i = 0; i < Q; i++)
        cout << answers[i] << "\n";
    return 0;
}





#include <cstdio>
#include <algorithm>
using namespace std;

#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

struct node {
    int L, R, i;
}q[N];

bool cmp(node x, node y) {
    if(x.L/BLOCK != y.L/BLOCK) {
        // different blocks, so sort by block.
        return x.L/BLOCK < y.L/BLOCK;
    }
    // same block, so sort by R value
    return x.R < y.R;
}

void add(int position) {
    cnt[a[position]]++;
    if(cnt[a[position]] == 1) {
        answer++;
    }
}

void remove(int position) {
    cnt[a[position]]--;
    if(cnt[a[position]] == 0) {
        answer--;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d%d", &q[i].L, &q[i].R);
        q[i].L--; q[i].R--;
        q[i].i = i;
    }
    
    sort(q, q + m, cmp);
    
    int currentL = 0, currentR = 0;
    for(int i=0; i<m; i++) {
        int L = q[i].L, R = q[i].R;
        while(currentL < L) {
            remove(currentL);
            currentL++;
        }
        while(currentL > L) {
            add(currentL-1);
            currentL--;
        }
        while(currentR <= R) {
            add(currentR);
            currentR++;
        }
        while(currentR > R+1) {
            remove(currentR-1);
            currentR--;
        }
        ans[q[i].i] = answer;
    }
    
    for(int i=0; i<m; i++)
        printf("%d\n", ans[i]);
}
