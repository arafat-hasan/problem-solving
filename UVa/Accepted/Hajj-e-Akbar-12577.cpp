/*
 * FILE: Hajj-e-Akbar-12577.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    21 Feb 2017    New             1.0        AC
 *
 */

#include <iostream>
#include <cstring>

int main(){
    
    int Cs = 0;
    char str[6];
    while(std::cin >> str, str[0] != '*'){
            if(strcmp(str, "Hajj"))
                std::cout << "Case " << ++Cs << ": Hajj-e-Asghar" << std::endl;
            else
                std::cout << "Case " << ++Cs << ": Hajj-e-Akbar" << std::endl;
    }

}
