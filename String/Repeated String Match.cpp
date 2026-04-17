// Input: a = "abcd", b = "cdabcdab"
// Output: 3
// Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

/*
* Approach:
* 1. We can do one thing is that add string a untill the length become greater than or equal to b and increment the count.
* 2. After that check 
*    a. If b is a substring of a then return the count of how many times we have added a.
*    b. If b is not a substring of a then add one more time a and check if b is a substring of a or not.
*    c. If b is a substring of a then return the count of how many times we have added a.
*    d. If b is not a substring of a then return -1.
*/

vector<int> computeLPSArray(string pat){
    int len=0;
    int i=1;
    vector<int> lps(pat.size(),0);

    while (i<n)
    {
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(j!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
    
}

bool isSubstring(string a,string b){
    int n = a.size();
    int m = b.size();
    vector<int> lps = computeLPSArray(b);
    int j=0;
    int i=0;
    while(i<n){
        if(a[i]==b[j]){
            j++;
            i++;
        }
        if(j==m){
            return 1;
        }else if(i<n && a[i]!=b[j]){
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    return 0;
}

int repeatedStringMatch(string a, string b) {
    int count=1;
    string temp = a;
    while(temp.size()<b.size()){
        temp+=a;
        count++;
    }
    if(isSubstring(temp,b)){
        return count;
    }
    temp+=a;
    count++;
    if(isSubstring(temp,b)){
        return count;
    }
    return -1;
}