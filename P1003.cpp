/*
为了准备一个独特的颁奖典礼，组织者在会场的一片矩形区域（可看做是平面直角坐标系的第一象限）铺上一些矩形地毯。
一共有 n 张地毯，编号从 1 到 n。现在将这些地毯按照编号从小到大的顺序平行于坐标轴先后铺设，后铺的地毯覆盖在前面已经铺好的地毯之上。
地毯铺设完成后，组织者想知道覆盖地面某个点的最上面的那张地毯的编号。注意：在矩形地毯边界和四个顶点上的点也算被地毯覆盖。
*/
#include<iostream>
using namespace std;
/*
                               (r[2],r[3])

(r[0],r[1])
*/
int r[4];
void area(int x,int y,int a,int b){
    r[0]=x;
    r[1]=y;
    r[2]=x+a;
    r[3]=y+b;
}
int main(){
    int n;
    cin>>n;
    int input[11000][4];
    for(int i=1;i<=n;i++){
        cin>>input[i][0]>>input[i][1]>>input[i][2]>>input[i][3];
    }
    int x,y;
    int ans=-1;
    cin>>x>>y;
    for(int i=1;i<=n;i++){
        area(input[i][0],input[i][1],input[i][2],input[i][3]);
        if(x>=r[0]&&x<=r[2]&&y>=r[1]&&y<=r[3]){
            ans=i;
        }
    }
    cout<<ans;
}