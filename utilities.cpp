#include "header.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>


using namespace std;



int bin2Dec(string str){
    
    int n = 0;
    int size = str.size() -1 ;
    int count = 0;
    for(int i = 0; i <= size; i++) {
    if ( str[i] == '1' ) 
        n = n + pow(2, size - count );
        count++; 
        // str++;
    }
    return n;
}

int hextoDec(string str){
	unsigned int result;
    int i;
    int size =  4 * (str.size() -2);
    i = 0;
    result = 0;
    
    if(str[i] == '0' && str[i+1] == 'x')
    {
        i = i + 2;
    }

    while(str[i] != '\0')
    {
        result = result * 16;
        if(str[i] >= '0' && str[i] <= '9')
        {
            result = result + (str[i] - '0');
        }
        else if(tolower(str[i]) >= 'a' && tolower(str[i]) <= 'f')
        {
            result = result + (tolower(str[i]) - 'a') + 10;
        }
        i++;
    }
    return result;
}

// int bintodec(string str) {
//     int n = 0;
//     int size = str.size() ;
//     int count = 0;
//     for(int i = 0; i < size; i++) {
//     if ( str[i] == '1' ) 
//         n = n + pow(2, size - count );
//         count++; 
//         // str++;
//     }
//     return n;
// }


string hextoBinary(string str){
    // cout << str << "__________________________________________________";
    
    // cout << str.size();
    str = str.substr(2,str.size() - 3);
    int size =  4* (str.size());
    // cout << str.substr(2,str.size() -3);;
    int num = hextoDec(str);
    // cout << "NUmber us" << num;
    /* Calculate the Binary String */
    
    string bstring;    
    // bstring[size] = '\0';
    // cout << "Size is " << size << endl;
    
    for(int i = size -1; i >= 0; i-- )
    {
        bstring  += (num == ((1 << i) | num)) ? '1' : '0';
    }
    
    // cout << bstring.size() << "--->" << bin2Dec(bstring) << endl;
    // cout << bstring.size() << endl;

    return bstring;
   
}
