#include <iostream>
#include <vector>
#include <ctime>
#include  <algorithm>
#include <cmath>

using namespace std;

void Print_vec(vector <int> w)
{
    for (int i = 0; i < w.size(); i++) {
        cout << w[i] << " ";
    }
    cout << endl;
}
class myLambda
{
public:
    myLambda() : i(0) {}
    
    vector <int> get_vec2() 
    {
        return vec_int2;
    }
    void set_dist(int dist) 
    {
        _dist = dist;
    }
    void operator()(int _x) 
    {
        if (i > _dist)
        {
            i++;
            vec_int2.push_back(_x);
        }
        i++;        
    }
private:
    int _dist, i;
    vector <int> vec_int2;
};

int main()
{
    setlocale(0, "");
    srand(time(0));
    vector <int> vec_int;
    
    vector<int>::iterator iter2;
    for (int i = 0; i < 10; i++)
    {
        vec_int.push_back((rand() % 100));
    }
    myLambda g;
    Print_vec(vec_int);    
    g.set_dist((distance(vec_int.begin(), max_element(vec_int.begin(), vec_int.end()))));
    g = for_each(vec_int.begin(), vec_int.end(), g);
    Print_vec(g.get_vec2());
    
    getchar();
    return 0;
}