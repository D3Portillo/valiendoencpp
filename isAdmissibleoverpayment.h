#ifndef ISADMISSIBLEOVERPAYMENT_H
#define ISADMISSIBLEOVERPAYMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using std::vector;
using std::string;
using Prices = vector<double>;
using Notes = vector<string>;
using std::boolalpha;

class isAdmissibleoverpayment {
  private:
     bool run(Prices prices, Notes notes, double x);
  public:
    void runExample();
};

#endif // ISADMISSIBLEOVERPAYMENT_H
