#ifndef TASK_HPP
#define TASK_HPP

#include "common.h"

class Task {

public:
        Task(string name, Time* deadline);
        ~Task();

        string getName();
        string getDate();
        int getRelativeDate();
        Time* getDeadline();
        string getState();

        bool isDeadlineRelative();

        void setFinished();
        void setUnfinished();
        bool isFinished();

        void setRelativeDate(Task* relativeDeadline, int dayInterval);
        void setAbsoluteDate(Time* deadline);

        void addRequiredTask(Task *task);
        void removeRequiredTask(int row);

        void debug(string indent);

private:
        string name;
        Time* deadline;
        Task* relativeDeadline;
        int dayInterval;
        bool finished;

        vector<Task*> requiredTasks;
};

#endif
