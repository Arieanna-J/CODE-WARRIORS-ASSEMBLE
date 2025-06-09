// COPYRIGHT AND INTELLECTUAL PROPERTY NOTICE
//
// SONIC THE HEDGEHOG AND ITS ASSOCIATED CHARACTERS AND FRANCHISES BELONGS TO DEVELOPERS YUJI NAKA, 
// NAOTO OHSHIMA AND HIROKAZU YASUHARA OF SEGA COOPERATION ©
//
// This fangame is a non-commercial fan project created out of appreciation and love for the original work.
// Sonic Under Siege is not affiliated with, endorsed by, or sponsored by SEGA, Sonic Team, or any of their affiliates.
// All original characters, names, locations, and other elements related to Sonic the Hedgehog are the intellectual property of SEGA and Sonic Team.
// This project is distributed for free and is intended for entertainment and educational purposes only. No copyright infringement is intended.


// Importing Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h> // Sleep() function.
#include <conio.h> 
// Alert: This library requires C++ 11. When compiling, make sure it's up to date please ^^
// If you're using Dev C++ --- Go to Tools > Compiler Options > Settings > Code Generation > Select ISO C++ 11
// Then recompile the code once again and it should run with no hiccups! Hope that helps 
#include <thread>
#include <chrono> // For Timer Function
#include <atomic> // atomic uses to check the bool value.
#include <limits> // cin.ignore() to stop text from printing 
#include <algorithm> // For transform function
using namespace std;
// =======================================================================================================================================================================


// Function Prototypes: ----- Jayne's Part
void loadingScreen(int c);
bool firstSegment();
bool secondSegment();
bool thirdSegment();
string doorSegment();
bool quizSection();
void BadEnding();
void goodEnding();

// Setting Color Function ----- Siti's Part 
void setColor(const string& color) {
    if (color == "YELLOW") {
        cout << "\033[33m";  // Yellow color code
    } else if (color == "LIGHT_BLUE") {
        cout << "\033[94m";  // Light blue color code
    } else if (color == "RED") {
        cout << "\033[31m";  // Red color code
    } else if (color == "WHITE") {
        cout << "\033[0m";   // White (reset)
    }
}

// Start of program! ----- Jayne, Siti, Halini's Part
int main(){
    // Console Color and Background
    system("Color 9");

    // Declaration of Variables
    string menuInput;
    loadingScreen(5); // Function Loading Screen Call
	do {
		system("Color 9");
	    system("cls");
	    Sleep(40);
	    cout << "                           .--------------* Sonic Under Siege! *--------------." << endl;
	    cout << "                                  ---- A Game created by Hidden Sparks ----" << endl;
	    cout << "       (Sonic has been kidnapped by Eggman! You play as Tails and you gotta rescue Sonic from Eggman)" << endl;
	    cout << "                                           [Start] -------- [Exit]" << endl;
	    cout << "Press S to Start, or E to Exit: ";
	    cin >> menuInput;
	
	    // Transform input to uppercase for case-insensitive comparison
	    transform(menuInput.begin(), menuInput.end(), menuInput.begin(), ::toupper);
	
	    // Loop until the user enters exactly "S" or "E"
	    while (menuInput != "S" && menuInput != "E") {
	        if (menuInput.length() != 1) {
	            cout << "\nThat Doesn't Even Make Sense! Wanna Try Again buddy?" << endl;
	        } else {
	            cout << "\nWhoopsies! That's Just Not valid. Wanna Try that Again?" << endl;
	        }
	
	        // Clear the error state and ignore remaining input in the buffer
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	        // Prompt the user again
	        cout << "Press S to Start, or E to Exit: ";
	        cin >> menuInput;
	
	        // Transform input to uppercase again
	        transform(menuInput.begin(), menuInput.end(), menuInput.begin(), ::toupper);
	    }
	
	    // Handle the 'S' input
	    // Game Start!
	    if (menuInput == "S") { 
			bool secondSegmentContinuation = firstSegment(); // if True, it's Game Over
			if (!secondSegmentContinuation){ 
				system("cls");
				bool thirdSegmentContinuation = secondSegment(); // if True it's Game Over
				if (!thirdSegmentContinuation){ 
					system("cls");
					bool lastSegmentContinuation = thirdSegment();
					if (!lastSegmentContinuation){
						system("cls");
						string doorSegmentRoute = doorSegment();
						if (doorSegmentRoute != "GAMEOVER"){
							system("cls");
							bool quizSegmentPass = quizSection();
							if (!quizSegmentPass){
								system("cls");
								goodEnding();
								if (doorSegmentRoute == "BAD"){
									BadEnding();
								} else {
									setColor("LIGHT_BLUE");	
									cout << "Good Ending: Partners Till The End\n\n Thank You For Playing Sonic Under Siege!";
									cout.flush();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
									cout << endl << "\n[Press Enter to Return to Main Menu]";
	   								cin.get();  // Wait for the user to press Enter	
								}
							}
						}
					}
				}
			}
		}
	} while (menuInput != "E"); 
	cout << "Too Bad! Guess we'll see you next time, pal.";
	Sleep(200);
	exit(0);

    return 0;
}

