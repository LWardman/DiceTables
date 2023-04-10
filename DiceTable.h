//
// Created by lewis on 04/04/2023.
//

#ifndef DICE_DICETABLE_H
#define DICE_DICETABLE_H

#include <vector>

class DiceTable {

public:
    /*
     * Taking an integer as an input to the constructor allows initialisation of the 'possibility table's' dimensions.
     * Once the table is initialised, we can immediately call the Solve function.
     * This is done so that all targets and number of dice up to 'dice' can be retrieved.
     */
    explicit DiceTable(int NumDice) : TableHeight(NumDice), TableWidth(6 * NumDice){Solve();}

    // Marked as maybe unused since the function provides utility once the table is constructed.
    [[maybe_unused]] unsigned long long ReachTargetWithXDice(int target, int dice);

private:
    // The table will be represented by a vector of vectors, each of which contain integer values.
    std::vector<std::vector<unsigned long long>> DTable;

    // Initialised in the constructor
    int TableHeight;
    int TableWidth;

    void Solve();

    // Marked as maybe unused as it is optionally toggled on/off in the solve() function.
    [[maybe_unused]] static void PrintTable(const std::vector<std::vector<unsigned long long>>& table);

    void InitialiseTable(std::vector<std::vector<unsigned long long>> &table) const;

    unsigned long long DetermineValue(int RowNum, int ColNum);

    void SolveTable();

};


#endif //DICE_DICETABLE_H
