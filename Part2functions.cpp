/** \file Part2functions.cpp
 * \brief File contains all the verification functions for all the Rules included for the logic proof checker.
 *
 */

#include<bits/stdc++.h>
#include<sstream>
#include "Part1functions.cpp"
/** \brief Boolean Function to verify correct application of AND Introduction rule.
 * \param tokens- vector of string type which contains lines of proof.
 * \param premise- string array to store the premises and the true statements.
 * \param linenumber- integer which is the current line number of the proof.
 * \return Returns true if And Introduction is applied successfully.
 */
bool verifyAndI(vector<string> tokens,string premise[],int linenumber){
		int l1=0,l2=0;
		/**< string given-Returns the given well formed statement after converting it to a parse tree */
		string given=inOrder(MakeTree(InToPoConv(tokens[0])));
		stringstream conv1(tokens[2]);
		conv1>>l1;
		stringstream conv2 (tokens[3]);
		conv2>>l2;
		/**< string have-Contains the apparent statement referred to by the rule */
		string have="("+premise[l1]+"^"+premise[l2]+")";
		if(given==have)
		{
			premise[linenumber]=tokens[0];
			return true;
		}
		else
		{
			return false;
		}
}
/** \brief Boolean Function to verify correct application of Implication Elimination rule.
 * \param tokens- vector of string type which contains lines of proof.
 * \param premise- string array to store the premises and the true statements.
 * \param linenumber- integer which is the current line number of the proof.
 * \return Returns true if Implication Elimination is applied successfully.
 */
bool verifyImpE(vector<string> tokens,string premise[],int linenumber)
{
		int l1=0,l2=0;
		stringstream conv1(tokens[2]);
		conv1>>l1;
		stringstream conv2 (tokens[3]);
		conv2>>l2;
		/**< string have-Contains the apparent statement referred to by the rule */
		string have=premise[l1];
		string given="("+premise[l2]+">"+tokens[0]+")";
		if(given==have)
		{
			premise[linenumber]=tokens[0];
			return true;
		}
		else
		{
			return false;
		}
}
/** \brief Boolean Function to verify correct application of Modus Tollens rule.
 * \param tokens- vector of string type which contains lines of proof.
 * \param premise- string array to store the premises and the true statements.
 * \param linenumber- integer which is the current line number of the proof.
 * \return Returns true if Modus Tollens is applied successfully.
 */
bool verifyMT(vector<string> tokens,string premise[],int linenumber)
{
		int l1=0,l2=0;
		stringstream conv1(tokens[2]);
		conv1>>l1;
		stringstream conv2 (tokens[3]);
		conv2>>l2;
		string have=premise[l1];
		string left=tokens[0];
		string right=premise[l2];
		left.erase(left.begin());
		right.erase(right.begin());
		string given="("+left+">"+right+")";
			if(given==have)
		{
			premise[linenumber]=tokens[0];
			return true;
		}
		else
		{
			return false;
		}
}
/** \brief Boolean Function to verify correct application of AND Elimination 1 rule.
 * \param tokens- vector of string type which contains lines of proof.
 * \param premise- string array to store the premises and the true statements.
 * \param linenumber- integer which is the current line number of the proof.
 * \return Returns true if And Elimination 1 is applied successfully.
 */
bool verifyAndE1(vector<string> tokens,string premise[],int linenumber)
{
		int l1=0;
		stringstream conv1(tokens[2]);
		conv1>>l1;
		stack<char> op;
		stack<int> ind;
		int counter=0;
		int index=0;
		for(int x=0;x<premise[l1].length();x++)
		{
			char ch=premise[l1][x];
			if(ch=='V'|| ch=='^'||ch=='>')
			{
				op.push(ch);
				ind.push(x);
			}
			else if(ch=='(')
			{
				counter++;
			}
			else if(ch==')')
			{
				if(counter==1)
				{
					index=ind.top();
					ind.pop();
					op.pop();
					break;
				}
				else
				{	op.pop();
					ind.pop();
					counter--;
				}
			}
		}
		string left;
		for(int x=1;x<index;x++)
		{
			left+=premise[l1][x];
		}
		if(left==tokens[0])
		{
			premise[linenumber]=tokens[0];
			return true;
		}
		else return false;
}
/** \brief Boolean Function to verify correct application of AND Elimination 2 rule.
 * \param tokens- vector of string type which contains lines of proof.
 * \param premise- string array to store the premises and the true statements.
 * \param linenumber- integer which is the current line number of the proof.
 * \return Returns true if And Elimination 2 is applied successfully.
 */
