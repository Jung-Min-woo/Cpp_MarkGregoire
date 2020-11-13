#include <iostream>
#include <string>
#include <vector>
using namespace std;
//ex1
using StringVector = std::vector<std::string>;
void processVector(const StringVector& vec){
}
//ex2
using MatchFunction = bool(*)(int, int);
void findMatches(int values1[], int values2[], size_t numValues, MatchFunction matcher){
    for(size_t i=0; i<numValues; i++)
        if(matcher(values1[i], values2[i])){
            cout<<"Match found at position "<<i<<
            "("<<values1[i]<<", "<<values2[i]<<")"<<endl;
        }
}
bool intEqual(int item1, int item2){
    return item1 == item2;
}
bool bothOdd(int item1, int item2){
    return item1 % 2 ==1 && item2 % 2 ==1;
}
int main(void){
    StringVector myVector;
    processVector(myVector);

    int arr1[] = {2,5,6,9,10,1,1};
    int arr2[] = {4,4,2,9,0,3,4};
    size_t arrSize = std::size(arr1);
    cout<<"Calling findMatches() using intEqual() : "<<endl;
    findMatches(arr1, arr2, arrSize, &intEqual);
    cout<<"Calling findMatches() using bothOdd(): "<<endl;
    findMatches(arr1,arr2,arrSize, &bothOdd);
    return 0;
}