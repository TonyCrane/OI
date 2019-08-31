/*************************************************************
 *  > File Name        : c1063_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/27 13:02:20
 *  > Algorithm        : priority_queue
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxm = 100010;
const char _CREATE[10]  = "create";
const char _MESSAGE[10] = "message";
const char _PROCESS[10] = "process";
const char _RUN[10]     = "run";
const char _CHANGE[10]  = "change";
const char _KILL[10]    = "kill";
const char _KILLMAX[10] = "killmax";

int cnt = 0;

struct Process {
    int pid;
    long long data;
    Process() {data = pid = 0;}
    Process(int id, long long mem): pid(id), data(mem) {}
    bool operator < (const Process& a) const {
        if (data == a.data) {
            return pid > a.pid;
        }
        return data < a.data;
    }
};

bool valid[maxm];
priority_queue<Process> __ALL_PROCESS_, __ALL_MEMORY_;
priority_queue<int> __ALL_MESSAGE_[maxm];
long long priority[maxm], memory[maxm];

void _create(int pid, int mem, int pri) {
    if (valid[pid]) {
        printf("Error\n");
        return;
    } else {
        if (mem == 0LL) return;
        valid[pid] = true;
        priority[pid] = pri;
        memory[pid] = mem;
        __ALL_MEMORY_.push(Process(pid, mem));
        return;
    }
}

void _message(int pid, int pri) {
    if (!valid[pid]) {
        printf("Error\n");
        return;
    } else {
        __ALL_MESSAGE_[pid].push(pri);
        __ALL_PROCESS_.push(Process(pid, pri * priority[pid]));
        return;
    }
}

void _process(int pid) {
    if (!valid[pid]) {
        printf("Error\n");
        return;
    } else {
        if (__ALL_MESSAGE_[pid].empty()) {
            printf("Empty\n");
            return;
        } else {
            printf("Process: %d\n", __ALL_MESSAGE_[pid].top());
            __ALL_MESSAGE_[pid].pop();
            if (!__ALL_MESSAGE_[pid].empty()) {
                __ALL_PROCESS_.push(Process(pid, priority[pid] * __ALL_MESSAGE_[pid].top()));
            }
            return;
        }
    }
}

void _run() {
    while ((!__ALL_PROCESS_.empty()) && ((!valid[__ALL_PROCESS_.top().pid]) \
            || __ALL_MESSAGE_[__ALL_PROCESS_.top().pid].empty() \
            || __ALL_MESSAGE_[__ALL_PROCESS_.top().pid].top() \
            * priority[__ALL_PROCESS_.top().pid] != __ALL_PROCESS_.top().data)) {
        __ALL_PROCESS_.pop();
    }
    if (__ALL_PROCESS_.empty()) {
        printf("Empty\n");
        return;
    } else {
        printf("Run: %lld\n", __ALL_PROCESS_.top().data);
        __ALL_MESSAGE_[__ALL_PROCESS_.top().pid].pop();
        if (!__ALL_MESSAGE_[__ALL_PROCESS_.top().pid].empty()) {
            __ALL_PROCESS_.push(Process(__ALL_PROCESS_.top().pid, \
            priority[__ALL_PROCESS_.top().pid] * __ALL_MESSAGE_[__ALL_PROCESS_.top().pid].top()));
        }
        __ALL_PROCESS_.pop();
    }
}

void _change(int pid, int pri) {
    if (!valid[pid]) {
        printf("Error\n");
        return;
    } else {
        priority[pid] = pri;
        if (!__ALL_MESSAGE_[pid].empty()) {
            __ALL_PROCESS_.push(Process(pid, __ALL_MESSAGE_[pid].top() * priority[pid]));
        }
        return;
    }
}

void _kill(int pid) {
    if (!valid[pid]) {
        printf("Error\n");
        return;
    } else {
        valid[pid] = false;
    }
}

void _killmax() {
    while ((!__ALL_MEMORY_.empty()) && ((!valid[__ALL_MEMORY_.top().pid]) \
            || memory[__ALL_MEMORY_.top().pid] != __ALL_MEMORY_.top().data)) {
        __ALL_MEMORY_.pop();
    }
    if (__ALL_MEMORY_.empty()) {
        printf("Empty\n");
        return;
    } else {
        valid[__ALL_MEMORY_.top().pid] = false;
        printf("Kill: %d\n", __ALL_MEMORY_.top().pid);
        __ALL_MEMORY_.pop();
        return;
    }
}

int main() {
    int m = read(); 
    while (m--) {
        char opt[10]; scanf("%s", opt);
        if (strcmp(opt, _CREATE) == 0) {
            int pid = read(), mem = read(), pri = read();
            _create(pid, mem, pri);
        } else if (strcmp(opt, _MESSAGE) == 0) {
            int pid = read(), pri = read();
            _message(pid, pri);
        } else if (strcmp(opt, _PROCESS) == 0) {
            int pid = read();
            _process(pid);
        } else if (strcmp(opt, _RUN) == 0) {
            _run();
        } else if (strcmp(opt, _CHANGE) == 0) {
            int pid = read(), pri = read();
            _change(pid, pri);
        } else if (strcmp(opt, _KILLMAX) == 0) {
            _killmax();
        } else if (strcmp(opt, _KILL) == 0) {
            int pid = read();
            _kill(pid);
        }
    }
    return 0;
}