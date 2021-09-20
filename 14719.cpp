#include<iostream>

int rain(int H, int W, int blkstack[]);

int main()
{

    int H=0, W=0;
    std::cin >> H >> W;

    int blkstack[W];

    for(int i=0; i<W; i++)
        std::cin >> blkstack[i];

    std::cout << rain(H, W, blkstack);


    return 0;
}

int rain(int H, int W, int blkstack[])
{
    //int H_real = H+1;

    int count = 0, count_before = 0;
    bool flag = false;
    int low = 0;

    for(int level=1; level<=H; level++)
    {
        flag = false;
        low = 0;
        count_before = count;
        for(int width=0; width<W; width++)
        {
            if(blkstack[width] >= level)
            {
                if(flag == false)
                {
                    flag = true;
                    low = width;
                }
                else
                {
                    count += (width - low - 1);
                    low = width;                    
                }
            }
        }
        if(flag == false)
            return count;
    }

    return count;
}
