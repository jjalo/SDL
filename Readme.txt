For testing without compilation, you can find the lastest executable, resources and DLL files from the "TestBuild.zip" file.

In order to compile the game, you need to create project files.

For Visual studio
1. Run VS Command Prompt
2. Change directory to the root folder of the module
3. mkdir build
4. cd build
4. run cmake with the following command or equivalent*: 
Cmake -G "Visual Studio 12 Win64" ..
5. Refresh & Open VS project in build directory
6. Set quickescape as start project
7. Build solution
8. Copy required .dll files from ./deps/lib to the running folder. Also the ./res folder must be in the same folder as the executable, otherwise it will crash. The location of the exe can apparently differ when running from inside VS or the build folder.

*Note: Boost is in the default directory, this can be set in CMakeLists if it differs.