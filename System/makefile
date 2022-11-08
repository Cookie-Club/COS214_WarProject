CC = g++
CFLAGS = -g -Wall -Werror
LFLAGS = -static
TARGET = main.out
OBJECTS = Participants.o Action.o Aggressive.o AlliedFactory.o AlliedInfantry.o\
AlliedPowers.o AlliedTank.o AmmoDepoFactory.o\
AmmoDeposit.o attackStrategy.o CentralFactory.o CentralInfantry.o\
CentralPowers.o CentralTank.o Bog.o Bombardment.o Caretaker.o Cell.o\
CellFeatures.o Defensive.o FeatureFactory.o\
Flatlands.o Frontline.o FuelDepoFactory.o FuelDeposit.o Infantry.o\
InfantryDamage.o Mining.o main.o MilitaryUnit.o SaveState.o\
Squad.o SquadDamage.o Tank.o TankDamage.o TeamMembers.o War.o WorldMap.o
# Linking all the object code:
all: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(TARGET)

# Dependencies:
Action.o: Action.h Action.cpp Squad.h
Aggressive.o: Aggressive.h Aggressive.cpp Action.h Action.cpp
AlliedFactory.o: AlliedFactory.h AlliedFactory.cpp Factory.h AlliedInfantry.h AlliedInfantry.cpp AlliedTank.h AlliedTank.cpp
AlliedInfantry.o: AlliedInfantry.h AlliedInfantry.cpp Infantry.h Infantry.cpp
AlliedPowers.o: AlliedPowers.h AlliedPowers.cpp Participants.h
AlliedTank.o: AlliedTank.h AlliedTank.cpp Tank.h TeamMembers.h MilitaryUnit.h
AmmoDepoFactory.o: AmmoDepoFactory.h AmmoDepoFactory.cpp FeatureFactory.h AmmoDeposit.h
AmmoDeposit.o: AmmoDeposit.h AmmoDeposit.cpp CellFeatures.h
attackStrategy.o: attackStrategy.h attackStrategy.cpp Squad.h
CentralFactory.o: CentralFactory.h CentralFactory.cpp Factory.h
CentralInfantry.o: CentralInfantry.h CentralInfantry.cpp Infantry.h TeamMembers.h MilitaryUnit.h
CentralPowers.o: CentralPowers.h CentralPowers.cpp Participants.h
CentralTank.o: CentralTank.h CentralTank.cpp Tank.h TeamMembers.h MilitaryUnit.h
Bog.o: Bog.h Bog.cpp Cell.h
Bombardment.o: Bombardment.h Bombardment.cpp SquadDamage.h InfantryDamage.h TankDamage.h Order.h Cell.h Squad.h
Caretaker.o: Caretaker.h Caretaker.cpp
Cell.o: Cell.h Cell.cpp
CellFeatures.o: CellFeatures.h CellFeatures.cpp 
Defensive.o: Defensive.h Defensive.cpp Action.h
FeatureFactory.o: FeatureFactory.h FeatureFactory.cpp
Flatlands.o: Flatlands.h Flatlands.cpp Cell.h
Frontline.o: Frontline.h Frontline.cpp attackStrategy.h
FuelDepoFactory.o: FuelDepoFactory.h FuelDepoFactory.cpp FeatureFactory.h FuelDeposit.h
FuelDeposit.o: FuelDeposit.h FuelDeposit.cpp CellFeatures.h
Infantry.o: Infantry.h Infantry.cpp TeamMembers.h MilitaryUnit.h
InfantryDamage.o: InfantryDamage.h InfantryDamage.cpp Bombardment.h
Mining.o: Mining.h Mining.cpp attackStrategy.h
main.o: main.cpp War.h AlliedPowers.h CentralPowers.h
MilitaryUnit.o: MilitaryUnit.h MilitaryUnit.cpp
Participants.o: Participants.h Participants.cpp
SaveState.o: SaveState.h SaveState.cpp
Squad.o: Squad.h Squad.cpp MilitaryUnit.h Participants.h attackStrategy.h Aggressive.h Defensive.h
SquadDamage.o: Bombardment.h SquadDamage.h SquadDamage.cpp
Tank.o: Tank.h Tank.cpp TeamMembers.h MilitaryUnit.h
TankDamage.o: TankDamage.h TankDamage.cpp Bombardment.h
TeamMembers.o: TeamMembers.h TeamMembers.cpp MilitaryUnit.h
War.o: War.h War.cpp
WorldMap.o: WorldMap.h WorldMap.cpp AmmoDepoFactory.h FuelDepoFactory.h Bog.h Flatlands.h

# Compilation rule:
\%.o: \%.cpp
	$(CC) \$< $(CFLAGS) -c -o $@
	
# Custom commands:
clean:
	rm -f $(TARGET) $(OBJECTS) *~ # deleting executable, .o’s and backups

run: $(TARGET)
	./$(TARGET) # executing the program

# Cleans up terminal before compiling and running
stuff:
	clear && make && make run

# Stuff for testing
# Creates Test Directory with passed in name
create_test:
	mkdir ${DIR_NAME} && \
	cp -i ./Example_Test/CMakeLists.txt ./${DIR_NAME}/ && \
	cp -i ./Example_Test/Test_Config.h.in ./${DIR_NAME}/ && \
	cp -i ./Example_Test/Test_Template.cpp ./${DIR_NAME}/${DIR_NAME}_main.cpp && \
	cp -i ./Example_Test/Fixtures_Template.h ./${DIR_NAME}/${DIR_NAME}_Fixtures.h && \
	cd ./${DIR_NAME} && \
	mkdir ${DIR_NAME}_Build

# Builds and runs tests in passed directory
test:
	cd ${DIR_NAME}/${DIR_NAME}_Build && cmake .. && cmake --build . && ctest --output-on-failure
