Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size();
        int n2=version2.size();
        int i=0,j=0;
        while(i<n1 || j<n2){
            string a,b;
            while(i<n1 and version1[i]!='.')
            {
                a+=version1[i];i++;
            }
            while(j<n2 and version2[j]!='.'){
                b+=version2[j];j++;
            }
            if(a.size()==0)
                a="0";
        if(b.size()==0)
            b="0";
            if(stoi(a)<stoi(b))
                return -1;
            if(stoi(b)<stoi(a))
                return 1;
        i++,j++;
        }
        return 0;
    }
};

 vector<int> convert(string s)
    {
        vector<int> ans;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='.')
            {
                ans.push_back(res);
                res=0;
            }
            else{
                res=res*10+(s[i]-'0');
            }
        }
        ans.push_back(res);
        return ans;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1=convert(version1);
        vector<int> v2=convert(version2);
        while(v1.size()<v2.size())
            v1.push_back(0);
        while(v2.size()<v1.size())
            v2.push_back(0);
        cout<<v1.size()<<' '<<v2.size()<<endl;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]<v2[i])
                return -1;
             if(v1[i]>v2[i])
                return 1;
        }
        return 0;
    }