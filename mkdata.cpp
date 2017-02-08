/* 
 * Author:          Mark Wright (markscottwright@gmail.com)
 * Creation Date:   2017-02-04
 */
#include <iostream>
#include "faker.h"

int main(int argc, char* argv[])
{
    using namespace std;
    faker::usafaker f;

    int n=1;
    int base=0;

    if (argc > 1)
        n = atoi(argv[1]);
    if (argc > 2)
        base = atoi(argv[2]);
    
    for (int i=0; i < n; ++i) {
        cout << i+base
            << "|" << f.username()
            << "|" << f.email()
            << "|" << f.name()
            << "|" << f.ssn()
            << "|" << f.phone_number()
            << "|" << f.date()
            << "|" << f.street_address()
            << "|" << f.city()
            << "|" << f.state_abbr()
            << "|" << f.zipcode()
            << endl;
        if (i % 100 == 0)
            cerr << i << "\r";
    }

    return 0;
}


