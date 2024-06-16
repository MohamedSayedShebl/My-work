#include <iostream>
#include "bmplib.h"
#include <unistd.h>
#include <cmath>
// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				Image processing program.cpp
// Last Modification Date:	18/10/2023
// Author1 and ID and Group:	Mohamed shebl-20220290-Group A
// Author2 and ID and Group:	Ali Emad-20220210-Group A
//Purpose:A program that processes images from the user in different ways
unsigned char imgRGB[SIZE][SIZE][RGB];
unsigned char imgRGB2[SIZE][SIZE][RGB];
unsigned char imgRGB3[SIZE][SIZE][RGB];

void read(){
    std::string imagename,path = "\\imgs\\" ;
    std::cout<<"Enter image name: ";                    //read image function
    std::cin>>imagename;
    imagename+=".bmp";                                //the function adds the bmp extension by itself
    path+=imagename;
    char cwd[PATH_MAX];
    readRGBBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()),imgRGB);
}
void save(){
    char newname[100];
    std::cout<<"Enter new image name with the .bmp extension: ";              //save image function
    std::cin>>newname;                                               //the image name has to have the .bmp extension inputted by the user
    writeRGBBMP(newname,imgRGB);
}
void Menu(char &a){
    std::cout << "Please enter the number or letter of the operation you would like to be done to the image:\n ";
    std::cout<< "1-Black and White\n2-Invert Image\n3-Merge Images\n4-Flip Image\n5-Rotate Image\n6-Darken and Lighten Image\n7-Detect Image Edges\n8-Enlarge Image\n9-Shrink Image\na-Mirror Image\nb-Shuffle Image\nc-Blur Image\nd-Crop Image\ne-Skew Horizontally\nf-Skew Vertically\ns-Save image\n0-Exit\n";
    std::cin >> &a;            //this is the op number
}

void blackAndWhiteFilter() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int avr=0;
            for (int k = 0; k < RGB; ++k) {
                avr+=imgRGB[i][j][k];                       //calculating the average of RGB components
            }
            avr=avr/3;
            for (int k = 0; k < RGB; ++k) {
                if(avr>127)imgRGB[i][j][k]=255;                      // if pixel value is lower than gray average make it black
                else imgRGB[i][j][k]=0;                              //if else make it white
            }

        }
    }
}

void invertFilter(){
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < RGB; ++k) {
                imgRGB[i][j][k] = 255 - imgRGB[i][j][k];          //make every color the negative version of itself
            }
}

void mergeFilter() {
    std::string imagename2, path = "\\imgs\\";
    std::cout << "Enter image#2 name: ";
    std::cin >> imagename2;
    path += imagename2;                              //reading the picture the user wants to merge with the original one
    char cwd[PATH_MAX];
    readRGBBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgRGB2);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                imgRGB3[i][j][k] = imgRGB[i][j][k];             //copying the original picture
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {                                 //merging the images
                imgRGB[i][j][k] = (imgRGB3[i][j][k] + imgRGB2[i][j][k]) / 2;
            }
        }
    }
}
void flipFilter(){
    int tmp;
    char state;
    std::cout << "(h)orizontally or (v)ertically?";               // take user input for flip direction
    std::cin >> state;
    if (state == 'v') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    tmp = imgRGB[i][j][k];
                    imgRGB[i][j][k] = imgRGB[256 - 1 - i][j][k];       // swap pixel with it's corresponding vertical pixel
                    imgRGB[256 - 1 - i][j][k] = tmp;
                }
            }
        }
    } else if (state == 'h') {
        for (int j = 0; j < SIZE / 2; j++) {
            for (int i = 0; i < SIZE; i++) {
                for (int k = 0; k < RGB; ++k) {
                    tmp = imgRGB[i][j][k];
                    imgRGB[i][j][k] = imgRGB[i][256 - 1 - j][k];      // swap pixel with it's corresponding horizontal pixel
                    imgRGB[i][256 - 1 - j][k] = tmp;
                }
            }
        }
    }
}

