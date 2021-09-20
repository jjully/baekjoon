#include<iostream>

int main()
{

    int N=0, K=0;
    std::cin >> N >> K;
    int device[K];  //how many times will device be used            //do we need this?
    int order[K];   //using order
    //int hole_used[N];   //check whether hole is used or not //lets just use count
    int device_plugged[K]; //check whether device is already plugged in

    //hole_used를 N개의 별도 data로 저장하지 않고
    //bit mask를 이용하면 for문 없이 이번 차례에 이용하려는 device가
    //이미 꽂혀있는지, 안 꽂혀있는지 바로 확인 가능
    //고쳐서 해보자
    //100bit를 넘는 용량을 data가 가져야해서 실패

    for(int i=0; i<K; i++) {
        //device[i] = 0; 
        device_plugged[i] = 0;
        }

    //0. input
    for(int i=0; i<K; i++) {
        std::cin >> order[i];
        //device[order[i]-1]++;
    }

    int plugoff = 0;
    int count = 0;
    for(int i=0; i<K; i++) {
        //0. if already plugged in, skip
        if( device_plugged[order[i] - 1] ) {
            //device[order[i]-1]--;                   //
            continue;
        }
        //1. if not plugged in && if hole is left
        else if(count < N) {
            //device[order[i]-1]--;                   //
            device_plugged[order[i]-1] = 1;
            count++;
            continue;
        }
        else {
        //2.    if not plugged in && no hole left 
        //      time to plug out and plug in
        //      since here, count is always N
        //select one which has the least left
        //and plug off

            int max = 0;
            int max_device = 0;
            for(int j=0; j<K; j++) {
                int l = 0;
                if( device_plugged[j] == 1 ) {  //for all plugged device
                    for( l=(i+1); l<K; l++) {       //find when same device is used
                        if( j == (order[l]-1) ) {       
                            if( max < (l-i) ) {         //if the device is the further one
                                max = l-i;              //write down the distance and
                                max_device = j;         //check which device it is
                            }
                            break;
                        }
                    }
                    if (l == K) {                    //if the device didn't meet break, it means no device_used time left        //so plug off
                        max_device = j;
                        break;
                    } 
                }
            }

            plugoff++;
            device_plugged[max_device] = 0;
            device_plugged[order[i]-1] = 1;
            //device[order[i]-1]--;
        }
    }

    std::cout <<plugoff;
    return 0;
}