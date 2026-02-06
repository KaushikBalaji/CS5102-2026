#include <iostream>
#include <iomanip>

// DUT declaration
extern void FIR_ALL(int *y, int x);

#define N 11

int main() {

    int x;
    int y;

    // FIR coefficients (golden reference)
    int C[N] = {53, 0, -91, 313, 500, 313, 0, -91, 0, 53, 0};

    bool pass = true;

    std::cout << "n\t x\t DUT_y\t GOLDEN\t MATCH\n";
    std::cout << "---------------------------------------------\n";

    for (int n = 0; n < 11; n++) {

        x = (n == 0) ? 1 : 0;

        FIR_ALL(&y, x);

        // golden output
        int golden;
        if (n < N)
            golden = C[n];
        else
            golden = 0;

        bool match = (y == golden);
        pass &= match;

        std::cout << std::setw(2) << n << "\t"
                  << std::setw(2) << x << "\t"
                  << std::setw(7) << y << "\t"
                  << std::setw(7) << golden << "\t"
                  << (match ? "YES" : "NO") << "\n";
    }

    std::cout << "---------------------------------------------\n";
    if (pass)
        std::cout << "PASS !! All outputs match golden data\n";
    else
        std::cout << "FAIL !! Output mismatch detected\n";

    return 0;
}
