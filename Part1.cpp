/** \file Part1.cpp
 * \brief File contains the main function implementation for Part 1
 *
 *
 */

#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include "Part1functions.cpp"
using namespace std;
int main()
{
    string nospace;/**< string nospace-For storage without spaces */
    char test[200000];
    cin.getline(test,200000);
    /**< Ignoring all spaces in Input expression */
    for(int i=0;i<strlen(test);i++)
    {
        if(test[i]!=' ')
        {
            nospace+=test[i];
        }
    }
    //string s="(d>(~aV((~b^(c>((~a>((cV(a>((~cV(a>(~cV(b>((~c>(aV(c^(a^(~bV(dV((a>(c>(bV(~d^(~c>(b>(d>(~b>(((~c>(d^(cV(aV(b^(a^(bV(~dV(~a>((~c^(~d^((a>(d>((~b>(((~a^(d>(~aV(~b>((d>((b>(d^(~bV(~cV(d^((~a^(~bV(a>((b^(~dV(c^(d>(b>(~c^(a>(dV(a^(((cV(~aV(cV((~d^(a>((cV(d>(bV((((((~c>(~aV((d>(~bV((~d>(bV(c^(((~a>(((dV(b>(c^((~a>((cV(~bV((~dV(aV(c^(bV(aV(b^(d^(bV((d>(~b^((dV(~b^((d^(cV(~a^((((cV((bV(c>(a^((c>(~a^(b>(dV(aV(~cV(a^(c>(aV(((c^((aV((~cV(b^(c^((b>(((~a^(b>((dV(a^(((d>(bV((~c^(~a>(~c^(b>((d>((c^(d^((((~cV(((~aV(c>((((~a>(c>(aV(cV(~d>(cV((a>(d^(bV((c^((((~dV((b>(a>(c>(a^(dV(a>(((~c>(d^(~bV(aV(c^((~d^((~cV(a^(c>(aV((((d^(c^(a>(~c>(((~b>(d>(b>(~dV(b^(~d^(((cV(~a>((~d>(~b>(~cV(b>(a^(cV(a^(c>((d^(bV(dV((~bV(dV(c>(aV(d>((~b^(~d^(c>((b^(a>(((bV(~d>(((~c>((~bV(((d^(((~b^(c>(~b^((d>(cV((~aV(((~d>((~b>(((((~a^(dV(b>((a>(~d>(~aV(((d>((b>(cV((d>((b^(aV(cV(b^(aV(((~dV(b^((~aV(b>(d>(~c>((~a^(c>(~b^(~c>(b^((~aV(bV((d^((b^((d^((~b^(((~d^(((((~cV((d^(((~b>(d^(a>(c>(((b^(a^(((d>(c>((~a>(c^((d^(bV((a>(c>(dV(b>(cV(~bV(~d>(~b^(~d^(bV((~d>~a)^~c)))))))))))>b)))>a)))^~d)))^c)>d)))^b)>~a)))))>c)Vd))V~b))^a)>b)>d)>b))>d)Vc))Vb))^a))>c))Va)))^~b))))))^a)))))Vc)))>a)>~b))))))V~d))^b)))>~a))>~d)Vb))))>a))))V~d)>a)^c)Va))^~c))Vd)^~b))^d)))>~c))))Vd)>b))V~d)>c))>b))^d)>b)))^d)>b)))V~d))))^a))))))^~b))))>c)))))))))Va)))>c)V~d)))))))Vb)Vd)))))Vc)Vb)Vd)))))>~c))V~b))))))^d)^~c)))))))Va))V~d)>b)>d))^b))))^~d)))))))^~c)^~d)>c)))V~a)Vd))Vc)^~a)Vc)))>~d))^~b)))))>c)))>a)^~b)))^~d)))^a)V~c))^b))))>a))^b))>c)>a))))))))))^c))))V~a))Vc)^~a)>c))))>~a)))^d)))^b)))))))))>~d)))^~c))Vb))))^a)>d))>a)Vc))))^d)))>~b)))^a)Vb)Vd)^~c)Vd))))>~a)))^~b))))V~c)Vb))))))))))^d))))Va))))))>b))V~c)))))>a)Vd))Va)))^b)))>~d))))))))))>b)V~d)))))))))>b)))))))Va)))))V~c)))V~a))>b)))>~a)))";
    cout<<"Postfix expression: "<<InToPoConv(nospace)<<endl;
    string ans=inOrder(MakeTree(InToPoConv(nospace)));
    cout<<"Infix expression: "<<ans<<endl;
}
