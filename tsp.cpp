#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream input;
    input.open("Sample_Tours/reuc_100");
    //input.open("Sample_Tours/samInp");
    ofstream ofile;
    ofile.open("sample.txt", ios::trunc | ios::out | ios::in);
    string line;
    int euclidean,N;
    vector<vector<double>> coordinate,distance;
    // vector<vector<long long int>> coordinate;
    long long int flag = 0,sum = 0,cnt = 0,flag1 = 0,cnt1 = 1;
    while(input){
        if(cnt1>N) flag = 3;
        getline(input,line);
        if(line.length()){
        if(flag == 0){
            if(line == "euclidean") euclidean = 1;
            else euclidean = 0;
            //cout<<euclidean<<endl;
            flag = 1;
        }
        else if(flag == 1){
            N = 0;
            for(auto x:line){
                N = (N*10)+((int)x-48);
                if(x == ' ') break;
            }
            //cout<<N<<endl;
            flag = 2;
        }
        else if(flag == 2){
            cnt1++;
            sum = 0;cnt = 0;flag1 = 0;
             vector<double> vec;
            //vector<long long int> vec;
            for(auto x:line){
                
                if(x == ' '){
                    //cout<<sum<<" "<<cnt<<endl;
                    vec.push_back(sum*pow(0.1,cnt));
                    ofile<<cnt<<" ";
                    //vec.push_back((sum*10000)+cnt);
                    sum = 0;
                    cnt = 0;
                    flag1 = 0;
                }
                else if(x == '.') flag1 = 1;
                else{
                    sum = (sum*10)+((int)x-48);
                    if(flag1) cnt++;
                }
            }
            vec.push_back(sum*pow(0.1,cnt));
            ofile<<cnt<<endl;
            //vec.push_back((sum*1000)+cnt);
            coordinate.push_back(vec);
        }
        else if(flag == 3){
            sum = 0;cnt = 0;flag1 = 0;
             vector<double> vec;
            //vector<long long int> vec;
            for(auto x:line){
                
                if(x == ' '){
                    //cout<<sum<<" "<<cnt<<endl;
                    vec.push_back(sum*pow(0.1,cnt));
                    ofile<<cnt<<" ";
                    //vec.push_back((sum*10000)+cnt);
                    sum = 0;
                    cnt = 0;
                    flag1 = 0;
                }
                else if(x == '.') flag1 = 1;
                else{
                    sum = (sum*10)+((int)x-48);
                    if(flag1) cnt++;
                }
            }
            vec.push_back(sum*pow(0.1,cnt));
            ofile<<cnt<<endl;
            //vec.push_back((sum*1000)+cnt);
            distance.push_back(vec);
        }
        }
    }
    input.close();

    
    // for(int j=0;j<coordinate[0].size();j++){
    //         cout<<fixed<<setprecision(10)<<coordinate[0][j]<<" ";
    //     }
    //     cout<<endl;
        //cout<<distance[0].size()<<endl;
        // for(int i=0;i<distance.size();i++){
        // for(int j=0;j<distance[i].size();j++){
        //     cout<<fixed<<setprecision(10)<<distance[i][j]<<" ";
        // }
        // cout<<endl;
        // }
        //  cout<<endl;
    // for(int i=0;i<coordinate.size();i++){
    //     for(int j=0;j<coordinate[i].size();j++){
    //         cout<<fixed<<setprecision(10)<<coordinate[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<distance.size();i++){
    //     for(int j=0;j<distance[i].size();j++){
    //         cout<<fixed<<setprecision(10)<<distance[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    ofile.close();

    //INITIALIZATION
    int l = 2;
    vector<double> Lk,probability,cumulativeProb;
    Lk.clear();probability.clear();cumulativeProb.clear();

    vector<vector<double>> pheromoneTrail;
    pheromoneTrail.clear();
    vector<int> VisitedNode;
    for(int i=0;i<N;i++){
        vector<double> temp;
        for(int j=0;j<N;j++){
            temp.push_back(1);
        }
        pheromoneTrail.push_back(temp);
    }
    // for(int i=0;i<pheromoneTrail.size();i++){
    //     for(int j=0;j<pheromoneTrail[i].size();j++){
    //         cout<<pheromoneTrail[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // vector<int> demo = {2,1,4,3};
    // int a = min_element(demo.begin(),demo.end())-demo.begin();
    // cout<<a<<endl;
    // for (int i = 0; i < 5; i++) 
    // {
    //     cout << (double) rand()/RAND_MAX << endl;
    // }

    //cout<<pheromoneTrail.size()<<" "<<pheromoneTrail[0].size()<<" "<<Lk.size()<<" "<<probability.size()<<" "<<cumulativeProb.size()<<endl;
    //cout<<fixed<<setprecision(10)<<(pheromoneTrail[0][1]/distance[0][1])<<endl;
    
    vector<int> startAnt;
    int key;
    while(startAnt.size() != l){
        key = rand()%l;
        //cout<<key<<endl;
        if(!count(startAnt.begin(),startAnt.end(),key)){
            startAnt.push_back(key);
        }
    }
    vector<int> observedNode;
    //cout<<startAnt.size()<<endl;
    int length = 0,index,index1;
    double sumD;
    for(int k=0;k<startAnt.size();k++){
        VisitedNode.clear();
            index = startAnt[k];
            VisitedNode.push_back(index);
            length = 0;
            for(int i=0;i<distance.size()-1;i++){
                //cout<<"i : "<<i<<endl;
                sumD = 0;
                // sum = accumulate(distance[index].begin(),distance[index].end(),0);
                //Calculate Divide Sum Probability
                for(int j=0;j<distance[index].size();j++){
                    if(!count(VisitedNode.begin(),VisitedNode.end(),j)){
                        sumD += (pheromoneTrail[index][j]/distance[index][j]);
                    }
                    
                }
                //cout<<sumD<<endl;
                //Calculate Probability - make zero
                for(int j=0;j<distance[index].size();j++){
                    if(!count(VisitedNode.begin(),VisitedNode.end(),j)){
                        probability.push_back((pheromoneTrail[index][j]/distance[index][j])/sumD);
                        observedNode.push_back(j);
                    }
                }
                //Calculate Cumulative Probability - make zero
                double val;
                for(int j=0;j<probability.size();j++){
                    val = 0;
                    for(int h=j;h<probability.size();h++){
                        val += probability[h];
                    }
                    cumulativeProb.push_back(val);
                }

                //Randomly choose neighbour with some probability
                double finalProb = (double) rand()/RAND_MAX;
                int fProb;
                //cout<<"FinalProb : "<<finalProb<<endl;
                for(int j=1;j<cumulativeProb.size();j++){
                    if(finalProb>cumulativeProb[j]){
                        fProb = j-1;
                        break;
                    }
                }
                //cout<<"FinalProb : "<<fProb<<endl;
                //New visited node
                // cout<<probability.size()<<endl;
                // cout<<"Probability : ";
                // for(int m=0;m<probability.size();m++){
                //     cout<<probability[m]<<" ";
                // }
                // cout<<endl;
                // cout<<cumulativeProb.size()<<endl;
                // cout<<"Cumulative : ";
                // for(int m=0;m<cumulativeProb.size();m++){
                //     cout<<cumulativeProb[m]<<" ";
                // }
                // cout<<endl;
                if(probability.size()){
                    //index1 = observedNode[max_element(probability.begin(),probability.end())-probability.begin()];
                    index1 = observedNode[fProb];
                    length += distance[index][index1];//sum of length of path
                    index = index1;
                    VisitedNode.push_back(index);
                }
                probability.clear();
                observedNode.clear();
                cumulativeProb.clear();
                // cout<<"VisitedNode : ";
                // for(int i=0;i<VisitedNode.size();i++){
                //     cout<<VisitedNode[i]<<" ";
                // }
                // cout<<endl;
                // cout<<VisitedNode.size()<<" "<<length<<endl;
                // cout<<endl;
            }
            // cout<<length<<endl;
            Lk.push_back(length+distance[VisitedNode[0]][VisitedNode[VisitedNode.size()-1]]);

// <----------------------------- PHEROMONE INTENSITY REMAINING -------------------------------------------->
            
            //Pheromone Intensity 
            sum = 0;
            for(int p=0;p<Lk.size();p++){
                //Add only if ant k travels from here
                //Find edge from which it travelled and only add to that edge
                sum += (1/Lk[p]);
            }
            for(int p=0;p<pheromoneTrail.size();p++){
                for(int q=0;q<pheromoneTrail[p].size();q++){
                    if(distance[p][q]){

                    }
                }
            }

            cout<<"VisitedNode : ";
            for(int i=0;i<VisitedNode.size();i++){
                cout<<VisitedNode[i]<<" ";
            }
            cout<<endl;
            cout<<VisitedNode.size()<<endl;
    }
    cout<<"Length : ";
    for(int i=0;i<Lk.size();i++){
        cout<<Lk[i]<<" ";
    }
    cout<<endl;
    // sort(VisitedNode.begin(),VisitedNode.end());
    // cout<<"VisitedNode : ";
    //         for(int i=0;i<VisitedNode.size();i++){
    //             cout<<VisitedNode[i]<<" ";
    //         }
    //         cout<<endl;

    // for(int i=0;i<startAnt.size();i++){
    //     cout<<startAnt[i]<<" ";
    // }
    // cout<<endl;


    // cout<<pheromoneTrail.size()<<endl;
    // for(int i=0;i<pheromoneTrail[0].size();i++){
    //     cout<<pheromoneTrail[0][i]<<" ";
    // }
    // cout<<endl;
    //ITERATIONS
    
    return 0;
}