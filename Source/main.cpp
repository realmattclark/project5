#include <iostream>
#include <fstream>
#include <string>
#include "audio.h"
#include "video.h"
#include "media.h"

using namespace std;

int main() {
    ifstream myfile("Program5Data.txt");

    ifstream in;
    ofstream outAudio;
    ofstream outVideo;
    string file1 = "Program5Data.txt";
    string file2 = "audio.txt";
    string file3 = "video.txt";

    Media* mediaFiles[200];
    int readIndex = 0;
    int writeIndex = 0;
    char fileType = ' ';

    in.open(file1);
    if (!in.is_open()) {
        cout << "Failed to open file: " << file1 << endl;
    }
    else {
        outAudio.open(file2);
        outVideo.open(file3);
        if (!outAudio.is_open() || !outVideo.is_open()) {
        }
        else {
            while (in >> fileType) {
                in.ignore();
                switch (fileType) {
                case 'A':
                    mediaFiles[readIndex] = new Audio;
                    break;
                case 'V':
                    mediaFiles[readIndex] = new Video;
                    break;
                }
                mediaFiles[readIndex]->ReadData(in);
                readIndex++;
            }
        }

        while (mediaFiles[writeIndex] != nullptr && writeIndex <= readIndex) {
            if (mediaFiles[writeIndex]->getType() == "A") {
                mediaFiles[writeIndex]->WriteData(outAudio);
            }
            else if(mediaFiles[writeIndex]->getType()=="V") {
                mediaFiles[writeIndex]->WriteData(outVideo);
            }
            writeIndex++;

        }
    }

    string line;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << endl;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file" << endl;
    return 0;
}