void rotateFilter() {
    int tmp;
    int deg;
    std::cout << "please enter the degree: ";
    std::cin >> deg;
    if (deg == 90) {
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = i + 1; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    if (i <= j) {
                        tmp = imgRGB[i][j][k];
                        imgRGB[i][j][k] = imgRGB[j][i][k];
                        imgRGB[j][i][k] = tmp;
                    }
                }
            }                                  //rotating the picture 90 degrees
        }
        for (int j = 0; j < SIZE / 2; j++) {
            for (int i = 0; i < SIZE; i++) {
                for (int k = 0; k < RGB; ++k) {
                    tmp = imgRGB[i][j][k];
                    imgRGB[i][j][k] = imgRGB[i][256 - 1 - j][k];
                    imgRGB[i][256 - 1 - j][k] = tmp;
                }
            }
        }
    }
    if (deg == 180) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    tmp = imgRGB[i][j][k];
                    imgRGB[i][j][k] = imgRGB[256 - 1 - i][j][k];
                    imgRGB[256 - 1 - i][j][k] = tmp;
                }
            }
        }                                     //rotating the picture 180 degrees
        for (int j = 0; j < SIZE / 2; j++) {
            for (int i = 0; i < SIZE; i++) {
                for (int k = 0; k < RGB; ++k) {
                    tmp = imgRGB[i][j][k];
                    imgRGB[i][j][k] = imgRGB[i][256 - 1 - j][k];
                    imgRGB[i][256 - 1 - j][k] = tmp;
                }
            }
        }
    }
    if (deg == 270) {
        for (int t = 0; t < 3; ++t) {
            for (int i = 0; i < SIZE - 1; i++) {
                for (int j = i + 1; j < SIZE; j++) {
                    for (int k = 0; k < RGB; ++k) {
                        if (i <= j) {
                            tmp = imgRGB[i][j][k];
                            imgRGB[i][j][k] = imgRGB[j][i][k];
                            imgRGB[j][i][k] = tmp;
                        }
                    }                                          //rotating the picture 270 degrees
                }
            }
            for (int j = 0; j < SIZE / 2; j++) {
                for (int i = 0; i < SIZE; i++) {
                    for (int k = 0; k < RGB; ++k) {
                        tmp = imgRGB[i][j][k];
                        imgRGB[i][j][k] = imgRGB[i][256 - 1 - j][k];
                        imgRGB[i][256 - 1 - j][k] = tmp;
                    }
                }
            }

        }
    }
}

