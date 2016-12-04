# Monopoly
Project for PIC 10C (Monopoly Game)

# Attribution
Copyright: Public domain.  
Filename: player.h, player.cpp, player.ui, gameslot.h, gameslot.cpp, gameslot.ui, chance.h, chance.cpp, monopoly.h, monopoly.cpp,  
          monopoly.ui, main.cpp, monopoly.pro  
Purpose: This project aims to simulate the game Monopoly, when UI finished users can play the game  
player.h, player.cpp and player.ui are for the class Player and functions associated with behaviors of players in games  
gameslot.h, gameslot.cpp and gameslot.ui are for the class and functions in charge of the game board  
chance.h, chance.cpp, chance.ui contain class and functions for the Chance and Community Chest cards  
main.cpp is the main program and contains unit tests  
Assembler: SidShi  
Contact: Tianyi Shi shitianyisid@gmail.com  
Last update: 12/4/2016  

# Unit tests
1. Player lands on the correct slot when dice rolled & rolling counter works well  
	- seed 1 gives 6 and 6, 5 and 5, 6 and 5  
	- seed 2 gives 4 and 3  

2. When rolling counter increments to 3, whether the player goes to jail  

3. When player goes around, whether landing on the right position  

4. Roll different cannot get out of jail  

5. Roll same can get out of jail  

6. Use jail free card can get out of jail  

7. The third round can get out of jail no matter what rolled  

8. One railroad is purchased  

9. Another railroad is purchased  

10. One Utility is purchased  

11. Another Utility is purchased  

12. One household is purchased  

13. Another household is purchased  

14. Go past GO and see if receiving 200  

15. if on GO TO JAIL whether to jail  

16. visiting jail option  

17. If landing on slots can be purchased  

18. If landing on own households  

19. If landing on other people's households/railroads/utility  

20. If landing on Community Chest  
	seed: 2 gives 11, 3 gives 14, 4 gives 0, 5 gives 3, 6 gives 7  

21. If landing on Chance  
	seed: 11 gives 2, then gives 1  

22. Cards that move player  

23. Cards that change money generally  

24. Cards that change money according to houses  

25. Cards that move people to utilities  
