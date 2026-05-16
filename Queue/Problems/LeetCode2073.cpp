#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LeetCode 2073: Time Needed to Buy Tickets
// Given an array tickets of positive integers where tickets[i] represents the number of tickets the ith
// person wants to buy and a positive integer k, return the time it takes for the kth person to finish buying tickets.
// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to wait 
// in line until it's their turn to buy the next ticket.

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int, int>> ticket_counter;

        for(int i = 0; i < tickets.size(); i++) {
            
            ticket_counter.push({i, tickets[i]});
        }

        int total_time = 0;

        while(!ticket_counter.empty()) {

            int idx = ticket_counter.front().first;
            int tkt = ticket_counter.front().second;

            ticket_counter.pop();

            if(idx == k && tkt == 1) {
                return total_time + 1;
            }

            if(tkt > 1) {
                ticket_counter.push({idx, tkt - 1});
            }

            total_time++;
        }
        
        return total_time;
    }
};

// Time Complexity: O(n * max(tickets[i])) where n is the number of people in the queue and 
// max(tickets[i]) is the maximum number of tickets any person wants to buy.
// Space Complexity: O(n) for the queue storing the people and their remaining tickets.