# Making Your First Task

Of course it would be useless to have a task library if you couldn't make your own task. This is a quick start up tutorial on how you can write you first one!

## __How to make an RPL Task?__

To make your first RPL Task just include the RPL Task class as an interface! Here is an example below:

``` c++
    class ExampleTask : public RplTask{

    }
```

It's really that simple! You've made your first RPL Task. However, this task doesn't have much functionality, so let us now add some.

## __Key features of an RPL Task__

### Task Functions

Every RPL task has a couple of key functions that you need to implement. These are:

``` c++
    virtual void onStart() {};
    virtual void onResume() {};
    virtual void onPause() {};
    virtual void onLoop() {};
    virtual void init(RplTask** tasks, int taskCount) {};
```

These functions are what define what the Task should do whenever it is running as well as what it should do when it gets paused, resumed, and started. the `init` function is a set up function when the task is originally created.

### Header Comments

One really important part of RPL Tasks are the Header Comments. These comments allow for the sorting and organization of tasks which is needed for the code generation. These header comments have the following format:

``` c++
/*
RPL-TASK-HEADER
CLASS: Task3
START-ON-BOOT: TRUE/FALSE
TASK-DEPENDENCIES
Task1
Task2
END-TASK-DEPENDENCIES
END-RPL-TASK-HEADER
*/
```

These comments tell the code important information for code generation such as: what Tasks does this Task depend on, what is this Task's name, and should this Task be on at start up of the rocket.

