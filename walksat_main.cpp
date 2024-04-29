/******************************************
Copyright (c) 2018, Mate Soos <soos.mate@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
***********************************************/

#include "walksat.h"
using namespace CMSat;

int main(int argc, char* argv[])
{
    long long max_steps = 1000, max_tries=10;
    double p = 0.5;
    // Default random seed
    std::uint64_t seed = 0;
    // Set default value for verbosity
    double bencht = -1.0;

    // Assign provided values
    switch (argc) {
        case 6:
            bencht = std::stod(argv[5]);
        case 5:
            seed = std::stoull(argv[4]);
        case 4:
            p = std::stod(argv[3]);
        case 3:
            max_tries = std::stoull(argv[2]);
        case 2:
            max_steps = std::stoull(argv[1]);
        default: ;
    }

    WalkSAT walk;
    walk.walk_probability = p;
    walk.cutoff = max_steps;
    walk.seed = seed;
    walk.numrun = max_tries;
    walk.main(bencht);
    return 0;
}
