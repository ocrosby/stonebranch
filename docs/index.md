# Documentation

## Building

In order to build this project you must first create a build directory and run cmake from that directory. 

The following commands will create a build directory and build the project.

```bash
mkdir build
cd build
cmake ..
make
```

This essentially generates a Makefile from the CMakeLists.txt file and then runs make to build the project.

As a result a file named build/demo will be created. This is the executable that you can run to see the program in 
action.


# References

* [Markdown Cheatsheet](http://commonmark.org/help/)
* [Markdown Syntax](https://daringfireball.net/projects/markdown/syntax)
* [Google Test](https://github.com/google/googletest)
* [Unit Testing C Code with Google Test](https://notes.eatonphil.com/unit-testing-c-code-with-gtest.html)