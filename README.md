# Generic Testing Environment Template

This package has been designed as a template for developers to use as a starting point to implement a testing environment in their new ROS package.

Each file based around the testing environment contains a generic example of what needs to be added to their package's file system. Additionally, each file has a complete example as well as the generic one to assist in constructing the testing environment.

http://wiki.ros.org/Quality/Tutorials/UnitTesting

## Unit Testing

Unit testing is for testing the Library itself. 

Do the functions operate as expected and are the parameters set to the correct values? 

These are some of the things that should be tested through unit testing.

Unit tests for the ROS framework include gtest (C++) and unittest (Python).

There are methods of using pytest for ROS but it requires a test runner script as well as the unit test code.

#### Research Resources

[unittest](http://wiki.ros.org/unittest)

[gtest](http://wiki.ros.org/gtest)

[pytest runner for ros](https://machinekoder.com/testing-ros-powered-robots-pytest/)

[pytest](https://docs.pytest.org/en/latest/)

## Rostest

Rostest is a ROS built integration testing tool.

It is used for testing nodes but can also run unit tests while the roscore is running.

Has the same capabilities as .launch files but operates within a testing environment.

#### Research Resources

[rostest](http://wiki.ros.org/rostest)

## .test files

.test files are the same syntax as .launch files and run in a very similar way.

However, the .test files allow for nodes to be testing while they operate on the roscore.

#### Research Resources

[writing .test files](http://wiki.ros.org/rostest/Writing)

## Building Tests

If the package and workspace is set up correctly for testing there are two ways to build and run tests.

1. Open the terminal and Run "roscore".

2. Build the code:

```
catkin build --catkin-make-args run_tests
```
3. Run the tests:

```
cd /catkin_ws/build/foo_pkg
make run_tests
```

[catkin_make documentation](http://docs.ros.org/en/jade/api/catkin/html/howto/format2/run_tests.html)

[catkin build documentation](https://catkin-tools.readthedocs.io/en/latest/verbs/catkin_build.html#advanced-options)

## Running Tests

Rostest can be run indivdually with a commandline call.

```
rostest (package-name) (test-filename) (args)
```

[rostest commandline](http://wiki.ros.org/rostest/Commandline)