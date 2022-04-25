#include <iostream>
#include <fstream>
#include <string>
#include "audio.h"
#include "video.h"
#include "media.h"

using namespace std;

int main() {

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
        return -1;
    }
    else {
        outAudio.open(file2);
        outVideo.open(file3);
        if (!outAudio.is_open() || !outVideo.is_open()) {
            std::cout << "Failed to open either " << file2 << " or " << file3 << std::endl;
            return -1;
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

        while (mediaFiles[writeIndex] != nullptr
            && writeIndex <= readIndex) {
            if (mediaFiles[writeIndex]->getType() == "Audio") {
                mediaFiles[writeIndex]->WriteData(outAudio);
            }
            else {
                mediaFiles[writeIndex]->WriteData(outVideo);
            }
            writeIndex++;
        }
    }
    in.close();
    outAudio.close();
    outVideo.close();

    return 0;
}