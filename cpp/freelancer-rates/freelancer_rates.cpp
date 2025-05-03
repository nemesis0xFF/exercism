// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {

    return 8.0*hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount-(before_discount*discount/100);
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double monthly_rate = 22*8*hourly_rate;
    if (discount > 0) {
        monthly_rate = apply_discount(monthly_rate, discount);
    }
    return ceil(monthly_rate);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double daily_rate = 8*hourly_rate;
    if (discount > 0) {
        daily_rate = apply_discount(daily_rate, discount);
    }
    int days = budget/daily_rate;
    return floor(days);
}