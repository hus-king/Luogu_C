#include <iostream>
using namespace std;
int main(){
    int a,n,m,x;
    cin>>a>>n>>m>>x;
    //始发站上车人数 a，车站数 n，终点站下车人数 m 和所求的站点编号 x。
    //m = result_a * a + result_x * reslove
    if(n==2){
        cout<<a;
        return 0;
    }
    int people[30][2]={0};
    people[1][0] = 1;
    people[1][1] = 0;
    people[2][0] = 0;
    people[2][1] = 1;
    for(int i=3;i<n;i++){
        people[i][0] = people[i-1][0]+people[i-2][0];
        people[i][1] = people[i-1][1]+people[i-2][1];
    }
    int result_a = 1;
    int result_x = 0;
    for(int i=1;i<=n-3;i++){
        result_a += people[i][0];
        result_x += people[i][1];
    }
    result_a = result_a*a;
    int reslove = m - result_a;
    reslove = reslove/result_x;
    int output,output_a = 1,output_x = 0;
    for(int i=1;i<=x-2;i++){
        output_a += people[i][0];
        output_x += people[i][1];
    }
    output = output_a*a+output_x*reslove;
    cout<<output;
}