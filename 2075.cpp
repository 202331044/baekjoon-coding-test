#include "iostream"
using namespace std;

class Priorty_queue
{
private:
    int* arr = new int[1500 * 1500];
    int pos = 0;

public:
    void Insert(int value);
    int Delete();
};

void Priorty_queue::Insert(int value)
{
    arr[pos] = value;
    int t_pos = pos;
    pos++;
    while (t_pos > 0)
    {
        if (arr[(t_pos - 1) / 2] < arr[t_pos])
        {
            int tmp = arr[(t_pos - 1) / 2];
            arr[(t_pos - 1) / 2] = arr[t_pos];
            arr[t_pos] = tmp;
            t_pos = (t_pos - 1) / 2;
        }
        else
            break;
    }
    //if (arr[pos - 1] == value && pos != 1)
    //    pos--;
    return;
}

int Priorty_queue::Delete()
{
    int result = arr[0];
    pos--;
    arr[0] = arr[pos];
    int t_pos = 0;
    while (t_pos < pos)
    {
        if (t_pos * 2 + 2 <= pos)
        {
            int left = arr[t_pos * 2 + 1];
            int right = arr[t_pos * 2 + 2];
            if (left >= right)
            {
                if (arr[t_pos] >= left)
                    break;
                else
                {
                    arr[t_pos * 2 + 1] = arr[t_pos];
                    arr[t_pos] = left;
                    t_pos = t_pos * 2 + 1;
                }
            }
            else
            {
                if (arr[t_pos] >= right)
                    break;
                else
                {
                    arr[t_pos * 2 + 2] = arr[t_pos];
                    arr[t_pos] = right;
                    t_pos = t_pos * 2 + 2;
                }
            }
        }
        else if (t_pos * 2 + 1 <= pos)
        {
            int left = arr[t_pos * 2 + 1];
            if (arr[t_pos] >= left)
                break;
            else
            {
                arr[t_pos * 2 + 1] = arr[t_pos];
                arr[t_pos] = left;
                t_pos = t_pos * 2 + 1;
            }
        }
        else
            break;
    }
    return result;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, value;
    Priorty_queue que;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> value;
            que.Insert(value);
        }
    }

    for (int k = 0; k < n - 1; k++)
        que.Delete();
    cout << que.Delete();
    return 0;
}