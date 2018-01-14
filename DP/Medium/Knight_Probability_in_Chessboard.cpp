class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        //These are the neighbors of that point on board
        int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
        int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
        //We will just keep the probability at each coordinate at each step
        //2 is used to store only the 2 recent step layer (For ex:- 0th step and 1st step)
        //For other layers we will use modulo operator i.e step%2
        double bd[N][N][2];
        //This is when 0 steps are left
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                bd[i][j][0] = 1.0000000;
        
        //We see at each step,at every coordinate on board
        for(int step=1;step<=K;step++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    bd[i][j][step%2] = 0.0000000;
                    //For each neighbor
                    for(int k=0;k<8;k++){
                        int x = i+dx[k],y = j+dy[k];
                        //If it is on board add that probability
                        if(x>=0 && y>=0 && x<N && y<N)
                            bd[i][j][step%2] = bd[i][j][step%2] + bd[x][y][!(step%2)];  //for previous layer we have !(step%2)
                    }
                    //There could be 8 possibilities,so we divide by 8
                    bd[i][j][step%2] = bd[i][j][step%2]/8.00000000;
                }
            }
        }
        return bd[r][c][K%2];
    }
};