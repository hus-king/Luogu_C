/*将 1,2,…,9 共 9 个数分成 3 组，分别组成 3 个三位数，
且使这 3 个三位数构成 1:2:3 的比例，试求出所有满足条件的 3 个三位数。*/
#include<iostream>
using namespace std;
int num[10]={0};
int number[3]={0};
int flag[10]={0};
void calculate(){
    num[1]=number[1]/100;
    num[2]=number[1]/10%10;
    num[3]=number[1]%10;
    num[4]=number[2]/100;
    num[5]=number[2]/10%10;
    num[6]=number[2]%10;
    num[7]=number[3]/100;
    num[8]=number[3]/10%10;
    num[9]=number[3]%10;
}
int check(){
    int sum=0;
    int mul=1;
    for(int i=1;i<=9;i++){
        sum+=num[i];
        mul*=num[i];
    }
    if(sum==45&&mul==362880) return 1;
    return 0;
}
int main(){
    for(number[1]=100;number[1]<333;number[1]++){
        number[2]=number[1]*2;
        number[3]=number[1]*3;
        calculate();
        if(check()){
            cout<<number[1]<<" "<<number[2]<<" "<<number[3]<<endl;
        }
    }
    return 0;
}