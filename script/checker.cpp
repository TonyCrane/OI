#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define in(x) (string)argv[x]

int COMPARE_TIMES = 30; // times you want to compare
const int PRINT_TIMES = 10;

int main(int argc, char * argv[]) {
    COMPARE_TIMES = atoi(argv[4]);
    system(("g++ " + in(2) + ".cpp -o first").c_str());
    system(("g++ " + in(3) + ".cpp -o second").c_str());
    int cnt = 1;
    time_t begin_process, end_process;
    double tim1 = 0, tim2 = 0, alltime1 = 0, alltime2 = 0;
    cout<< fixed << setprecision(2);
    while(1) {
        if(cnt % PRINT_TIMES == 0) {
            printf("%d Data# \n", cnt);
            system("echo \"\033[32mProvisionally Same\033[0m\"");
        }
        system(("python3 " + in(1) + ".py > data.in").c_str());

        begin_process = clock();
        system("./first < data.in > first.out");
        end_process = clock();
        tim1 += (double)(end_process - begin_process) / CLOCKS_PER_SEC * 1000.0;

        begin_process = clock();
        system("./second < data.in > second.out");
        end_process = clock();
        tim2 += (double)(end_process - begin_process) / CLOCKS_PER_SEC * 1000.0;

        if(cnt % PRINT_TIMES == 0) {
            double ave1 = tim1 / PRINT_TIMES;
            double ave2 = tim2 / PRINT_TIMES;
            alltime1 += tim1; alltime2 += tim2;
            tim1 = 0; tim2 = 0;
            printf("%d Data# First  Program  :  %.3lf ms\n", PRINT_TIMES, ave1);
            printf("%d Data# Second Program  :  %.3lf ms\n\n", PRINT_TIMES, ave2);
        }
        if(system("diff first.out second.out -w")){
            printf("%d# \n", cnt);
            system("echo \"\033[1;31mInconsistent answers\033[0m\"");
            return 0;
        }
        cnt++;
        if(cnt > COMPARE_TIMES) {
            puts("");
            printf("%d Data# \n", COMPARE_TIMES);
            system("echo \"\033[32mSame Answer\033[0m\"");
            puts("");
            printf("First  Program  :  %.4lf ms on average\n", alltime1 / COMPARE_TIMES);
            printf("Second Program  :  %.4lf ms on average\n\n", alltime2 / COMPARE_TIMES);
            return 0;
        }
    }
    return 0;
}
