#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Job.h"
using namespace std;

class Scheduler
{
public:
    void addJob(int start, int finish, int profit);
    void solve();
    void printJobs();
    void printSolution();

private:
    vector<Job> jobs;
    vector<int> dp;
    vector<int> previous;
    vector<Job> selectedJobs;

    void sortJobs();
    int latestCompatible(int index);
    void buildSolution(int index);
};

#endif
