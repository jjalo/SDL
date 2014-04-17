In order to compile the game, you probably need to create new project files.

For Visual studio
1. Run VS Command Prompt
2. Change directory to "build"
3. run cmake with the following command or equivalent: 
Cmake -G "Visual Studio 12 Win64" ..
4. Refresh & Open VS project in build directory
5. Set quickescape as start project
6. Build solution
(7.) Copy .dll files from ../deps/lib if not present in the folder to run the game. Also the "res" folder must be in the same folder as the executable, otherwise it will crash. The location of the exe can apparently differ when running from inside VS or the build folder.

*Note: Boost is in the default directory, this can be set in CMakeLists if it differs.