// Function Definitions

// Loading Screen Function ----- Jayne's Part
void loadingScreen(int c){
	int counter = c;
	boolean gameOver = false;
    cout.flush();
    int j = 0;
    cout << "Loading";
	while (j < counter){
        for (int i = 0; i < 3; i++) {
            cout << ".";
            cout.flush();
            Sleep(250);
        }
        cout << "\b\b\b   \b\b\b";
        j++;
    }
}

// First Section of the Game! ----- Jayne's Part
bool firstSegment(){
	// Declaration of Variables
	int decisionMaking;
	// Loading Screen
	system("cls");
	loadingScreen(3);
	system("cls");
	
	// Start of Scenario
	setColor("WHITE");
	cout << "Tails appears before Eggman's lair. He knows his best friend is in there, \neveryone was in a riot when they realised Sonic is in the hands of Eggman. \nIts up to Tails to get him back now!\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "Tails: I can do this... Just wait for me, Sonic! I'll get you out of there soon! \n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("WHITE");
	cout << "Tails begins to climb up into a window and tumbles inside a room. He's in a storage room! He needs to get out of here\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "Tails: There seems to be a security panel here... \n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("WHITE");
	cout << "What will Tails do now?" << endl;
	cout << "Bust It Open           [1]" << endl;
	cout << "Hack It                [2]" << endl;
	cout << "Wait for Guard to Open [3]" << endl;
	cout << "Enter Code Here: ";
	cin >> decisionMaking;
	while (decisionMaking != 1 && decisionMaking != 2 && decisionMaking != 3){
		setColor("YELLOW");
		cout << "\nTails: Hold on, that's not an option I was considering. What was it I wanted to do again? \n\n";
		setColor("WHITE");
		cout << "What will Tails do now?" << endl;
		cout << "Bust It Open           [1]" << endl;
		cout << "Hack It                [2]" << endl;
		cout << "Wait for Guard to Open [3]" << endl;
		cout << "Enter Code Here: ";
		cin >> decisionMaking;
	}
	bool gameOver = false;
	
	switch(decisionMaking){
		case 1:
			setColor ("YELLOW");
			cout << "\nTails: I'm not a coward, I''m gonna be like Amy! Bust it open!" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "\nTails grabs a hammer from his toolbox and takes a huge swing at the door.  \nThe door makes a huge crash on the floor, gathering the attention of the robots nearby!\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor ("YELLOW");
			cout << "Tails: ...Uh oh.\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails got caught!\n\nGAME OVER!" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			gameOver = true;
			cout.flush();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
    		cout << "Press Enter to continue...";
   			cin.get();  // Wait for the user to press Enter			
			break;
		case 2: // Correct Choice
			system("cls");
	        setColor("YELLOW");
			cout << "Tails: Oh, this is nothing, Eggman! You're facing a hardcore mechanic here,\nlet me take a crack at hacking this!" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "\nTails takes out his tools he keeps in his box opens up the security panel. \nHe then carefully tampers with the wires and codes..." << endl;
			cout << "\nCLANG! \n\nThe door is opened!\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("YELLOW");
			cout << "\nTails: Take that Eggman!" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "\nTails begins to enter deeper into Eggman's Lair...";
			cout.flush();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
			cout << endl << "\n[Press Enter]";
   			cin.get();  // Wait for the user to press Enter	
			break;
		
		case 3:
			setColor("YELLOW");
			cout << "\nTails: I wanna play it safe... I'll wait for a guard to open it.\n" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout<< "Tails waited for god knows how long, hoping a guard comes by and open the door. Suddenly..." << endl;
			cout << "A group of robots that were about to get in the lair spotted Tails! He seized him immediately!\n" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			setColor("YELLOW");
			cout << "Tails: AAAAH!! I SHOULDN'T HAVE WAITED!\n" <<endl;
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "GAME OVER!\n";
			gameOver = true;
			cout.flush();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
    		cout << "Press Enter to continue...";
   			cin.get();  // Wait for the user to press Enter	
			break;
	}
	return gameOver;
} // End of First Segment

