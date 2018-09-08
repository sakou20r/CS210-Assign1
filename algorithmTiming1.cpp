#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

// This program determines the run time of an algorithm whose life
// is very short. A measurement technique is used that determines
// the number of times the algorithm can run in one second. The
// elapsed time for one run of the algorithm can then be derived
// from this value.

int main()
{

// Verify host.

    char hostName [256];

    gethostname (hostName, sizeof (hostName));
    if (strcmp (hostName, "hercules") == 0)
    {
        cout << "Error: algorithm timing program will not run on hercules" << endl;
        exit (1);
    }
    else if (strcmp (hostName, "a049831") == 0)
    {
        cout << "Error: algorithm timing program will not run on a049831" << endl;
        exit (1);
    }

// Variable declarations.

    unsigned long n;
    unsigned int reps;
    unsigned int i;
    int count;
    vector <long> iterations;
    time_t start;
    time_t finish;
    double timeWithAlgorithm;
    double timeWithoutAlgorithm;

// Get input.

    cout << "Algorithm Timing Started!" << endl;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter repetitions: ";
    cin >> reps;

// Phase 1.

    iterations.reserve (reps);

    // Determine the number of iterations of the following while loop that
    // can be executed in one second (it includes the algorithm).

    while (iterations.size () < reps)
    {
        count = 0;
        start = time (0);
        do
        {
            ++count;
            // Algorithm that you are timing goes here for this phase

            //
            finish = time (0);
            // Continue as long as time hasn't changed
        } while (finish == start);
        // Record the number of iterations
        iterations.push_back (count);
    }

    cout << "Iteration counts (with algorithm): " << endl;
    for (i = 0; i < iterations.size (); ++i)
    {
        cout << iterations [i] << " ";
    }
    cout << endl;

    cout << "Sorted iteration counts (with algorithm): " << endl;
    sort (iterations.begin (), iterations.end ());
    for (i = 0; i < iterations.size (); ++i)
    {
        cout << iterations [i] << " ";
    }
    cout << endl;

    cout << "Selected value (with algorithm): " << iterations [reps / 2] << endl;
    timeWithAlgorithm = 1000.0 / iterations [reps / 2];
    cout << "Approximate elapsed time (with algorithm): " << timeWithAlgorithm << " ms" << endl;

    iterations.clear ();

// Phase 2.

    iterations.reserve (reps);

    // Now determine the number of iterations of the following while loop that
    // can be executed in one second (it does not include the algorithm).

    while (iterations.size () < reps)
    {
        count = 0;
        start = time (0);
        do
        {
            ++count;
            // Algorithm is removed for this phase

            //
            finish = time (0);
            // Continue as long as time hasn't changed
        } while (finish == start);
        // Record the number of iterations
        iterations.push_back (count);
    }

    cout << "Iteration counts (without algorithm): " << endl;
    for (i = 0; i < iterations.size (); ++i)
    {
        cout << iterations [i] << " ";
    }
    cout << endl;

    cout << "Sorted iteration counts (without algorithm): " << endl;
    sort (iterations.begin (), iterations.end ());
    for (i = 0; i < iterations.size (); ++i)
    {
        cout << iterations [i] << " ";
    }
    cout << endl;

    cout << "Selected value (without algorithm): " << iterations [reps / 2] << endl;
    timeWithoutAlgorithm = 1000.0 / iterations [reps / 2];
    cout << "Approximate elapsed time (without algorithm): " << timeWithoutAlgorithm << " ms" << endl;

// Phase 3.

    cout << "Approximate elapsed time (algorithm): " << timeWithAlgorithm - timeWithoutAlgorithm << " ms" << endl;

    cout << "Algorithm Timing Ended!" << endl;

    return 0;
}

// Created by Jaskirat Josan on 2018-09-07.
//

