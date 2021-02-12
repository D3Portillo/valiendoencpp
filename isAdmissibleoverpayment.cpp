/**
 * After recently joining Instacart's beta testing developer group,
 * you decide to experiment with their new API.
 * You know that the API returns item-specific display-ready strings
 * like `10.0% higher than in-store` or `5.0% lower than in-store` that inform
 * users when the price of an item is different from the one in-store.
 *
 * But you want to extend this functionality by giving people a better
 * sense of how much more they will be paying for their entire shopping cart.
 * Your app lets a user decide the total amount x they are willing to pay via
 * Instacart over in-store prices. This you call their price sensitivity.
 * Your job is to determine whether a given customer will be willing to pay
 * for the given items in their cart based on their stated price sensitivity x.
 *
 * @bold https://app.codesignal.com/challenge/pRuhLib5DdetsY4E7
 */

#include "isAdmissibleoverpayment.h"

string SAME_PRICE_NOTE = "Same as in-store";

class Example {
  public:
    Prices prices = {20, 20};
    Notes notes = {
      "20.0% higher than in-store",
      "20.0% lower than in-store"
    };
    // User willing to pay amount
    double x = 0;
};

bool isAdmissibleoverpayment
::run(Prices prices, Notes notes, double x) {
  string delimiter = "%";
  // To take approach of looping and vector range
  int i = 0;
  for (string &note : notes) {
    double perc = 0;
    double multiplier = 1;
    double price = prices[i];
    if(note!=SAME_PRICE_NOTE) {
      string percStr = note.substr(0, note.find(delimiter));
      perc = std::stod(percStr);
      // If `lo` exists in str multiplier is -1
      if(~note.find("lo")) multiplier = -1;
    }
    // Applies multiplier ex: ( .2 * -1 ) => -.2
    double finalPerc = multiplier * perc;
    x += price * 100 / (100 + finalPerc) - price;

    // We want to take out next price in prices<>
    ++i;
  }

  return x >= 0;
}


void isAdmissibleoverpayment
::runExample(){
  Example example;
  bool result = run(example.prices,example.notes,example.x);
  std::cout << "Result: " << boolalpha << result << "\n";
}

