#include <iostream>
using namespace std;
//S = No. of days you have to survive 
//N = No. of units of food you can purchase per day
//M = Unit of food to survive one day
// Find minimum number of day you need to buy food from the Shop to survive and if the shop is closed on Sunday

int minimumDayToBuyFoodToSurvive(int S, int N, int M){
    //To find Sundays in your life span just divide total no. of survival days by 7
    int Sunday = S / 7;

    //Now we have to find no. of days you can buy from Shop
    int buyingDays = S - Sunday; //the number of buying days will be subtracted from Sunday as shop will be closed on Sunday
    
    //Now total food you need to have to survive, will be amount of days to survive X unit of food consumed in one day
    int totalFood = S*M;

    int ans = 0; // this will contains minimum number of day you need to buy food to survive

    //From the below formula you will get no. days you have to purchase to survive
    if(totalFood % N == 0){
        ans = totalFood / N;
    } 
    else{
        ans = totalFood / N + 1;
    }

    //If no. days to purchase are more than the no. of days to buy then definitely you will die
    if(ans <= buyingDays){
        return ans;
    }
    else{
        return -1;        
    }



}
int main()
{
    cout<<"Minimum number of Days To Buy Food To Survive is "<<minimumDayToBuyFoodToSurvive(10,20,30)<<endl;
    return 0;
}