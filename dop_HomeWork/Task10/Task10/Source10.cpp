#include<iostream>
using namespace std;

int main() {

    int prv, cur, nxt, pos = 0, prv_max = 0, min_len = 0, cur_len;
    int count = 0;
    if (cin >> prv && prv)
    {
        if (cin >> cur && cur)
        {
            if (cin >> nxt)
            {
                pos = 2;
                while (nxt)
                {
                    if ((prv < cur) && (cur > nxt))
                    {
                        if (prv_max != 0)
                        {
                            cur_len = pos - prv_max;
                            if (min_len == 0)
                                min_len = cur_len;
                            else
                                min_len = min(min_len, cur_len);
                        }
                        prv_max = pos;
                    }
                    prv = cur;
                    cur = nxt;
                    cin >> nxt;
                    pos++;

                }
            }
        }
    }
    cout << min_len;
    return 0;
}