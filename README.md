# DiceTables

Given a number of dice N, a reasonable question is to ask how many different ways there are of reaching a target T with those N dice.

This project explores this question and looks to make the calculations as fast as possible.

The code in its current state gives an approximation (accurate to N +-10) of how large a dice-table can be made within a second. This gives an answer of around 1100

The method used to determine each entry in the table can seem a little mysterious within being explicitly told how to do the calculation. So it goes as follows...

Consider how many ways there are to roll a total of 7 with two dice (T = 7, N = 2). 

The number of possibilities is equivalent to rolling a 1 on the first dice, then a 6 on the next, plus rolling a 2 on the first dice and then a 5 on the next and so on.

This can be broken down to the following formula.

Let N > 1 be the number of dice thrown and T be the target number. Let P(N, T) be equal to the number of ways to do this, then...

P(N, T) = P(N - 1, T - 6) + P(N - 1, T - 5) + P(N - 1, T - 4) + P(N - 1, T - 3) + P(N - 1, T - 2) + P(N - 1, T - 1).

This can therefore be computed recursively until we reduce N enough times for P(N, T) to be equivalent to a bunch of P(1, t) + ....

However we don't actually save any time by considering a recursive chain as opposed to using two for loops. 

Where we need to apply this knowledge is by filling out entries in the table and then looking up values in the table when we need them. 

For example, the cost of computing P(N-1, T-1) is massive if N is large. 

However, if we have already computed this value then the cost of computing the value is equivalent to the cost of looking up a value in a table that is Nx6N large.

Whilst this is a much faster way to do this, we also get the added bonus that we can look up any value in this table after it has been computed. 

Meaning that if we let N = 600, then we can look up P(n, t) for every 0 < n < N.
