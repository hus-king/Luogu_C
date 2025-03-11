#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(void)
{
    int MAX_TIME, kinds;
    cin >> MAX_TIME >> kinds;
    vector<pair<int, int>> time_value;
    vector<int> value(MAX_TIME+1, 0);
    for(int i = 0; i < kinds; i++)
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
            value[j] = max(value[j], value[j-time_value[i].first] + time_value[i].second);
        }
    }
    cout << value[MAX_TIME];
}