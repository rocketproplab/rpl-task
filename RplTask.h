#include "TaskLinkedList.h"

enum TaskStatus { CREATED, STARTING, RUNNING, PAUSING, STOPPED, RESUMING};
class RplTask {
    protected:
        virtual void onStart() {}; // Children implement for first-time start behavior.
        virtual void onLoop() {}; // Children implement for handling loop
        virtual void onResume() {}; // Children implement for handling resume
        virtual void onPause() {}; // Children implement for handling pause

    public:
        TaskStatus status;
        TaskLinkedList dependList;
        /*
            Starts this task; calls onStart(), then onLoop() every process().
        */
        void start();

        /*
            Pauses this task; calls onPause(), then prevents loop-level logic from firing.
        */
        void pause();

        /*
            Called in the main loop, this method manages the loop-level
            logic for this task.

            If the task was not running, but is now running this loop for
            the first time, call onStart().

            If the task was not running last loop, but is now running this loop,
            call onResume once.

            If the task was running but is now not running, call onPause once.

            If the task is running, run onLoop.
        */
        void process(float deltaTime);

        /*
            Returns the current status of this task (CREATED, STARTING, RUNNING, PAUSING, STOPPED, RESUMING)
            If the status changed, this function should reflect the current state as of
            the most recent loop.
        */
        TaskStatus getStatus();

        /*
            Add a another task as a dependency to this task; stored in dependList.
        */
        void addDepend(RplTask* newDepend);
        
        /*
            Returns true if all dependencies have status STOPPED and false if a task is still running.
        */
        bool checkDepend();

        /*
            Begins a task again; calls onResume(), then onLoop() every processs().
        */
        void resume();

        RplTask() : status(CREATED), dependList(TaskLinkedList()) {};
        ~RplTask();
};
