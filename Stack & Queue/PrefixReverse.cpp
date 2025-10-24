#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool ispresent(string word, char ch) {
    for(int i=0; i<word.length(); i=i+1) {
        if(ch==word[i])
            return true;
    }
    return false;
}

string reverse(string &word, char ch) {
    stack<char>st;
    int l=0,i=0;
    string temp="";
    for(int i=0; i<word.length(); i=i+1) {
        if(word[i]==ch) {
            break;
        } 
        else {
            l++;
            st.push(word[i]);
        }
    }
    st.push(ch); // push character itself
    while(i<(l+1)) {
        temp.push_back(st.top());
        st.pop();
        i++;
    }
    return temp;
}

int main() {
    string word="abcdefd";
    char ch='d';
    bool present=ispresent(word, ch);
    if(present==true) {
        string temp=reverse(word, ch);
        int index;
        for(int i=0; i<word.length(); i=i+1) {
            if(ch==word[i]) {
                index=i;
                break;
            }
        }
        for(int i=0; i<(index+1); i=i+1) {
            word[i]=temp[i];
        }
        for(int i=0; i<word.length(); i=i+1) {
            cout << word[i];
        }
    }
    
    return 0;
}