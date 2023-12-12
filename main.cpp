#include <iostream>
#include <algorithm>
#include "stack.h"
#include "queue.h"

using namespace std;

template <class T> class numerate
{
public:
    numerate(T start = 0, T _shift = 1): seed(start), shift(_shift) {};
    T operator () () {T old = seed; seed += shift; return old; }
private:
    T seed, shift;
};

template <class T, class C> T sum (const C& c)
{
    T res = 0;
    for (typename C::const_iterator i = c.begin(); i != c.end(); ++i)
       res += *i;
    return res;
}

void test_queue()
{
    Queue<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1 << endl;          // 1->2->3
    cout << s1.getSize() << endl;

    Queue<int> s2 (s1), s3;

    s1.pop();
    s1.push(4);
    s1.push(5);

    s2.pop();
    s2.push(6);

    cout << s1 << endl;         // 2->3->4->5
    cout << s1.getSize() << endl;

    cout << s2 << endl;         // 2->3->6
    cout << s2.getSize() << endl;

    s3 = s1;

    s1.pop();
    s1.push(7);
    s1.push(8);

    s3.pop();
    s3.push(9);

    cout << s1 << endl;         // 3->4->5->7->8
    cout << s1.getSize() << endl;

    cout << s2 << endl;         // 2->3->6
    cout << s2.getSize() << endl;

    cout << s3 << endl;
    cout << s3.getSize() << endl;  // 3->4->5->9

}

void test2_queue()
{
    Queue<int> s1, s2;
    numerate<int> f(100);

    s1.push(1);
    s1.push(2);
    s1.push(3);

    s2.push(5);
    s2 = s1;
    s2.push(4);

    cout << s1 << endl;          // 1->2->3
    cout << s1.getSize() << endl;

    cout << s2 << endl;          // 1->2->3->4
    cout << s2.getSize() << endl;

    swap(s1, s2);

    cout << s1 << endl;          // 1->2->3->4
    cout << s1.getSize() << endl;

    cout << s2 << endl;          // 1->2->3
    cout << s2.getSize() << endl;

    generate(s1.begin(), s1.end(), f);

    cout << s1 << endl;          // 100->101->102->103
    cout << s1.getSize() << endl;

    cout << sum<int,List<int>>(s2) << endl;     // 6
}

void test_stack()
{
    Stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1 << endl;         // 3->2->1
    cout << s1.getSize() << endl;

    Stack<int> s2 (s1), s3;

    s1.pop();
    s1.push(4);
    s1.push(5);

    s2.pop();
    s2.push(6);

    cout << s1 << endl;         // 5->4->2->1
    cout << s1.getSize() << endl;

    cout << s2 << endl;         // 6->2->1
    cout << s2.getSize() << endl;

    s3 = s1;

    s1.pop();
    s1.push(7);
    s1.push(8);

    s3.pop();
    s3.push(9);

    cout << s1 << endl;         // 8->7->4->2->1
    cout << s1.getSize() << endl;

    cout << s2 << endl;         // 6->2->1
    cout << s2.getSize() << endl;

    cout << s3 << endl;         // 9->4->2->1
    cout << s3.getSize() << endl;

}

void test2_stack()
{
    Stack<int> s1, s2;
    numerate<int> f(100);

    s1.push(1);
    s1.push(2);
    s1.push(3);

    s2.push(5);
    s2 = s1;
    s2.push(4);

    cout << s1 << endl;          // 3->2->1
    cout << s1.getSize() << endl;

    cout << s2 << endl;          // 4->3->2->1
    cout << s2.getSize() << endl;

    swap(s1, s2);

    cout << s1 << endl;          // 4->3->2->1
    cout << s1.getSize() << endl;

    cout << s2 << endl;          // 3->2->1
    cout << s2.getSize() << endl;

    generate(s1.begin(), s1.end(), f);

    cout << s1 << endl;          // 100->101->102->103
    cout << s1.getSize() << endl;

    cout << sum<int,List<int>>(s2) << endl;     // 6
}

int main()
{
    test_queue();
    cout << endl;
    test2_queue();
    cout << endl;
    cout << endl;

    test_stack();
    cout << endl;
    test2_stack();
    cout << endl;
    cout << endl;

    return 0;
}
