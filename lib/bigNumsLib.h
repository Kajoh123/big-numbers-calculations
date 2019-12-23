#ifndef BIG_NUMS_LIB_H
#define BIG_NUMS_LIB_H
#include <string>

std::string giveGreater(std::string &num1, std::string &num2)
{
    if(num1.size() < num2.size())
    {
        return num2; //just returning std::string 
    }
    else
    {
        //swapping them
        std::string tmp = num1;
        num1 = num2;
        num2 = tmp;
        return num1;
    }
    
}

std::string reverseString(std::string strToReverse)
{
    std::string newString;
    for(int characters = strToReverse.size() - 1; characters >= 0; --characters)
    {
        newString += strToReverse[characters];
    }
    return newString;
}

std::string add(std::string first, std::string second)
{
    int tempValueToSave = 0; //here will be temporary value to add to returning std::string
    int rest = 0; //this is what we get in adding
    std::string returnNumber; //this std::string will be returned
    //we have to sort it first string should be shorter (or same length as second)
    giveGreater(first, second);
    int digitIndexBigger = second.size() - 1;
    int digitIndexLower = first.size() - 1;
    while(digitIndexBigger >= 0)
    {
        if(digitIndexLower >= 0)
        {
            //counting every number carefully
            tempValueToSave = (int)first[digitIndexLower] - '0' + (int)second[digitIndexBigger] - '0' + rest;
            returnNumber += std::to_string(tempValueToSave % 10); //adding it to returning string
            rest = tempValueToSave / 10;
        }
        else
        {
            tempValueToSave = (int)second[digitIndexBigger] - '0' + rest;
            returnNumber += std::to_string(tempValueToSave % 10);
            rest = tempValueToSave / 10;
        }
        if(digitIndexBigger == 0 && rest > 0)
        {
            returnNumber += std::to_string(rest);
        }

        digitIndexBigger--;
        digitIndexLower--;
    }
    returnNumber = reverseString(returnNumber);
    return returnNumber;
}

std::string multiplication(std::string number, std::string multiplier)
{
    std::string returningNumber = "0"; //this is returning value
    std::string tmp = "0";

    while(tmp != multiplier)
    {
        returningNumber = add(returningNumber, number);
        tmp = add(tmp, "1");
    }
    return returningNumber;
}

std::string squareRoot(std::string num1)
{
    std::string returningNumber = "1";
    std::string tmp = "1";
    std::string helper = "1"; //it's sequence of odd numbers (length of this sequence equals num1 and sum of this sequence equals square root of num1)
    while(tmp != num1)
    {
        helper = add(helper, "2");
        returningNumber = add(returningNumber, helper);
        tmp = add(tmp, "1");
    }
    return returningNumber;
}

#endif