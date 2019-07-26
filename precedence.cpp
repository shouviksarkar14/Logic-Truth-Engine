/** \file precedence.cpp
 *  \brief File assigns the precedence to the operators.
 *
 */

#include<iostream>
/**
 * \brief Function to assign precedence to each logical operator.
 * \param c A character argument
 * \return The precedence value of each operator, -1 for non-operators.
 *
 */
int precedence(char c)
{
    if(c == '~')
        return 4;
    else if(c == '^')
        return 3;
    else if(c == 'V')
        return 2;
    else if(c == '>')
        return 1;
    else return -1;
}
