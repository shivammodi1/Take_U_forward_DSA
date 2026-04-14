#include<bits/stdc++.h>
using namespace std;

/*
KMP (Knuth-Morris-Pratt) Algorithm

1. KMP ek string searching algorithm hai.
   Iska use text ke andar pattern ko efficiently search karne ke liye hota hai.

2. Basic Idea:
   Normal search me mismatch hone par hum pattern ko fir se start se check karte hain.
   KMP me hum aisa nahi karte — hum pattern ke kuch part ko reuse karte hain,
   jisse unnecessary comparisons avoid hote hain.

3. KMP ke 2 main steps hote hain:

   (a) Preprocessing (LPS Array banana):
       LPS (Longest Prefix which is also Suffix) array banate hain pattern ke liye.
       LPS = Longest Prefix which is also Suffix
       Har index par yeh store hota hai ki us point tak ka
       longest proper prefix jo suffix bhi ho, uski length kya hai.

       Example:
       Pattern: A B A B C
       LPS:     0 0 1 2 0

   (b) Searching:
       Do pointers use hote hain:
       i -> text ke liye
       j -> pattern ke liye

       - Agar characters match kare:
         i++ aur j++

       - Agar mismatch ho:
         j = LPS[j - 1]  (pattern shift hota hai, restart nahi hota)

4. Time Complexity:
   - LPS banane me: O(m)
   - Searching me: O(n)

   Total: O(n + m)

   (n = text length, m = pattern length)

5. Advantage:
   - Repeated comparison avoid karta hai
   - Efficient string matching provide karta hai
*/ 

vector<int> LPS(string pattern){
   int n=pattern.size();
   vector<int> lps(n,0);
   int len=0;
   int i=1;
   while(i<n){
      if(pattern[i]==pattern[len]){
         len++;
         lps[i]=len;
         i++;
      }else{
         if(len!=0){
            len = lps[len-1];
         }
         else{
            lps[i]=0;
            i++;
         }
      }
   }
   return lps;
}

int KMP(string text,string pattern){
   vector<int> lps = LPS(pattern);
   int n = text.size();
   int m = pattern.size();
   int i=0;
   int j=0;
   while(i<n){
      if(text[i]==pattern[j]){
         i++;
         j++;
      }
      if(j==m){
         return i-j; // pattern found at index (i-j)
      }
      else if(i<n && text[i]!=pattern[j]){
         // Mismatch after j matches
         if(j!=0){
            j = lps[j-1];
         }
         else{
            // No match, move to the next character in text
            i++;
         }
      }
   }
   return -1; // pattern not found
}

int main(){
   return 0;
}