
# University of Washington Bothell | Dong Si | 342 | Fall Quarter 2022 | Program 5, The Jolly Banker
### Parth Gupta | Oliver Schwab | Alex Covaci | Scott Cruickshank

## Overview
The Jolly Banker is a banking applicaition that processes transactions from an input .txt file. The program has all the functionality of a tradiontal bank. It can  open accounts, withdraw funds, deposit funds, transfer funds, or ask for the transactional history to be printed. Each client account contains assets held in up to ten funds. A client account is represented by a first and last name (two strings) and a unique 4 digit identifier. A fifth digit can be added to the digit id to represent the individual fund within the account. The account transactions from the input file are placed into a que (first in first out) these accounts are then stored in a binary search tree for implementation in the correct order. Once all of the transactions in the que have been completed, all open accounts and balances will be printed. 

## Specifications

Account ID's are unique to each account and contain 4 digits <br>

Each client account type is assigned a numerical value for easy access. They are as listed below. <br>
0: Money Market <br>
1: Prime Money Market <br>
2: Long-term Bond <br>
3: Short-Term Bond <br>
4: 500 Index Fund <br>
5: Capital Value Fund <br>
6: Growth Equity fund <br>
7: Growth Index Fund <br>
8: Value Fund <br>
9: Value Stock Fund <br>

When requesting to make a transaction the appropriate call sign must lead the command. The call signs for each type of transaction are as follows.. <br>
O: Open a client account with the appropriate funds <br>
D: Deposit assets into a fund <br>
W: Withdraw assets from a fund <br>
T: Transfer assets between funds (can be funds owned by a single client or 
transfers between clients) <br> 
H: Display the history of all transactions for a client account or for a single fund <br>



For the program to operate as intended the transactions must be entered in the following format. <br>

D 12341 100 Deposit $100 into the prime money market account of client ID 1234 <br>
W 12340 500 Withdraw $500 from the money market of client ID 1234 <br>
T 12340 1000 12341 Transfer $1000 from client 1234's money market to the prime money market <br>
T 12340 1000 56780  Transfer $1000 from 1234's money market to 5678's money market <br>
H 1234  Display the history of all transactions of all accounts for client 1234 <br>
H 12344 Display the history for all transactions on the 500 Index Fund for client 1234 <br>
O Bowden Charles 6537 Open an account for client Charles Bowden.  Use account id 6537 <br>

## Installation 





  
