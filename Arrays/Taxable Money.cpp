

Input: brackets = [[3,50],[7,10],[12,25]], income = 10
Output: 2.65000
Explanation:
The first 3 dollars you earn are taxed at 50%. You have to pay $3 * 50% = $1.50 dollars in taxes.
The next 7 - 3 = 4 dollars you earn are taxed at 10%. You have to pay $4 * 10% = $0.40 dollars in taxes.
The final 10 - 7 = 3 dollars you earn are taxed at 25%. You have to pay $3 * 25% = $0.75 dollars in taxes.
You have to pay a total of $1.50 + $0.40 + $0.75 = $2.65 dollars in taxes.

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax=0.0,prev=0.0;
for(auto const &it:brackets){
    int up=it[0],pr=it[1];
    int rn=min(up,income);
    tax+=((rn-prev)*pr)/100;
    prev=up;
    if(up>=income)
        break;
}        
        return tax;
    }
};