// Second Section of the Game! ----- Siti's Part
bool secondSegment(){
	int optionMaking;
	setColor("WHITE");
	cout << "Tails walks through a long corridor until he needs to make a turn to the left. \nWhen he takes a peek, he finds himself with a group of robot guards blocking the way of the remaining corridor\n\n";
	cout << "They are so adamant that Sonic will never leave this lair!\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "Tails: Oh no... Those are a lot of robot guards... I guess I can try to attack them...But is there any other way?\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("WHITE");
	cout << "What will Tails do now?" << endl;
	cout << "Hide in a Box [1]" << endl;
	cout << "Fly Over Them [2]" << endl;
	cout << "Distraction   [3]" << endl;
	cout << "Enter Code Here: ";
	cin >> optionMaking;
	bool gameOver_2 = false;
	
	while (optionMaking != 1 && optionMaking != 2 && optionMaking != 3){
		setColor("YELLOW");
		cout << "\nTails: Hold on, that's not an option I was considering. What was it I wanted to do again? \n\n";
		setColor("WHITE");
		cout << "Hide in a Box [1]" << endl;
		cout << "Fly Over Them [2]" << endl;
		cout << "Distraction   [3]" << endl;
		cout << "Enter Code Here: ";
		cin >> optionMaking;
	}
	switch(optionMaking){
		case 1:
			setColor("YELLOW");
			cout << "\nTails: This is too risky for me, let me hide in this big, conveniently placed box!\nI'll wait for the guards to pass this corrdor." << endl;
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "\nTails begins to crawl in the box. He silently waits for the footsteps of the guards to pass him...\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("YELLOW");
			cout << "Tails: ...This seems like a good time to leave, the footsteps are gone.\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "As Tails opens the lid of the box, he meets face to face with one of the robot guards.\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("YELLOW");
			cout << "Tails: ...Guess not? ;D\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails makes a mental note to never trust his guts, or ears for that matter ever again.\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Tails was caught!\n\nGAME OVER!\n";
			gameOver_2 = true;
			cout.flush();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
    		cout << "Press Enter to continue...";
   			cin.get();  // Wait for the user to press Enter	
			break;
		case 2:
			setColor("YELLOW");
			cout << "\nTails: Well, the ceiling looks high enough for me to fly over them. They won't even know what hit 'em!\nHere goes!\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails jumps and begins to fly over the robots... Things seem to be going well!\nOh? Why do they look so confused?\n\n...They're looking up now...\n\n";
			cout << "Tails just now realised his tails makes swishing sounds when he flies...\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("YELLOW");
			cout << "Tails:...Dammit!\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails was caught!\n\nGAME OVER!\n";
			this_thread::sleep_for(chrono::seconds(1));
			gameOver_2 = true;
			cout.flush();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
    		cout << "Press Enter to continue...";
   			cin.get();  // Wait for the user to press Enter	
			break;
		case 3: // Correct Choice
			system("cls");
			setColor("WHITE");
			cout << "Tails takes out a screw from his toolbox and throws it adjacent to him\nIt caught the attention of the robots! They went the opposite direction where Tails was at.\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("YELLOW");
			cout << "Tails: Bingo!\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails carefully sneaks down the corridor, happy that each progress he makes he is one step closer in meeting his best friend.\n";
			cout.flush();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
			cout << endl << "\n[Press Enter]";
   			cin.get();  // Wait for the user to press Enter	
			break;
			
	}
	return gameOver_2;
} // End of SecondSegment

bool thirdSegment(){ // Third Section of the Game ! --- Siti, Jayne's Part
	int choiceMaking;
	setColor("WHITE");
	cout << "Tails continues down the corridor until he reaches a diverging pathway. There's three paths he can take and knowing Eggman,\nhe definitely booby trapped two of them.";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "\n\nTails: Darn it... This isn't in the map, I guess I have to go with my gut.";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("WHITE");
	cout << "\n\nWhat would Tails do now?\n";
	cout << "Go Center [1]" << endl;
	cout << "Go Right  [2]" << endl;
	cout << "Go Left   [3]" << endl;
	cout << "Enter Code Here: ";
	cin >> choiceMaking;
	bool gameOver_3 = false;
	while (choiceMaking != 1 && choiceMaking != 2 && choiceMaking != 3){
		setColor("YELLOW");
		cout << "\nTails: Hold on, that's not an option I was considering. What was it I wanted to do again? \n\n";
		setColor("WHITE");
		cout << "Go Center [1]" << endl;
		cout << "Go Right  [2]" << endl;
		cout << "Go Left   [3]" << endl;
		cout << "Enter Code Here: ";
		cin >> choiceMaking;
	}
	switch(choiceMaking){
		case 1:
			setColor("YELLOW");
			cout << "\n\nTails: Maybe if I just go straight, it'll lead to sonic. It seems like there's nothing dangerous.\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails begin to walk forward, things seems to be going well until...\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "CLANG!\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "A trapped door opened under him!\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("YELLOW");
			cout << "Tails: AAAAAAAAAAH!!";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails was caught!\n\nGAME OVER!\n";
			this_thread::sleep_for(chrono::seconds(1));
			gameOver_3 = true;
			cout.flush();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
    		cout << "Press Enter to continue...";
   			cin.get();  // Wait for the user to press Enter	
			break;
		case 2:
			setColor("YELLOW");
			cout << "Tails: I turned left before, the next turn MUST be a right! Let's do this!\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails takes the right path, things seem to be going well, until...";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "\n\nWHOOSH!\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "A net dropped down and captured Tails! Loud bells began ringing down, alerting nearby robots.\n\n";
			setColor("YELLOW");
			cout << "Tails: Argh, no! My gut was wrong!!\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails was caught!\n\nGAME OVER!\n";
			this_thread::sleep_for(chrono::seconds(1));
			gameOver_3 = true;
			cout.flush();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
    		cout << "Press Enter to continue...";
   			cin.get();  // Wait for the user to press Enter	
			break;
		case 3:
			system("cls");
			setColor("YELLOW");
			cout << "Tails: Hmm... Left doesn't seem so bad. I might as well.\n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Tails takes the left path, things seem to be going well until";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".\n";
			cout << "It did! This path was safe, Tails continues safely down this path!";
			cout.flush();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
			cout << endl << "\n[Press Enter]";
   			cin.get();  // Wait for the user to press Enter	
			break;
		}
	return gameOver_3;
} // End of thirdSection

