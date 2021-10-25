#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Efficiency {
    double diam = 1;
    double time = 1;
    int index = 0;
    double eff = 0;
};

bool Compare(const Efficiency* leftSide, const Efficiency* rightSide)
{
    if (leftSide->eff == rightSide->eff)
    {
        return leftSide->diam > rightSide->diam;
    }
    else
    {
        return (leftSide->eff > rightSide->eff);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Efficiency*> v;
    int i = 0;
    double diam = 0;
    double time = 0;
    do
    {
        cin >> diam >> time;
        if (diam > 0 && time > 0)
        {
            Efficiency* obj = new Efficiency;
            obj->time = time;
            obj->diam = diam;
            obj->eff = (double)((double)(obj->diam * obj->diam) / (double)obj->time);
            obj->index = i + 1;
            v.push_back(obj);
            i++;
        }
    } while (i < n);
    stable_sort(v.begin(), v.end(), Compare);
    for (int i = 0; i < n; i++)
    {
        cout << v.at(i)->index << " ";
    }

    return 0;
}