//
// Created by lewis on 04/04/2023.
//

#include "DiceTable.h"
#include <iostream>

[[maybe_unused]] unsigned long long DiceTable::ReachTargetWithXDice(int target, int dice)
{
    /*
     * Param: int target is the total sum that can be reached by throwing dice.
     * Param: int dice is the number of dice thrown, which their values sum up to a total (target).
     *
     * Returns the table entry corresponding to the number of dice thrown and the target sum.
     * return type is an unsigned since it is impossible for the number of possibilities to be negative.
     * return type is also long long since the values in the table can get extremely large very rapidly.
     */

    return DTable[dice - 1][target - 1];
}

void DiceTable::Solve()
{
    /*
     * This function is called on construction of the DiceTable object.
     * It first Initialises, then solves the table. Info on how it is initialised is found in the function.
     * Printing the table out is an option, only works effectively for low valued entries. Takes up a lot of time too.
     */

    InitialiseTable(DTable);
    SolveTable();
    //PrintTable(DTable);
}

[[maybe_unused]] void DiceTable::PrintTable(const std::vector<std::vector<unsigned long long>>& table)
{
    /*
     * Param: const table ref. Is const since no changes to the table should be made.
     *
     * Loops through each row in the table and printing out each value in the row, padded with borders for easy viewing.
     */

    for (const std::vector<unsigned long long>& Row : table) // For each row in the table.
    {
        for (unsigned long long Val : Row) // For each value in the row.
        {
            std::cout << "|" << Val << "|"; // Print val
        }
        std::cout << std::endl; // Start a new line at the end of each row.
    }
}

void DiceTable::InitialiseTable(std::vector<std::vector<unsigned long long>> &table) const
{
    /*
     * Param: table ref. Is not const since values in this table are going to be changed.
     *
     * Function works be setting up an [N][6N] matrix, with N being the number of dice thrown.
     * Then the function sets the first six values in the first row to be 1.
     * Then sets the value of every single other entry to 0.
     */

    for (int i = 0; i < TableHeight; i++) // TableHeight = Number of dice thrown.
    {
        std::vector<unsigned long long> RowVec; // Create a vector of integers to add to.

        for (int j = 0; j < TableWidth; j++) // TableWidth = 6 * TableHeight
        {
            if (i == 0 && j < 6) // For the first 6 entries in the first row...
            {
                RowVec.push_back(1); // Value = 1;
            }
            else // Otherwise
            {
                RowVec.push_back(0); // Value = 0;
            }
        }
        table.push_back(RowVec); // Append vector to the table.
    }
}

unsigned long long DiceTable::DetermineValue(int RowNum, int ColNum)
{
    /*
     * Param: RowNum is the index of the table.
     * Param: ColNum is the index of the Row we are interested in.
     *
     * Calculates the value that should be in table[RowNum][ColNum].
     * This is done by considering values in the previous row.
     *
     * Returns the value calculated from the previous row.
     */

    // The values we wish to sum exist on the previous row, six spaces back.
    RowNum -= 1;
    ColNum -= 6;

    unsigned long long Sum = 0; // This will be the table entry.

    for (int itr = 0; itr < 6; itr++) // Considering only 6 numbers.
    {
        if (ColNum >= 0) // Check that the index of the table is in bounds before trying to access it.
        {
            Sum += DTable[RowNum][ColNum]; // Add to the table entry.
        }
        ColNum++;
    }
    return Sum;
}

void DiceTable::SolveTable()
{
    /*
     * Solves the table given that the first row is initialised.
     * Loops over every entry in the table and determines the value that the entry should hold.
     */

    for (int RowNum = 1; RowNum < TableHeight; RowNum++) // Row 2 : Row N.
    {
        for (int ColNum = 1; ColNum < TableWidth; ColNum++) // Col 2 : Col 6N.
        {
            DTable[RowNum][ColNum] = DetermineValue(RowNum, ColNum); // Table entry determined and assigned.
        }
    }
}
