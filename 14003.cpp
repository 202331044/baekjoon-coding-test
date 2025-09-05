#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    vector<int> res;
    vector<int> index;

    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        vector<int>::iterator it = lower_bound(res.begin(), res.end(), vec[i]);

        if (it == res.end())
        {
            res.push_back(vec[i]);
            index.push_back(res.size());
        }
        else
        {
            *it = vec[i];
            index.push_back(it - res.begin() + 1);
        }
    }

    cout << res.size() << "\n";

    int size = res.size();
    stack<int> s;

    for (int j = vec.size() - 1; j >= 0; --j)
    {
        if (size == index[j])
        {
            s.push(vec[j]);
            size--;
        }     
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}
