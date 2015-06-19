//FILE : Bronson 2.4 Project.cpp
//PROG : Carlos Marti
//PURP : This is the Bronson textbook Program 2.4 (pp 109 - 110)
//Note:  this program has the class defined in the same file as main
//In your programs the class will usually be defined in a separate header file

#include <iostream>
using namespace std;

#include "RoomTypeClass.h"

int main()
{
  RoomType roomOne;  //Declare a variable of type RoomType

  cout << "The values for this room are:\n";
  roomOne.showRoomValues();       //Use a class method on this object
  cout << "\nThe floor area of this room is: ";
  roomOne.calculateRoomArea();    //Use another class method on this object
  cout << "\nThe volume for This room is: ";
  roomOne.displayVolumeOfRoom();

  roomOne.setNewRoomValues();   //Call the mutator
  
  cout << "\n\nThe values for this room have been changed to:\n";
  roomOne.showRoomValues();
  cout << "\nThe floor area of this room is: ";
  roomOne.calculateRoomArea();
  cout << "\nThe volume for this room is: ";
  roomOne.displayVolumeOfRoom();

  cout << endl;
  system("pause");
  return 0;
}
