#include<iostream>
#include<ctime>
using namespace std;

int n;
long long int cnt;

void combination() {
    
    int upnum = 1, downnum = 1;
    
    int i = n;
    int j = 2 * n;
    for(; i > 0; --i, --j){
        upnum *= j;
        downnum *= i;
    }
    cnt = (upnum/downnum)/(n + 1);
}

int main() {

    printf("\n**             售票处找零问题                **\n");
    printf("=============================================\n");
    printf("**               请选择操作                 **\n");
    printf("**              1---输入购票人数            **\n");
    printf("**              2---利用组合算法求解         **\n");
    printf("**              3---退出程序                **\n");
    printf("=============================================\n");
    int op;
    bool flag = false;
    while (true) {

        printf("\n请选择操作：");
        scanf("%d", &op);

        if(op == 1){

            flag = true;
            printf("有2n人排队购票，请输入n：");
            scanf("%d", &n);
        }


        else if (op == 2) {

            if(!flag){
                printf("未输入购票人数，请输入！\n");
                continue;
            }
            flag = false;

            cnt = 0;

            clock_t clockstart, clockend;
            clockstart = clock();
            combination();
            clockend = clock();
            double timeused = (clockend - clockstart) / static_cast<double>(CLOCKS_PER_SEC);
            printf("n为%d时，共有%lld种方案，所用时间为%lfs\n ", n, cnt, timeused);
        }

        else if(op== 3)
            break;

        else {
            printf("输入非法数字，请重新输入！\n");
            continue;
        }
    }

    return 0;
}
