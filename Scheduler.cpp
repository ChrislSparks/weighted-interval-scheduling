#include "Scheduler.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void Scheduler::addJob(int start, int finish, int profit)
{
    jobs.push_back(Job(start, finish, profit));
}

void Scheduler::sortJobs()
{
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.finish < b.finish;
    });
}

int Scheduler::latestCompatible(int index)
{
    int low = 0;
    int high = index - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (jobs[mid].finish <= jobs[index].start)
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}

void Scheduler::solve()
{
    sortJobs();

    int n = jobs.size();
    dp.resize(n);
    previous.resize(n);

    for (int i = 0; i < n; i++)
    {
        previous[i] = latestCompatible(i);
    }

    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++)
    {
        int includeProfit = jobs[i].profit;

        if (previous[i] != -1)
        {
            includeProfit += dp[previous[i]];
        }

        int excludeProfit = dp[i - 1];

        dp[i] = max(includeProfit, excludeProfit);
    }

    selectedJobs.clear();
    buildSolution(n - 1);
}

void Scheduler::buildSolution(int index)
{
    if (index < 0)
    {
        return;
    }

    int includeProfit = jobs[index].profit;

    if (previous[index] != -1)
    {
        includeProfit += dp[previous[index]];
    }

    int excludeProfit = 0;

    if (index > 0)
    {
        excludeProfit = dp[index - 1];
    }

    if (includeProfit > excludeProfit)
    {
        buildSolution(previous[index]);
        selectedJobs.push_back(jobs[index]);
    }
    else
    {
        buildSolution(index - 1);
    }
}

void Scheduler::printJobs()
{
    cout << "Jobs Sorted by Finish Time\n\n";
    cout << left << setw(10) << "Start"
         << setw(10) << "Finish"
         << setw(10) << "Profit" << endl;

    cout << "-----------------------------\n";

    for (const Job& job : jobs)
    {
        cout << left << setw(10) << job.start
             << setw(10) << job.finish
             << setw(10) << job.profit << endl;
    }

    cout << endl;
}

void Scheduler::printSolution()
{
    printJobs();

    cout << "Optimal Job Schedule\n\n";
    cout << left << setw(10) << "Start"
         << setw(10) << "Finish"
         << setw(10) << "Profit" << endl;

    cout << "-----------------------------\n";

    for (const Job& job : selectedJobs)
    {
        cout << left << setw(10) << job.start
             << setw(10) << job.finish
             << setw(10) << job.profit << endl;
    }

    cout << "\nMaximum Profit: " << dp.back() << endl;
}
