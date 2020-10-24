# Repository that contains students' work for the Data structure course 2020/2021
### Structure:
* group1 - contains code for the students that belong to group 1
* group4 - contains code for the students that belong to group 4

### Rules:
* **master** branch is protected so every change must be made through pull request.
* Students should touch only their folders
* When opening PR, it should contain summary of the problems that are being solved. If a student tries to add solution to a problem that is not in this repository, task description must be provided.

### Testing
For unit tests we will use the **doctest** library. You can find the header located in `shared/specs` folder.<br>
There you will also find another header `specHelper` which includes the test library and configures it to run without main function.

You can either include the **doctest** library itself or use the **specHelper** header. In order to do this you can:

* Include them by providing the absolute path to the file. It is not recommended since they cannot be on any other machine than yours because of the path that you will be providing.
* Include them by providing the relative path to the file. It will work but you will have some long pathnames that will be difficult to track
* You can add a path that the compiler will use in addition to the default ones when searching for your included files. You can do this by passing the following option when compiling the code:<br>
> `g++ - I (rootFolder) (yourFilesToCompile)`
* You can use Makefile to manage the compilation process. In fact you can do this to manage the not only your tests but all other code that you have. There is a sample makefile in `shared/specs` folder which contains sample configuration for the tests. It follows the strategy suggested above. You are free to copy this file wherever you need an modify if you want. In order to build the tests files you need to execute the *buil_tests* step with the following command <br>
> `make build_tests`