string doorSegment(){ // Last and Final section to determine Ending --- Siti, Jayne's part
	int finalDecision;
	setColor("WHITE");
	cout << "Tails has reached the end of the corridor. He is faced with three ominous doors in front of him.\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\nThe first door shows a picture of a skull, with two bones crossed behind it.\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\nThe second door shows a picture of a bloody eye, dark aura sending shivers down his spine.\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\nThe last door shows a picture of a two tier cake, with a knife slicing it.\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "Tails: All these doors are so confusing...I'm sure Sonic is behind one of these doors, but...\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	boolean doorLoop = false;
	boolean bloodyEyeDoor = false;
	string endingRoute = "null";
	while (!doorLoop){
		setColor("WHITE");
		cout << "What door will Tails choose?\n";
		cout << "Door with Skull's Crossed [1]" << endl;
		cout << "Door with Bloody Eye      [2]" << endl;
		cout << "Door with Cake and Knife  [3]" << endl;
		cout << "Enter Code Here: ";
		cin >> finalDecision;
		
		while (finalDecision != 1 && finalDecision != 2 && finalDecision != 3){
			setColor("YELLOW");
			cout << "\nTails: Hold on, that's not an option I was considering. What was it I wanted to do again? \n\n";
			setColor("WHITE");
			cout << "What door will Tails choose?\n";
			cout << "Door with Skull's Crossed [1]" << endl;
			cout << "Door with Bloody Eye      [2]" << endl;
			cout << "Door with Cake and Knife  [3]" << endl;
			cout << "Enter Code Here: ";
			cin >> finalDecision;
		}
		
		switch(finalDecision){
			case 1:
				setColor("WHITE");
				cout << "Tails takes a deep breath when approaching the door with the skull.\nHands shivering, he holds the knob and gently open the door...\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				cout << ".";
				this_thread::sleep_for(chrono::seconds(1));
				cout << ".";
				this_thread::sleep_for(chrono::seconds(1));
				cout << ".";
				this_thread::sleep_for(chrono::seconds(1));
				cout << "\n\nA sight of a chair, with a hedgehog tied to it under a swinging lamp greeted Tails.\n\n";
				setColor("YELLOW");
				cout << "Tails: Sonic! Are you okay?!\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				setColor("WHITE");
				cout << "The blue figure perks up.\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				setColor("LIGHT_BLUE");
				cout << "Sonic: ...Tails? TAILS!!\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				setColor("WHITE");
				cout << "Sonic is ecstatic seeing his best friend! Tails quickly unties him and gave Sonic a hearty hug.\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				setColor("YELLOW");
				cout << "Tails: I'm so glad you're okay!\n";
				this_thread::sleep_for(chrono::seconds(1));
				setColor("LIGHT_BLUE");
				cout << "Sonic: And I'm glad you're here, buddy! Thanks! This place is the dumps,\nlet's get out of here...\n";
				endingRoute = "GOOD";
				setColor("WHITE");
				doorLoop = true;
				cout.flush();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
				cout << endl << "\n[Press Enter]";
	   			cin.get();  // Wait for the user to press Enter	
				break;
			case 2: 
				if (!bloodyEyeDoor){
					// Declaration of Variables:
					int bloodEye_choice;
					
					setColor("WHITE");
					cout << "Tails quietly approaches the door with the bloody eye. It took all his strength bringing his hands to the doorknob,\nbut the thought of Sonic being behind this door keeps him going...\n";
					this_thread::sleep_for(chrono::seconds(1));
					setColor("YELLOW");
					cout << "\nTails: I'm coming Sonic...\n\n";
					this_thread::sleep_for(chrono::seconds(1));
					setColor("WHITE");
					cout << "As Tails opens the door, what he sees gave him a shock. A lone person at the corner of the room,\nshivering and sobbing. The person doesn't even acknowledge Tails.\n\n";
					this_thread::sleep_for(chrono::seconds(1));
					setColor("YELLOW");
					cout << "Tails: Oh, are you okay?! I'm trying to find Sonic, I mean no harm...\n\n";
					this_thread::sleep_for(chrono::seconds(1));
					setColor("WHITE");
					cout << "As Tails approaches the shaming figure...\n\n";
					this_thread::sleep_for(chrono::seconds(1));
					setColor("RED");
					cout << "???: ...He is coming, he is coming, he is coming, he is coming...\n";
					this_thread::sleep_for(chrono::seconds(1));
					setColor("YELLOW");
					cout << "Tails: Uh...Excuse me...?\n\n";
					this_thread::sleep_for(chrono::seconds(1));
					setColor("RED");
					cout << "???: Make it stop, make it stop...SOMEBODY MAKE HIM STOP THIS!\n\n";
					this_thread::sleep_for(chrono::seconds(1));
					setColor("WHITE");
					cout << "The individual gives a blood curdling scream, as they turned around and ran towards Tails,\nmouth foaming and bloodshot eyes.\n\n";
					cout << "This guy is a lost cause.\n\n";
					cout << "What will Tails do?\n";
					cout << "Dodge                       [1]" << endl;
					cout << "Run Away and Close the Door [2]" << endl;
					cout << "Attack in Self Defense      [3]" << endl;
					cout << "Enter Code Here: ";
					cin >> bloodEye_choice;
					while (bloodEye_choice != 1 && bloodEye_choice != 2 && bloodEye_choice != 3){
						setColor("YELLOW");
						cout << "\nTails: Hold on, that's not an option I was considering. What was it I wanted to do again? \n\n";
						setColor("WHITE");
						cout << "What will Tails do?\n";
						cout << "Dodge                       [1]" << endl; // Game Over!
						cout << "Run Away and Close the Door [2]" << endl; // Redemption option
						cout << "Attack in Self Defense      [3]" << endl; // Bad ending option
						cout << "Enter Code Here: ";
						cin >> bloodEye_choice;
					}
					
					switch(bloodEye_choice){
						case 1:
							setColor("WHITE");
							cout << "\nTails dodged, but the person is faster. They quickly grabbed Tails, and slams him against the door.\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							cout << "His head is throbbing...Oh no, he's losing conscious!\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							cout << "The last thing he remembers is the figure going back to the corner...sobbing once again.\n";
							cout << "\nGAME OVER!\n";
							this_thread::sleep_for(chrono::seconds(1));
							endingRoute = "GAMEOVER";
							doorLoop = true;
							cout.flush();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
    						cout << "Press Enter to continue...";
   							cin.get();  // Wait for the user to press Enter	
							break;
						case 2: // Redemption Arc
							setColor("YELLOW");
							cout << "Tails: NOPE, NOPE, NOPE! GET ME OUT OF HERE!!\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("WHITE");
							cout << "Tails makes a dash to the door, barley making it out before slamming the door on the person's face.\nHe takes a moment to recollect...\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("YELLOW");
							cout << "Tails: Oh...that was SUCH a close call! Why would Eggman capture such a scary person?!\nSonic is definitely not in that door, so...\n\n";
							bloodyEyeDoor = true;
							break;
						case 3:
							system("cls");
							setColor("YELLOW");
							cout << "Tails: No, NO! STAY BACK!!\n\n";
							setColor("WHITE");
							cout << "Going on pure adrenaline, Tails takes out his gun and shoots right through the chest of that person.\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							cout << "As they let out a loud screech, they fall flat to the ground, devoid of light.\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							cout << "...\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							cout << "They're";
							this_thread::sleep_for(chrono::seconds(1));
							cout << ".";
							this_thread::sleep_for(chrono::seconds(1));
							cout << ".";
							this_thread::sleep_for(chrono::seconds(1));
							cout << ".";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("RED");
							cout << "dead.\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("WHITE");
							cout << "Tails takes a moment to realize this.\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("YELLOW");
							cout << "Tails: ...This...This is not my fault. They...They attacked me, they attacked me first.\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("WHITE");
							cout << "Tails looks up, he sees a door. That's odd. Was it there before? He's losing his sense of reality...\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("YELLOW");
							cout << "Tails: ...Sonic, he's waiting for me. I have to move on.\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("WHITE");
							cout << "He passed by the person on the ground and entered the door.\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							cout << "Behind the door, he sees Sonic, sitting on the floor, as if he's waiting for Tails.";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("LIGHT_BLUE");
							cout << "\n\nSonic: Tails! It's you! Took you a while.\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("YELLOW");
							cout << "Tails: Sonic!! I finally found you!\n\n";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("WHITE");
							cout << "Tails runs to Sonic and gives him a big hug...\nHe thinks to himself, despite what happened, it's worth to see Sonic.\nHe'll keep this to himself.";
							this_thread::sleep_for(chrono::seconds(1));
							setColor("LIGHT_BLUE");
							cout << "\n\nSonic: God, I've been in this room for a good while...Let's finally get out of here!\n\n";
							endingRoute = "BAD";
							setColor("WHITE");
							doorLoop = true;
							cout.flush();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
    						cout << "[Press Enter]";
   							cin.get();  // Wait for the user to press Enter	
							break;
					}
				} else {
					setColor("YELLOW");
					cout << "Tails: Nope...I'm not going in there again.\n\n";
					break;
				}
				break;
			case 3:
				setColor("YELLOW");
				cout << "Tails: This door is just a cake and a knife...Weird, what is behind it?\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				setColor("WHITE");
				cout << "As curiousity got the better of Tails, he opened the door. And, to his surprise,\nit's just a chocolate cake and a knife.\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				cout << "Well... He was getting hungry...\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				setColor("YELLOW");
				cout << "Tails: A slice won't hurt anyone! Plus it's Eggman, who cares if he cries over a cake?\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				setColor("WHITE");
				cout << "Tails takes a slice and eats the cake. It's so tasty! The robots really know how to make a good cake!\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				cout << "It's even too good to be true...\n";
				this_thread::sleep_for(chrono::seconds(1));
				cout << "Woah, who'd knew a chocolate cake can be so good, you can see stars...\n\n";
				this_thread::sleep_for(chrono::seconds(1));
				cout << "Wait, his vision is getting blurry...\n";
				cout << "Oh no, the cake is a trap! It's making Tails faint!\nBefore he knew it, Tails falls to the ground, being so tired by that deceiving cake.\n\n";
				cout << "\nGAME OVER!\n";
				this_thread::sleep_for(chrono::seconds(1));
				endingRoute = "GAMEOVER";
				doorLoop = true;
				cout.flush();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
    			cout << "Press Enter to continue...";
   				cin.get();  // Wait for the user to press Enter	
				break;
		}
	}
	return endingRoute;
}

