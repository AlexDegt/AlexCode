#include <iostream>
#include <malloc.h>
#include <cstdlib>

using namespace std;

class stack
{
    public:
        stack()
        {
            sizeVal = 0;
            capacityVal = 0;
            data = NULL;
        }
        void push(double value);
        double pop();
        void empty();
        size_t  size();
    private:
        double * data;
        size_t sizeVal;
        size_t capacityVal;
        int checkCap(int value);
};

int main()
{
    stack s;
    s.push(1);
    //s.push(2);
    //cout << s.pop() << endl;
    cout << s.size() << endl;
    system("PAUSE");
    return 0;
}

size_t stack::size()
{
    return sizeVal;
}

void stack::push(double value)
{
    printf("%lld", capacityVal);
    if (checkCap(value))
    {
        if (data)
            data = (double*) realloc(data,(capacityVal+value)*sizeof(double));
        else
            data = (double*) malloc((capacityVal+value)*sizeof(double));
    }
    data[sizeVal++] = value;
    capacityVal++;
}

double stack::pop()
{
    return data[sizeVal--];
}

void stack::empty()    //если мы хотим удалить стэк, то free(this)
{
    for (int i = 0; i < sizeVal; i++)
        data[i] = 0;
    sizeVal = 0;
}

int stack::checkCap(int value)
{
    if (sizeVal+value-1>capacityVal)
    {
        return 1;
    }
    else return 0;
}
