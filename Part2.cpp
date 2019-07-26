/** \file Part2.cpp
 * \brief File contains the implementation of main function of Part 2, logic proof checker.
 *
 */

#include<bits/stdc++.h>
#include<sstream>
#include "Part2functions.cpp"
/** \mainpage Logic Assignment 2
 *\version 1.0
 *\date 25-10-2018
 *
 *
 *  \section Part-1
    Part1.cpp
 *  \subsection Task1
 * Function to convert infix to postfix InToPoConv()
 *  \subsection Task2
 * Function to convert postfix expression to rooted binary parse tree MakeTree()
 *  \subsection Task3
 * Function to traverse parse tree to output infix expression by inorder traversal inOrder()
 * \section Part-2
 * Part2.cpp
 * A tool for verifying whether a certain proof of a given sequent is valid or not . Allowed proof rules are-
 * \subsection Premise
 * #premise
 * \subsection ANDIntroduction
 * verifyAndI()
 * \subsection ANDElimination
 * verifyAndE1() verifyAndE2()
 * \subsection ORIntroduction
 * verifyOrI1() verifyOrI2()
 * \subsection ImplicationElimination
 * verifyImpE()
 * \subsection ModusTollens
 * verifyMT()
 *
 */

using namespace std;
/**< Premise string array to store all true values */
string premise[10000];
int main()
{   bool valid=false; /**< bool valid initially set to false until a valid proof is found. */
    int n;
    cout<<"Enter the number of statements for the proof."<<endl;
    cin>>n;
    cin.ignore(1000,'\n');/**< cin.ignore is used to clear the cin buffer which contains the newline character *///To clear the newline buffer
    string store[n+1],input;
    for(int i=1;i<=n;i++)
    {
        getline(cin,input);
        for(int j=0;j<input.length();j++)
		{
			if(input[j]!=' ')
			{
				store[i]+=input[j];
			}
		}
    }
    for(int i=1;i<=n;i++)
    {
        string line;
        string statement=store[i]+"/";
        vector<string> tokens;
        for(int x=0;x<statement.length();x++)
        {
            char ch=statement[x];
            if(ch!='/')
            {
                line+=ch;
            }
            else
            {
                tokens.push_back(line);
                line="";
            }

        }
        if(tokens[1]=="P")
        {
            premise[i]=tokens[0];
            valid=true;
        }
        else if(tokens[1]=="^i")
        {
            if(tokens.size()!=4)
            {
                valid=false;
                break;
            }
            valid=verifyAndI(tokens,premise,i);
        }
        else if(tokens[1]==">e")
        {
             /**< Checking well formed data */
             if(tokens.size()!=4)
            {
                valid=false;
                break;
            }
            valid=verifyImpE(tokens,premise,i);
        }
        else if(tokens[1]=="^e1")
        {
            if(tokens.size()!=3)
            {
                valid=false;
                break;
            }
            valid=verifyAndE1(tokens,premise,i);
        }
        else if(tokens[1]=="MT")
        {
             if(tokens.size()!=4)
            {
                valid=false;
                break;
            }
            valid=verifyMT(tokens,premise,i);
        }
        else if(tokens[1]=="^e2")
        {
            if(tokens.size()!=3)
            {
                valid=false;
                break;
            }
            valid=verifyAndE2(tokens,premise,i);
        }
        else if(tokens[1]=="Vi1")
        {
            if(tokens.size()!=3)
            {
                valid=false;
                break;
            }
            valid=verifyOrI1(tokens,premise,i);
        }
        else if(tokens[1]=="Vi2")
        {
            if(tokens.size()!=3)
            {
                valid=false;
                break;
            }
            valid=verifyOrI2(tokens,premise,i);
        }
    }
    if(valid==1)
	{
		cout<<"Valid Proof";
	}
	else cout<<"Invalid Proof";
}

