/*
Minimal_timer by rimaturus

Tested for Windows 10
*/

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <MMSystem.h>

using namespace std;
  
// hours, minutes, seconds of timer
int hours = 0;
int minutes = 0;
int seconds = 0;

int studio;
int nTomatoes = 0;
  
// function to display the timer
void displayClock()
{
    // system call to clear the screen
    system("cls");
  
    if(studio == 1)
		cout << setfill(' ') << setw(55) << "         STUDY          \n";
	else
		cout << setfill(' ') << setw(55) << "         RELAX         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
    cout << setfill('0') << setw(2) << minutes << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    
    cout << endl << setfill(' ') << setw(47) << "nTomatoes: " << nTomatoes << endl;
    
    
    //set color of screen
    if((hours == 0) && (minutes == 0) && (seconds < 59)){
    	if(seconds%2)
			system("color cf");
		else
			system("color 0f");
	}
}
  
void timer()
{
    while (true) {
          
        // display the timer
        displayClock();
  
        // sleep system call to sleep 
        // for 1 second
        Sleep(1000);
  
        // increment seconds
        seconds--;
  
        // if seconds reaches 60
        if (seconds < 0) {
          	
          	if (minutes == 0) {
          
          		if(hours == 0){
          			return;
				  }
                // increment hours
                hours--;
                minutes = 59;
            }
            // increment minutes
            minutes--;
            // if minutes reaches 60
            
            seconds = 59;
        }
    }
    
}
  
// Driver Code
int main(){
	
	int hh_study, mm_study, ss_study;
	int hh_relax, mm_relax, ss_relax;
	
	char t_studio[10];
	char t_relax[10];
	
	
	cout << "How do you want to set the timer:\n" << "0) Manually\n" << "1) Automatically according to the 'tomato method' (25 + 5)\n";
	
	int sel;
	cin >> sel;
	
	if(sel == 0){
		cout << "Enter study time in the format HH:MM:SS		";
		cin >> t_studio;
		
		hh_study = int(t_studio[0] - '0')*10 + int(t_studio[1] - '0');
		mm_study = int(t_studio[3] - '0')*10 + int(t_studio[4] - '0');
		ss_study = int(t_studio[6] - '0')*10 + int(t_studio[7] - '0');
		
		cout << "Enter relaxation time in the format HH:MM:SS		";
		cin >> t_relax;
		
		hh_relax = int(t_relax[0] - '0')*10 + int(t_relax[1] - '0');
		mm_relax = int(t_relax[3] - '0')*10 + int(t_relax[4] - '0');
		ss_relax = int(t_relax[6] - '0')*10 + int(t_relax[7] - '0');
			
	}
	
	if(sel == 1){
		//Tomatoes technique
		hh_study = 0;
		mm_study = 25;
		ss_study = 0;
		
		hh_relax = 0;
		mm_relax = 5;
		ss_relax = 0;
	}
	
	while(1){
	    studio = 1;
	    
	    hours = hh_study;
	    minutes = mm_study;
		seconds = ss_study;
	    timer();
	    
	    printf("\a");	//it makes a system sound
		// system (path/of_the/audio_file/to_play/end_studying_time);
                                            
		char stop;
		
		cout << "End of tomato n." << nTomatoes + 1 << endl << "Do you want to take a 5 minute break? [Y = Relax] [N = exit]" << endl;
		cin >> stop;
		
		if(stop == 'N' || stop == 'n')
			exit(0);

	    studio = 0;
	    
	    hours = hh_relax;
	    minutes = mm_relax;
		seconds = ss_relax;
		
	    timer();
	    
	    nTomatoes++;
	    
	    printf("\a");	//it makes a system sound
	    // system (path/of_the/audio_file/to_play/end_relax_time);

		cout << "Do you want to start another tomato? [Y = Letsego] [N = exit]" << endl;
		cin >> stop;
		
		if(stop == 'N')
			exit(0);
	    
	}
	
    return 0;
}