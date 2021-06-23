#include <iostream>  
#include <fstream>  
#include <stdio.h>
#include <stdlib.h>

#include "29_DivideTwoIntegers.h"


int main(int argc,char** agrv){
    
    Solution29 s29;
    int result;

    result = s29.divide(10, 6);
    std::cout << result << std::endl;

    return 0;
}