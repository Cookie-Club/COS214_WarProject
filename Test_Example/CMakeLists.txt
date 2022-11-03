#[[
How to create unit testing project:

1. Check that you have cmake version 3.14 or higher installed

2. In the project root directory; create a directory named <Test_Name> and second <Test_Name>_Build directory inside your <Test_Name> one
  **The name of the second directory must end in "_Build" in order for the .gitignore file to ignore the files inside,
    they are rather large and can always be reconstructed, so commiting them is pointless

3. Copy this CMakefile into your new <Test_Name> directory and create your own <Test_Name>_Fixtures.h and <Test_Name>_main.cpp files
4. Replace all instances of "test_Example" in your new CMakeLists.txt file with your project name of choice
5. Replace all instances of "test_main_Example.cpp" in your new CMakeLists.txt file with the name of your <Test_Name>_main.cpp
6. Open your terminal, cd into your new <Test_Name>_Build directory and run the following commands:

    cmake ..      <! Note the two full stops
    cmake --build .     <! Note the full stop
    ctest
]]

cmake_minimum_required(VERSION 3.14)
#Project name, change when you copy the file
project(test_Example)
#Minimum release version for googletest
set(CMAKE_CXX_STANDARD 14)


#---Yoinked from http://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#------------------------------------------------------------------------


#Get path to parent directory where source files are located
set(curr_path "${CMAKE_CURRENT_SOURCE_DIR}")
cmake_path(GET curr_path PARENT_PATH p_path)
include_directories(${p_path})

#Add to list of source files to form dependenices in constructed makefile
#Please remember to add newly created files
set(SOURCES ${p_path}/Action.cpp ${p_path}/Action.h
            ${p_path}/Aggressive.cpp ${p_path}/Aggressive.h
            ${p_path}/AlliedFactory.cpp ${p_path}/AlliedFactory.h
            ${p_path}/AlliedInfantry.cpp ${p_path}/AlliedInfantry.h
            ${p_path}/AlliedPowers.cpp ${p_path}/AlliedPowers.h
            ${p_path}/AlliedTank.cpp ${p_path}/AlliedTank.h
            ${p_path}/AmmoDepoFactory.cpp ${p_path}/AmmoDepoFactory.h
            ${p_path}/AmmoDeposit.cpp ${p_path}/AmmoDeposit.h
            ${p_path}/attackStrategy.h
            ${p_path}/Bog.cpp ${p_path}/Bog.h
            ${p_path}/Bombardment.cpp ${p_path}/Bombardment.h
            ${p_path}/Caretaker.cpp ${p_path}/Caretaker.h
            ${p_path}/Cell.cpp ${p_path}/Cell.h
            ${p_path}/CellFeatures.cpp ${p_path}/CellFeatures.h
            ${p_path}/CentralFactory.cpp ${p_path}/CentralFactory.h
            ${p_path}/CentralInfantry.cpp ${p_path}/CentralInfantry.h
            ${p_path}/CentralPowers.cpp ${p_path}/CentralPowers.h
            ${p_path}/CentralTank.cpp ${p_path}/CentralTank.h
            ${p_path}/Context.cpp ${p_path}/Context.h
            ${p_path}/Defensive.cpp ${p_path}/Defensive.h
            ${p_path}/Enumerations.h
            ${p_path}/Factory.h
            ${p_path}/FeatureFactory.cpp ${p_path}/FeatureFactory.h
            ${p_path}/Flatlands.cpp ${p_path}/Flatlands.h
            ${p_path}/Frontline.cpp ${p_path}/Frontline.h
            ${p_path}/FuelDepoFactory.cpp ${p_path}/FuelDepoFactory.h
            ${p_path}/FuelDeposit.cpp ${p_path}/FuelDeposit.h
            ${p_path}/Infantry.cpp ${p_path}/Infantry.h
            ${p_path}/InfantryDamage.cpp ${p_path}/InfantryDamage.h
            ${p_path}/MilitaryUnit.cpp ${p_path}/MilitaryUnit.h
            ${p_path}/Mining.cpp ${p_path}/Mining.h
            ${p_path}/Order.h
            ${p_path}/Participants.cpp ${p_path}/Participants.h
            ${p_path}/SaveState.cpp ${p_path}/SaveState.h
            ${p_path}/Squad.cpp ${p_path}/Squad.h
            ${p_path}/SquadDamage.cpp ${p_path}/SquadDamage.h
            ${p_path}/Tank.cpp ${p_path}/Tank.h
            ${p_path}/TankDamage.cpp ${p_path}/TankDamage.h
            ${p_path}/TeamMembers.cpp ${p_path}/TeamMembers.h
            ${p_path}/War.cpp ${p_path}/War.h
            ${p_path}/WorldMap.cpp ${p_path}/WorldMap.h)

enable_testing()

#Declare source files with which to construct the executable
add_executable(test_Example test_main_Example.cpp ${SOURCES})

#specify directories where the compiler should look for files specified in #include statements
target_include_directories(test_Example PUBLIC 
                            "${PROJECT_BINARY_DIR}" 
                            p_path)

target_link_libraries(test_Example GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_Example)
