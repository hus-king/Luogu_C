#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(void)
{
    int MAX_TIME,kinds;
    cin >> MAX_TIME >> kinds;
    vector<pair<int, int>> time_value;
    vector<int> values(MAX_TIME+1, 0);
    for(int i=0; i < kinds; i++)
    {
        int n, m;
        cin >> n >> m;
        time_value.push_back({n, m});
    }
    sort(time_value.begin(), time_value.end());
    for(int i = 0; i < kinds; i++)
    {
        for(int j = MAX_TIME; j >= time_value[i].first; j--)
        {
            int count;
            for(count = 1; count * time_value[i].first <= j; count++)
            {
                if(values[j] < values[j - count * time_value[i].first] + count * time_value[i].second)
                {
                    values[j] = values[j - count * time_value[i].first] + count * time_value[i].second;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout << values[MAX_TIME] << endl;
}