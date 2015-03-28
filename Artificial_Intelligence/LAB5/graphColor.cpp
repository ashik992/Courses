#include <iostream>
#include <vector>

#define V 11

using namespace std;

int m;
bool graph[V][V] = {0};
int color[V] = {0};
string colorName[6] = {" ", "Red", "Gre", "Blue", "Yellow", "Black"};
 
void init();
bool backTrack();

int main(){
    cout<<"Input the number of colors: ";
    cin>>m;
    m++;

    init();
    if(backTrack()){
        cout<<"\t";
        for (int i = 1; i < V; i++)
            cout<<i<<"("<<colorName[color[i]]<<")\t";
        cout<<endl;
            
        for (int i = 1; i < V; i++) {
            cout<<i<<"("<<colorName[color[i]]<<")\t";
            for (int j = 1; j < V; j++) {
                cout<<graph[i][j]<<"\t";
            }
            cout<<endl<<endl;
        }
    }else{
        cout<<"Coloring not possible";
    }
    
    return 0;
}

void init(){
    graph[1][4] = 1;
    graph[4][1] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[2][5] = 1;
    graph[5][2] = 1;
    graph[2][9] = 1;
    graph[9][2] = 1;
    graph[9][7] = 1;
    graph[7][9] = 1;
    graph[7][6] = 1;
    graph[6][7] = 1;
    graph[5][8] = 1;
    graph[8][5] = 1;
    graph[3][8] = 1;
    graph[8][3] = 1;
    graph[3][7] = 1;
    graph[7][3] = 1;
    graph[5][6] = 1;
    graph[6][5] = 1;
    graph[4][6] = 1;
    graph[6][4] = 1;
    graph[9][10] = 1;
    graph[10][9] = 1;
    graph[8][10] = 1;
    graph[10][8] = 1;
    graph[4][10] = 1;
    graph[10][4] = 1;
}

bool backTrack(){
    int j;
    bool possible[V][m];

    for (int i = 1; i < V; i++)
        for (int j = 1; j < m; j++)
            possible[i][j] = 1;

    for (int i = 1; i < V; i++) {
        for (j = 1; j <= m; j++){
            if(possible[i][j]){
                color[i] = j;
                possible[i][j] = 0;
                break;
            }else if(j == m){
                if(i==0)
                    return false;
                i -= 2;
            }
        }

        for (int k = 1; k < V; k++) {
            if(graph[i][k])
                possible[k][j] = 0;
        }
    }

    return true;
}
