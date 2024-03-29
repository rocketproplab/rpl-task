
enum TaskStatus { CREATED, STARTING, RUNNING, PAUSING, STOPPED, RESUMING};
class RplTask {
private:

protected:
    virtual void onStart() {}; // Children implement for first-time start behavior.
    virtual void onResume() {}; // Children implement for handling resume
    virtual void onPause() {}; // Children implement for handling pause
    virtual void onLoop() {}; // Children implement for handling loop
    virtual void init(RplTask** tasks, int taskCount) {};
public:
    TaskStatus status;
    /*
        Starts this task.
    */
    void start();

    /*
        Pauses this task, preventing loop-level logic from firing.
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
        Returns the current status of this task (created, running, or stopped.)
        If the status changed, this function should reflect the current state as of
        the most recent loop.
    */
    TaskStatus getStatus();
    void resume();
    RplTask() : status(CREATED) {};
    ~RplTask();
};