// Quiz Section! ---- Siti, Jayne's part
bool quizSection(){
	
	// Declaration of Variables
	string quizAnswer[8] = {"R", "O", "B", "O", "T", "N", "I", "K"};
	string quizInput[8];
	bool gameOver_3 = false;
	int totalTimeLimit = 60; // Total time limit for the quiz in seconds

	
	setColor("WHITE");
	cout << "Sonic and Tails were finally reunited until suddenly..." << endl << "\nSLAM!!\n\nWhat's this? The door is closed shut! There's a device that unlocks it,\n";
	cout << "but Sonic and Tails need to answer some questions to bypass the lock on this door." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	setColor("RED");
	cout << "\nEggman: Aha! You thought you were very clever Tails, sneaking pass all my securities.\nLuckily, my robots spotted a broken panel that I KNOW is your doing. I'm sending all of my guards to that room now!\n";
	this_thread::sleep_for(chrono::seconds(3));
	setColor("WHITE");
	cout << "\nSonic and Tails don't have much time! Hurry up, before Eggman's security will seize the both of them!\n" << endl;
	this_thread::sleep_for(chrono::seconds(2));
	
	atomic<bool> quizCompleted(false); // Flag to track if the quiz was completed in time

    // Timer thread
    thread timer([&]() {
        for (int i = 0; i < totalTimeLimit; ++i) {
            if (quizCompleted) return; // Stop timer if quiz is completed
            this_thread::sleep_for(chrono::seconds(1));
        }
        if (!quizCompleted) {
        	system("cls");
        	setColor("LIGHT_BLUE");
			cout << "\n\nSonic: Dammit, we were so close! \n\n";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "Sonic and Tails couldn't manage to type the correct password in time!\n";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Eggman's henchman began swarming into the room, surrounding the duo." << endl;
			this_thread::sleep_for(chrono::seconds(1));
			setColor("RED");
			cout << "\nEggman: Oh, poor you. You spent all this time going past my securities only to fall right into my hands!\nFace it, you both are never matched for me! With you two out of the picture,\nI can finally rule the entire world!";
			this_thread::sleep_for(chrono::seconds(1));
			setColor("WHITE");
			cout << "\n\nSonic and Tails felt a sense of dread engulfing them as they got tied up by the robots.\nThe future seems so dark and bleak as the two duos fall into Eggman's trap.\n" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Bad Ending: So Close, Yet So Far.";
            exit(0);
        }
    });
    
    while (!quizCompleted){
    	if (quizCompleted)
    		break;
		// Question 1
		cout << "[Q1] What Kind of Eggs does Eggman like?\n" << endl;
		cout << "Runny Eggs     [I]" << endl;
		cout << "Sunny Side Up  [R]" << endl;
		cout << "Scrambled Eggs [H]" << endl;
		cout << "Enter Passcode Here: " << endl;
		cin >> quizInput[0];
		
		cout << endl << "[Q2] In Sonic Adventures 2, What Did Eggman Blow Up?\n" << endl;
		cout << "A Village [P]" << endl;
		cout << "The Moon  [O]" << endl;
		cout << "A City    [U]" << endl;
		cout << "Enter Passcode Here: " << endl;
		cin >> quizInput[1];
		
		cout << endl << "[Q3] What is Eggman's Blood Type?\n" << endl;
		cout << "Blood Type A  [A]" << endl;
		cout << "Blood Type O  [O]" << endl;
		cout << "Blood Type B  [B]" << endl;
		cout << "Blood Type AB [X]" << endl;
		cout << "Enter Passcode Here: " << endl;
		cin >> quizInput[2];
		
		cout << endl << "[Q4] Which One of These Activities Does Eggman Like to Do?\n" << endl;
		cout << "Kidnapping Sonic [K]" << endl;
		cout << "Making Machines  [Q]" << endl;
		cout << "Taking Selfies   [O]" << endl;
		cout << "Enter Passcode Here: " << endl;
		cin >> quizInput[3];
		
		cout << endl << "[Q5] What is Eggman's Favourite Hot Dog?\n" << endl;
		cout << "Egg Dog    [T]" << endl;
		cout << "Chilli Dog [C]" << endl;
		cout << "Cat Dog    [W]" << endl;
		cout << "Enter Passcode Here: " << endl;
		cin >> quizInput[4];
		
		cout << endl << "[Q6] What Property Does Eggman Own?\n" << endl;
		cout << "Casinos     [N]" << endl;
		cout << "Appartments [Q]" << endl;
		cout << "Factories   [F]" << endl;
		cout << "Enter Passcode Here: " << endl;
		cin >> quizInput[5];
		
		cout << endl << "[Q7] What Kind of Doctorate Does Eggman Have?\n" << endl;
		cout << "Doctor of Veterinary Medicine [G]" << endl;
		cout << "Doctor of Philosophy          [P]" << endl;
		cout << "Doctor of Engineering         [I]" << endl;
		cout << "Enter Passcode Here: " << endl;
		cin >> quizInput[6];
	
		cout << endl << "[Q8] What is Eggman's IQ?\n" << endl;
		cout << "100 [C]" << endl;
		cout << "300 [K]" << endl;
		cout << "50  [W]" << endl;
		cout << "Enter Passcode Here: " << endl;
		cin >> quizInput[7];
		quizCompleted = true; // Mark the quiz as completed
	}
	timer.join(); // Ensure the timer thread finishes
	
	int point = 0;
	for (int i = 0; i < 8; i++){
		string result = quizInput[i];
    	transform(result.begin(), result.end(), result.begin(), ::toupper);
		if (result == quizAnswer[i]){
			point++;
		} 
	}
	cout << "Passcode Entered: ";
	for (int i = 0; i < 8; i++){
		string upperCase = quizInput[i];
    	transform(upperCase.begin(), upperCase.end(), upperCase.begin(), ::toupper);
		cout << upperCase << " ";
		cout.flush();
		Sleep(200);
			
	}
	switch(point){
		case 0:
			cout << endl << "\nIncorrect Passcode! You didn't answer";
			setColor("RED");
			cout << " eight";
			setColor("WHITE");
			cout << " questions correctly.";
			break;
		case 1:
			cout << endl << "\nIncorrect Passcode! You didn't answer";
			setColor("RED");
			cout << " seven";
			setColor("WHITE");
			cout << " questions correctly.";
			break;
		case 2:
			cout << endl << "\nIncorrect Passcode! You didn't answer";
			setColor("RED");
			cout << " six";
			setColor("WHITE");
			cout << " questions correctly.";
			break;
		case 3:
			cout << endl << "\nIncorrect Passcode! You didn't answer";
			setColor("RED");
			cout << " five";
			setColor("WHITE");
			cout << " questions correctly.";
			break;
		case 4:
			cout << endl << "\nIncorrect Passcode! You didn't answer";
			setColor("RED");
			cout << " four";
			setColor("WHITE");
			cout << " questions correctly.";
			break;
		case 5:
			cout << endl << "\nIncorrect Passcode! You didn't answer";
			setColor("RED");
			cout << " three";
			setColor("WHITE");
			cout << " questions correctly.";
			break;
		case 6:
			cout << endl << "\nIncorrect Passcode! You didn't answer";
			setColor("RED");
			cout << " two";
			setColor("WHITE");
			cout << " questions correctly.";
			break;
		case 7:
			cout << endl << "\nIncorrect Passcode! You didn't answer";
			setColor("RED");
			cout << " one";
			setColor("WHITE");
			cout << " questions correctly.";
			break;

	}
	if (point !=8){
		this_thread::sleep_for(chrono::seconds(1));
		setColor("YELLOW");
		cout << "\n\nTails: Dangit! I couldn't bust this passcode open.\n\n";
		this_thread::sleep_for(chrono::seconds(1));
		setColor("LIGHT_BLUE");
		cout << "Sonic: Crap, I think I hear more of Eggman's henchmen coming...";
		this_thread::sleep_for(chrono::seconds(1));
		setColor("WHITE");
		cout << "\n\nOver the speakers inside that locked room, Eggman's voice echoed in all corners.\n\n";
		this_thread::sleep_for(chrono::seconds(1));
		setColor("RED");
		cout << "Eggman: Aha! Not so clever now are you, Tails? Finally, I got the both of you now!\n\n";
		this_thread::sleep_for(chrono::seconds(1));
		setColor("WHITE");
		cout << "There was nothing Sonic and Tails could do, they were surrounded by Eggman's robot guards. \nThe fate of the duos are in Eggman’s hands as Eggman laughs maniacally in the background \n\n";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Bad Ending: An Uncertain Demise";
		gameOver_3 = true;
		cout.flush();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any remaining input in the buffer
		cout << endl << "Press Enter to continue...";
		cin.get();  // Wait for the user to press Enter	
	}
	return gameOver_3;
}

