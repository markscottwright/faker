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
    cout << f.digit() << endl;
    cout << f.digits(5) << endl;
    cout << f.ssn() << endl;
    cout << f.first_name() << endl;
    cout << f.last_name() << endl;
    cout << f.zipcode() << endl;
    cout << f.state() << endl;
    cout << f.state_abbr() << endl;
    cout << f.secondary_unit_number() << endl;
    cout << f.secondary_unit_designator() << endl;
    cout << f.unixtime() << endl;
    cout << f["unixtime"] << endl;

    cout << endl;
    cout << f.name() << endl;
    cout << f.street_address() << endl;
    cout << f.city() << ", " << f.state() << endl;
    cout << f.zipcode() << endl;
    cout << f.phone_number() << endl;
    cout << f.email() << endl;
    cout << f.date() << endl;
    cout << f["date"] << endl;

    return 0;
}


