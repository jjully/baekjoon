#include<iostream>
#include<vector>
#include<string>
#define ALPHABET_NO 26

int wordNo(int N, int K, std::string word[]);
void init_array(int arr[], int N);
void findMAX(std::string word[], int N, std::vector<char> learned, int* max);
void dfs_combi(std::string word[], int N, std::vector<char> apt_tobeLearned, int visit[], int* max, int idx, int cnt, int alpha_num);

int main()
{

    int N=0, K=0;
    std::cin >> N >> K;
    std::string word[N];
    for(int i=0; i<N; i++)
        std::cin >> word[i];

    std::cout << wordNo(N, K, word);

    return 0;
}

void init_array(int arr[], int N)
{
    for(int i=0; i<N; i++)
        arr[i] = 0;
}

int wordNo(int N, int K, std::string word[])
{

    int alphabet[ALPHABET_NO];
    int count = 0;  //no. of max alphabet you need to learn
    int max = 0;    //no. of words you can learn w. K alphabets
    std::vector<char> apt_tobeLearned;

    if(K<5)
        return 0;
    else
    {
        init_array(alphabet, ALPHABET_NO);  //reset 0
        for(int i=0; i<N; i++)   //making bitmap
        {
            for(int j=4; j<(word[i].length()-4); j++)
            {
                int index = word[i][j] - 97;
                switch(index)
                {
                    case('a'-97): case('n'-97): case('t'-97): case('i'-97): case('c'-97): 
                        break;
                    default:
                    {
                        if(alphabet[index] == 0)
                            count++;
                        alphabet[index] = 1;
                        //count++;
                        break;
                    }
                }
            }
        }

        for(int i=0; i<ALPHABET_NO; i++)
        {
            if(alphabet[i] == 1)
                apt_tobeLearned.push_back(i+97);
        }
/*
        char learnedAlpahbet[K];
        learnedAlpahbet[0] = 'a';
        learnedAlpahbet[1] = 'n';
        learnedAlpahbet[2] = 't';
        learnedAlpahbet[3] = 'i';
        learnedAlpahbet[4] = 'c';
*/
        if((K-5) >= count)  //if you can learn all words
        {
            return N;
        }
        else    //find max no. of words you can learn
        {
            int * max = new int;
            *max = 0;
            int visit[apt_tobeLearned.size()];
            for(int i=0; i<apt_tobeLearned.size(); i++)
                visit[i] = 0;
            
            dfs_combi(word, N, apt_tobeLearned, visit, max, 0, 0, K-5);  //need to fix
            return *max;
        }
    }
}

void findMAX(std::string word[], int N, std::vector<char> learned, int* max)    //alpha_num == K-5
{
    int cnt = N;
    int i=0, j=0, k=0;
    for(i=0; i<N; i++)  //for all words
    {
        for(j=0; j<word[i].length(); j++)   //for all alphabets
        {
            k=0;
            switch(word[i][j])
            {
                case('a'): case('n'): case('t'): case('i'): case('c'): 
                    break;
                default:
                    for(k=0; k<learned.size(); k++) //compare an alphabet w. learned alphabet
                    {
                        if(word[i][j] == learned[k])    //if it matches
                            break;
                    }
            }
            /*
                for(k=0; k<apt_tobeLearned.size(); k++) //compare an alphabet w. learned alphabet
                {
                    if(word[i][j] == apt_tobeLearned[k])    //if it matches
                        break;
                }
                */
            if(k == learned.size()) //if not matches
            {
                cnt--;
                break;
            }
        }
    }

    if(*max < cnt)
        *max = cnt;
}

void dfs_combi(std::string word[], int N, std::vector<char> apt_tobeLearned, int visit[], int* max, int idx, int cnt, int alpha_num)
{
    if(cnt == alpha_num)
    {
        std::vector<char> learned;
        for(int i=0; i<apt_tobeLearned.size(); i++)
        {
            if(visit[i] == true)
            learned.push_back(apt_tobeLearned[i]);
        }

        //for test
        std::string new_word[N];
        for(int j=0; j<N; j++)
        {
            new_word[j] = word[j];
        }



        //
        findMAX(new_word, N, learned, max);
        return;
    }

    for(int i=idx; i<apt_tobeLearned.size(); i++)
    {
        if(visit[i] == true) continue;
        visit[i] = true;
        dfs_combi(word, N, apt_tobeLearned, visit, max, i, cnt+1, alpha_num);
        visit[i] = false;
    }
}

/*
int findMax(std::string word[], int N, int alphabet[], char learnedAlphabet[], int K, int cur, int max)
{
    //word[]: words we have to learn
    //N: no. of words
    //alphabet[]: bitmap for alphabets we need to learn
    //cur: left no. of alphabet we can learn
    int count = 0;

    if(cur == 0)
    {
        for(int i=0; i<N; i++)
        {
            if(compareAlphabet(word[i], learnedAlphabet, K))
                count++;
        }
        if(count >= max)
            return count;
        else
            return max;
    }
    else
    {
        
    }

}

bool compareAlphabet(std::string word, char learnedAlphabet[], int K)
{
    //bool result = false;
    for(int i=0; i<word.length(); i++)
    {
        int j=0;
        for(j=0; j<K; j++)
        {
            if(word[i] == learnedAlphabet[j])
                break;
        }
        if(j==K)
            return false;
    }

    return true;
}
*/