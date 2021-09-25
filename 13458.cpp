#include<iostream>
#include<vector>

int N=0, B=0, C=0;

void findSub(std::vector<int>& A, std::vector<int>& Sub);

int main()
{

    //0. Enter input
    scanf("%d", &N);
    std::vector<int> A;
    int tmp = 0;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &tmp);
        A.push_back(tmp);
    }

    scanf("%d %d", &B, &C);

    //1. Find sub no.   //MFaculty, SubFaculty

    std::vector<int> Sub(N, 0); //SubFaculty, init w. 0

    findSub(A, Sub);

    uint64_t supervisor = N; //MFaculty
    for(int i=0; i<N; i++) {
        supervisor += Sub[i];
    }

    printf("%lu", supervisor);

    return 0;
}

void findSub(std::vector<int>& A, std::vector<int>& Sub)
{
    int idx=0, student = 0;

    while( idx != A.size() ) {
        
        student = A[idx];
        if(B >= student) {   //no need Sub
            idx++;
            continue;
        }
        else if((student - B) % C == 0) {
             Sub[idx] = (student - B)/C;
        }
        else {
            Sub[idx] = (student - B)/C + 1;
        }
        idx++;
    }


}