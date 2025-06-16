#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    string id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit; // Sort jobs based on profit in descending order
}

int minValue(int x, int y)
{
    return (x < y) ? x : y;
}

void jobSequencingWithDeadline(vector<Job> &jobs, int n)
{
    int maxprofit = 0;
    int dmax = 0;

    // Find the maximum deadline value
    for (int i = 0; i < n; i++)
    {
        dmax = max(dmax, jobs[i].deadline);
    }

    // Create a vector to store the free time slots
    vector<int> timeslot(dmax + 1, -1); // Initialize all slots to -1 (EMPTY)
    int filledTimeSlot = 0;

    // Job sequencing logic
    for (int i = 0; i < n; i++)
    {
        int k = minValue(dmax, jobs[i].deadline);
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = i;
                filledTimeSlot++;
                break;
            }
            k--;
        }

        if (filledTimeSlot == dmax)
        {
            break;
        }
    }

    // Output the required jobs
    cout << "\nRequired Jobs: ";
    for (int i = 1; i <= dmax; i++)
    {
        if (timeslot[i] != -1)
        {
            cout << jobs[timeslot[i]].id;
            if (i < dmax)
            {
                cout << " --> ";
            }
        }
    }

    // Output the total profit
    for (int i = 1; i <= dmax; i++)
    {
        if (timeslot[i] != -1)
        {
            maxprofit += jobs[timeslot[i]].profit;
        }
    }

    cout << "\nMax Profit: " << maxprofit << endl;
}

int main()
{
    vector<Job> jobs = {
        {"j1", 2, 60},
        {"j2", 1, 100},
        {"j3", 3, 20},
        {"j4", 2, 40},
        {"j5", 1, 20}};

    int n = jobs.size();

    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    // Display job details
    cout << "Job       Deadline       Profit\n";
    for (int i = 0; i < n; i++)
    {
        cout << jobs[i].id << "       " << jobs[i].deadline << "             " << jobs[i].profit << endl;
    }

    jobSequencingWithDeadline(jobs, n);
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";
    return 0;
}
