#include "Josephus.h"

Josephus::Josephus(void)
{
	string tempNames [20] = {"Josephus","David","Benjamin","Judah","Ephraim","Menassah","Ezra","Asher","Joseph","Isaiah","Moses","Aaron","Maher-Shalal-Hashbaz","Zurishaddai","Zuar","Ammishaddai","Reuben","Gad","Zebulun","Simeon"};
	for(int n=0;n<20;n++){
		names.push_back(tempNames[n]);
	}
}

Josephus::~Josephus(void) {}


vector<string> Josephus::getNames()
{
	return names;
}

vector<string> Josephus::playGame(int n, int m)
{
	vector<string> deadList;
	vector<string> namesUsed;
	for(int j=0;j<n;j++){
		namesUsed.push_back(names[j]);
	}
	if(n>=10 || n<=20 || m<=0)
		return deadList;
	else{
		int index = m-1;
		while(namesUsed.size() != 0){
			for(index;index<namesUsed.size();index+=(m-1)){
				deadList.push_back(namesUsed[index]);
				namesUsed.erase(namesUsed.begin()+index);
			}
			index -= namesUsed.size();
			}
		return deadList;
		}
}


int Josephus::reportSafeIndex(int n, int m)
{
	if(n>=10 || n<=20 || m<=0)
		return -1;
	else{
		vector<string> namesUsed;
		for(int j=0;j<n;j++){
			namesUsed.push_back(names[j]);
		}
		int index = m-1;
		vector<int> safeIndex;
		while(safeIndex.size() != n){
			for(index;index<n;index+=(m-1)){
				for(int y=0;y<safeIndex.size();y++){
					if(safeIndex[y] == index){
						index++;
					}
				}
				safeIndex.push_back(index);
			}
			index -= namesUsed.size();
		}
		return safeIndex[n-1];
	}
}