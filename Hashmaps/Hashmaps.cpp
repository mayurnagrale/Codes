#include<bits/stdc++.h>
using namespace std;

int cal(string s1,string s2){
  unordered_map<char,int> fh;
	unordered_map<char,int> sh;
	int minVal=INT_MAX;

  for(auto c :s1){
		fh[c]++;
	}

  for(auto c :s2){
		sh[c]++;
	}

  for(auto it:sh){
    auto i=fh.find(it.first);
    if(i!=fh.end()){
      // cout<<i->first<<" "<<i->second<<" ";
      // cout<<it.first<<" "<<it.second<<endl;
      minVal= min(minVal,i->second/it.second);
    }
  }

  return minVal;
}


int main(){
     // Create a HashMap
  unordered_map<string, int> my_map;

  // Insert elements into the HashMap
  my_map["John"] = 10;
  my_map["Jane"] = 20;
  my_map["Mike"] = 30;

  // // Get the number of elements in the HashMap
  // cout << my_map.size() << endl; // Prints 3

  // // Find the value associated with the key "John"
  // auto it = my_map.find("John");
  // if (it != my_map.end()) {
  //   cout << "The value associated with the key 'John' is " << it->second << endl;
  // } else {
  //   cout << "The key 'John' does not exist" << endl;
  // }

  // // Check if the HashMap is empty
  // if (my_map.empty()) {
  //   cout << "The HashMap is empty" << endl;
  // } else {
  //   cout << "The HashMap is not empty" << endl;
  // }

  // // Remove all elements from the HashMap
  // my_map.clear();

  // // Check if the HashMap is empty again
  // if (my_map.empty()) {
  //   cout << "The HashMap is empty" << endl;
  // } else {
  //   cout << "The HashMap is not empty" << endl;
  // }

  // // Find the value associated with the key "John"
  // int value = my_map["John"];
  // cout << "The value associated with the key 'John' is " << value << endl;

  // // Remove the key-value pair with the key "Jane"
  // my_map.erase("Jane");

  // // Print the contents of the HashMap
  // for (auto it = my_map.begin(); it != my_map.end(); ++it) {
  //   cout << it->first << " : " << it->second << endl;
  //}

  // cal("hgeb","ebh");
  int num=1;
	//cin >> num;    //Reading input from STDIN
	//cout << "Input number is " << num << endl;	// Writing output to STDOUT
	for (int i = 0; i < num; i++) {
    // Read the size of the string
    int n1,n2;
    //cin >> n1 >> n2;
    // Read the two strings
    string str1, str2;
    //cin >> str1 >> str2;
    str1 ="hgeb";
    str2="ebh";
	  cout<<cal(str1,str2)<<endl;
	}

  return 0;
}

/*
2
4 3 
hgeb
ebh
7 3
xyzxyxz
xyz
*/