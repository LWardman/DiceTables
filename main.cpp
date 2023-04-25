#include <iostream>
#include "DiceTable.h"
#include <chrono>

/**
* Determines time to create a 'possibility table'.
*
* @param[in] NumDice Number of dice thrown.
* @return Time taken to create the possibility table.
*/
double TimeCode(int NumDice)
{
    auto start = std::chrono::high_resolution_clock::now(); // Start the timer.

    DiceTable DT = DiceTable(NumDice); // Create the 'possibility table'.

    auto end = std::chrono::high_resolution_clock::now(); // End the timer.

    // Measure the time difference between the start and the end.
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9; // Convert the time take from nanoseconds to seconds.

    // Output the time taken to the log. Comment out to speed up the function.
    //std::cout << "Time taken by program is : " << std::fixed << time_taken << " sec" << std::endl;

    return time_taken;
}

/**
* Stress testing creations of 'possibility tables'.
*
* @param TimeLimit The time limit to create a 'possibility table'.

* @return Largest number of dice possible to create a 'possibility table' in under the time limit.
*/
int TestTableCreationTimes(double TimeLimit)
{
    // Initialise the base case.
    int NumDice = 1;

    // Output the current number of dice. Comment out to speed the function up.
    //std::cout << "Number of Dice : " << NumDice << std::endl;

    while (TimeCode(NumDice) < TimeLimit) // While the table is created in the time limit.
    {
        NumDice += 10; // Increase the number of dice thrown by ten. Ten is used to speed the process up.
    }

    return NumDice;
}

int main()
{
    TimeCode(5);

    std::cout << TestTableCreationTimes(1.0) << std::endl;

    return 0;
}
