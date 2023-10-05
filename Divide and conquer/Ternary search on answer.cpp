double f(double x) {
    return 2 * x * x - 12 * x + 7;
}

double ternarySearch(double lo, double hi) {
    for (int i = 0; i < 200; i++) {
        double mid1 = lo + (hi - lo) / 3;
        double mid2 = hi - (hi - lo) / 3;
        if (f(mid1) < f(mid2))
            hi = mid2;
        else
            lo = mid1;
    }
    double x = lo;
    return f(lo);
}