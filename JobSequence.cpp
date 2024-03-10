#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compareJobs(Job &a,Job &b) {
    return (a.profit > b.profit);
}

void jobSequencing(vector<Job> &jobs) {
    int n = jobs.size();
    vector<int> result(n, -1); // Result array to store the scheduled jobs
    vector<bool> slot(n, false); // Array to check if a slot is occupied

    // Sort jobs based on profit in descending order
    sort(jobs.begin(), jobs.end(), compareJobs);

    // Iterate through the sorted jobs and schedule them
    for (int i = 0; i < n; ++i) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; --j) {
            // Find an available slot with the highest deadline
            if (!slot[j]) {
                result[j] = i; // Schedule the job
                slot[j] = true; // Mark the slot as occupied
                break;
            }
        }
    }

    // Print the scheduled jobs
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < n; ++i) {
        if (slot[i]) {
            cout << jobs[result[i]].id << " ";
        }
    }
    cout << endl;
     int sum=0;
    cout<<"Total profit = ";
    for(int i =0;i<n;++i){
        if(slot[i]){
            sum+=jobs[result[i]].profit;
        }
    }
    cout<<sum;
    
}

int main() {
    // Example usage
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    jobSequencing(jobs);
                            //Contributed By Shafaat
    return 0;    
}
