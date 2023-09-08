#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Define a structure to represent a document
struct Document {
    int id;
    string content;
};

// Define a simple inverted index data structure
unordered_map<string, vector<int>> invertedIndex;

// Function to tokenize a document into words
vector<string> tokenize(const string& document) {
    vector<string> tokens;
    string word;
    for (char c : document) {
        if (isalnum(c)) {
            word += tolower(c);
        } else if (!word.empty()) {
            tokens.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        tokens.push_back(word);
    }
    return tokens;
}

// Function to build the inverted index from a collection of documents
void buildInvertedIndex(const vector<Document>& documents) {
    for (const Document& doc : documents) {
        vector<string> tokens = tokenize(doc.content);
        for (const string& token : tokens) {
            cout<<token<<" ";
            invertedIndex[token].push_back(doc.id);
        }
    }
}

// Function to perform a simple search using the inverted index
vector<int> search(const string& query) {
    string queryTerm="";
    for(auto ch:query){
        queryTerm+=tolower(ch);
    }
     
    if (invertedIndex.find(queryTerm) != invertedIndex.end()) {
        return invertedIndex[queryTerm];
    }
    return vector<int>();
}

int main() {
    // Create a sample collection of documents
    vector<Document> documents = {
        {1, "This is a sample document."},
        {2, "Sample documents are used for testing."},
        {3, "A search engine example is provided."},
    };

    // Build the inverted index
    buildInvertedIndex(documents);

    // Perform a search
    string searchTerm;
    cout << "Enter a search term: ";
    cin >> searchTerm;

    vector<int> results = search(searchTerm);

    if (!results.empty()) {
        cout << "Search results for '" << searchTerm << "':" << endl;
        for (int docId : results) {
            cout << "Document " << docId << ": " << documents[docId - 1].content << endl;
        }
    } else {
        cout << "No results found for '" << searchTerm << "'" << endl;
    }

    return 0;
}
