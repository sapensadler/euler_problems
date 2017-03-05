# euler_problems

The main point of this project was to learn more about C++, using Project Euler problems.

To run build and run the problems you will need, g++ installed, cmake, make and libgmp-dev. To build run the build-all.sh script or to build individual problems run ./build-project.sh problem<xx>.

The build-all scripts take an optional argument of --concurrent or --consecutive. This can speed up build and run times dramatically.

Use the run-all.sh and run-project.sh problem<xx> to execute the problems.

Build scripts have an optional second argument for CMAKE e.c -DCMAKE_BUILD_TYPE=Debug which will be passed. --concurrent or --consecutive must go BEFORE the CMAKE option.