void darkenAndLightenFilter(){
    char mood;
    std::cout << "Do you want to (d)arken or (l)ighten?";
    std::cin >> mood;
    if (mood == 'd') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    imgRGB[i][j][k] -= imgRGB[i][j][k] / 2;                 //decreasing the brightness of every pixel by half its value
                    if (imgRGB[i][j][k] < 0) {
                        imgRGB[i][j][k] = 0;                                   //preventing the pixel from becoming a negative value
                    }
                }
            }
        }
    } else if (mood == 'l') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    if (imgRGB[i][j][k] < 170) {
                        imgRGB[i][j][k] += imgRGB[i][j][k] / 2;         //increasing the brightness of every pixel by half its value
                    } else {
                        imgRGB[i][j][k] = 255;                        //preventing the pixel from becoming higher than 255
                    }
                }
            }
        }
    }
}
void detectEdgeFilter(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int avr=0;                                            //turn the picture black and white
            for (int k = 0; k < RGB; ++k) {
                avr+=imgRGB[i][j][k];
            }
            avr=avr/3;
            for (int k = 0; k < RGB; ++k) {
                if(avr>127)imgRGB[i][j][k]=255;
                else imgRGB[i][j][k]=0;
            }

        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                if (imgRGB[i][j][k] != imgRGB[i][j + 1][k] || imgRGB[i][j][k] != imgRGB[i + 1][j][k])      // if pixel is not the same value as the next horizontal or vertical pixel
                    imgRGB[i][j][k] = 0;                                 //make it black
                else
                    imgRGB[i][j][k] = 255;                               //make it white
            }
        }
    }

}
void enlargeFilter(){
    int x = 0;
    int y = 0;
    int startX = 0, startY = 0;
    char quarter;
    std::cout << "enter the quarter number you would like to enlarge: ";
    std::cin >> quarter;                                    //taking from the user which quarter to enlarge
    if (quarter == '1') {
        startX = 0;
        startY = 0;
    } else if (quarter == '2') {
        startX = 0;
        startY = 128;
    } else if (quarter == '3') {                           //setting the coordinates that the quarter starts at
        startX = 128;
        startY = 0;
    } else if (quarter == '4') {
        startX = 128;
        startY = 128;
    }
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB2[i][j][k] = imgRGB[startX + i][startY + j][k];
            }
        }
    }
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB[x][y][k] = imgRGB2[i][j][k];
                imgRGB[x][y + 1][k] = imgRGB2[i][j][k];                 //enlarging said quarter
                imgRGB[x + 1][y + 1][k] = imgRGB2[i][j][k];            //by putting each single pixel from quarter into 4 pixels of the original image in the shape of a square.
                imgRGB[x + 1][y][k] = imgRGB2[i][j][k];
            }
                y += 2;
                if (y == 256) {
                    y = 0;
                    x += 2;
                }

        }
    }

}
void shrinkFilter(){
    int x = 0, y = 0;
    std::string dim;
    std::cout << "Shrink to (1/2), (1/3) or (1/4)?";
    std::cin >> dim;                             //taking the shrinking factor from the user
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB2[i][j][k] = imgRGB[i][j][k];        //copying the original picture
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB[i][j][k] = 255;                    //turning the original array all white
            }
        }
    }
    if (dim=="1/2") {
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2, y++) {
                for (int k = 0; k < RGB; ++k) {
                    imgRGB[x][y][k] = imgRGB2[i][j][k];      //filling the original array with a shrunk version of the original picture
                }                                           //by cutting out some pixels
            }
            y = 0;
            x++;
        }
    }else if (dim=="1/3") {
        for (int i = 0; i < SIZE; i += 3) {
            for (int j = 0; j < SIZE; j += 3, y++) {
                for (int k = 0; k < RGB; ++k) {
                    imgRGB[x][y][k] = imgRGB2[i][j][k];
                }
            }
            y = 0;
            x++;
        }
    }else if (dim=="1/4") {
        for (int i = 0; i < SIZE; i += 4) {
            for (int j = 0; j < SIZE; j += 4, y++) {
                for (int k = 0; k < RGB; ++k) {
                    imgRGB[x][y][k] = imgRGB2[i][j][k];
                }
            }
            y = 0;
            x++;
        }
    }
}
void mirrorFilter(){
    char half;
    int tmp;
    std::cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side? ";
    std::cin >> half;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB2[i][j][k] = imgRGB[i][j][k];          //copying the original picture
            }
        }
    }
    if (half == 'l') {
        for (int j = 0; j < SIZE / 2; j++) {
            for (int i = 0; i < SIZE; i++) {
                for (int k = 0; k < RGB; ++k) {
                    tmp = imgRGB2[i][j][k];
                    imgRGB2[i][j][k] = imgRGB2[i][256 - 1 - j][k];         //horizontally flipping the picture
                    imgRGB2[i][256 - 1 - j][k] = tmp;
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 128; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    imgRGB[i][j][k] = imgRGB2[i][j][k];              //overwriting the right half with a flipped left half of the picture
                }
            }
        }
    } else if (half == 'r') {
        for (int j = 0; j < SIZE / 2; j++) {
            for (int i = 0; i < SIZE; i++) {
                for (int k = 0; k < RGB; ++k) {                             //horizontally flipping the picture
                    tmp = imgRGB2[i][j][k];
                    imgRGB2[i][j][k] = imgRGB2[i][256 - 1 - j][k];
                    imgRGB2[i][256 - 1 - j][k] = tmp;
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < 128; j++) {
                for (int k = 0; k < RGB; ++k) {                        //overwriting the left half with a flipped right half of the picture
                    imgRGB[i][j][k] = imgRGB2[i][j][k];
                }
            }
        }
    } else if (half == 'd') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    tmp = imgRGB[i][j][k];                           //vertically flipping the picture
                    imgRGB[i][j][k] = imgRGB[256 - 1 - i][j][k];
                    imgRGB[256 - 1 - i][j][k] = tmp;
                }
            }
        }
        for (int i = 128; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {                     //overwriting the lower half with a flipped upper half of the picture
                    imgRGB[i][j][k] = imgRGB2[i][j][k];
                }
            }
        }
    } else if (half == 'u') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    tmp = imgRGB[i][j][k];                        //vertically flipping the picture
                    imgRGB[i][j][k] = imgRGB[256 - 1 - i][j][k];
                    imgRGB[256 - 1 - i][j][k] = tmp;
                }
            }
        }
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {             //overwriting the upper half with a flipped lower half of the picture
                    imgRGB[i][j][k] = imgRGB2[i][j][k];
                }
            }
        }
    }
}
void shuffleFilter(){
    int n;
    int x;
    int y;
    std::cout << "Enter the order of quarters you want: ";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB2[i][j][k] = imgRGB[i][j][k];           //copying the original picture
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        std::cin >> n;
        if (i == 0) {                               //taking the order of the quarters as the user desires
            x = 0;                                  //n is the number of the quarter that will be copied from the original picture
            y = 0;                                  //i is the order of the n quarter in the shuffled picture
            int temp = y;
            if (n == 1)
                for (int k = 0; k < SIZE / 2; x++, k++) {
                    y = temp;        //resetting y to its original first value after every iteration
                    for (int z = 0; z < SIZE / 2; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 2)
                for (int k = 0; k < SIZE / 2; x++, k++) {
                    y = temp;
                    for (int z = SIZE / 2; z < SIZE; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 3)
                for (int k = SIZE / 2; k < SIZE; x++, k++) {
                    y = temp;
                    for (int z = 0; z < SIZE / 2; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 4)
                for (int k = SIZE / 2; k < SIZE; x++, k++) {
                    y = temp;
                    for (int z = SIZE / 2; z < SIZE; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
        } else if (i == 1) {
            x = 0;
            y = 128;
            int temp = y;
            if (n == 1)
                for (int k = 0; k < SIZE / 2; x++, k++) {
                    y = temp;
                    for (int z = 0; z < SIZE / 2; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 2)
                for (int k = 0; k < SIZE / 2; x++, k++) {
                    y = temp;
                    for (int z = SIZE / 2; z < SIZE; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 3)
                for (int k = SIZE / 2; k < SIZE; x++, k++) {
                    y = temp;
                    for (int z = 0; z < SIZE / 2; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 4)
                for (int k = SIZE / 2; k < SIZE; x++, k++) {
                    y = temp;
                    for (int z = SIZE / 2; z < SIZE; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
        } else if (i == 2) {
            x = 128;
            y = 0;
            int temp = y;
            if (n == 1)
                for (int k = 0; k < SIZE / 2; x++, k++) {
                    y = temp;
                    for (int z = 0; z < SIZE / 2; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 2)
                for (int k = 0; k < SIZE / 2; x++, k++) {
                    y = temp;
                    for (int z = SIZE / 2; z < SIZE; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 3)
                for (int k = SIZE / 2; k < SIZE; x++, k++) {
                    y = temp;
                    for (int z = 0; z < SIZE / 2; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 4)
                for (int k = SIZE / 2; k < SIZE; x++, k++) {
                    y = temp;
                    for (int z = SIZE / 2; z < SIZE; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                        imgRGB[x][y][j] = imgRGB2[k][z][j];
                    }
                }
                }
        } else if (i == 3) {
            x = 128;
            y = 128;
            int temp = y;
            if (n == 1)
                for (int k = 0; k < SIZE / 2; x++, k++) {
                    y = temp;
                    for (int z = 0; z < SIZE / 2; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 2)
                for (int k = 0; k < SIZE / 2; x++, k++) {
                    y = temp;
                    for (int z = SIZE / 2; z < SIZE; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 3)
                for (int k = SIZE / 2; k < SIZE; x++, k++) {
                    y = temp;
                    for (int z = 0; z < SIZE / 2; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                            imgRGB[x][y][j] = imgRGB2[k][z][j];
                        }
                    }
                }
            else if (n == 4)
                for (int k = SIZE / 2; k < SIZE; x++, k++) {
                    y = temp;
                    for (int z = SIZE / 2; z < SIZE; y++, z++) {
                        for (int j = 0; j < RGB; ++j) {
                        imgRGB[x][y][j] = imgRGB2[k][z][j];
                    }
                }
                }
        }
    }
}
void blurFilter(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB2[i][j][k] = imgRGB[i][j][k];
            }
        }
    }
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {                     //box blur method
            for (int k = 0; k < RGB; ++k) {
                imgRGB[i][j][k] = (imgRGB2[i - 1][j - 1][k] * 1 + imgRGB2[i - 1][j][k] * 1 + imgRGB2[i - 1][j + 1][k] * 1 +
                               imgRGB2[i][j - 1][k] * 1 + imgRGB2[i][j][k] * 1 + imgRGB2[i][j + 1][k] * 1 +
                               imgRGB2[i + 1][j - 1][k] * 1 + imgRGB2[i + 1][j][k] * 1 + imgRGB2[i + 1][j + 1][k] * 1) * 1 / 9;
            }
        }
    }

}

void cropFilter(){
    int x, y, l, w;
    std::cout << "Please enter x y l w: ";
    std::cin >> x >> y >> l >> w;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB2[i][j][k] = imgRGB[i][j][k];             //copying the original picture
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB[i][j][k] = 0;                      //turning the original array all black
            }
        }
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB[i][j][k] = imgRGB2[x + i][y + j][k];          //cropping the picture
            }
        }
    }
}

void skewHorizontally(){

    double rad;
    std::cout << "Please enter degree to skew right: ";
    std::cin >> rad;
    rad = (rad * 22) / (180 * 7);
    double mov = tan(rad) * 256;
    double step = mov / SIZE;
    unsigned char img_in[SIZE][SIZE + (int) mov][RGB];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < RGB; ++k)
            img_in[i][j][k] = 255;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                img_in[i][j + (int) mov][k] = imgRGB[i][j][k];
            }
        }
        mov -= step;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB[i][j][k] = img_in[i][j][k];
            }
        }
    }
}

