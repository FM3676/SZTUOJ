#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Cat
{
private:
    string name;
    float weight;

public:
    Cat()
    {
        name = "<name>";
        weight = 0;
    }
    Cat(string _n, float _w)
    {
        name = _n;
        weight = _w;
    }
    string getName()
    {
        return name;
    }
    int getWeight()
    {
        return weight;
    }
};

void compare(Cat &p, Cat &q)
{
    Cat temp;
    if (p.getWeight() > q.getWeight())
    {
        temp = p;
        p = q;
        q = temp;
    }
}

int main()
{
    int t;
    float weight;
    string name;
    cin >> t;
    Cat *cats = new Cat[t];
    for (int i = 0; i < t; i++)
    {
        cin >> name >> weight;
        cats[i] = {name, weight};
    }

    for (int i = 0; i < t - 1; i++){
        for (int j = i + 1; j < t; j++){
            compare(cats[i], cats[j]);
        }
    }

    for (int i = 0; i < t; i++) {
        cout << cats[i].getName() << " ";
    }
}