#include <iostream>
#include <vector>
using namespace std;

void init(vector<double> &v) // pass-by-reference
{
    for (int i = 0; i < v.size(); ++i)
        v[i] = i;
}
void g(int x)
{
    vector<double> vd1(10);      // small vector
    vector<double> vd2(1000000); // large vector
    vector<double> vd3(x);       // vector of some unknown size
    init(vd1);
    init(vd2);
    init(vd3);
}

int main()
{
    g(1000);
}