bool verifyAndE2(vector<string> tokens,string premise[],int linenumber)
{
		int l1=0;
		stringstream conv1(tokens[2]);
		conv1>>l1;
		stack<char> op;
		stack<int> ind;
		int counter=0;
		int index=0;
		for(int x=0;x<premise[l1].length();x++)
		{
			char ch=premise[l1][x];
			if(ch=='V'|| ch=='^'||ch=='>')
			{
				op.push(ch);
				ind.push(x);
			}
			else if(ch=='(')
			{
				counter++;
			}
			else if(ch==')')
			{
				if(counter==1)
				{
					index=ind.top();
					ind.pop();
					op.pop();
					break;
				}
				else
				{  op.pop();
					ind.pop();
					counter--;
				}
			}
		}
		string left;
		string right;
		for(int x=index+1;x<=premise[l1].length()-2;x++)
		{
			right+=premise[l1][x];
		}
		if(right==tokens[0])
		{
			premise[linenumber]=tokens[0];
			return true;
		}
		else return false;
}
/** \brief Boolean Function to verify correct application of OR Introduction 1 rule.
 * \param tokens- vector of string type which contains lines of proof.
 * \param premise- string array to store the premises and the true statements.
 * \param linenumber- integer which is the current line number of the proof.
 * \return Returns true if OR Introduction 1 is applied successfully.
 */
bool verifyOrI1(vector<string>tokens,string premise[],int linenumber)
{
	int l1=0;
	stringstream conv1(tokens[2]);
	conv1>>l1;
	stack<char> op;
	stack<int> ind;
	int counter=0;
	int index=0;
	for(int x=0;x<tokens[0].length();x++)
	{
			char ch=tokens[0][x];
			if(ch=='V'|| ch=='^'||ch=='>')
			{
				op.push(ch);
				ind.push(x);
			}
			else if(ch=='(')
			{
				counter++;
			}
			else if(ch==')')
			{
				if(counter==1)
				{
					index=ind.top();
					ind.pop();
					op.pop();
					break;
				}
				else
				{	op.pop();
					ind.pop();
					counter--;
				}
			}
		}
		string left;
		for(int x=1;x<index;x++)
		{
			left+=tokens[0][x];
		}

		if(left==premise[l1])
		{
			premise[linenumber]=tokens[0];
			return true;
		}
		else return false;
}
/** \brief Boolean Function to verify correct application of OR Introduction 2 rule.
 * \param tokens- vector of string type which contains lines of proof.
 * \param premise- string array to store the premises and the true statements.
 * \param linenumber- integer which is the current line number of the proof.
 * \return Returns true if OR Introduction 2 is applied successfully.
 */
bool verifyOrI2(vector<string>tokens,string premise[],int linenumber)
{
	int l1=0;
	stringstream conv1(tokens[2]);
	conv1>>l1;
	stack<char> op;
	stack<int> ind;
	int counter=0;
	int index=0;
	for(int x=0;x<tokens[0].length();x++)
	{
			char ch=tokens[0][x];
			if(ch=='V'|| ch=='^'||ch=='>')
			{
				op.push(ch);
				ind.push(x);
			}
			else if(ch=='(')
			{
				counter++;
			}
			else if(ch==')')
			{
				if(counter==1)
				{
					index=ind.top();
					ind.pop();
					op.pop();
					break;
				}
				else
				{	op.pop();
					ind.pop();
					counter--;
				}
			}
		}
		string right;
		for(int x=index+1;x<=tokens[0].length()-2;x++)
		{
			right+=tokens[0][x];
		}
		if(right==premise[l1])
		{
			premise[linenumber]=tokens[0];
			return true;
		}
		else return false;
}
