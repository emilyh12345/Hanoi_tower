#include<iostream>
#include<vector>
using namespace std;

void odd_move(vector<int> t[], int &to, int &from, int &candidate); //create odd and even move functions 
void even_move(vector<int> t[], int &to, int &from, int &candidate); 

int main(){
    vector<int>t[3]; //declare t as an array of vectors
    int rings, candidate=1, to, from=0, move=1; //initialize from tower to 0(the first tower) to start, candidate (smallest ring that hasnt just been moved) to start at 1 since that starts at the top and smallest ring that hasnt just been moved
    cout << "Enter number of rings: ";
    cin >> rings; //get user input for the number of rings
    for (int i=rings+1; i>0; i--){
        t[0].push_back(i); // loop to add numbers of rings to first tower
    }
    t[1].push_back(rings+1);// add number of rings plus 1 to bottom of next towers
    t[2].push_back(rings+1); 
    bool isOdd; //check if number of rings is even or odd
    if(rings%2==1){ // if have an odd number of rings
        isOdd=true;
        to=1; //initialize to tower as tower 1 because checking to the right
    } else { //if have even number of rings
        isOdd=false;
        to=2; //initialize to tower as tower 2 because checking to the left
    }
    while(t[1].size()<(rings+1){ //loop until finished putting on rings
        cout << "Move # " << move << ": move ring " << candidate << " from " << char(from+65) << " tower to " << char(to+65) << " tower" << endl;  
        move++; //increment move number to keep track of number of moves of rings
        t[to].push_back(t[from].back()); //get the top ring from the from tower and push it onto the to tower
        t[from].pop_back(); //then delete that ring from the from tower it was on because you moved it to new to tower
        if(isOdd) odd_move(t, to, from, candidate); //check if number of rings is odd to call correct odd or even function
        else even_move(t, to, from, candidate);
        candidate=t[from].back(); //intiialize candidate to be the top-most ring in the from tower
    }
}

void odd_move(vector<int> t[], int &to, int &from, int &candidate){
    if ( t[(to+1)%3].back()<(t[(to+2)%3].back()) ) { //if the top-most ring on tower to the right of current to tower is less than that of the tower 2 to the right 
        from=(to+1)%3; //initialize from tower to be that first tower to the right of current to tower 
        candidate=t[from].back(); //intiialize candidate to be the top most element of the from tower
    } else {
        from=(to+2)%3; //otherwise the new from tower is the tower 2 to the right of current to tower
        candidate=t[from].back(); 
    }
    if (candidate < t[(from+1)%3].back()) to=(from+1)%3; //if candidate is smaller than the top-most ring on the tower to the right of the from tower (since its an odd number of rings) then initialize to tower to be that tower
    else to=(from+2)%3; //if that move isnt valid then to tower must be the other tower (tower 2 to the right)
}

void even_move(vector<int> t[], int &to, int &from, int &candidate){
    if ( t[(to+1)%3].back()<(t[(to+2)%3].back()) ) { //check for to tower in same way as did for odd move function
        from=(to+1)%3;
        candidate=t[from].back();
    } else {
        from=(to+2)%3;
        candidate=t[from].back();
    }
    if ( candidate < t[(from+2)%3].back() ) to=(from+2)%3; //if candidate is smaller than the top-most ring on the tower to the left of the from tower (since its an even number of rings) then initialize to tower to be that tower
    else to=(from+1)%3; //if that move isnt valid then to tower must be the other tower (tower 1 to the right)
}
