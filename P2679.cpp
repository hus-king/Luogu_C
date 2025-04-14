    #include <bits/stdc++.h>
    using namespace std;
    int a,b,k;
    string A;
    string B;
    int Astart;
    int Bstart;
    int out = 0;
    vector<vector<int>> maybe(210);
    void find(int x);
    int main(){
        cin>>a>>b>>k;
        cin>>A>>B;
        Astart = 0;
        Bstart = 0;
        find(0);
        cout<<out;

    }
    void find(int x){
        if(x == k){
            if(Bstart == b){
                out++;
                out %= 1000000007;
            }
            return;
        }
        if(Bstart >= b) return;
        if(b-Bstart < k-x) return;
        for(int i=Astart;i<a;i++){
            if(a-1-i < k-1-x) break;
            if(A[i] == B[Bstart]){
                maybe[x].push_back(i);
                // cout<<"i="<<i<<endl;
            }
        }
        reverse(maybe[x].begin(),maybe[x].end());
        while(maybe[x].size()){
            int test = maybe[x].back();
            // cout<<"test="<<test<<endl;
            maybe[x].pop_back();
            for(int i=0;;i++){
                int temp = Astart;
                Astart = test;
                if(test+i >= a) break;
                if(A[test+i] == B[Bstart+i]){
                    Astart+=i+1;
                    Bstart+=i+1;
                    find(x+1);
                    Astart-=i+1;
                    Bstart-=i+1;
                }
                else{
                    Astart = temp;
                    break;
                }
            }
        }
    }