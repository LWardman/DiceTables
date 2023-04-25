//
// Created by lewis on 04/04/2023.
//

#ifndef DICE_DICETABLE_H
#define DICE_DICETABLE_H

#include <vector>

class DiceTable {

public:
    /**
     * Constructs the possibility table with dimensions [NumDice] x [6 * NumDice]
     *
     * @param[in] NumDice The number of dice thrown.
     */
    explicit DiceTable(int NumDice) : TableHeight(NumDice), TableWidth(6 * NumDice){Solve();}

    /**
     * Look-up an entry in the dice possibility table.
     *
     * @param[in] Target is the total sum that can be reached by throwing dice.
     * @param[in] Dice is the number of dice thrown.
     *
     * @returns The desired entry from the possibility table.
     */
    [[maybe_unused]] unsigned long long ReachTargetWithXDice(int target, int dice);

private:
    // The table will be represented by a vector of vectors.
    std::vector<std::vector<unsigned long long>> DTable;

    // Initialised in the constructor.
    int TableHeight;
    int TableWidth;


    /**
     * Initialises and then solves the possibility table.
     */
    void Solve();


    /**
     * Prints out elements in a table row-wise.
     *
     * @param[in] table Table to print out values from.
     */
    [[maybe_unused]] static void PrintTable(const std::vector<std::vector<unsigned long long>>& table);


    /**
     * Creates a [N][6N] matrix. Manually solves the first row in the table, then initialises all other values in the table to zero.
     *
     * @param[out] table Table to assign values into.
     */
    void InitialiseTable(std::vector<std::vector<unsigned long long>> &table) const;


    /**
     * Calculates the value that should be in table[RowNum][ColNum].
     *
     * @param[in] RowNum Row index of the table.
     * @param[in] ColNum Col index of the table.

     * @returns Calculated value.
     */
    unsigned long long DetermineValue(int RowNum, int ColNum);


    /**
     * Solves the possibility table.
     */
    void SolveTable();

};


#endif //DICE_DICETABLE_H
