#include <iostream>
#include <string>
using namespace std;

class Musicplayer {
    public:
        string playlist[100];
        string currentsong;
        int count=0;

    void addSong(string songname) {
        playlist[count++]=songname;
    }

    void removesong(string songname) {
    int check = 0;    
        for(int i=0;i<=count;i++){
            if(playlist[i]==songname){
                playlist[i]="";
                cout<<"song : "<<songname<<" is removed from the playlist"<<endl;
                check=1;
                break;
            }
        }
        if(check!=1){
            cout<<songname<<" not found in the playlist "<<endl;
        }
    }

    void playsong(string songname){
    int check =0;
        for(int i=0; i <=count; i++){
            if(songname==playlist[i]){
                cout<<"song is playing"<<endl;
                check =1;
            }
        }
        if(check!=1){
            cout<<"song not found"<<endl;
        }
    }

    void displayplaylist(){
        for(int i=0;i<=count;i++){
            cout<<playlist[i]<<endl;
        }
    }
};
int main() {
    Musicplayer m1;
    for(int i=0;i<10;i++){
        m1.addSong("song"+to_string(i));
    }
    m1.removesong("song5");
    m1.removesong("song15");
    m1.playsong("song3");
    m1.playsong("song13");
    m1.displayplaylist();

    return 0;
}