void skewVertically(){
    double rad;
    std::cout << "Please enter degree to skew up: ";
    std::cin >> rad;
    rad = (rad * 22) / (180 * 7);
    double mov = tan(rad) * 256;
    double step = mov / SIZE;
    unsigned char img_in[SIZE + (int) mov][SIZE][RGB];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < RGB; ++k)
            img_in[i][j][k] = 255;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                img_in[j + (int) mov][i][k] = imgRGB[j][i][k];
            }
        }
        mov -= step;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                imgRGB[i][j][k] = img_in[i][j][k];
            }
        }
    }

}
int main() {
    // The program loops on the same picture until saved, The user can apply multiple filters on the same picture.
    // The program asks for a new picture only after the user save the previous picture.
    char op_number = '1';
    read();
    while (op_number != '0') {
        Menu(op_number);
        if (op_number == '1') {
            blackAndWhiteFilter();
        }
        if (op_number == '2') {
            invertFilter();
        }
        if (op_number == '3') {
            mergeFilter();
        }
        if (op_number == '4') {
            flipFilter();
        }
        if (op_number == '5') {
            rotateFilter();
        }
        if (op_number == '6') {
            darkenAndLightenFilter();
        }
        if (op_number == '7') {
            detectEdgeFilter();
        }
        if (op_number == '8') {
            enlargeFilter();
        }
        if (op_number == '9') {
            shrinkFilter();
        }
        if (op_number == 'a') {
            mirrorFilter();
        }
        if (op_number == 'b') {
            shuffleFilter();
        }
        if (op_number == 'c') {
            blurFilter();
        }
        if (op_number == 'd') {
            cropFilter();
        }
        if (op_number == 'e') {
            skewHorizontally();
        }
        if (op_number == 'f') {
            skewVertically();
        }
        if (op_number == 's') {
            save();
            std::cout<<"Save completed!\n";
            read();           //reading the new picture after the save is completed
        }
        if (op_number == '0') {
            std::cout<<"Thank you for using our program!\n";
        }
    }
    return 0;
}