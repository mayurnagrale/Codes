#include<bits/stdc++.h>
using namespace std;

//Sort elements in a stack
stack<int> sorted(stack<int> & unsorted){
    stack<int> second;
    while(!unsorted.empty()){
        int temp= unsorted.top();
        unsorted.pop();
        while(!second.empty() && second.top()>temp){
            int x= second.top();
            unsorted.push(x);
            second.pop();
        }
        second.push(temp);
    }

    //push back all items from second stack to first one
    while(!second.empty()){
        unsorted.push(second.top());
        second.pop();
    }
    return unsorted;
}

//Balenced Parenthesis
// bool checkParenthesis(string s){
//     stack<char> temp;
//     int templen=0;
//     while(templen<s.size()){
//         if()
//         templen++;
//     }
//     return false;
// }

int checkParenthesis(string A)
{
    if (A == "")
        return 1;
    stack<char> parenthesis;
    int i = 0, count = 0;
    while (i < A.length())
    {
        if (A[i] == '{' || A[i] == '(' || A[i] == '['){
            parenthesis.push(A[i]);
        }
        else{
            if (!parenthesis.empty()){
                if (A[i] == ')' && parenthesis.top() == '(')
                    parenthesis.pop();
                if (A[i] == '}' && parenthesis.top() == '{')
                    parenthesis.pop();
                if (A[i] == ']' && parenthesis.top() == '[')
                    parenthesis.pop();
            }
            else{
                count++; /* For the ones with no opening brackets but having closed brackets */
            }
        }
        i++;
    }
    if (!parenthesis.empty() || count > 0)
    {
        return 0;
    }
    return 1;
}

string doubleTrouble(string A){
    int i=0;
    string temp="x";
    stack<char> st;
    while(!st.empty() && i<A.size()){
        if(st.top() == A[i]){
            st.pop();
        }
        else{
            st.push(A[i]);
        }
        i++;
    }

    if(st.empty()){
        return temp;
    }

    while(!st.empty()){
        temp = temp + st.top();
        st.pop();
    }
    return temp;
}

int main(){
    // stack<int> unsorted;
    // stack<int> res;
    // unsorted.push(1);
    // unsorted.push(3);
    // unsorted.push(5);
    // unsorted.push(2);
    // unsorted.push(-1);
    // unsorted.push(0);
    // unsorted.push(-5);
    // unsorted.push(6);
    // unsorted.push(4);
    // res = sorted(unsorted);
    // while(!res.empty()){
    //     int temp=res.top();
    //     cout<<temp<<endl;
    //     res.pop();
    // }
    string s="abba";
    cout<<doubleTrouble(s);
    return 0;
}