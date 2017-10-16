/*
 * FILE: Maximum_Sum_II-10656.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://uva.onlinejudge.org/external/106/10656.pdf
 *
 * Description:
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *      3 Feb 2017    New             1.0        Completed, AC
 *
 *
 */


#include <iostream>

int main() {
    
    bool flag;
    int t, n;
    while(std::cin >> t, t){
        flag = false;
        while(t-- > 0 && std::cin >> n) if (n){ std::cout << n; flag = true; break;}
        while(t-- > 0 && std::cin >> n) if(n) std::cout << " " << n, flag = true;
        if(!flag) std::cout << 0;
        std::cout << std::endl;
    }
    return 0;
}

