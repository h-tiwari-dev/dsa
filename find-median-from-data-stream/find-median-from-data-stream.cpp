#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater_equal<int>> *min_heap;
    priority_queue<int, vector<int>, less<int>> *max_heap;
    MedianFinder()
    {
        min_heap = new priority_queue<int, vector<int>, greater_equal<int>>();
        max_heap = new priority_queue<int, vector<int>, less<int>>();
    }

    void addNum(int num)
    {

        min_heap->push(num);
        if ((max_heap->size() && min_heap->size()) && (min_heap->top() > max_heap->top()))
        {
            int value = min_heap->top();
            min_heap->pop();
            max_heap->push(value);
        }
        if (min_heap->size() > (max_heap->size() + 1))
        {
            int value = min_heap->top();
            min_heap->pop();
            max_heap->push(value);
        }
        if (max_heap->size() > (min_heap->size() + 1))
        {
            int value = max_heap->top();
            max_heap->pop();
            min_heap->push(value);
        }
    }

    double findMedian()
    {
        if (max_heap->size() > min_heap->size())
        {
            return max_heap->top();
        }
        else if (min_heap->size() > max_heap->size())
        {
            return min_heap->top();
        }
        return (float(max_heap->top()) + float(min_heap->top())) / 2;
    }
};

int main()
{
    MedianFinder *medianFinder = new MedianFinder();
    medianFinder->addNum(1);                    // arr = [1]
    medianFinder->addNum(2);                    // arr = [1, 2]
    cout << medianFinder->findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder->addNum(3);                    // arr[1, 2, 3]
    cout << medianFinder->findMedian() << endl; // return 2.0

    return 0;
}