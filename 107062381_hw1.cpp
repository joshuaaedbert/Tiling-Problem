#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 
  
int size_of_grid, b, a, cnt = 0; 
int arr[1024][1024]; 
  
// Placing tile at the given coordinates 
void place(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
    cnt++; 
    arr[x1][y1] = cnt; 
    arr[x2][y2] = cnt; 
    arr[x3][y3] = cnt; 
} 
  
// Function based on divide and conquer 
void tile(int n, int x, int y) 
{
    int r, c;
    //base case 
    if(n == 2){ 
      cnt++; 
      for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
          if (arr[x + i][y + j] == 0) { 
            arr[x + i][y + j] = cnt; 
          } 
        } 
      } 
      return; 
    } 
    // finding hole location
    for (int i = x; i < n; i++){ 
      for (int j = y; j < n; j++) { 
        if (arr[i][j] != 0) 
          r = i, c = j; 
      } 
    }
    // If missing tile is in 2nd quadrant 
    if (r < x+(n/2) && c < y+n/2){
      place(x+((n/2)-1), y+(n/2), x+(n/2), y+(n/2-1), x+(n/2), y+(n/2));
      // diving it again in 4 quadrants
      tile(n/2, x+n/2, y); //quadrant 3 
      tile(n/2, x, y+n/2); //quadrant 1
      tile(n/2, x, y);  //quadrant 2
      tile(n/2, x+n/2, y+n/2); //quadrant 4
    } 
    // If missing Tile is in 3rd quadrant 
    else if (r >= x+n/2 && c < y+n/2){
      place(x+(n/2-1), y+(n/2), x+((n/2)-1), y+(n/2-1), x+(n/2), y+(n/2));
      // diving it again in 4 quadrants
      tile(n/2, x+n/2, y); //quadrant 3 
      tile(n/2, x, y+n/2); //quadrant 1
      tile(n/2, x, y);  //quadrant 2
      tile(n/2, x+n/2, y+n/2); //quadrant 4
    } 
    // If missing Tile is in 1st quadrant 
    else if (r < x+n/2 && c >= y+n/2){
      place(x+(n/2-1), y+(n/2-1), x+(n/2), y+(n/2-1), x+(n/2), y+(n/2));
      // diving it again in 4 quadrants 
      tile(n/2, x, y+n/2); //quadrant 1
      tile(n/2, x, y);  //quadrant 2
      tile(n/2, x+n/2, y); //quadrant 3
      tile(n/2, x+n/2, y+n/2); //quadrant 4
    } 
    // If missing Tile is in 4st quadrant 
    else if (r >= x+n/2 && c >= y+n/2){
      place(x+(n/2-1), y+(n/2-1), x+(n/2), y+(n/2-1), x+(n/2-1), y+(n/2));
      // diving it again in 4 quadrants 
      tile(n/2, x, y+n/2); //quadrant 1
      tile(n/2, x, y);  //quadrant 2
      tile(n/2, x+n/2, y); //quadrant 3
      tile(n/2, x+n/2, y+n/2); //quadrant 4 
    } 
    return; 
}

// Driver program to test above function 
int main() 
{ 
  int Testcase;
  cin >> Testcase;

  while(Testcase--){ //for each Testcase
    //size of box
    cnt = 0; 
    int k;
    cin >> k;
    size_of_grid = pow( 2, k);   
    memset(arr, 0, sizeof(arr)); 
    // Coordinates which will be marked 
    cin >> b >> a;
    // Here tile can not be placed 
    arr[a][b] = -1;
    tile(size_of_grid, 0, 0); 
    // The grid is 
    for (int i = 0; i < size_of_grid; i++) { 
        for (int j = 0; j < size_of_grid; j++) 
            cout << arr[i][j] << " \t"; 
        cout << "\n"; 
    }
    cout << endl;
  }   
} 

//test case
/*
3
1 0 0
2 2 1
3 1 3
*/