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
    int a1 = -2;
    vector<string> s;
    string word;
    cout << "Enter words (enter $ to stop):\n";
    while (cin >> word && word != "$") {
        s.push_back(word);
    }
    string y="";
    for (int i=0; i < s.size()-1; i++){
        vector<string> x;
        x.push_back(s[i]);
        x.push_back(s[i+1]);
        string z = longestCommonPrefix(x);
        string q = commonsuffix(s[i],s[i+1]);
        if(q.length()>z.length()){
            z = q;
            a1 = -1;
        }
        if(z.length()>y.length()){
            y = z;
        }
    }
    cout << y << endl;
    cout << a1 << endl;
    return 0;
}