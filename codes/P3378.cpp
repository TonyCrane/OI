/*************************************************************
 *  > File Name        : P3378.cpp
 *  > Author           : Tony
 *  > Created Time     : 2018年12月21日 星期五 19时42分16秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, op, x;
int heap[1000010];
int heap_size = 0;

void put(int d)
{
	int now, next;
	heap[++heap_size] = d;
	now = heap_size;
	while (now > 1)
	{
		next = now >> 1;
		if (heap[now] >= heap[next]) return;
		swap(heap[now], heap[next]);
		now = next;
	}
}

int get()
{
	int now, next, res;
	res = heap[1];
	heap[1] = heap[heap_size--];
	now = 1;
	while (now * 2 <= heap_size)
	{
		next = now * 2;
		if (next < heap_size && heap[next + 1] < heap[next]) next++;
		if (heap[now] <= heap[next]) break;
		swap(heap[now], heap[next]);
		now = next;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			int x;
			scanf("%d", &x);
			put(x);
		}
		else if (op == 2) printf("%d\n", heap[1]);
		else if (op == 3) get();
	}
    return 0;
}
