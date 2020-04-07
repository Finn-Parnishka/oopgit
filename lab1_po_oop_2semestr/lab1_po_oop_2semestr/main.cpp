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
void Proc_vec(vector <int> vec_int, vector <int> &vec_int2)
{
    vector<int>::iterator iter;    
    iter = max_element(vec_int.begin(), vec_int.end());

    for (int i = (distance(vec_int.begin(), iter) + 1); i < vec_int.size(); i++)
    {
        vec_int2.push_back(vec_int[i]);
    }
}

int main() 
{
    setlocale(0, "");
    srand(time(0));
    vector <int> vec_int;
    vector <int> vec_int2;
    vector<int>::iterator iter2;
    for(int i = 0; i < 10; i++)
    {
        vec_int.push_back((rand() % 100));
    }
    
    Print_vec(vec_int);
    Proc_vec(vec_int, vec_int2);
    Print_vec(vec_int2);
    
    

    getchar();
    return 0;
}