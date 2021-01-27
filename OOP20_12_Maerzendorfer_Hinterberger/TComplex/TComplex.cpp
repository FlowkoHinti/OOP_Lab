#include "Complex.cpp"
#include <deque>
#include <iostream>

//using namespace HeeMan;
template <typename T, int val = 10>
class FixedQueue
{
public:
    FixedQueue() {
        q;
    }
    bool empty() {
        return q.empty();
    }
    int size() {
        return q.size();
    }
    T& front() {
        return q.front();
    }
    T back() {
        return q.back();
    }
    void push(T t) {
        if (q.size() == val) {
            q.front() = t;
        }
        else
        {
            q.push_back(t);
        }
    }
    void pop() 
    {
        q.pop_front();
    }

private:
    std::deque<T> q;
};

int main()
{
    
    Complex<long double> heeHee{ std::string{"12+4.3232i"} };
    Complex<int> hee(std::string{ "5-7i" });

    FixedQueue<int, 20> mq;

    for(int i=0; i<30; i++){
        mq.push(i);
    }
}

