/** \file Part1functions.cpp
 * \brief File contains the functions required for the implementation of Part 1 of the assignment.
 *
 */

#include<bits/stdc++.h>
#include "precedence.cpp"
using namespace std;
/**
 * \brief Function to convert an infix expression to a postfix expression.
 * This function makes use of the stack to make a postfix expression.
 * \param s A string argument
 * \return The postfix expression of the given infix expression.
 */
string InToPoConv(string s)
{
    stack<char> st; /**< This character stack shall store our operators and brackets according to the algorithm. */
    st.push('T');
    int len = s.length(); /**< An integer data type to store the length of the string argument. */
    string out;
    for(int i=0;i<len;i++)
    {
        /**< add operand to output */
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z' && s[i]!='V'))
            out+=s[i];
        /**< Push '(' to stack */
        else if(s[i] == '(')
            st.push('(');
        /**< If ')' is encountered, pop to output until '(' found */
        else if(s[i]==')')
        {
            while(st.top()!='T' && st.top()!='(')
            {
                char c=st.top();
                st.pop();
                out+=c;
            }
            if(st.top()=='(')
            {
                char c = st.top();
                st.pop();
            }
        }
       /**< If an operator is scanned */
        else{
            while(st.top()!='T' && precedence(s[i])<=precedence(st.top()))
            {
                char c = st.top();
                st.pop();
                out+=c;
            }
            st.push(s[i]);
        }
    }
        /**< Pop all the remaining elements from the stack */
        while(st.top()!='T')
        {
            char c=st.top();
            st.pop();
            out+=c;
        }
        return out;
}
/** \brief Class for making a node with char type storing data, left and right pointers.
 *
 * \param
 * \param
 * \return A node.
 *
 */
class Node
{
    public:
    char data; /**< Character type to store data */
    Node* left, *right; /**< For references to left and right child nodes */
};
stack<Node*> nodestack; /**< Stack of Node* type which is required for making parse tree */
/** \brief Function of Node* type used to make a Parse Tree
 * \param post A string argument, which is the postfix expression.
 * \param
 * \return root node of Node* type, which contains all subnodes, thus creating a complete link for a parse tree.
 *
 */
Node* MakeTree(string post)
{
    Node *root;
    for(int i=0;i<post.length();i++)
    {
        char ch = post[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z' && ch!='V'))
        {
            Node *ptr = new Node;
            ptr->data=ch;
            ptr->left=NULL;
            ptr->right=NULL;
            nodestack.push(ptr);
            root=ptr;
        }
        else if(ch=='V' || ch=='^' || ch=='>')
        {
            Node *ptr = new Node;
            ptr->data = ch;
            ptr->right=nodestack.top();
            nodestack.pop();
            ptr->left=nodestack.top();
            nodestack.pop();
            nodestack.push(ptr);
            root=ptr;
        }
        else if(ch=='~')
        {
            Node *ptr = new Node;
            ptr->data = ch;
            ptr->right=nodestack.top();
            nodestack.pop();
            ptr->left=NULL;
            nodestack.push(ptr);
            root=ptr;
        }
    }
    return root;
}
/** \brief Recursive function of string type for inorder traversal of Parse tree
 * \param st A Node* argument, which contains the root node of the parse tree.
 * \param
 * \return An infix expression from the given parse tree.
 */
string inOrder(Node* st)
{   string ret;
    if(st->left==NULL && st->right==NULL)
    {
           ret+=st->data;
    }
    else if(st->left==NULL && st->right!=NULL)
    {
        ret+=st->data;
        ret+=inOrder(st->right);
    }
    else
    {
        if(st->left!=NULL)
        {
            ret+="(";
            ret+=inOrder(st->left);
        }
       ret+=st->data;
        if(st->right!=NULL)
        {
             ret+=inOrder(st->right);
             ret+=")";
        }
    }
    return ret;
}
