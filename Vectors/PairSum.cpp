#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> &vec, int size, int target){
    vector<int> result;
    int start = 0, end = size - 1;

    while (start <= end){
        if(vec[start] + vec[end] == target){
            result.push_back(start);
            result.push_back(end);
            break;
        }
        else if(vec[start] + vec[end] < target){
            start ++;
        }
        else{
            end --;
        }
    }
    return result;
    
}

int main(){
    vector<int> vec = {2, 7, 11, 15};
    vector<int> result;
    int size = 4;
    int target = 22;

    result = pairSum(vec, size, target);
    cout<< result[0]<<", "<< result[1]<<endl;
    return 0;
}