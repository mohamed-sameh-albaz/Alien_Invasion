[33mcommit ebccbc54eda8e7b04a3b3414aad4d06fe3de7b07[m[33m ([m[1;36mHEAD -> [m[1;32mmaster[m[33m, [m[1;31morigin/master[m[33m)[m
Author: mohamed-sameh-albaz <136837275+mohamed-sameh-albaz@users.noreply.github.com>
Date:   Tue Apr 2 14:35:06 2024 +0200

    Adding Army Lists

[1mdiff --git a/AlienArmy/AlienDroneList.h b/AlienArmy/AlienDroneList.h[m
[1mnew file mode 100644[m
[1mindex 0000000..e69de29[m
[1mdiff --git a/AlienArmy/AlineSoldierList.h b/AlienArmy/AlineSoldierList.h[m
[1mnew file mode 100644[m
[1mindex 0000000..e69de29[m
[1mdiff --git a/AlienArmy/MonsterList.h b/AlienArmy/MonsterList.h[m
[1mnew file mode 100644[m
[1mindex 0000000..e69de29[m
[1mdiff --git a/AlienInvasion.vcxproj b/AlienInvasion.vcxproj[m
[1mindex f06f98c..4cf0f02 100644[m
[1m--- a/AlienInvasion.vcxproj[m
[1m+++ b/AlienInvasion.vcxproj[m
[36m@@ -134,6 +134,8 @@[m
     <ClInclude Include="AlienArmy\AlienSoldier.h" />[m
     <ClInclude Include="AlienArmy\monster.h" />[m
     <ClInclude Include="AlienDrone.h" />[m
[32m+[m[32m    <ClInclude Include="AlienDroneList.h" />[m
[32m+[m[32m    <ClInclude Include="AlineSoldierList.h" />[m
     <ClInclude Include="DS\ArrayStack.h" />[m
     <ClInclude Include="DS\LinkedQueue.h" />[m
     <ClInclude Include="DS\Node.h" />[m
[36m@@ -145,7 +147,11 @@[m
     <ClInclude Include="EarthArmy\EarthGun.h" />[m
     <ClInclude Include="EarthArmy\EarthSoldier.h" />[m
     <ClInclude Include="EarthArmy\EarthTank.h" />[m
[32m+[m[32m    <ClInclude Include="EarthGunList.h" />[m
[32m+[m[32m    <ClInclude Include="EarthSoldierList.h" />[m
[32m+[m[32m    <ClInclude Include="EarthTankList.h" />[m
     <ClInclude Include="game.h" />[m
[32m+[m[32m    <ClInclude Include="MonsterList.h" />[m
     <ClInclude Include="randGen.h" />[m
     <ClInclude Include="unit.h" />[m
   </ItemGroup>[m
[1mdiff --git a/AlienInvasion.vcxproj.filters b/AlienInvasion.vcxproj.filters[m
[1mindex 533b740..d7f2ecf 100644[m
[1m--- a/AlienInvasion.vcxproj.filters[m
[1m+++ b/AlienInvasion.vcxproj.filters[m
[36m@@ -79,5 +79,23 @@[m
     <ClInclude Include="AlienDrone.h">[m
       <Filter>AlienArmy</Filter>[m
     </ClInclude>[m
[32m+[m[32m    <ClInclude Include="EarthGunList.h">[m
[32m+[m[32m      <Filter>EarthArmy</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="EarthSoldierList.h">[m
[32m+[m[32m      <Filter>EarthArmy</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="EarthTankList.h">[m
[32m+[m[32m      <Filter>EarthArmy</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="AlineSoldierList.h">[m
[32m+[m[32m      <Filter>AlienArmy</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="MonsterList.h">[m
[32m+[m[32m      <Filter>AlienArmy</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="AlienDroneList.h">[m
[32m+[m[32m      <Filter>AlienArmy</Filter>[m
[32m+[m[32m    </ClInclude>[m
   </ItemGroup>[m
 </Project>[m
\ No newline at end of file[m
[1mdiff --git a/DS/ArrayStack.h b/DS/ArrayStack.h[m
[1mindex 68e042e..bea901d 100644[m
[1m--- a/DS/ArrayStack.h[m
[1m+++ b/DS/ArrayStack.h[m
[36m@@ -14,15 +14,16 @@[m
 template<typename T>[m
 class ArrayStack : public StackADT<T>[m
 {[m
[31m-	enum { MAX_SIZE = 100 };[m
 private:[m
[31m-	T items[MAX_SIZE];		// Array of stack items[m
[32m+[m	[32mT *items;		// Array of stack items[m
 	int top;                   // Index to top of stack[m
[32m+[m	[32mconst int STACK_SIZE;[m
 	[m
 public:[m
 [m
[31m-	ArrayStack()[m
[32m+[m	[32mArrayStack(int MaxSize) : STACK_SIZE(MaxSize)[m
 	{[m
[32m+[m		[32mitems = new T[STACK_SIZE];[m
 		top = -1;[m
 	}  // end default constructor[m
 [m
[36m@@ -33,10 +34,11 @@[m [mpublic:[m
 [m
 	bool push(const T& newEntry)[m
 	{[m
[31m-		if( top == MAX_SIZE-1 ) return false;	//Stack is FULL[m
[32m+[m		[32mif( top == STACK_SIZE-1 ) return false;	//Stack is FULL[m
 [m
 		top++;[m
 		items[top] = newEntry;   [m
[32m+[m		[32m//items[++top];[m
 		return true;[m
 	}  // end push[m
 [m
[36m@@ -46,6 +48,7 @@[m [mpublic:[m
 		[m
 		TopEntry = items[top];		 [m
 		top--;[m
[32m+[m		[32m//TopEntry = items[top--];[m
 		return true;[m
 	}  // end pop[m
 	[m
[1mdiff --git a/DS/LinkedQueue.h b/DS/LinkedQueue.h[m
[1mindex 9668a13..4ab4533 100644[m
[1m--- a/DS/LinkedQueue.h[m
[1m+++ b/DS/LinkedQueue.h[m
[36m@@ -41,9 +41,10 @@[m [mSingle Node Case:[m
 #ifndef LINKED_QUEUE_[m
 #define LINKED_QUEUE_[m
 [m
[31m-[m
[32m+[m[32m#include<iostream>[m
 #include "Node.h"[m
 #include "QueueADT.h"[m
[32m+[m[32musing namespace std;[m
 [m
 template <typename T>[m
 class LinkedQueue:public QueueADT<T>[m
[1mdiff --git a/DS/priQueue.h b/DS/priQueue.h[m
[1mindex 1df1734..8d2a217 100644[m
[1m--- a/DS/priQueue.h[m
[1m+++ b/DS/priQueue.h[m
[36m@@ -14,7 +14,7 @@[m [mpublic:[m
     ~priQueue() {[m
         T tmp;[m
         int p;[m
[31m-        while (dequeue(tmp,p));[m
[32m+[m[32m        while (dequeue(tmp,p ));[m
     }[m
 [m
     //insert the new node in its correct position according to its priority[m
[36m@@ -51,7 +51,7 @@[m [mpublic:[m
         if (isEmpty())[m
             return false;[m
 [m
[31m-        topEntry = head->getItem();[m
[32m+[m[32m        topEntry = head->getItem(pri);[m
         pri = head->getPri();[m
         return true;[m
     }[m
[1mdiff --git a/EarthArmy/EarthGunList.h b/EarthArmy/EarthGunList.h[m
[1mnew file mode 100644[m
[1mindex 0000000..e69de29[m
[1mdiff --git a/EarthArmy/EarthSoldierList.h b/EarthArmy/EarthSoldierList.h[m
[1mnew file mode 100644[m
[1mindex 0000000..e69de29[m
[1mdiff --git a/EarthArmy/EarthTankList.h b/EarthArmy/EarthTankList.h[m
[1mnew file mode 100644[m
[1mindex 0000000..e69de29[m
[1mdiff --git a/Source.cpp b/Source.cpp[m
[1mindex b93de18..863b408 100644[m
[1m--- a/Source.cpp[m
[1m+++ b/Source.cpp[m
[36m@@ -1,7 +1,11 @@[m
 #include <iostream>[m
[32m+[m[32m#include"DS/LinkedQueue.h"[m
[32m+[m[32m#include"DS/priQueue.h"[m
[32m+[m[32m#include"DS/ArrayStack.h"[m
 using namespace std;[m
 [m
 [m
 int main() {[m
[32m+[m[41m	[m
 	return 0;[m
[31m-}[m
\ No newline at end of file[m
[32m+[m[32m}[m
