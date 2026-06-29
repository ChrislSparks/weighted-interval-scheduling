#ifndef JOB_H
#define JOB_H

class Job
{
public:
    int start;
    int finish;
    int profit;

    Job(int s, int f, int p)
    {
        start = s;
        finish = f;
        profit = p;
    }
};

#endif
