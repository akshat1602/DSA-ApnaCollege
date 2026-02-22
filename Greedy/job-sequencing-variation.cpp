//Variation -> to also show order of jobs selected along with profit output.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job{
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit){
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector <pair<int, int>> pairs){
    int n = pairs.size();
    vector <Job> jobs;

    for (int i = 0; i < n; i++)
    { //because we are storing more than 2 values that's why OOPS implementation.
        jobs.emplace_back(i, pairs[i].first, pairs[i].second); //idx, deadline, profit
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){
        return a.profit > b.profit;
        //descending order on basis of profit
        //same as compare function
        //It's a lambda function : nameless function
        //[] -> it's a capture list.
    });

    cout<<"Selecting Job"<<jobs[0].idx<<endl; //original idx printing
    int profit = jobs[0].profit;
    int safeDeadline = 2;

    for (int i = 1; i < n; i++)
    {
        if(jobs[i].deadline >= safeDeadline){
            cout << "Selecting Job"<< jobs[i].idx<<endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }
    return profit;
}

int main() {
    int n = 4;
    vector <pair<int, int>> jobs(n, make_pair(0,0));

    jobs[0] = make_pair(4,20);
    jobs[1] = make_pair(1,10);
    jobs[2] = make_pair(1,40);
    jobs[3] = make_pair(1,30);

    cout<<"Max Profit : "<<maxProfit(jobs)<<endl;
    return 0;
}