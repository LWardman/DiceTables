//
// Created by lewis on 04/04/2023.
//

#include "DiceTable.h"
#include <iostream>

[[maybe_unused]] unsigned long long DiceTable::ReachTargetWithXDice(int target, int dice)
{
    return DTable[dice - 1][target - 1];
}

void DiceTable::Solve()
{
    InitialiseTable(DTable);
    SolveTable();
    //PrintTable(DTable);
}

[[maybe_unused]] void DiceTable::PrintTable(const std::vector<std::vector<unsigned long long>>& table)
{
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
    for (int RowNum = 1; RowNum < TableHeight; RowNum++) // Row 2 : Row N.
    {
        for (int ColNum = 1; ColNum < TableWidth; ColNum++) // Col 2 : Col 6N.
        {
            DTable[RowNum][ColNum] = DetermineValue(RowNum, ColNum); // Table entry determined and assigned.
        }
    }
}
