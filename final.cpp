#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
string longestCommonPrefix(vector<string>& S) {
        if (S.size() == 0) return "";
        std::string prefix = S[0];
 
        for (int i = 1; i < S.size(); ++i) {
          std::string s = S[i];
          if (s.size() == 0 || prefix == "") return "";
          prefix = prefix.substr(0, std::min(prefix.size(), s.size()) );
            
            for (int k = 0; k < s.size() && k < prefix.size(); ++k) {
                if (s[k] != prefix[k]) {
                    prefix = prefix.substr(0, k);
                    break;
                }
            }
        }
        return prefix;
    }
string commonsuffix(string s1,string s2)
{
    int m=s1.size()-1; int n=s2.size()-1; string ans="";

    while(m>-1 && n>-1)
    {
        if(s1[m]==s2[n]){
            ans+=s1[m];
            m--; n--;
        }
        else
        {
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    int a1 = -1;
    int a2 = -2;
    vector<string> s;
    string word;
    while (cin >> word && word != "$") {
        s.push_back(word);
    }
    string y="";
    string l="";
    for (int i=0; i < s.size()-1; i++){
        vector<string> x;
        x.push_back(s[i]);
        x.push_back(s[i+1]);
        string z = longestCommonPrefix(x);
        string q = commonsuffix(s[i],s[i+1]);
        if(q.length()>l.length()){
            l = q;
            a1 = 0;
        }
        if(z.length()>y.length()){
            y = z;
            a2 = 0;
        }
    }
    if (a2==0){
        cout << y << endl;
    }
    else{
        cout << a2 << endl;
    }
    if (a1==0){
        cout << l << endl;
    }
    else{
        cout << a1 << endl;
    }
    return 0;
}
