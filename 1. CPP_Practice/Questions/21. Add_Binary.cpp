/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101" 


 * logic: reverse the string and do bit comparision
eg: 10,111 , we will manipulate 111(max one) and give the answer
reverse: 01,111 and a variable carry=0 for stroring carry
now computation bit by bit
01,111 and carry=0........111=>111(no change)
01,111 and carry=0........111=>101....carry=1
01 is done and we are left with 101 and carry=1
now 101 and carry=1 gives 101=>100....carry=1
reverse(100)=001
now just add the carry 001=>1001 which is the answer
*/


string addBinary(string a, string b) {
        reverse(a.begin(),a.end());reverse(b.begin(),b.end());
        char carry='0';
//swap if b>a
        if(a.length()<b.length()){string t=a; a=b;b=t;}
        int i;
//now compare bits with smaller array and also check carry
            for(i=0;i<b.length();i++){
                if(b[i]=='1'&&a[i]=='0'&&carry=='0')a[i]='1';
                else if(b[i]=='1'&&a[i]=='1'&&carry=='0'){a[i]='0';carry='1';}
                else if(b[i]=='0'&&a[i]=='0'&&carry=='1'){a[i]='1';carry='0';}
                else if(b[i]=='0'&&a[i]=='1'&&carry=='1'){a[i]='0';}
            }
//now check carry with the remaining bits of the longer array
                 while(carry=='1'&&i<a.length()){
                    if(a[i]=='0'){a[i]='1';carry='0';}
                    else a[i]='0';
                     i++;
                 }
         reverse(a.begin(),a.end());
//if carry is still left
         if(carry=='1')a.insert(a.begin(),carry);
        return a;
        }
