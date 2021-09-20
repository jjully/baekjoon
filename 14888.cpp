#include<iostream>

void maxmin(int num[], int op[], int N, int cur, long long int* max, long long int* min, long long int ans)
{
    if(cur == (N-1)) {
        if(ans > *max) *max = ans;
        if(ans < *min) *min = ans;
        return;
    }

    int op_count[4] = {op[0], op[1], op[2], op[3]};

    if(op_count[0] != 0){
        op_count[0] = op_count[0] - 1;
        maxmin(num, op_count, N, (cur+1), max, min, ans+num[cur+1]);
        op_count[0] = op_count[0] + 1;
    }
    if(op_count[1] != 0){
        op_count[1] = op_count[1] - 1;
        maxmin(num, op_count, N, (cur+1), max, min, ans-num[cur+1]);
        op_count[1] = op_count[1] + 1;
    }
    if(op_count[2] != 0){
        op_count[2] = op_count[2] - 1;
        maxmin(num, op_count, N, (cur+1), max, min, ans*num[cur+1]);
        op_count[2] = op_count[2] + 1;
    }
    if(op_count[3] != 0){
        op_count[3] = op_count[3] - 1;
        maxmin(num, op_count, N, (cur+1), max, min, ans/num[cur+1]);
        op_count[3] = op_count[3] + 1;
    }
}

int main()
{

    int N=0;
    std::cin >> N;

    int num[N];
    int op[4];
    
    for(int i=0;i<N;i++)
        std::cin >> num[i];
    
    for(int j=0;j<4;j++)
        std::cin >> op[j];

    long long int* max = new long long int;
    long long int* min = new long long int;
    *max = -1000000000;
    *min = 1000000000;

    maxmin(num, op, N, 0, max, min, num[0]);

    std::cout << *max << '\n';
    std::cout << *min << std::endl;

    return 0;
}