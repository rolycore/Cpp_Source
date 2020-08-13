#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

#define MAX_LEN 1500

size_t _calc(string &s1, string &s2, int i, int j, size_t k)
{
    size_t len = s1.length();
    size_t ret = 0;

    size_t cnt = std::min(len - i, len - j);
    vector<int> rec(cnt, 0);
    size_t o = 0;
    while(o < cnt)
    {
        rec[o] = s1[i + o] == s2[j + o] ? 0 : 1;
        o ++;
    }

    // sliding window
    size_t curr_diff = 0;
    int s = 0, e = 0;
    while(e < cnt)
    {
        //    expand
        while((curr_diff <= k) && (e < cnt))
        {            
            curr_diff += rec[e];            
            if (curr_diff <= k)
            {
                ret = std::max(ret, size_t(e - s + 1));
            }
            e++;
        }
        if(e >= cnt) break;
        
        // shrink
        while((curr_diff > k) && (s < e))
        {
            curr_diff -= rec[s++];
        }
    }
    return ret;
}

size_t calc(string &s1, string &s2, int k)
{
    size_t len = s1.length();
    size_t ret = 0;

    int i = 0, j = 0;
    for(j = 0; j < len; j ++)
    {
        size_t r = _calc(s1, s2, i, j, k);        
        ret = std::max(ret, r);
    }
    
    j = 0;
    for(int i = 1; i < len; i ++)
    {
        size_t r = _calc(s1, s2, i, j, k);        
        ret = std::max(ret, r);
    }
        
    return ret;
}

int main() 
{
    int t; cin >> t;
    while (t--)
    {
        int k; cin >> k;
        char buf1[MAX_LEN + 1] = {0};
        char buf2[MAX_LEN + 1] = {0};
        scanf("%s %s", buf1, buf2);
        
        string str1(buf1);
        string str2(buf2);
        size_t r = calc(str1, str2, k);
        cout << r << endl;
    }

    return 0;
}
