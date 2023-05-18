#include<bits/stdc++.h>
using namespace std;

 
// Function to demonstrate printing pattern
void triangle(int n)
{
    // number of spaces
    int k = 2 * n - 2;
 
    // Outer loop to handle number of rows
    // n in this case
    for (int i = 1; i <= n; i++) {
 
        // Inner loop to handle number spaces
        // values changing acc. to requirement
        for (int j = 1; j < k; j++)
            cout << " ";
 
        // Decrementing k after each loop
        k = k - 1;
 
        // Inner loop to handle number of columns
        // values changing acc. to outer loop
        for (int j = 1; j <= i; j++) {
            // Printing stars
            cout << j<<" ";
        }
 
        // Ending line after each row
        cout << endl;
    }
}
 
// Driver Code
int main()
{
    int n = 5;
   
      // Function Call
    triangle(n);
    return 0;
}