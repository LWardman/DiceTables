#include <iostream>
#include "DiceTable.h"
#include <chrono>

double TimeCode(int NumDice)
{
    /*
     * Param: int NumDice is an integer that represents how many dice get thrown.
     *
     * This function determines how long it takes to create a 'possibility table' given an integer.
     *
     * The 'possibility table' is a [NumDice] X [6 * NumDice] matrix constructed with std::vectors.
     * An example entry Table[5][12] contains unsigned long long information.
     * This information corresponds to how many possibilities there are to roll a total of 12 from 5 dice.
     *
     * This function makes use of the <chrono> library and is the only function to do so.
     *
     * Return: The time taken to create the possibility table.
     */

    auto start = std::chrono::high_resolution_clock::now(); // Start the timer.

    DiceTable DT = DiceTable(NumDice); // Create the 'possibility table'.

    auto end = std::chrono::high_resolution_clock::now(); // End the timer.

    // Measure the time difference between the start and the end.
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9; // Convert the time take from nano-seconds to seconds.

    // Output the time taken to the log. Comment out to speed up the function.
    //std::cout << "Time taken by program is : " << std::fixed << time_taken << " sec" << std::endl;

    return time_taken;
}

int TestTableCreationTimes(double TimeLimit)
{
    /*
     * Param: double TimeLimit, representing the time limit to create a 'possibility table' in.
     *
     * This function takes in a TimeLimit and tests against the time to create a 'possibility table'.
     *
     * Return: the largest number of dice possible to create a 'possibility table' in under the time limit.
     */

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
    std::cout << TestTableCreationTimes(1.0) << std::endl;

    return 0;
}
