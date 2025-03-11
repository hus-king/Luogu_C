#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int x,y;
        string move;
        cin>>x>>y>>move;
        for(char c:move){
            // cout<<"c="<<c<<endl;
            // cout<<"move ="<<move<<endl;
            switch(c){
                case 'l':x--;break;
                case 'r':x++;break;
                case 'f':y++;break;
                case 'b':y--;break;
            }
            if(x>n) x--;
            if(x<1) x++;
            if(y>n) y--;
            if(y<1) y++;
        }
        cout<<x<<" "<<y<<endl;
    }
}