void goodEnding(){
	setColor("WHITE");
	cout << "The passcode was correct, the door is opened!" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "Tails: Yes! First try, baby! \n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("LIGHT_BLUE");
	cout << "Sonic: Let's get the heck out of here!!!\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("WHITE");
	cout << "The duo dashes through the long corridor, hand in hand, making their way through Eggman's lair.\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("LIGHT_BLUE");
	cout << "Sonic: We're not gonna make it through the main exit, hold on tight Tails, I know a shortcut!\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "Tails: W-what are you planning to do?? Sonic?! SONIC!?\n\n" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	setColor("WHITE");
	cout << "They crash through the window, leaping away from the hell on earth which is Eggman’s lair. They landed onto a pile of bushes,\nhearing a faint scream from Eggman as he cursed them...\n\n...\n\nThey both erupted in laughter.\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("LIGHT_BLUE");
	cout << "Sonic: Dude, that was the most fun I had in days, haha! Did you see his dumb face when we ran away!? \n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "Tails: HAHAHA right!? Hahh... I'm so glad you're safe man...\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("LIGHT_BLUE");
	cout << "Sonic: Heh, thanks Tails, I'm so happy to have a friend like you.\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("WHITE");
	cout << "They hug it out, happy that they're finally together to go on more adventures again." << endl;
	this_thread::sleep_for(chrono::seconds(1));
}
//Setting Bad Ending Route! --- Halini, Haziqah's Part
void BadEnding()
{
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".\n";
	this_thread::sleep_for(chrono::seconds(3));
	setColor("RED");
	cout << "Something is wrong.";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\nSomething...is SERIOUSLY wrong.\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "The blood is on your hands now. There's no way out of this.";
	this_thread::sleep_for(chrono::seconds(2));
	setColor("WHITE");
	cout << "\n\nThe place looks";
	setColor("RED");
	cout << " darker";
	setColor("WHITE");
	cout << " and it feels like time is";
	setColor("RED");
	cout << " stopping.\n\n";
	this_thread::sleep_for(chrono::seconds(3));
	setColor("RED");
	cout << "'What's going on?' ";
	setColor("WHITE");
	cout <<  "Tails wondered.\n";
	
	//The Bad Route's dialogue begin...
	setColor("WHITE");
	cout << "Tails's vision grows";
	setColor("RED");
	cout << " darker";
	setColor("WHITE");
	cout << " with every thought...\n\n";
	setColor("YELLOW");
	cout << "Tails: Did I do it";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "? Did I save...Sonic?";
	setColor("WHITE");
	cout << "\nTails panicked.\n\n";
	
	setColor("WHITE");
	cout << "As Tails's vision grows fuzzier to almost complete";
	setColor("RED");
	cout << " darkness";
	setColor("WHITE");
	cout << ", he sees a blue figure right ahead of him. Just out of reach";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "Tails: Sonic!\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("WHITE");
	cout << "\nHe cries but it falls on to deaf ears";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("RED");
	cout << "Sonic (?): I've been waiting for so long for someone to release me...\n";
	this_thread::sleep_for(chrono::seconds(1));
	setColor("YELLOW");
	cout << "Tails: Sonic";
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "?\n\n";
	setColor("RED");
	cout << "Sonic (?): Thank you, Tails. You've been such a great 'friend'.\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Sonic (?): ...Sure, let's go on more adventures, shall we?\n";
	this_thread::sleep_for(chrono::seconds(1));
	
	//Here comes Sonic the Devil
	setColor("WHITE");
	cout << "Tails could hear a faint laughter right before he blacks out. Sonic mutters something,\nthat sends chills down upon Tails's spine.\n\n";
	setColor("RED");
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\aDeleting C:/Windows/System32/\n";
	cout << "SONIC.exe: ";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "G ";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "O ";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "O ";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "D ";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "B ";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Y ";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "E\n\n";
	for (int i = 0; i < 20; i++)
	{
		cout << "nawskjlbejfP'awabvlw;2398329432dhQ;HP83B2\n\n";
		cout << "8823hDOAHDQ3DP9b8232Q9]32FQIQjq32qpfj93qp\n\n";
		cout << "283hen32d98329hfn34qpmfwpq893blcao32h2h9h\n\n";
		cout << "82941hd82983402840242jd1n238h38pfj39j3f93\n\n";
	}
	cout << "BAD ENDING: New God.";
	exit(0);	
}

