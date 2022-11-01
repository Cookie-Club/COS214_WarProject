CC = g++
CFLAGS = -g -Wall -Werror
LFLAGS = -static
TARGET = main.out
OBJECTS = Action.o Aggressive.o AlliedFactory.o AlliedInfantry.o\
AlliedPowers.o AlliedTank.o AmmoDepoFactory.o\
AmmoDeposit.o AxisFactory.o AxisInfantry.o\
AxisPowers.o AxisTank.o Bog.o Bombardment.o Caretaker.o Cell.o\
CellFeatures.o Context.o Defensive.o FeatureFactory.o\
Flatlands.o Frontline.o FuelDepoFactory.o FuelDeposit.o Infantry.o\
InfantryDamage.o Mining.o main.o MilitaryUnit.o SaveState.o\
Squad.o Tank.o TankDamage.o TeamMembers.o War.o WarScene.o WorldMap.o
# Linking all the object code:
all: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(TARGET)

# Dependencies:
Action.o: Action.h Action.cpp
Aggressive.o: Aggressive.h Aggressive.cpp Action.h Action.cpp
AlliedFactory.o: AlliedFactory.h AlliedFactory.cpp Factory.h AlliedInfantry.h AlliedInfantry.cpp AlliedTank.h AlliedTank.cpp
AlliedInfantry.o: AlliedInfantry.h AlliedInfantry.cpp Infantry.h Infantry.cpp
AlliedPowers.o: AlliedPowers.h AlliedPowers.cpp Participants.h
AlliedTank.o: AlliedTank.h AlliedTank.cpp Tank.h TeamMembers.h MilitaryUnit.h
AmmoDepoFactory.o: AmmoDepoFactory.h AmmoDepoFactory.cpp FeatureFactory.h
AmmoDeposit.o: AmmoDeposit.h AmmoDeposit.cpp CellFeatures.h
AxisFactory.o: AxisFactory.h AxisFactory.cpp Factory.h
AxisInfantry.o: AxisInfantry.h AxisInfantry.cpp Infantry.h TeamMembers.h MilitaryUnit.h
AxisPowers.o: AxisPowers.h AxisPowers.cpp Participants.h
AxisTank.o: AxisTank.h AxisTank.cpp Tank.h TeamMembers.h MilitaryUnit.h
Bog.o: Bog.h Bog.cpp Cell.h
Bombardment.o: Bombardment.h Bombardment.cpp Order.h
Caretaker.o: Caretaker.h Caretaker.cpp
Cell.o: Cell.h Cell.cpp
CellFeatures.o: CellFeatures.h CellFeatures.cpp 
Context.o: Context.h Context.cpp
Defensive.o: Defensive.h Defensive.cpp Action.h
FeatureFactory.o: FeatureFactory.h FeatureFactory.cpp
Flatlands.o: Flatlands.h Flatlands.cpp Cell.h
Frontline.o: Frontline.h Frontline.cpp attackStrategy.h
FuelDepoFactory.o: FuelDepoFactory.h FuelDepoFactory.cpp FeatureFactory.h
FuelDeposit.o: FuelDeposit.h FuelDeposit.cpp CellFeatures.h
Infantry.o: Infantry.h Infantry.cpp TeamMembers.h MilitaryUnit.h
InfantryDamage.o: InfantryDamage.h InfantryDamage.cpp Bombardment.h Order.h
Mining.o: Mining.h Mining.cpp attackStrategy.h
main.o: main.cpp
MilitaryUnit.o: MilitaryUnit.h MilitaryUnit.cpp
Participants.o: Participants.h Participants.cpp
SaveState.o: SaveState.h SaveState.cpp
Squad.o: Squad.h Squad.cpp MilitaryUnit.h
Tank.o: Tank.h Tank.cpp TeamMembers.h MilitaryUnit.h
TankDamage.o: TankDamage.h InfantryDamage.cpp Bombardment.h Order.h
TeamMembers.o: TeamMembers.h TeamMembers.cpp MilitaryUnit.h
War.o: War.h War.cpp
WarScene.o: WarScene.h WarScene.cpp CellState.h
WorldMap.o: WorldMap.h WorldMap.cpp

# Compilation rule:
\%.o: \%.cpp
	$(CC) \$< $(CFLAGS) -c -o $@
	
# Custom commands:
clean:
	rm -f $(TARGET) $(OBJECTS) *~ # deleting executable, .o’s and backups

run: $(TARGET)
	./$(TARGET) # executing the program