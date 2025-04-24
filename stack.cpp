#include <iostream>

#define SIZE 100
using namespace std;

class stack
{
    public:
        int topindex = 0;
        int st[SIZE];

        bool empty(){
            return topindex == 0;
        }

        bool full(){
            return topindex == SIZE;
        }

        void push (int x){
            if (!full())
            {
                st[topindex] = x;
                topindex ++;
            }
        }

        void pop(){
            if (!empty())
            {
                topindex--;
            }
            
        }

        int top(){
            return st[topindex - 1];
        }
};

int main() {
    stack s;

    s.push(1);
 

    cout << s.top() << endl;
    
 

    return 0;
}
