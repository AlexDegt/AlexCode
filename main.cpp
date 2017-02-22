#include <iostream>
#include <malloc.h>
#include <cstdlib>

using namespace std;

class stack
{
    public:
        stack();
        stack(size_t capacit);
        void push(double value);
        double pop();
        void empty();
        size_t  size();
    private:
        double * data;
        size_t sizeVal;
        size_t capacityVal;
        int checkCap();
        bool ok() const;
};

int main()
{
    stack s(0);
    s.push(1);
    s.push(2);
    cout << s.pop() << endl;
    system("PAUSE");
    return 0;
}
bool stack::ok() const
{
    return ((data && capacityVal && sizeVal <= capacityVal) || (!data && !capacityVal && !sizeVal));
}

stack::stack(size_t capacit)
    {
        data = new double[capacit];
        capacityVal = capacit;
        sizeVal = 0;
    }

size_t stack::size()
{
    if (ok())
    {
        return sizeVal;
    }
}

void stack::push(double value)
{
    if (data)
    {
        if (sizeVal >= capacityVal)
            data = (double*) realloc(data,(++capacityVal)*sizeof(double));
        data[sizeVal++] = value;
    }
    else
        cout << "ERROR" << endl;
}

double stack::pop()
{
    if (ok())
    {
        return data[sizeVal-1];
        sizeVal--;
    }
}

void stack::empty()
{
    if (ok())
    {
        for (size_t i = 0; i < sizeVal; i++)
            data[i] = 0;
        sizeVal = 0;
    }
}
