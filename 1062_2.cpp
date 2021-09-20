#include<iostream>
#include<string>

#define MAX_A 26
#define max(a, b) (a>b ? a:b)

int max_words=0;

void init_array(int words[], int size)
{
    for(int i=0; i<size; i++)
    {
        words[i] = 0;
    }
}

void dfs(int words[], int idx, int cnt, int know, int N, int K);

int main()
{

    int N=0, K=0;
    int words[50];
    init_array(words, 50);
    int need=0;
    std::cin >> N >> K;
    if(K < 5)
    {
        std::cout << '0';
        return 0;
    }

    std::string buf;

    for(int i=0; i<N; i++)
    {
        int cur = 0;
        std::cin >> buf;
        for(int j=0; j<buf.length(); j++)
        {
            switch(buf[cur])
            {
                case('a'): case('n'): case('t'): case('i'): case('c'): 
                    break;
                default:
                    if( !(words[i] & (1<<(buf[cur] - 'a'))) )
                    {
                        words[i] |= (1<<(buf[cur]-'a'));
                    }
            }
            cur++;
        }
    }


    //add 'a' 'n' 't' 'i' 'c'
    need |= (1<<('a' - 'a'));
    need |= (1<<('n' - 'a'));
    need |= (1<<('t' - 'a'));
    need |= (1<<('i' - 'a'));
    need |= (1<<('c' - 'a'));
    K-=5;
 
    dfs(words, 0, 0, need, N, K);

    std::cout << max_words;

    return 0;
}

void dfs(int words[], int idx, int cnt, int know, int N, int K)
{
    if( cnt == K ){
        int cur_cnt = 0;
        for(int w=0; w<N; w++) {
            if( !( words[w] & ~know ) )
                cur_cnt++;
        }
        max_words = max(max_words, cur_cnt);
        return;
    }

    if(idx == MAX_A)
        return;
    
    if( (idx != 'a'-'a') && (idx != 'n'-'a') && (idx != 't'-'a') && (idx != 'i'-'a') && (idx != 'c'-'a') ) {
        dfs(words, idx+1, cnt+1, know | (1<<idx), N, K);
        dfs(words, idx+1, cnt, know, N, K);
    }
    else
        dfs(words, idx+1, cnt, know, N, K);

}