#ifndef TASK_HPP
#define TASK_HPP

#include "common.h"

class Task {

public:
        Task(string name, Time* deadline);
        ~Task();

        void setFinished();
        void setUnfinished();
        bool isFinished();


        void debug(string indent);

private:
        string name;
        Time* deadline;
        bool finished;

};

#endif
