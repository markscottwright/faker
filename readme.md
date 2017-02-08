Faker for C++
=============

Introduction
------------

This is a C++ implementation of a large subset of the Perl::Fake module.
Strings were stolen from that module, and the implementation is modeled on it.

Building
--------

It is a header-only implementation, so you should be able to just #include it in
your project.  

Extending
---------

New faker types can be created via sub-classing `fakerbase`. then creating an
appropriately named function on `faker` or `usafaker` (I broke them into two in
case I every want to create locale-aware fake demographic data) that returns a
fakerp to your new class.

You may find that a combination of faker::series, faker::oneof, faker::digit,
faker::template and faker::str a sufficient for your needs without creating a
fakerbase-derived class.



Rationale
---------

Perl and python both have nice, feature-laden libraries for generating fake
demographic data.  I first tried using the python module _faker_ - but I
wanted a million or so rows of data and faker was *slow*.  It took around 20
minutes to generate those million rows.  Mod::Fake was a little better, but
still slow enough that generating large amounts of data was painful.

My C++ faker is around 30 times faster than python's faker - fast enough that
1,000,000 rows only takes a few minutes on my dual core i7 laptop.

To compare, here are two functionally equivalent CSV data generators (source
below)::
    $ time python mkdata.py 10000 > t
    real    0m53.317s
    user    0m47.890s
    sys     0m5.358s

    $ time ./mkdata.exe 10000 > t
    real    0m2.192s
    user    0m2.156s
    sys     0m0.046s


Here's mkdata.py::
    import sys

    n = 1
    base = 0

    if len(sys.argv) > 1:
        n = int(sys.argv[1])
    if len(sys.argv) > 2:
        base = int(sys.argv[2])
        
    fake = Factory.create()
    for i in range(n):
        print "|".join([
            str(i+base),
            fake.user_name(),
            fake.email(),
            fake.name(),
            fake.ssn(),
            fake.phone_number(),
            fake.date(),
            fake.street_address(),
            fake.city(),
            fake.state_abbr(),
            fake.zipcode()])
        if i % 100 == 0:
            sys.stderr.write(str(i))
            sys.stderr.write("\r")


And mkdata.cpp::

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


